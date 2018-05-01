/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "src/gen-cpp2/module_types.h"
#include "src/gen-cpp2/module_types.tcc"

#include <algorithm>
#include <folly/Indestructible.h>

#include "src/gen-cpp2/module_data.h"

namespace cpp2 {

const _MyEnum_EnumMapFactory::ValuesToNamesMapType _MyEnum_VALUES_TO_NAMES = _MyEnum_EnumMapFactory::makeValuesToNamesMap();
const _MyEnum_EnumMapFactory::NamesToValuesMapType _MyEnum_NAMES_TO_VALUES = _MyEnum_EnumMapFactory::makeNamesToValuesMap();

} // cpp2
namespace std {

} // std
namespace apache { namespace thrift {

template <> const std::size_t TEnumTraits< ::cpp2::MyEnum>::size = 2;
template <> const folly::Range<const  ::cpp2::MyEnum*> TEnumTraits< ::cpp2::MyEnum>::values = folly::range( ::cpp2::_MyEnumEnumDataStorage::values);
template <> const folly::Range<const folly::StringPiece*> TEnumTraits< ::cpp2::MyEnum>::names = folly::range( ::cpp2::_MyEnumEnumDataStorage::names);
template <> const char* TEnumTraits< ::cpp2::MyEnum>::findName( ::cpp2::MyEnum value) {
  static auto const map = folly::Indestructible< ::cpp2::_MyEnum_EnumMapFactory::ValuesToNamesMapType>{ ::cpp2::_MyEnum_EnumMapFactory::makeValuesToNamesMap()};
  return findName(*map, value);
}

template <> bool TEnumTraits< ::cpp2::MyEnum>::findValue(const char* name,  ::cpp2::MyEnum* outValue) {
  static auto const map = folly::Indestructible< ::cpp2::_MyEnum_EnumMapFactory::NamesToValuesMapType>{ ::cpp2::_MyEnum_EnumMapFactory::makeNamesToValuesMap()};
  return findValue(*map, name, outValue);
}

}} // apache::thrift
namespace cpp2 {

MyStruct::MyStruct(apache::thrift::FragileConstructor, int64_t MyIntField__arg, std::string MyStringField__arg) :
    MyIntField(std::move(MyIntField__arg)),
    MyStringField(std::move(MyStringField__arg)) {
  __isset.MyIntField = true;
  __isset.MyStringField = true;
}

void MyStruct::__clear() {
  // clear all fields
  MyIntField = 0;
  MyStringField = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
  __isset = {};
}

bool MyStruct::operator==(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  if (!(lhs.MyIntField == rhs.MyIntField)) {
    return false;
  }
  if (!(lhs.MyStringField == rhs.MyStringField)) {
    return false;
  }
  return true;
}

bool MyStruct::operator<(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  if (!(lhs.MyIntField == rhs.MyIntField)) {
    return lhs.MyIntField < rhs.MyIntField;
  }
  if (!(lhs.MyStringField == rhs.MyStringField)) {
    return lhs.MyStringField < rhs.MyStringField;
  }
  return false;
}

void MyStruct::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "MyIntField") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_I64;
  }
  else if (_fname == "MyStringField") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

void swap(MyStruct& a, MyStruct& b) {
  using ::std::swap;
  swap(a.MyIntField, b.MyIntField);
  swap(a.MyStringField, b.MyStringField);
  swap(a.__isset, b.__isset);
}

template void MyStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
