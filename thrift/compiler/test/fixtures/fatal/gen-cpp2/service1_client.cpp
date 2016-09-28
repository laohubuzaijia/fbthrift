/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/fatal/gen-cpp2/service1.h"

#include "thrift/compiler/test/fixtures/fatal/gen-cpp2/service1.tcc"

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
namespace test_cpp2 { namespace cpp_reflection {

const char* service1AsyncClient::getServiceName() {
  return "service1";
}

void service1AsyncClient::method1(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  method1(rpcOptions, std::move(callback));
}

void service1AsyncClient::method1(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      method1T(&writer, rpcOptions, std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      method1T(&writer, rpcOptions, std::move(callback));
      break;
    }
    default:
    {
      throw apache::thrift::TApplicationException("Could not find Protocol");
    }
  }
}

void service1AsyncClient::sync_method1() {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_method1(rpcOptions);
}

void service1AsyncClient::sync_method1(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = folly::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, getChannel()->getEventBase(), false);
  method1(rpcOptions, std::move(callback));
  getChannel()->getEventBase()->loopForever();
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    std::rethrow_exception(_returnState.exception());
  }
  recv_method1(_returnState);
}

folly::Future<folly::Unit> service1AsyncClient::future_method1() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_method1(rpcOptions);
}

folly::Future<folly::Unit> service1AsyncClient::future_method1(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_method1, channel_);
  method1(rpcOptions, std::move(callback));
  return _future;
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> service1AsyncClient::header_future_method1(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_method1, channel_);
  method1(rpcOptions, std::move(callback));
  return _future;
}

void service1AsyncClient::method1(std::function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  method1(folly::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

folly::exception_wrapper service1AsyncClient::recv_wrapped_method1(::apache::thrift::ClientReceiveState& state) {
  auto ew = state.exceptionWrapper();
  if (ew) {
    return ew;
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_method1T(&reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_method1T(&reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void service1AsyncClient::recv_method1(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_method1(state);
  if (ew) {
    ew.throwException();
  }
}

void service1AsyncClient::recv_instance_method1(::apache::thrift::ClientReceiveState& state) {
  recv_method1(state);
}

folly::exception_wrapper service1AsyncClient::recv_instance_wrapped_method1(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_method1(state);
}

void service1AsyncClient::method2(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t x, const  ::test_cpp2::cpp_reflection::struct1& y, double z) {
  ::apache::thrift::RpcOptions rpcOptions;
  method2(rpcOptions, std::move(callback), x, y, z);
}

void service1AsyncClient::method2(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t x, const  ::test_cpp2::cpp_reflection::struct1& y, double z) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      method2T(&writer, rpcOptions, std::move(callback), x, y, z);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      method2T(&writer, rpcOptions, std::move(callback), x, y, z);
      break;
    }
    default:
    {
      throw apache::thrift::TApplicationException("Could not find Protocol");
    }
  }
}

void service1AsyncClient::sync_method2(int32_t x, const  ::test_cpp2::cpp_reflection::struct1& y, double z) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_method2(rpcOptions, x, y, z);
}

void service1AsyncClient::sync_method2(apache::thrift::RpcOptions& rpcOptions, int32_t x, const  ::test_cpp2::cpp_reflection::struct1& y, double z) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = folly::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, getChannel()->getEventBase(), false);
  method2(rpcOptions, std::move(callback), x, y, z);
  getChannel()->getEventBase()->loopForever();
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    std::rethrow_exception(_returnState.exception());
  }
  recv_method2(_returnState);
}

folly::Future<folly::Unit> service1AsyncClient::future_method2(int32_t x, const  ::test_cpp2::cpp_reflection::struct1& y, double z) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_method2(rpcOptions, x, y, z);
}

folly::Future<folly::Unit> service1AsyncClient::future_method2(apache::thrift::RpcOptions& rpcOptions, int32_t x, const  ::test_cpp2::cpp_reflection::struct1& y, double z) {
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_method2, channel_);
  method2(rpcOptions, std::move(callback), x, y, z);
  return _future;
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> service1AsyncClient::header_future_method2(apache::thrift::RpcOptions& rpcOptions, int32_t x, const  ::test_cpp2::cpp_reflection::struct1& y, double z) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_method2, channel_);
  method2(rpcOptions, std::move(callback), x, y, z);
  return _future;
}

