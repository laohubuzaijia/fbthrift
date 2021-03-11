/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/coroutines/gen-cpp2/MyServiceAsyncClient.h"
#include "thrift/compiler/test/fixtures/coroutines/gen-cpp2/module_types.h"

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace cpp2 {

class MyServiceSvAsyncIf {
 public:
  virtual ~MyServiceSvAsyncIf() {}
  virtual void async_tm_ping(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) = 0;
  virtual folly::Future<folly::Unit> future_ping() = 0;
  virtual folly::SemiFuture<folly::Unit> semifuture_ping() = 0;
  virtual void async_tm_getRandomData(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr<::std::string>>> callback) = 0;
  virtual folly::Future<std::unique_ptr<::std::string>> future_getRandomData() = 0;
  virtual folly::SemiFuture<std::unique_ptr<::std::string>> semifuture_getRandomData() = 0;
  virtual void async_tm_hasDataById(std::unique_ptr<apache::thrift::HandlerCallback<bool>> callback, ::std::int64_t p_id) = 0;
  virtual folly::Future<bool> future_hasDataById(::std::int64_t p_id) = 0;
  virtual folly::SemiFuture<bool> semifuture_hasDataById(::std::int64_t p_id) = 0;
  virtual void async_eb_getDataById(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr<::std::string>>> callback, ::std::int64_t p_id) = 0;
  virtual void async_tm_putDataById(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback, ::std::int64_t p_id, std::unique_ptr<::std::string> p_data) = 0;
  virtual folly::Future<folly::Unit> future_putDataById(::std::int64_t p_id, std::unique_ptr<::std::string> p_data) = 0;
  virtual folly::SemiFuture<folly::Unit> semifuture_putDataById(::std::int64_t p_id, std::unique_ptr<::std::string> p_data) = 0;
};

class MyServiceAsyncProcessor;

class MyServiceSvIf : public MyServiceSvAsyncIf, public apache::thrift::ServerInterface {
 public:
  typedef MyServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;


  virtual void ping();
  folly::Future<folly::Unit> future_ping() override;
  folly::SemiFuture<folly::Unit> semifuture_ping() override;
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<void> co_ping();
  virtual folly::coro::Task<void> co_ping(apache::thrift::RequestParams params);
#endif
  void async_tm_ping(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) override;
  virtual void getRandomData(::std::string& /*_return*/);
  folly::Future<std::unique_ptr<::std::string>> future_getRandomData() override;
  folly::SemiFuture<std::unique_ptr<::std::string>> semifuture_getRandomData() override;
  void async_tm_getRandomData(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr<::std::string>>> callback) override;
  virtual bool hasDataById(::std::int64_t /*id*/);
  folly::Future<bool> future_hasDataById(::std::int64_t p_id) override;
  folly::SemiFuture<bool> semifuture_hasDataById(::std::int64_t p_id) override;
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<bool> co_hasDataById(::std::int64_t p_id);
  virtual folly::coro::Task<bool> co_hasDataById(apache::thrift::RequestParams params, ::std::int64_t p_id);
#endif
  void async_tm_hasDataById(std::unique_ptr<apache::thrift::HandlerCallback<bool>> callback, ::std::int64_t p_id) override;
  void async_eb_getDataById(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr<::std::string>>> callback, ::std::int64_t p_id) override;
  virtual void putDataById(::std::int64_t /*id*/, std::unique_ptr<::std::string> /*data*/);
  folly::Future<folly::Unit> future_putDataById(::std::int64_t p_id, std::unique_ptr<::std::string> p_data) override;
  folly::SemiFuture<folly::Unit> semifuture_putDataById(::std::int64_t p_id, std::unique_ptr<::std::string> p_data) override;
  void async_tm_putDataById(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback, ::std::int64_t p_id, std::unique_ptr<::std::string> p_data) override;
};

class MyServiceSvNull : public MyServiceSvIf {
 public:
  void ping() override;
  void getRandomData(::std::string& /*_return*/) override;
  bool hasDataById(::std::int64_t /*id*/) override;
  void putDataById(::std::int64_t /*id*/, std::unique_ptr<::std::string> /*data*/) override;
};

class MyServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  MyServiceSvIf* iface_;
 public:
  void processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
 protected:
  std::shared_ptr<folly::RequestContext> getBaseContextForRequest() override;
 public:
  using ProcessFunc = GeneratedAsyncProcessor::ProcessFunc<MyServiceAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFunc>;
  static const MyServiceAsyncProcessor::ProcessMap& getBinaryProtocolProcessMap();
  static const MyServiceAsyncProcessor::ProcessMap& getCompactProtocolProcessMap();
 private:
  static const MyServiceAsyncProcessor::ProcessMap binaryProcessMap_;
  static const MyServiceAsyncProcessor::ProcessMap compactProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_ping(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_ping(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_ping(int32_t protoSeqId, apache::thrift::ContextStack* ctx);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_ping(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_getRandomData(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_getRandomData(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_getRandomData(int32_t protoSeqId, apache::thrift::ContextStack* ctx, ::std::string const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_getRandomData(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_hasDataById(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_hasDataById(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_hasDataById(int32_t protoSeqId, apache::thrift::ContextStack* ctx, bool const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_hasDataById(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_getDataById(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_getDataById(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_getDataById(int32_t protoSeqId, apache::thrift::ContextStack* ctx, ::std::string const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_getDataById(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_putDataById(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_putDataById(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_putDataById(int32_t protoSeqId, apache::thrift::ContextStack* ctx);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_putDataById(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  MyServiceAsyncProcessor(MyServiceSvIf* iface) :
      iface_(iface) {}

  virtual ~MyServiceAsyncProcessor() {}
};

} // cpp2
