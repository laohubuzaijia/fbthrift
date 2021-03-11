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
struct myEnum;
struct myBigEnum;
} // namespace tag
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_myEnum
#define APACHE_THRIFT_ACCESSOR_myEnum
APACHE_THRIFT_DEFINE_ACCESSOR(myEnum);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_myBigEnum
#define APACHE_THRIFT_ACCESSOR_myBigEnum
APACHE_THRIFT_DEFINE_ACCESSOR(myBigEnum);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums
namespace test { namespace fixtures { namespace enumstrict {

enum class EmptyEnum {
};




enum class MyEnum {
  ONE = 1,
  TWO = 2,
};




enum class MyBigEnum {
  UNKNOWN = 0,
  ONE = 1,
  TWO = 2,
  THREE = 3,
  FOUR = 4,
  FIVE = 5,
  SIX = 6,
  SEVEN = 7,
  EIGHT = 8,
  NINE = 9,
  TEN = 10,
  ELEVEN = 11,
  TWELVE = 12,
  THIRTEEN = 13,
  FOURTEEN = 14,
  FIFTEEN = 15,
  SIXTEEN = 16,
  SEVENTEEN = 17,
  EIGHTEEN = 18,
  NINETEEN = 19,
};




}}} // test::fixtures::enumstrict
namespace std {


template<> struct hash<typename ::test::fixtures::enumstrict::EmptyEnum> : public apache::thrift::detail::enum_hash<typename ::test::fixtures::enumstrict::EmptyEnum> {};
template<> struct equal_to<typename ::test::fixtures::enumstrict::EmptyEnum> : public apache::thrift::detail::enum_equal_to<typename ::test::fixtures::enumstrict::EmptyEnum> {};


template<> struct hash<typename ::test::fixtures::enumstrict::MyEnum> : public apache::thrift::detail::enum_hash<typename ::test::fixtures::enumstrict::MyEnum> {};
template<> struct equal_to<typename ::test::fixtures::enumstrict::MyEnum> : public apache::thrift::detail::enum_equal_to<typename ::test::fixtures::enumstrict::MyEnum> {};


template<> struct hash<typename ::test::fixtures::enumstrict::MyBigEnum> : public apache::thrift::detail::enum_hash<typename ::test::fixtures::enumstrict::MyBigEnum> {};
template<> struct equal_to<typename ::test::fixtures::enumstrict::MyBigEnum> : public apache::thrift::detail::enum_equal_to<typename ::test::fixtures::enumstrict::MyBigEnum> {};


} // std

namespace apache { namespace thrift {


template <> struct TEnumDataStorage<::test::fixtures::enumstrict::EmptyEnum>;

template <> struct TEnumTraits<::test::fixtures::enumstrict::EmptyEnum> {
  using type = ::test::fixtures::enumstrict::EmptyEnum;

  static constexpr std::size_t const size = 0;
  static folly::Range<type const*> const values;
  static folly::Range<folly::StringPiece const*> const names;

  static char const* findName(type value);
  static bool findValue(char const* name, type* out);

};


template <> struct TEnumDataStorage<::test::fixtures::enumstrict::MyEnum>;

template <> struct TEnumTraits<::test::fixtures::enumstrict::MyEnum> {
  using type = ::test::fixtures::enumstrict::MyEnum;

  static constexpr std::size_t const size = 2;
  static folly::Range<type const*> const values;
  static folly::Range<folly::StringPiece const*> const names;

  static char const* findName(type value);
  static bool findValue(char const* name, type* out);

  static constexpr type min() { return type::ONE; }
  static constexpr type max() { return type::TWO; }
};


template <> struct TEnumDataStorage<::test::fixtures::enumstrict::MyBigEnum>;

template <> struct TEnumTraits<::test::fixtures::enumstrict::MyBigEnum> {
  using type = ::test::fixtures::enumstrict::MyBigEnum;

  static constexpr std::size_t const size = 20;
  static folly::Range<type const*> const values;
  static folly::Range<folly::StringPiece const*> const names;

  static char const* findName(type value);
  static bool findValue(char const* name, type* out);

  static constexpr type min() { return type::UNKNOWN; }
  static constexpr type max() { return type::NINETEEN; }
};


}} // apache::thrift