void service1AsyncClient::method2(std::function<void (::apache::thrift::ClientReceiveState&&)> callback, int32_t x, const  ::test_cpp2::cpp_reflection::struct1& y, double z) {
  method2(folly::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), x, y, z);
}

folly::exception_wrapper service1AsyncClient::recv_wrapped_method2(::apache::thrift::ClientReceiveState& state) {
  auto ew = state.exceptionWrapper();
  if (ew) {
    return ew;
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_method2T(&reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_method2T(&reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void service1AsyncClient::recv_method2(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_method2(state);
  if (ew) {
    ew.throwException();
  }
}

void service1AsyncClient::recv_instance_method2(::apache::thrift::ClientReceiveState& state) {
  recv_method2(state);
}

folly::exception_wrapper service1AsyncClient::recv_instance_wrapped_method2(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_method2(state);
}

void service1AsyncClient::method3(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  method3(rpcOptions, std::move(callback));
}

void service1AsyncClient::method3(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      method3T(&writer, rpcOptions, std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      method3T(&writer, rpcOptions, std::move(callback));
      break;
    }
    default:
    {
      throw apache::thrift::TApplicationException("Could not find Protocol");
    }
  }
}

int32_t service1AsyncClient::sync_method3() {
  ::apache::thrift::RpcOptions rpcOptions;
  return sync_method3(rpcOptions);
}

int32_t service1AsyncClient::sync_method3(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = folly::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, getChannel()->getEventBase(), false);
  method3(rpcOptions, std::move(callback));
  getChannel()->getEventBase()->loopForever();
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    std::rethrow_exception(_returnState.exception());
  }
  return recv_method3(_returnState);
}

folly::Future<int32_t> service1AsyncClient::future_method3() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_method3(rpcOptions);
}

folly::Future<int32_t> service1AsyncClient::future_method3(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<int32_t> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::FutureCallback<int32_t>>(std::move(_promise), recv_wrapped_method3, channel_);
  method3(rpcOptions, std::move(callback));
  return _future;
}

folly::Future<std::pair<int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> service1AsyncClient::header_future_method3(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::HeaderFutureCallback<int32_t>>(std::move(_promise), recv_wrapped_method3, channel_);
  method3(rpcOptions, std::move(callback));
  return _future;
}

void service1AsyncClient::method3(std::function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  method3(folly::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

folly::exception_wrapper service1AsyncClient::recv_wrapped_method3(int32_t& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = state.exceptionWrapper();
  if (ew) {
    return ew;
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_method3T(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_method3T(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

int32_t service1AsyncClient::recv_method3(::apache::thrift::ClientReceiveState& state) {
  int32_t _return;
  auto ew = recv_wrapped_method3(_return, state);
  if (ew) {
    ew.throwException();
  }
  return _return;
}

int32_t service1AsyncClient::recv_instance_method3(::apache::thrift::ClientReceiveState& state) {
  return recv_method3(state);
}

folly::exception_wrapper service1AsyncClient::recv_instance_wrapped_method3(int32_t& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_method3(_return, state);
}

void service1AsyncClient::method4(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t i, const  ::test_cpp2::cpp_reflection::struct1& j, double k) {
  ::apache::thrift::RpcOptions rpcOptions;
  method4(rpcOptions, std::move(callback), i, j, k);
}

void service1AsyncClient::method4(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t i, const  ::test_cpp2::cpp_reflection::struct1& j, double k) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      method4T(&writer, rpcOptions, std::move(callback), i, j, k);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      method4T(&writer, rpcOptions, std::move(callback), i, j, k);
      break;
    }
    default:
    {
      throw apache::thrift::TApplicationException("Could not find Protocol");
    }
  }
}

int32_t service1AsyncClient::sync_method4(int32_t i, const  ::test_cpp2::cpp_reflection::struct1& j, double k) {
  ::apache::thrift::RpcOptions rpcOptions;
  return sync_method4(rpcOptions, i, j, k);
}

int32_t service1AsyncClient::sync_method4(apache::thrift::RpcOptions& rpcOptions, int32_t i, const  ::test_cpp2::cpp_reflection::struct1& j, double k) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = folly::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, getChannel()->getEventBase(), false);
  method4(rpcOptions, std::move(callback), i, j, k);
  getChannel()->getEventBase()->loopForever();
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    std::rethrow_exception(_returnState.exception());
  }
  return recv_method4(_returnState);
}

