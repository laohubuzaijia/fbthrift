/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_types_h.h>



namespace apache {
namespace thrift {
namespace tag {
struct field1;
struct m1;
struct field2;
struct field3;
struct field4;
struct m2;
struct m3;
} // namespace tag
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_field1
#define APACHE_THRIFT_ACCESSOR_field1
APACHE_THRIFT_DEFINE_ACCESSOR(field1);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_m1
#define APACHE_THRIFT_ACCESSOR_m1
APACHE_THRIFT_DEFINE_ACCESSOR(m1);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_field2
#define APACHE_THRIFT_ACCESSOR_field2
APACHE_THRIFT_DEFINE_ACCESSOR(field2);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_field3
#define APACHE_THRIFT_ACCESSOR_field3
APACHE_THRIFT_DEFINE_ACCESSOR(field3);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_field4
#define APACHE_THRIFT_ACCESSOR_field4
APACHE_THRIFT_DEFINE_ACCESSOR(field4);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_m2
#define APACHE_THRIFT_ACCESSOR_m2
APACHE_THRIFT_DEFINE_ACCESSOR(m2);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_m3
#define APACHE_THRIFT_ACCESSOR_m3
APACHE_THRIFT_DEFINE_ACCESSOR(m3);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums

// END declare_enums
// BEGIN forward_declare
namespace cpp2 {
class Mixin1;
class Mixin2;
class Mixin3Base;
class Foo;
} // cpp2
// END forward_declare
// BEGIN typedefs
namespace cpp2 {
typedef ::cpp2::Mixin3Base Mixin3;

} // cpp2
// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace cpp2 {
class Mixin1 final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = Mixin1;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  Mixin1() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Mixin1(apache::thrift::FragileConstructor, ::std::string field1__arg);

  Mixin1(Mixin1&&) = default;

  Mixin1(const Mixin1&) = default;


  Mixin1& operator=(Mixin1&&) = default;

