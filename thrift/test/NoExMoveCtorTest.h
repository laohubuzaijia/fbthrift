/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <string>
#include <unordered_map>

namespace apache {
namespace thrift {
namespace test {

class s2sumap : public std::unordered_map<std::string, std::string> {
 public:
  using base_t = std::unordered_map<std::string, std::string>;
  s2sumap() {}
  s2sumap(const s2sumap& other) noexcept(false) : base_t(other) {}
  s2sumap(s2sumap&& other) noexcept(false) : base_t(std::move(other)) {}
  s2sumap& operator=(const s2sumap&) = default;
  s2sumap& operator=(s2sumap&&) = default;
};

// A type that may throw in move ctor.
class ThrowCtorType : public std::string {
 public:
  ThrowCtorType() {}

  // the move ctor is not annotated with "noexcept"
  [[noreturn]] ThrowCtorType(ThrowCtorType&& other)
      : std::string(std::move(other)) {
    throw(1);
  }

  explicit ThrowCtorType(std::string&& other) : std::string(std::move(other)) {}

  ThrowCtorType& operator=(const ThrowCtorType& other) = default;
  ThrowCtorType& operator=(const std::string& /* other */) { return *this; }
};

} // namespace test
} // namespace thrift
} // namespace apache