namespace test { namespace fixtures { namespace enumstrict {

using _EmptyEnum_EnumMapFactory = apache::thrift::detail::TEnumMapFactory<EmptyEnum>;
[[deprecated("use apache::thrift::util::enumNameSafe, apache::thrift::util::enumName, or apache::thrift::TEnumTraits")]]
extern const _EmptyEnum_EnumMapFactory::ValuesToNamesMapType _EmptyEnum_VALUES_TO_NAMES;
[[deprecated("use apache::thrift::TEnumTraits")]]
extern const _EmptyEnum_EnumMapFactory::NamesToValuesMapType _EmptyEnum_NAMES_TO_VALUES;

using _MyEnum_EnumMapFactory = apache::thrift::detail::TEnumMapFactory<MyEnum>;
[[deprecated("use apache::thrift::util::enumNameSafe, apache::thrift::util::enumName, or apache::thrift::TEnumTraits")]]
extern const _MyEnum_EnumMapFactory::ValuesToNamesMapType _MyEnum_VALUES_TO_NAMES;
[[deprecated("use apache::thrift::TEnumTraits")]]
extern const _MyEnum_EnumMapFactory::NamesToValuesMapType _MyEnum_NAMES_TO_VALUES;

using _MyBigEnum_EnumMapFactory = apache::thrift::detail::TEnumMapFactory<MyBigEnum>;
[[deprecated("use apache::thrift::util::enumNameSafe, apache::thrift::util::enumName, or apache::thrift::TEnumTraits")]]
extern const _MyBigEnum_EnumMapFactory::ValuesToNamesMapType _MyBigEnum_VALUES_TO_NAMES;
[[deprecated("use apache::thrift::TEnumTraits")]]
extern const _MyBigEnum_EnumMapFactory::NamesToValuesMapType _MyBigEnum_NAMES_TO_VALUES;

}}} // test::fixtures::enumstrict

// END declare_enums
// BEGIN forward_declare
namespace test { namespace fixtures { namespace enumstrict {
class MyStruct;
}}} // test::fixtures::enumstrict
// END forward_declare
// BEGIN typedefs

// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace test { namespace fixtures { namespace enumstrict {
class MyStruct final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = MyStruct;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  MyStruct() :
      myEnum(static_cast< ::test::fixtures::enumstrict::MyEnum>(0)),
      myBigEnum( ::test::fixtures::enumstrict::MyBigEnum::ONE) {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  MyStruct(apache::thrift::FragileConstructor, ::test::fixtures::enumstrict::MyEnum myEnum__arg, ::test::fixtures::enumstrict::MyBigEnum myBigEnum__arg);

  MyStruct(MyStruct&&) = default;

  MyStruct(const MyStruct&) = default;


  MyStruct& operator=(MyStruct&&) = default;

  MyStruct& operator=(const MyStruct&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::test::fixtures::enumstrict::MyEnum myEnum;
 private:
  ::test::fixtures::enumstrict::MyBigEnum myBigEnum;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool myEnum;
    bool myBigEnum;
  } __isset = {};
  bool operator==(const MyStruct& rhs) const;
#ifndef SWIG
  friend bool operator!=(const MyStruct& __x, const MyStruct& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const MyStruct& rhs) const;
#ifndef SWIG
  friend bool operator>(const MyStruct& __x, const MyStruct& __y) {
    return __y < __x;
  }
  friend bool operator<=(const MyStruct& __x, const MyStruct& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const MyStruct& __x, const MyStruct& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::test::fixtures::enumstrict::MyEnum>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> myEnum_ref() const& {
    return {this->myEnum, __isset.myEnum};
  }

  template <typename..., typename T = ::test::fixtures::enumstrict::MyEnum>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> myEnum_ref() const&& {
    return {std::move(this->myEnum), __isset.myEnum};
  }

  template <typename..., typename T = ::test::fixtures::enumstrict::MyEnum>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> myEnum_ref() & {
    return {this->myEnum, __isset.myEnum};
  }

  template <typename..., typename T = ::test::fixtures::enumstrict::MyEnum>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> myEnum_ref() && {
    return {std::move(this->myEnum), __isset.myEnum};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::test::fixtures::enumstrict::MyBigEnum>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> myBigEnum_ref() const& {
    return {this->myBigEnum, __isset.myBigEnum};
  }

  template <typename..., typename T = ::test::fixtures::enumstrict::MyBigEnum>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> myBigEnum_ref() const&& {
    return {std::move(this->myBigEnum), __isset.myBigEnum};
  }

  template <typename..., typename T = ::test::fixtures::enumstrict::MyBigEnum>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> myBigEnum_ref() & {
    return {this->myBigEnum, __isset.myBigEnum};
  }

  template <typename..., typename T = ::test::fixtures::enumstrict::MyBigEnum>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> myBigEnum_ref() && {
    return {std::move(this->myBigEnum), __isset.myBigEnum};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  ::test::fixtures::enumstrict::MyEnum get_myEnum() const {
    return myEnum;
  }

  ::test::fixtures::enumstrict::MyEnum& set_myEnum(::test::fixtures::enumstrict::MyEnum myEnum_) {
    myEnum = myEnum_;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.myEnum = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return myEnum;
  }

  ::test::fixtures::enumstrict::MyBigEnum get_myBigEnum() const {
    return myBigEnum;
  }

  ::test::fixtures::enumstrict::MyBigEnum& set_myBigEnum(::test::fixtures::enumstrict::MyBigEnum myBigEnum_) {
    myBigEnum = myBigEnum_;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.myBigEnum = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return myBigEnum;
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

  friend class ::apache::thrift::Cpp2Ops< MyStruct >;
  friend void swap(MyStruct& a, MyStruct& b);
};

template <class Protocol_>
uint32_t MyStruct::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

}}} // test::fixtures::enumstrict