folly::Future<int32_t> service1AsyncClient::future_method4(int32_t i, const  ::test_cpp2::cpp_reflection::struct1& j, double k) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_method4(rpcOptions, i, j, k);
}

folly::Future<int32_t> service1AsyncClient::future_method4(apache::thrift::RpcOptions& rpcOptions, int32_t i, const  ::test_cpp2::cpp_reflection::struct1& j, double k) {
  folly::Promise<int32_t> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::FutureCallback<int32_t>>(std::move(_promise), recv_wrapped_method4, channel_);
  method4(rpcOptions, std::move(callback), i, j, k);
  return _future;
}

folly::Future<std::pair<int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> service1AsyncClient::header_future_method4(apache::thrift::RpcOptions& rpcOptions, int32_t i, const  ::test_cpp2::cpp_reflection::struct1& j, double k) {
  folly::Promise<std::pair<int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::HeaderFutureCallback<int32_t>>(std::move(_promise), recv_wrapped_method4, channel_);
  method4(rpcOptions, std::move(callback), i, j, k);
  return _future;
}

void service1AsyncClient::method4(std::function<void (::apache::thrift::ClientReceiveState&&)> callback, int32_t i, const  ::test_cpp2::cpp_reflection::struct1& j, double k) {
  method4(folly::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), i, j, k);
}

folly::exception_wrapper service1AsyncClient::recv_wrapped_method4(int32_t& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = state.exceptionWrapper();
  if (ew) {
    return ew;
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_method4T(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_method4T(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

int32_t service1AsyncClient::recv_method4(::apache::thrift::ClientReceiveState& state) {
  int32_t _return;
  auto ew = recv_wrapped_method4(_return, state);
  if (ew) {
    ew.throwException();
  }
  return _return;
}

int32_t service1AsyncClient::recv_instance_method4(::apache::thrift::ClientReceiveState& state) {
  return recv_method4(state);
}

folly::exception_wrapper service1AsyncClient::recv_instance_wrapped_method4(int32_t& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_method4(_return, state);
}

void service1AsyncClient::method5(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  method5(rpcOptions, std::move(callback));
}

void service1AsyncClient::method5(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      method5T(&writer, rpcOptions, std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      method5T(&writer, rpcOptions, std::move(callback));
      break;
    }
    default:
    {
      throw apache::thrift::TApplicationException("Could not find Protocol");
    }
  }
}

void service1AsyncClient::sync_method5( ::test_cpp2::cpp_reflection::struct2& _return) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_method5(rpcOptions, _return);
}

void service1AsyncClient::sync_method5(apache::thrift::RpcOptions& rpcOptions,  ::test_cpp2::cpp_reflection::struct2& _return) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = folly::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, getChannel()->getEventBase(), false);
  method5(rpcOptions, std::move(callback));
  getChannel()->getEventBase()->loopForever();
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    std::rethrow_exception(_returnState.exception());
  }
  recv_method5(_return, _returnState);
}

folly::Future< ::test_cpp2::cpp_reflection::struct2> service1AsyncClient::future_method5() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_method5(rpcOptions);
}

folly::Future< ::test_cpp2::cpp_reflection::struct2> service1AsyncClient::future_method5(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise< ::test_cpp2::cpp_reflection::struct2> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::FutureCallback< ::test_cpp2::cpp_reflection::struct2>>(std::move(_promise), recv_wrapped_method5, channel_);
  method5(rpcOptions, std::move(callback));
  return _future;
}

folly::Future<std::pair< ::test_cpp2::cpp_reflection::struct2, std::unique_ptr<apache::thrift::transport::THeader>>> service1AsyncClient::header_future_method5(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair< ::test_cpp2::cpp_reflection::struct2, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::HeaderFutureCallback< ::test_cpp2::cpp_reflection::struct2>>(std::move(_promise), recv_wrapped_method5, channel_);
  method5(rpcOptions, std::move(callback));
  return _future;
}

