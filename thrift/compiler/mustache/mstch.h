/*

The source code contained in this file is based on the original code by
Daniel Sipka (https://github.com/no1msd/mstch). The original license by Daniel
Sipka can be read below:

The MIT License (MIT)

Copyright (c) 2015 Daniel Sipka

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once

#include <functional>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/variant.hpp>

namespace apache {
namespace thrift {
namespace mstch {

namespace internal {

template <class N>
class object_t {
 public:
  const N& at(const std::string& name) const {
    cache[name] = (methods.at(name))();
    return cache[name];
  }

  bool has(const std::string& name) const {
    return methods.find(name) != methods.end();
  }

 protected:
  void register_method(std::string name, std::function<N()> method) {
    auto result = methods.emplace(std::move(name), std::move(method));
    if (!result.second) {
      throw std::runtime_error(
          "Method already registered: " + result.first->first);
    }
  }

  template <class S>
  void register_methods(
      S* s, const std::map<std::string, N (S::*)()>& methods_) {
    for (const auto& item : methods_) {
      register_method(item.first, [s, m = item.second]() { return (s->*m)(); });
    }
  }

 private:
  std::map<std::string, std::function<N()>> methods;
  mutable std::map<std::string, N> cache;
};

template <class T, class N>
class is_fun {
 private:
  using not_fun = char;
  using fun_without_args = char[2];
  using fun_with_args = char[3];
  template <typename U, U>
  struct really_has;
  template <typename C>
  static fun_without_args& test(really_has<N (C::*)() const, &C::operator()>*);
  template <typename C>
  static fun_with_args& test(
      really_has<N (C::*)(const std::string&) const, &C::operator()>*);
  template <typename>
  static not_fun& test(...);

 public:
  static bool const no_args = sizeof(test<T>(0)) == sizeof(fun_without_args);
  static bool const has_args = sizeof(test<T>(0)) == sizeof(fun_with_args);
};

template <class N>
using node_renderer = std::function<std::string(const N& n)>;

template <class N>
class lambda_t {
 public:
  template <class F>
  /* implicit */ lambda_t(
      F f, typename std::enable_if<is_fun<F, N>::no_args>::type* = 0)
      : fun([f](node_renderer<N> renderer, const std::string&) {
          return renderer(f());
        }) {}

  template <class F>
  /* implicit */ lambda_t(
      F f, typename std::enable_if<is_fun<F, N>::has_args>::type* = 0)
      : fun([f](node_renderer<N> renderer, const std::string& text) {
          return renderer(f(text));
        }) {}

  std::string operator()(
      node_renderer<N> renderer, const std::string& text = "") const {
    return fun(renderer, text);
  }

 private:
  std::function<std::string(node_renderer<N> renderer, const std::string&)> fun;
};

} // namespace internal

using node = boost::make_recursive_variant<
    std::nullptr_t,
    std::string,
    int,
    double,
    bool,
    internal::lambda_t<boost::recursive_variant_>,
    std::shared_ptr<internal::object_t<boost::recursive_variant_>>,
    std::map<const std::string, boost::recursive_variant_>,
    std::vector<boost::recursive_variant_>>::type;
using object = internal::object_t<node>;
using lambda = internal::lambda_t<node>;
using map = std::map<const std::string, node>;
using array = std::vector<node>;

std::string render(
    const std::string& tmplt,
    const node& root,
    const std::map<std::string, std::string>& partials =
        std::map<std::string, std::string>());

} // namespace mstch
} // namespace thrift
} // namespace apache
