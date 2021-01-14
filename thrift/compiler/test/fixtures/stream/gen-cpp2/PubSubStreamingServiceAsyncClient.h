/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/stream/gen-cpp2/module_types.h"
#include <thrift/lib/cpp2/async/ClientBufferedStream.h>

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace cpp2 {

class PubSubStreamingServiceAsyncClient : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "PubSubStreamingService";
  }


  virtual void returnstream(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t p_i32_from, int32_t p_i32_to);
  virtual void returnstream(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t p_i32_from, int32_t p_i32_to);
 protected:
  void returnstreamImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::StreamClientCallback* callback, int32_t p_i32_from, int32_t p_i32_to);
 public:

  virtual apache::thrift::ClientBufferedStream<int32_t> sync_returnstream(int32_t p_i32_from, int32_t p_i32_to);
  virtual apache::thrift::ClientBufferedStream<int32_t> sync_returnstream(apache::thrift::RpcOptions& rpcOptions, int32_t p_i32_from, int32_t p_i32_to);

  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<int32_t>> semifuture_returnstream(int32_t p_i32_from, int32_t p_i32_to);
  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<int32_t>> semifuture_returnstream(apache::thrift::RpcOptions& rpcOptions, int32_t p_i32_from, int32_t p_i32_to);
  virtual folly::SemiFuture<std::pair<apache::thrift::ClientBufferedStream<int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_returnstream(apache::thrift::RpcOptions& rpcOptions, int32_t p_i32_from, int32_t p_i32_to);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<int32_t>> co_returnstream(int32_t p_i32_from, int32_t p_i32_to) {
    auto task = semifuture_returnstream(p_i32_from, p_i32_to);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<int32_t>> co_returnstream(apache::thrift::RpcOptions& rpcOptions, int32_t p_i32_from, int32_t p_i32_to) {
    auto task = semifuture_returnstream(rpcOptions, p_i32_from, p_i32_to);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<std::pair<apache::thrift::ClientBufferedStream<int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_co_returnstream(apache::thrift::RpcOptions& rpcOptions, int32_t p_i32_from, int32_t p_i32_to) {
    auto task = header_semifuture_returnstream(rpcOptions, p_i32_from, p_i32_to);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES



  static folly::exception_wrapper recv_wrapped_returnstream(apache::thrift::ClientBufferedStream<int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
  static apache::thrift::ClientBufferedStream<int32_t> recv_returnstream(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual apache::thrift::ClientBufferedStream<int32_t> recv_instance_returnstream(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_returnstream(apache::thrift::ClientBufferedStream<int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void returnstreamT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::StreamClientCallback* callback, int32_t p_i32_from, int32_t p_i32_to);
 public:
  virtual void streamthrows(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t p_foo);
  virtual void streamthrows(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t p_foo);
 protected:
  void streamthrowsImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::StreamClientCallback* callback, int32_t p_foo);
 public:

  virtual apache::thrift::ClientBufferedStream<int32_t> sync_streamthrows(int32_t p_foo);
  virtual apache::thrift::ClientBufferedStream<int32_t> sync_streamthrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo);

  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<int32_t>> semifuture_streamthrows(int32_t p_foo);
  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<int32_t>> semifuture_streamthrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo);
  virtual folly::SemiFuture<std::pair<apache::thrift::ClientBufferedStream<int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_streamthrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<int32_t>> co_streamthrows(int32_t p_foo) {
    auto task = semifuture_streamthrows(p_foo);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<int32_t>> co_streamthrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo) {
    auto task = semifuture_streamthrows(rpcOptions, p_foo);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<std::pair<apache::thrift::ClientBufferedStream<int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_co_streamthrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo) {
    auto task = header_semifuture_streamthrows(rpcOptions, p_foo);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES



  static folly::exception_wrapper recv_wrapped_streamthrows(apache::thrift::ClientBufferedStream<int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
  static apache::thrift::ClientBufferedStream<int32_t> recv_streamthrows(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual apache::thrift::ClientBufferedStream<int32_t> recv_instance_streamthrows(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_streamthrows(apache::thrift::ClientBufferedStream<int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void streamthrowsT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::StreamClientCallback* callback, int32_t p_foo);
 public:
  virtual void boththrows(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t p_foo);
  virtual void boththrows(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t p_foo);
 protected:
  void boththrowsImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::StreamClientCallback* callback, int32_t p_foo);
 public:

  virtual apache::thrift::ClientBufferedStream<int32_t> sync_boththrows(int32_t p_foo);
  virtual apache::thrift::ClientBufferedStream<int32_t> sync_boththrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo);

  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<int32_t>> semifuture_boththrows(int32_t p_foo);
  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<int32_t>> semifuture_boththrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo);
  virtual folly::SemiFuture<std::pair<apache::thrift::ClientBufferedStream<int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_boththrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<int32_t>> co_boththrows(int32_t p_foo) {
    auto task = semifuture_boththrows(p_foo);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<int32_t>> co_boththrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo) {
    auto task = semifuture_boththrows(rpcOptions, p_foo);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<std::pair<apache::thrift::ClientBufferedStream<int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_co_boththrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo) {
    auto task = header_semifuture_boththrows(rpcOptions, p_foo);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES



  static folly::exception_wrapper recv_wrapped_boththrows(apache::thrift::ClientBufferedStream<int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
  static apache::thrift::ClientBufferedStream<int32_t> recv_boththrows(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual apache::thrift::ClientBufferedStream<int32_t> recv_instance_boththrows(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_boththrows(apache::thrift::ClientBufferedStream<int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void boththrowsT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::StreamClientCallback* callback, int32_t p_foo);
 public:
  virtual void responseandstreamthrows(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t p_foo);
  virtual void responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t p_foo);
 protected:
  void responseandstreamthrowsImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::StreamClientCallback* callback, int32_t p_foo);
 public:

  virtual apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t> sync_responseandstreamthrows(int32_t p_foo);
  virtual apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t> sync_responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo);

  virtual folly::SemiFuture<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>> semifuture_responseandstreamthrows(int32_t p_foo);
  virtual folly::SemiFuture<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>> semifuture_responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo);
  virtual folly::SemiFuture<std::pair<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>> co_responseandstreamthrows(int32_t p_foo) {
    auto task = semifuture_responseandstreamthrows(p_foo);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>> co_responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo) {
    auto task = semifuture_responseandstreamthrows(rpcOptions, p_foo);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<std::pair<apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_co_responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, int32_t p_foo) {
    auto task = header_semifuture_responseandstreamthrows(rpcOptions, p_foo);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES



  static folly::exception_wrapper recv_wrapped_responseandstreamthrows(apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
  static apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t> recv_responseandstreamthrows(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t> recv_instance_responseandstreamthrows(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_responseandstreamthrows(apache::thrift::ResponseAndClientBufferedStream<int32_t,int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void responseandstreamthrowsT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::StreamClientCallback* callback, int32_t p_foo);
 public:
  virtual void returnstreamFast(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t p_i32_from, int32_t p_i32_to);
  virtual void returnstreamFast(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t p_i32_from, int32_t p_i32_to);
 protected:
  void returnstreamFastImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::StreamClientCallback* callback, int32_t p_i32_from, int32_t p_i32_to);
 public:

  virtual apache::thrift::ClientBufferedStream<int32_t> sync_returnstreamFast(int32_t p_i32_from, int32_t p_i32_to);
  virtual apache::thrift::ClientBufferedStream<int32_t> sync_returnstreamFast(apache::thrift::RpcOptions& rpcOptions, int32_t p_i32_from, int32_t p_i32_to);

  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<int32_t>> semifuture_returnstreamFast(int32_t p_i32_from, int32_t p_i32_to);
  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<int32_t>> semifuture_returnstreamFast(apache::thrift::RpcOptions& rpcOptions, int32_t p_i32_from, int32_t p_i32_to);
  virtual folly::SemiFuture<std::pair<apache::thrift::ClientBufferedStream<int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_returnstreamFast(apache::thrift::RpcOptions& rpcOptions, int32_t p_i32_from, int32_t p_i32_to);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<int32_t>> co_returnstreamFast(int32_t p_i32_from, int32_t p_i32_to) {
    auto task = semifuture_returnstreamFast(p_i32_from, p_i32_to);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<int32_t>> co_returnstreamFast(apache::thrift::RpcOptions& rpcOptions, int32_t p_i32_from, int32_t p_i32_to) {
    auto task = semifuture_returnstreamFast(rpcOptions, p_i32_from, p_i32_to);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<std::pair<apache::thrift::ClientBufferedStream<int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_co_returnstreamFast(apache::thrift::RpcOptions& rpcOptions, int32_t p_i32_from, int32_t p_i32_to) {
    auto task = header_semifuture_returnstreamFast(rpcOptions, p_i32_from, p_i32_to);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES



  static folly::exception_wrapper recv_wrapped_returnstreamFast(apache::thrift::ClientBufferedStream<int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
  static apache::thrift::ClientBufferedStream<int32_t> recv_returnstreamFast(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual apache::thrift::ClientBufferedStream<int32_t> recv_instance_returnstreamFast(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_returnstreamFast(apache::thrift::ClientBufferedStream<int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void returnstreamFastT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::StreamClientCallback* callback, int32_t p_i32_from, int32_t p_i32_to);
 public:
};

} // cpp2