void service1AsyncClient::method5(std::function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  method5(folly::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

folly::exception_wrapper service1AsyncClient::recv_wrapped_method5( ::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = state.exceptionWrapper();
  if (ew) {
    return ew;
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_method5T(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_method5T(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void service1AsyncClient::recv_method5( ::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_method5(_return, state);
  if (ew) {
    ew.throwException();
  }
}

void service1AsyncClient::recv_instance_method5( ::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_method5(_return, state);
}

folly::exception_wrapper service1AsyncClient::recv_instance_wrapped_method5( ::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_method5(_return, state);
}

void service1AsyncClient::method6(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t l, const  ::test_cpp2::cpp_reflection::struct1& m, double n) {
  ::apache::thrift::RpcOptions rpcOptions;
  method6(rpcOptions, std::move(callback), l, m, n);
}

void service1AsyncClient::method6(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t l, const  ::test_cpp2::cpp_reflection::struct1& m, double n) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      method6T(&writer, rpcOptions, std::move(callback), l, m, n);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      method6T(&writer, rpcOptions, std::move(callback), l, m, n);
      break;
    }
    default:
    {
      throw apache::thrift::TApplicationException("Could not find Protocol");
    }
  }
}

void service1AsyncClient::sync_method6( ::test_cpp2::cpp_reflection::struct2& _return, int32_t l, const  ::test_cpp2::cpp_reflection::struct1& m, double n) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_method6(rpcOptions, _return, l, m, n);
}

void service1AsyncClient::sync_method6(apache::thrift::RpcOptions& rpcOptions,  ::test_cpp2::cpp_reflection::struct2& _return, int32_t l, const  ::test_cpp2::cpp_reflection::struct1& m, double n) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = folly::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, getChannel()->getEventBase(), false);
  method6(rpcOptions, std::move(callback), l, m, n);
  getChannel()->getEventBase()->loopForever();
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    std::rethrow_exception(_returnState.exception());
  }
  recv_method6(_return, _returnState);
}

folly::Future< ::test_cpp2::cpp_reflection::struct2> service1AsyncClient::future_method6(int32_t l, const  ::test_cpp2::cpp_reflection::struct1& m, double n) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_method6(rpcOptions, l, m, n);
}

folly::Future< ::test_cpp2::cpp_reflection::struct2> service1AsyncClient::future_method6(apache::thrift::RpcOptions& rpcOptions, int32_t l, const  ::test_cpp2::cpp_reflection::struct1& m, double n) {
  folly::Promise< ::test_cpp2::cpp_reflection::struct2> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::FutureCallback< ::test_cpp2::cpp_reflection::struct2>>(std::move(_promise), recv_wrapped_method6, channel_);
  method6(rpcOptions, std::move(callback), l, m, n);
  return _future;
}

folly::Future<std::pair< ::test_cpp2::cpp_reflection::struct2, std::unique_ptr<apache::thrift::transport::THeader>>> service1AsyncClient::header_future_method6(apache::thrift::RpcOptions& rpcOptions, int32_t l, const  ::test_cpp2::cpp_reflection::struct1& m, double n) {
  folly::Promise<std::pair< ::test_cpp2::cpp_reflection::struct2, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = folly::make_unique<apache::thrift::HeaderFutureCallback< ::test_cpp2::cpp_reflection::struct2>>(std::move(_promise), recv_wrapped_method6, channel_);
  method6(rpcOptions, std::move(callback), l, m, n);
  return _future;
}

void service1AsyncClient::method6(std::function<void (::apache::thrift::ClientReceiveState&&)> callback, int32_t l, const  ::test_cpp2::cpp_reflection::struct1& m, double n) {
  method6(folly::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), l, m, n);
}

folly::exception_wrapper service1AsyncClient::recv_wrapped_method6( ::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = state.exceptionWrapper();
  if (ew) {
    return ew;
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_method6T(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_method6T(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void service1AsyncClient::recv_method6( ::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_method6(_return, state);
  if (ew) {
    ew.throwException();
  }
}

void service1AsyncClient::recv_instance_method6( ::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_method6(_return, state);
}

folly::exception_wrapper service1AsyncClient::recv_instance_wrapped_method6( ::test_cpp2::cpp_reflection::struct2& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_method6(_return, state);
}

}} // test_cpp2::cpp_reflection
namespace apache { namespace thrift {

}} // apache::thrift