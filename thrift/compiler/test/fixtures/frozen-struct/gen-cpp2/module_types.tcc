/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/compiler/test/fixtures/frozen-struct/gen-cpp2/module_types.h"

#include <thrift/lib/cpp2/gen/module_types_tcc.h>

namespace some { namespace ns {

}} // some::ns
namespace std {

} // std


namespace apache {
namespace thrift {
namespace detail {

template <>
struct TccStructTraits<::some::ns::ModuleA> {
  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype) noexcept;
};
template <>
struct TccStructTraits<::some::ns::ModuleB> {
  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype) noexcept;
};

} // namespace detail
} // namespace thrift
} // namespace apache

namespace some { namespace ns {

template <class Protocol_>
void ModuleA::readNoXfer(Protocol_* iprot) {
  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;


  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          1,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_i32Field:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, ::std::int32_t>::readWithContext(*iprot, this->i32Field, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.i32Field = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          1,
          2,
          apache::thrift::protocol::T_STRING))) {
    goto _loop;
  }
_readField_strField:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::readWithContext(*iprot, this->strField, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.strField = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          2,
          3,
          apache::thrift::protocol::T_LIST))) {
    goto _loop;
  }
_readField_listField:
  {
    _readState.beforeSubobject(iprot);
    this->listField = ::std::vector<::std::int16_t>();
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::list<::apache::thrift::type_class::integral>, ::std::vector<::std::int16_t>>::readWithContext(*iprot, this->listField, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.listField = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          3,
          4,
          apache::thrift::protocol::T_MAP))) {
    goto _loop;
  }
_readField_mapField:
  {
    _readState.beforeSubobject(iprot);
    this->mapField = ::std::map<::std::string, ::std::int32_t>();
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, ::std::map<::std::string, ::std::int32_t>>::readWithContext(*iprot, this->mapField, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.mapField = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          4,
          5,
          apache::thrift::protocol::T_STRUCT))) {
    goto _loop;
  }
_readField_inclAField:
  {
    _readState.beforeSubobject(iprot);
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::structure, ::some::ns::IncludedA>::readWithContext(*iprot, this->inclAField, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.inclAField = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          5,
          6,
          apache::thrift::protocol::T_STRUCT))) {
    goto _loop;
  }
