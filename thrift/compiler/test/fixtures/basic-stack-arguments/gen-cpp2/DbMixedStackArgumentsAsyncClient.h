/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/basic-stack-arguments/gen-cpp2/module_types.h"

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace cpp2 {

class DbMixedStackArgumentsAsyncClient : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "DbMixedStackArguments";
  }


  virtual void getDataByKey0(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::string& p_key);
  virtual void getDataByKey0(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::string& p_key);
 protected:
  void getDataByKey0Impl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const ::std::string& p_key);
 public:

  virtual void sync_getDataByKey0(::std::string& _return, const ::std::string& p_key);
  virtual void sync_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, ::std::string& _return, const ::std::string& p_key);

  virtual folly::Future<::std::string> future_getDataByKey0(const ::std::string& p_key);
  virtual folly::SemiFuture<::std::string> semifuture_getDataByKey0(const ::std::string& p_key);
  virtual folly::Future<::std::string> future_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key);
  virtual folly::SemiFuture<::std::string> semifuture_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key);
  virtual folly::Future<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key);
  virtual folly::SemiFuture<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key);
  FOLLY_NODISCARD [[deprecated("To be replaced by new API soon")]] virtual folly::Try<apache::thrift::RpcResponseComplete<::std::string>> sync_complete_getDataByKey0(
      apache::thrift::RpcOptions& rpcOptions,  const ::std::string& p_key);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<::std::string> co_getDataByKey0(const ::std::string& p_key) {
    auto task = semifuture_getDataByKey0(p_key);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<::std::string> co_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key) {
    auto task = semifuture_getDataByKey0(rpcOptions, p_key);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> header_co_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key) {
    auto task = header_semifuture_getDataByKey0(rpcOptions, p_key);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES

  virtual void getDataByKey0(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::std::string& p_key);


  static folly::exception_wrapper recv_wrapped_getDataByKey0(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
  static void recv_getDataByKey0(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_getDataByKey0(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_getDataByKey0(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void getDataByKey0T(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const ::std::string& p_key);
 public:
  virtual void getDataByKey1(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::string& p_key);
  virtual void getDataByKey1(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::string& p_key);
 protected:
  void getDataByKey1Impl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const ::std::string& p_key);
 public:

  virtual void sync_getDataByKey1(::std::string& _return, const ::std::string& p_key);
  virtual void sync_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, ::std::string& _return, const ::std::string& p_key);

  virtual folly::Future<::std::string> future_getDataByKey1(const ::std::string& p_key);
  virtual folly::SemiFuture<::std::string> semifuture_getDataByKey1(const ::std::string& p_key);
  virtual folly::Future<::std::string> future_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key);
  virtual folly::SemiFuture<::std::string> semifuture_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key);
  virtual folly::Future<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key);
  virtual folly::SemiFuture<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key);
  FOLLY_NODISCARD [[deprecated("To be replaced by new API soon")]] virtual folly::Try<apache::thrift::RpcResponseComplete<::std::string>> sync_complete_getDataByKey1(
      apache::thrift::RpcOptions& rpcOptions,  const ::std::string& p_key);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<::std::string> co_getDataByKey1(const ::std::string& p_key) {
    auto task = semifuture_getDataByKey1(p_key);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<::std::string> co_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key) {
    auto task = semifuture_getDataByKey1(rpcOptions, p_key);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
  template <int = 0>
  folly::coro::Task<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> header_co_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key) {
    auto task = header_semifuture_getDataByKey1(rpcOptions, p_key);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES

  virtual void getDataByKey1(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::std::string& p_key);


  static folly::exception_wrapper recv_wrapped_getDataByKey1(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
  static void recv_getDataByKey1(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_getDataByKey1(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_getDataByKey1(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void getDataByKey1T(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, const ::std::string& p_key);
 public:
};

} // cpp2
