/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "src/gen-cpp2/enums_types.h"
#include "src/gen-cpp2/enums_types.tcc"

#include <algorithm>
#include <folly/Indestructible.h>

#include "src/gen-cpp2/enums_data.h"

namespace facebook { namespace ns { namespace qwerty {

const _AnEnumA_EnumMapFactory::ValuesToNamesMapType _AnEnumA_VALUES_TO_NAMES = _AnEnumA_EnumMapFactory::makeValuesToNamesMap();
const _AnEnumA_EnumMapFactory::NamesToValuesMapType _AnEnumA_NAMES_TO_VALUES = _AnEnumA_EnumMapFactory::makeNamesToValuesMap();

}}} // facebook::ns::qwerty
namespace std {

} // std
namespace apache { namespace thrift {

template <> const std::size_t TEnumTraits< ::facebook::ns::qwerty::AnEnumA>::size = 1;
template <> const folly::Range<const  ::facebook::ns::qwerty::AnEnumA*> TEnumTraits< ::facebook::ns::qwerty::AnEnumA>::values = folly::range( ::facebook::ns::qwerty::_AnEnumAEnumDataStorage::values);
template <> const folly::Range<const folly::StringPiece*> TEnumTraits< ::facebook::ns::qwerty::AnEnumA>::names = folly::range( ::facebook::ns::qwerty::_AnEnumAEnumDataStorage::names);
template <> const char* TEnumTraits< ::facebook::ns::qwerty::AnEnumA>::findName( ::facebook::ns::qwerty::AnEnumA value) {
  static auto const map = folly::Indestructible< ::facebook::ns::qwerty::_AnEnumA_EnumMapFactory::ValuesToNamesMapType>{ ::facebook::ns::qwerty::_AnEnumA_EnumMapFactory::makeValuesToNamesMap()};
  return findName(*map, value);
}

template <> bool TEnumTraits< ::facebook::ns::qwerty::AnEnumA>::findValue(const char* name,  ::facebook::ns::qwerty::AnEnumA* outValue) {
  static auto const map = folly::Indestructible< ::facebook::ns::qwerty::_AnEnumA_EnumMapFactory::NamesToValuesMapType>{ ::facebook::ns::qwerty::_AnEnumA_EnumMapFactory::makeNamesToValuesMap()};
  return findValue(*map, name, outValue);
}

}} // apache::thrift
namespace facebook { namespace ns { namespace qwerty {

const _AnEnumB_EnumMapFactory::ValuesToNamesMapType _AnEnumB_VALUES_TO_NAMES = _AnEnumB_EnumMapFactory::makeValuesToNamesMap();
const _AnEnumB_EnumMapFactory::NamesToValuesMapType _AnEnumB_NAMES_TO_VALUES = _AnEnumB_EnumMapFactory::makeNamesToValuesMap();

}}} // facebook::ns::qwerty
namespace std {

} // std
namespace apache { namespace thrift {

template <> const std::size_t TEnumTraits< ::facebook::ns::qwerty::AnEnumB>::size = 2;
template <> const folly::Range<const  ::facebook::ns::qwerty::AnEnumB*> TEnumTraits< ::facebook::ns::qwerty::AnEnumB>::values = folly::range( ::facebook::ns::qwerty::_AnEnumBEnumDataStorage::values);
template <> const folly::Range<const folly::StringPiece*> TEnumTraits< ::facebook::ns::qwerty::AnEnumB>::names = folly::range( ::facebook::ns::qwerty::_AnEnumBEnumDataStorage::names);
template <> const char* TEnumTraits< ::facebook::ns::qwerty::AnEnumB>::findName( ::facebook::ns::qwerty::AnEnumB value) {
  static auto const map = folly::Indestructible< ::facebook::ns::qwerty::_AnEnumB_EnumMapFactory::ValuesToNamesMapType>{ ::facebook::ns::qwerty::_AnEnumB_EnumMapFactory::makeValuesToNamesMap()};
  return findName(*map, value);
}

template <> bool TEnumTraits< ::facebook::ns::qwerty::AnEnumB>::findValue(const char* name,  ::facebook::ns::qwerty::AnEnumB* outValue) {
  static auto const map = folly::Indestructible< ::facebook::ns::qwerty::_AnEnumB_EnumMapFactory::NamesToValuesMapType>{ ::facebook::ns::qwerty::_AnEnumB_EnumMapFactory::makeNamesToValuesMap()};
  return findValue(*map, name, outValue);
}

}} // apache::thrift
namespace facebook { namespace ns { namespace qwerty {

const _AnEnumC_EnumMapFactory::ValuesToNamesMapType _AnEnumC_VALUES_TO_NAMES = _AnEnumC_EnumMapFactory::makeValuesToNamesMap();
const _AnEnumC_EnumMapFactory::NamesToValuesMapType _AnEnumC_NAMES_TO_VALUES = _AnEnumC_EnumMapFactory::makeNamesToValuesMap();

}}} // facebook::ns::qwerty
namespace std {

} // std
namespace apache { namespace thrift {

template <> const std::size_t TEnumTraits< ::facebook::ns::qwerty::AnEnumC>::size = 1;
template <> const folly::Range<const  ::facebook::ns::qwerty::AnEnumC*> TEnumTraits< ::facebook::ns::qwerty::AnEnumC>::values = folly::range( ::facebook::ns::qwerty::_AnEnumCEnumDataStorage::values);
template <> const folly::Range<const folly::StringPiece*> TEnumTraits< ::facebook::ns::qwerty::AnEnumC>::names = folly::range( ::facebook::ns::qwerty::_AnEnumCEnumDataStorage::names);
template <> const char* TEnumTraits< ::facebook::ns::qwerty::AnEnumC>::findName( ::facebook::ns::qwerty::AnEnumC value) {
  static auto const map = folly::Indestructible< ::facebook::ns::qwerty::_AnEnumC_EnumMapFactory::ValuesToNamesMapType>{ ::facebook::ns::qwerty::_AnEnumC_EnumMapFactory::makeValuesToNamesMap()};
  return findName(*map, value);
}

template <> bool TEnumTraits< ::facebook::ns::qwerty::AnEnumC>::findValue(const char* name,  ::facebook::ns::qwerty::AnEnumC* outValue) {
  static auto const map = folly::Indestructible< ::facebook::ns::qwerty::_AnEnumC_EnumMapFactory::NamesToValuesMapType>{ ::facebook::ns::qwerty::_AnEnumC_EnumMapFactory::makeNamesToValuesMap()};
  return findValue(*map, name, outValue);
}

}} // apache::thrift
namespace facebook { namespace ns { namespace qwerty {

const _AnEnumD_EnumMapFactory::ValuesToNamesMapType _AnEnumD_VALUES_TO_NAMES = _AnEnumD_EnumMapFactory::makeValuesToNamesMap();
const _AnEnumD_EnumMapFactory::NamesToValuesMapType _AnEnumD_NAMES_TO_VALUES = _AnEnumD_EnumMapFactory::makeNamesToValuesMap();

}}} // facebook::ns::qwerty
namespace std {

} // std
namespace apache { namespace thrift {

template <> const std::size_t TEnumTraits< ::facebook::ns::qwerty::AnEnumD>::size = 1;
template <> const folly::Range<const  ::facebook::ns::qwerty::AnEnumD*> TEnumTraits< ::facebook::ns::qwerty::AnEnumD>::values = folly::range( ::facebook::ns::qwerty::_AnEnumDEnumDataStorage::values);
template <> const folly::Range<const folly::StringPiece*> TEnumTraits< ::facebook::ns::qwerty::AnEnumD>::names = folly::range( ::facebook::ns::qwerty::_AnEnumDEnumDataStorage::names);
template <> const char* TEnumTraits< ::facebook::ns::qwerty::AnEnumD>::findName( ::facebook::ns::qwerty::AnEnumD value) {
  static auto const map = folly::Indestructible< ::facebook::ns::qwerty::_AnEnumD_EnumMapFactory::ValuesToNamesMapType>{ ::facebook::ns::qwerty::_AnEnumD_EnumMapFactory::makeValuesToNamesMap()};
  return findName(*map, value);
}

template <> bool TEnumTraits< ::facebook::ns::qwerty::AnEnumD>::findValue(const char* name,  ::facebook::ns::qwerty::AnEnumD* outValue) {
  static auto const map = folly::Indestructible< ::facebook::ns::qwerty::_AnEnumD_EnumMapFactory::NamesToValuesMapType>{ ::facebook::ns::qwerty::_AnEnumD_EnumMapFactory::makeNamesToValuesMap()};
  return findValue(*map, name, outValue);
}

}} // apache::thrift
namespace facebook { namespace ns { namespace qwerty {

const _AnEnumE_EnumMapFactory::ValuesToNamesMapType _AnEnumE_VALUES_TO_NAMES = _AnEnumE_EnumMapFactory::makeValuesToNamesMap();
const _AnEnumE_EnumMapFactory::NamesToValuesMapType _AnEnumE_NAMES_TO_VALUES = _AnEnumE_EnumMapFactory::makeNamesToValuesMap();

}}} // facebook::ns::qwerty
namespace std {

} // std
namespace apache { namespace thrift {

template <> const std::size_t TEnumTraits< ::facebook::ns::qwerty::AnEnumE>::size = 1;
template <> const folly::Range<const  ::facebook::ns::qwerty::AnEnumE*> TEnumTraits< ::facebook::ns::qwerty::AnEnumE>::values = folly::range( ::facebook::ns::qwerty::_AnEnumEEnumDataStorage::values);
template <> const folly::Range<const folly::StringPiece*> TEnumTraits< ::facebook::ns::qwerty::AnEnumE>::names = folly::range( ::facebook::ns::qwerty::_AnEnumEEnumDataStorage::names);
template <> const char* TEnumTraits< ::facebook::ns::qwerty::AnEnumE>::findName( ::facebook::ns::qwerty::AnEnumE value) {
  static auto const map = folly::Indestructible< ::facebook::ns::qwerty::_AnEnumE_EnumMapFactory::ValuesToNamesMapType>{ ::facebook::ns::qwerty::_AnEnumE_EnumMapFactory::makeValuesToNamesMap()};
  return findName(*map, value);
}

template <> bool TEnumTraits< ::facebook::ns::qwerty::AnEnumE>::findValue(const char* name,  ::facebook::ns::qwerty::AnEnumE* outValue) {
  static auto const map = folly::Indestructible< ::facebook::ns::qwerty::_AnEnumE_EnumMapFactory::NamesToValuesMapType>{ ::facebook::ns::qwerty::_AnEnumE_EnumMapFactory::makeNamesToValuesMap()};
  return findValue(*map, name, outValue);
}

}} // apache::thrift
namespace facebook { namespace ns { namespace qwerty {

SomeStruct::SomeStruct(apache::thrift::FragileConstructor, int32_t fieldA__arg) :
    fieldA(std::move(fieldA__arg)) {
  __isset.fieldA = true;
}

void SomeStruct::__clear() {
  // clear all fields
  fieldA = 0;
  __isset = {};
}

bool SomeStruct::operator==(const SomeStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  if (!(lhs.fieldA == rhs.fieldA)) {
    return false;
  }
  return true;
}

bool SomeStruct::operator<(const SomeStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  if (!(lhs.fieldA == rhs.fieldA)) {
    return lhs.fieldA < rhs.fieldA;
  }
  return false;
}

void SomeStruct::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "fieldA") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_I32;
  }
}

void swap(SomeStruct& a, SomeStruct& b) {
  using ::std::swap;
  swap(a.fieldA, b.fieldA);
  swap(a.__isset, b.__isset);
}

template void SomeStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t SomeStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t SomeStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SomeStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void SomeStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t SomeStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t SomeStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t SomeStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;
template void SomeStruct::readNoXfer<>(apache::thrift::SimpleJSONProtocolReader*);
template uint32_t SomeStruct::write<>(apache::thrift::SimpleJSONProtocolWriter*) const;
template uint32_t SomeStruct::serializedSize<>(apache::thrift::SimpleJSONProtocolWriter const*) const;
template uint32_t SomeStruct::serializedSizeZC<>(apache::thrift::SimpleJSONProtocolWriter const*) const;

}}} // facebook::ns::qwerty