_readField_inclBField:
  {
    _readState.beforeSubobject(iprot);
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::structure, ::some::ns::IncludedB>::readWithContext(*iprot, this->inclBField, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.inclBField = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          6,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _loop;
  }

_end:
  _readState.readStructEnd(iprot);

  return;

_loop:
  _readState.afterAdvanceFailure(iprot);
  if (_readState.atStop()) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<ModuleA>>();
  }

  switch (_readState.fieldId) {
    case 1:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I32))) {
        goto _readField_i32Field;
      } else {
        goto _skip;
      }
    }
    case 2:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRING))) {
        goto _readField_strField;
      } else {
        goto _skip;
      }
    }
    case 3:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_LIST))) {
        goto _readField_listField;
      } else {
        goto _skip;
      }
    }
    case 4:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_MAP))) {
        goto _readField_mapField;
      } else {
        goto _skip;
      }
    }
    case 5:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRUCT))) {
        goto _readField_inclAField;
      } else {
        goto _skip;
      }
    }
    case 6:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRUCT))) {
        goto _readField_inclBField;
      } else {
        goto _skip;
      }
    }
    default:
    {
_skip:
      _readState.skip(iprot);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t ModuleA::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("ModuleA");
  xfer += prot_->serializedFieldSize("i32Field", apache::thrift::protocol::T_I32, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, this->i32Field);
  xfer += prot_->serializedFieldSize("strField", apache::thrift::protocol::T_STRING, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::serializedSize<false>(*prot_, this->strField);
  xfer += prot_->serializedFieldSize("listField", apache::thrift::protocol::T_LIST, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::list<::apache::thrift::type_class::integral>, ::std::vector<::std::int16_t>>::serializedSize<false>(*prot_, this->listField);
  xfer += prot_->serializedFieldSize("mapField", apache::thrift::protocol::T_MAP, 4);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, ::std::map<::std::string, ::std::int32_t>>::serializedSize<false>(*prot_, this->mapField);
  xfer += prot_->serializedFieldSize("inclAField", apache::thrift::protocol::T_STRUCT, 5);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::structure, ::some::ns::IncludedA>::serializedSize<false>(*prot_, this->inclAField);
  xfer += prot_->serializedFieldSize("inclBField", apache::thrift::protocol::T_STRUCT, 6);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::structure, ::some::ns::IncludedB>::serializedSize<false>(*prot_, this->inclBField);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t ModuleA::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("ModuleA");
  xfer += prot_->serializedFieldSize("i32Field", apache::thrift::protocol::T_I32, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, this->i32Field);
  xfer += prot_->serializedFieldSize("strField", apache::thrift::protocol::T_STRING, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::serializedSize<false>(*prot_, this->strField);
  xfer += prot_->serializedFieldSize("listField", apache::thrift::protocol::T_LIST, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::list<::apache::thrift::type_class::integral>, ::std::vector<::std::int16_t>>::serializedSize<false>(*prot_, this->listField);
  xfer += prot_->serializedFieldSize("mapField", apache::thrift::protocol::T_MAP, 4);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, ::std::map<::std::string, ::std::int32_t>>::serializedSize<false>(*prot_, this->mapField);
  xfer += prot_->serializedFieldSize("inclAField", apache::thrift::protocol::T_STRUCT, 5);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::structure, ::some::ns::IncludedA>::serializedSize<true>(*prot_, this->inclAField);
  xfer += prot_->serializedFieldSize("inclBField", apache::thrift::protocol::T_STRUCT, 6);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::structure, ::some::ns::IncludedB>::serializedSize<true>(*prot_, this->inclBField);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t ModuleA::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("ModuleA");
  xfer += prot_->writeFieldBegin("i32Field", apache::thrift::protocol::T_I32, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, ::std::int32_t>::write(*prot_, this->i32Field);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("strField", apache::thrift::protocol::T_STRING, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::write(*prot_, this->strField);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("listField", apache::thrift::protocol::T_LIST, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::list<::apache::thrift::type_class::integral>, ::std::vector<::std::int16_t>>::write(*prot_, this->listField);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("mapField", apache::thrift::protocol::T_MAP, 4);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, ::std::map<::std::string, ::std::int32_t>>::write(*prot_, this->mapField);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("inclAField", apache::thrift::protocol::T_STRUCT, 5);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::structure, ::some::ns::IncludedA>::write(*prot_, this->inclAField);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("inclBField", apache::thrift::protocol::T_STRUCT, 6);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::structure, ::some::ns::IncludedB>::write(*prot_, this->inclBField);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void ModuleA::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t ModuleA::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t ModuleA::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t ModuleA::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void ModuleA::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t ModuleA::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t ModuleA::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t ModuleA::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}} // some::ns
namespace some { namespace ns {

template <class Protocol_>
void ModuleB::readNoXfer(Protocol_* iprot) {
  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;


  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          1,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_i32Field:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, ::std::int32_t>::readWithContext(*iprot, this->i32Field, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.i32Field = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          1,
          2,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_inclEnumB:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration, ::some::ns::EnumB>::readWithContext(*iprot, this->inclEnumB, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.inclEnumB = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          2,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _loop;
  }

_end:
  _readState.readStructEnd(iprot);

  return;

_loop:
  _readState.afterAdvanceFailure(iprot);
  if (_readState.atStop()) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<ModuleB>>();
  }

  switch (_readState.fieldId) {
    case 1:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I32))) {
        goto _readField_i32Field;
      } else {
        goto _skip;
      }
    }
    case 2:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I32))) {
        goto _readField_inclEnumB;
      } else {
        goto _skip;
      }
    }
    default:
    {
_skip:
      _readState.skip(iprot);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t ModuleB::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("ModuleB");
  xfer += prot_->serializedFieldSize("i32Field", apache::thrift::protocol::T_I32, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, this->i32Field);
  xfer += prot_->serializedFieldSize("inclEnumB", apache::thrift::protocol::T_I32, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration, ::some::ns::EnumB>::serializedSize<false>(*prot_, this->inclEnumB);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t ModuleB::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("ModuleB");
  xfer += prot_->serializedFieldSize("i32Field", apache::thrift::protocol::T_I32, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, this->i32Field);
  xfer += prot_->serializedFieldSize("inclEnumB", apache::thrift::protocol::T_I32, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration, ::some::ns::EnumB>::serializedSize<false>(*prot_, this->inclEnumB);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t ModuleB::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("ModuleB");
  xfer += prot_->writeFieldBegin("i32Field", apache::thrift::protocol::T_I32, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, ::std::int32_t>::write(*prot_, this->i32Field);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("inclEnumB", apache::thrift::protocol::T_I32, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration, ::some::ns::EnumB>::write(*prot_, this->inclEnumB);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void ModuleB::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t ModuleB::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t ModuleB::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t ModuleB::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void ModuleB::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t ModuleB::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t ModuleB::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t ModuleB::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}} // some::ns