  Mixin1& operator=(const Mixin1&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::std::string field1;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool field1;
  } __isset = {};
  bool operator==(const Mixin1& rhs) const;
#ifndef SWIG
  friend bool operator!=(const Mixin1& __x, const Mixin1& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const Mixin1& rhs) const;
#ifndef SWIG
  friend bool operator>(const Mixin1& __x, const Mixin1& __y) {
    return __y < __x;
  }
  friend bool operator<=(const Mixin1& __x, const Mixin1& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const Mixin1& __x, const Mixin1& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> field1_ref() const& {
    return {this->field1, __isset.field1};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> field1_ref() const&& {
    return {std::move(this->field1), __isset.field1};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> field1_ref() & {
    return {this->field1, __isset.field1};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> field1_ref() && {
    return {std::move(this->field1), __isset.field1};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  const ::std::string& get_field1() const& {
    return field1;
  }

  ::std::string get_field1() && {
    return std::move(field1);
  }

  template <typename T_Mixin1_field1_struct_setter = ::std::string>
  ::std::string& set_field1(T_Mixin1_field1_struct_setter&& field1_) {
    field1 = std::forward<T_Mixin1_field1_struct_setter>(field1_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.field1 = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return field1;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< Mixin1 >;
  friend void swap(Mixin1& a, Mixin1& b);
};

template <class Protocol_>
uint32_t Mixin1::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class Mixin2 final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = Mixin2;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  Mixin2() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Mixin2(apache::thrift::FragileConstructor, ::cpp2::Mixin1 m1__arg, ::std::string field2__arg);

  Mixin2(Mixin2&&) = default;

  Mixin2(const Mixin2&) = default;


  Mixin2& operator=(Mixin2&&) = default;

  Mixin2& operator=(const Mixin2&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::cpp2::Mixin1 m1;
 private:
  ::std::string field2;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool m1;
    bool field2;
  } __isset = {};
  bool operator==(const Mixin2& rhs) const;
#ifndef SWIG
  friend bool operator!=(const Mixin2& __x, const Mixin2& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const Mixin2& rhs) const;
#ifndef SWIG
  friend bool operator>(const Mixin2& __x, const Mixin2& __y) {
    return __y < __x;
  }
  friend bool operator<=(const Mixin2& __x, const Mixin2& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const Mixin2& __x, const Mixin2& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::cpp2::Mixin1>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> m1_ref() const& {
    return {this->m1, __isset.m1};
  }

  template <typename..., typename T = ::cpp2::Mixin1>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> m1_ref() const&& {
    return {std::move(this->m1), __isset.m1};
  }

  template <typename..., typename T = ::cpp2::Mixin1>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> m1_ref() & {
    return {this->m1, __isset.m1};
  }

  template <typename..., typename T = ::cpp2::Mixin1>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> m1_ref() && {
    return {std::move(this->m1), __isset.m1};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<const T&> field2_ref() const& {
    return {this->field2, __isset.field2};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<const T&&> field2_ref() const&& {
    return {std::move(this->field2), __isset.field2};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<T&> field2_ref() & {
    return {this->field2, __isset.field2};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<T&&> field2_ref() && {
    return {std::move(this->field2), __isset.field2};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END
  FOLLY_ERASE auto field1_ref() &       { return m1.field1_ref();            }
  FOLLY_ERASE auto field1_ref() const&  { return m1.field1_ref();            }
  FOLLY_ERASE auto field1_ref() &&      { return std::move(m1).field1_ref(); }
  FOLLY_ERASE auto field1_ref() const&& { return std::move(m1).field1_ref(); }
  const ::cpp2::Mixin1& get_m1() const&;
  ::cpp2::Mixin1 get_m1() &&;

  template <typename T_Mixin2_m1_struct_setter = ::cpp2::Mixin1>
  ::cpp2::Mixin1& set_m1(T_Mixin2_m1_struct_setter&& m1_) {
    m1 = std::forward<T_Mixin2_m1_struct_setter>(m1_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.m1 = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return m1;
  }

  const ::std::string* get_field2() const& {
    return field2_ref() ? std::addressof(field2) : nullptr;
  }

  ::std::string* get_field2() & {
    return field2_ref() ? std::addressof(field2) : nullptr;
  }
  ::std::string* get_field2() && = delete;

  template <typename T_Mixin2_field2_struct_setter = ::std::string>
  ::std::string& set_field2(T_Mixin2_field2_struct_setter&& field2_) {
    field2 = std::forward<T_Mixin2_field2_struct_setter>(field2_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.field2 = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return field2;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< Mixin2 >;
  friend void swap(Mixin2& a, Mixin2& b);
};

template <class Protocol_>
uint32_t Mixin2::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class Mixin3Base final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = Mixin3Base;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  Mixin3Base() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Mixin3Base(apache::thrift::FragileConstructor, ::std::string field3__arg);

  Mixin3Base(Mixin3Base&&) = default;

  Mixin3Base(const Mixin3Base&) = default;


  Mixin3Base& operator=(Mixin3Base&&) = default;

  Mixin3Base& operator=(const Mixin3Base&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::std::string field3;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool field3;
  } __isset = {};
  bool operator==(const Mixin3Base& rhs) const;
#ifndef SWIG
  friend bool operator!=(const Mixin3Base& __x, const Mixin3Base& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const Mixin3Base& rhs) const;
#ifndef SWIG
  friend bool operator>(const Mixin3Base& __x, const Mixin3Base& __y) {
    return __y < __x;
  }
  friend bool operator<=(const Mixin3Base& __x, const Mixin3Base& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const Mixin3Base& __x, const Mixin3Base& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> field3_ref() const& {
    return {this->field3, __isset.field3};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> field3_ref() const&& {
    return {std::move(this->field3), __isset.field3};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> field3_ref() & {
    return {this->field3, __isset.field3};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> field3_ref() && {
    return {std::move(this->field3), __isset.field3};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  const ::std::string& get_field3() const& {
    return field3;
  }

  ::std::string get_field3() && {
    return std::move(field3);
  }

  template <typename T_Mixin3Base_field3_struct_setter = ::std::string>
  ::std::string& set_field3(T_Mixin3Base_field3_struct_setter&& field3_) {
    field3 = std::forward<T_Mixin3Base_field3_struct_setter>(field3_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.field3 = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return field3;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< Mixin3Base >;
  friend void swap(Mixin3Base& a, Mixin3Base& b);
};

template <class Protocol_>
uint32_t Mixin3Base::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class Foo final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = Foo;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  Foo() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Foo(apache::thrift::FragileConstructor, ::std::string field4__arg, ::cpp2::Mixin2 m2__arg, ::cpp2::Mixin3 m3__arg);

  Foo(Foo&&) = default;

  Foo(const Foo&) = default;


  Foo& operator=(Foo&&) = default;

  Foo& operator=(const Foo&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::std::string field4;
 private:
  ::cpp2::Mixin2 m2;
 private:
  ::cpp2::Mixin3 m3;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool field4;
    bool m2;
    bool m3;
  } __isset = {};
  bool operator==(const Foo& rhs) const;
#ifndef SWIG
  friend bool operator!=(const Foo& __x, const Foo& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const Foo& rhs) const;
#ifndef SWIG
  friend bool operator>(const Foo& __x, const Foo& __y) {
    return __y < __x;
  }
  friend bool operator<=(const Foo& __x, const Foo& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const Foo& __x, const Foo& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> field4_ref() const& {
    return {this->field4, __isset.field4};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> field4_ref() const&& {
    return {std::move(this->field4), __isset.field4};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> field4_ref() & {
    return {this->field4, __isset.field4};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> field4_ref() && {
    return {std::move(this->field4), __isset.field4};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::cpp2::Mixin2>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> m2_ref() const& {
    return {this->m2, __isset.m2};
  }

  template <typename..., typename T = ::cpp2::Mixin2>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> m2_ref() const&& {
    return {std::move(this->m2), __isset.m2};
  }

  template <typename..., typename T = ::cpp2::Mixin2>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> m2_ref() & {
    return {this->m2, __isset.m2};
  }

  template <typename..., typename T = ::cpp2::Mixin2>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> m2_ref() && {
    return {std::move(this->m2), __isset.m2};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::cpp2::Mixin3>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> m3_ref() const& {
    return {this->m3, __isset.m3};
  }

  template <typename..., typename T = ::cpp2::Mixin3>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> m3_ref() const&& {
    return {std::move(this->m3), __isset.m3};
  }

  template <typename..., typename T = ::cpp2::Mixin3>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> m3_ref() & {
    return {this->m3, __isset.m3};
  }

  template <typename..., typename T = ::cpp2::Mixin3>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> m3_ref() && {
    return {std::move(this->m3), __isset.m3};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END
  FOLLY_ERASE auto m1_ref() &       { return m2.m1_ref();            }
  FOLLY_ERASE auto m1_ref() const&  { return m2.m1_ref();            }
  FOLLY_ERASE auto m1_ref() &&      { return std::move(m2).m1_ref(); }
  FOLLY_ERASE auto m1_ref() const&& { return std::move(m2).m1_ref(); }
  FOLLY_ERASE auto field2_ref() &       { return m2.field2_ref();            }
  FOLLY_ERASE auto field2_ref() const&  { return m2.field2_ref();            }
  FOLLY_ERASE auto field2_ref() &&      { return std::move(m2).field2_ref(); }
  FOLLY_ERASE auto field2_ref() const&& { return std::move(m2).field2_ref(); }
  FOLLY_ERASE auto field1_ref() &       { return m2.field1_ref();            }
  FOLLY_ERASE auto field1_ref() const&  { return m2.field1_ref();            }
  FOLLY_ERASE auto field1_ref() &&      { return std::move(m2).field1_ref(); }
  FOLLY_ERASE auto field1_ref() const&& { return std::move(m2).field1_ref(); }
  FOLLY_ERASE auto field3_ref() &       { return m3.field3_ref();            }
  FOLLY_ERASE auto field3_ref() const&  { return m3.field3_ref();            }
  FOLLY_ERASE auto field3_ref() &&      { return std::move(m3).field3_ref(); }
  FOLLY_ERASE auto field3_ref() const&& { return std::move(m3).field3_ref(); }

  const ::std::string& get_field4() const& {
    return field4;
  }

  ::std::string get_field4() && {
    return std::move(field4);
  }

  template <typename T_Foo_field4_struct_setter = ::std::string>
  ::std::string& set_field4(T_Foo_field4_struct_setter&& field4_) {
    field4 = std::forward<T_Foo_field4_struct_setter>(field4_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.field4 = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return field4;
  }
  const ::cpp2::Mixin2& get_m2() const&;
  ::cpp2::Mixin2 get_m2() &&;

  template <typename T_Foo_m2_struct_setter = ::cpp2::Mixin2>
  ::cpp2::Mixin2& set_m2(T_Foo_m2_struct_setter&& m2_) {
    m2 = std::forward<T_Foo_m2_struct_setter>(m2_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.m2 = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return m2;
  }
  const ::cpp2::Mixin3& get_m3() const&;
  ::cpp2::Mixin3 get_m3() &&;

  template <typename T_Foo_m3_struct_setter = ::cpp2::Mixin3>
  ::cpp2::Mixin3& set_m3(T_Foo_m3_struct_setter&& m3_) {
    m3 = std::forward<T_Foo_m3_struct_setter>(m3_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.m3 = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return m3;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< Foo >;
  friend void swap(Foo& a, Foo& b);
};

template <class Protocol_>
uint32_t Foo::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
