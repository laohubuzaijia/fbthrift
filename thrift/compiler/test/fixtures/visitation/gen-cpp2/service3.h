/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/visitation/gen-cpp2/service3AsyncClient.h"
#include "thrift/compiler/test/fixtures/visitation/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/visitation/gen-cpp2/reflection_dep_B_types.h"
#include "thrift/compiler/test/fixtures/visitation/gen-cpp2/reflection_dep_C_types.h"
#include "thrift/test/fatal_custom_types.h"

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

namespace test_cpp2 { namespace cpp_reflection {

class service3SvAsyncIf {
 public:
  virtual ~service3SvAsyncIf() {}
  virtual void async_tm_methodA(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) = 0;
  virtual folly::Future<folly::Unit> future_methodA() = 0;
  virtual folly::SemiFuture<folly::Unit> semifuture_methodA() = 0;
  virtual void async_tm_methodB(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback, int32_t p_x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_y, double p_z) = 0;
  virtual folly::Future<folly::Unit> future_methodB(int32_t p_x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_y, double p_z) = 0;
  virtual folly::SemiFuture<folly::Unit> semifuture_methodB(int32_t p_x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_y, double p_z) = 0;
  virtual void async_tm_methodC(std::unique_ptr<apache::thrift::HandlerCallback<int32_t>> callback) = 0;
  virtual folly::Future<int32_t> future_methodC() = 0;
  virtual folly::SemiFuture<int32_t> semifuture_methodC() = 0;
  virtual void async_tm_methodD(std::unique_ptr<apache::thrift::HandlerCallback<int32_t>> callback, int32_t p_i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_j, double p_k) = 0;
  virtual folly::Future<int32_t> future_methodD(int32_t p_i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_j, double p_k) = 0;
  virtual folly::SemiFuture<int32_t> semifuture_methodD(int32_t p_i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_j, double p_k) = 0;
  virtual void async_tm_methodE(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>>> callback) = 0;
  virtual folly::Future<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> future_methodE() = 0;
  virtual folly::SemiFuture<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> semifuture_methodE() = 0;
  virtual void async_tm_methodF(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::test_cpp2::cpp_reflection::struct3>>> callback, int32_t p_l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_m, double p_n) = 0;
  virtual folly::Future<std::unique_ptr< ::test_cpp2::cpp_reflection::struct3>> future_methodF(int32_t p_l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_m, double p_n) = 0;
  virtual folly::SemiFuture<std::unique_ptr< ::test_cpp2::cpp_reflection::struct3>> semifuture_methodF(int32_t p_l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_m, double p_n) = 0;
};

class service3AsyncProcessor;

class service3SvIf : public service3SvAsyncIf, public apache::thrift::ServerInterface {
 public:
  typedef service3AsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;


  virtual void methodA();
  folly::Future<folly::Unit> future_methodA() override;
  folly::SemiFuture<folly::Unit> semifuture_methodA() override;
  void async_tm_methodA(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) override;
  virtual void methodB(int32_t /*x*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*y*/, double /*z*/);
  folly::Future<folly::Unit> future_methodB(int32_t p_x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_y, double p_z) override;
  folly::SemiFuture<folly::Unit> semifuture_methodB(int32_t p_x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_y, double p_z) override;
  void async_tm_methodB(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback, int32_t p_x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_y, double p_z) override;
  virtual int32_t methodC();
  folly::Future<int32_t> future_methodC() override;
  folly::SemiFuture<int32_t> semifuture_methodC() override;
  void async_tm_methodC(std::unique_ptr<apache::thrift::HandlerCallback<int32_t>> callback) override;
  virtual int32_t methodD(int32_t /*i*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*j*/, double /*k*/);
  folly::Future<int32_t> future_methodD(int32_t p_i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_j, double p_k) override;
  folly::SemiFuture<int32_t> semifuture_methodD(int32_t p_i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_j, double p_k) override;
  void async_tm_methodD(std::unique_ptr<apache::thrift::HandlerCallback<int32_t>> callback, int32_t p_i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_j, double p_k) override;
  virtual void methodE( ::test_cpp2::cpp_reflection::struct2& /*_return*/);
  folly::Future<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> future_methodE() override;
  folly::SemiFuture<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> semifuture_methodE() override;
  void async_tm_methodE(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>>> callback) override;
  virtual void methodF( ::test_cpp2::cpp_reflection::struct3& /*_return*/, int32_t /*l*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*m*/, double /*n*/);
  folly::Future<std::unique_ptr< ::test_cpp2::cpp_reflection::struct3>> future_methodF(int32_t p_l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_m, double p_n) override;
  folly::SemiFuture<std::unique_ptr< ::test_cpp2::cpp_reflection::struct3>> semifuture_methodF(int32_t p_l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_m, double p_n) override;
  void async_tm_methodF(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::test_cpp2::cpp_reflection::struct3>>> callback, int32_t p_l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_m, double p_n) override;
};

class service3SvNull : public service3SvIf {
 public:
  void methodA() override;
  void methodB(int32_t /*x*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*y*/, double /*z*/) override;
  int32_t methodC() override;
  int32_t methodD(int32_t /*i*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*j*/, double /*k*/) override;
  void methodE( ::test_cpp2::cpp_reflection::struct2& /*_return*/) override;
  void methodF( ::test_cpp2::cpp_reflection::struct3& /*_return*/, int32_t /*l*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*m*/, double /*n*/) override;
};

class service3AsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  service3SvIf* iface_;
 public:
  void processSerializedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
 protected:
  std::shared_ptr<folly::RequestContext> getBaseContextForRequest() override;
 public:
  using ProcessFunc = GeneratedAsyncProcessor::ProcessFunc<service3AsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFunc>;
  static const service3AsyncProcessor::ProcessMap& getBinaryProtocolProcessMap();
  static const service3AsyncProcessor::ProcessMap& getCompactProtocolProcessMap();
 private:
  static const service3AsyncProcessor::ProcessMap binaryProcessMap_;
  static const service3AsyncProcessor::ProcessMap compactProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_methodA(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodA(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_methodA(int32_t protoSeqId, apache::thrift::ContextStack* ctx);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodA(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_methodB(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodB(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_methodB(int32_t protoSeqId, apache::thrift::ContextStack* ctx);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodB(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_methodC(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodC(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_methodC(int32_t protoSeqId, apache::thrift::ContextStack* ctx, int32_t const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodC(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_methodD(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodD(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_methodD(int32_t protoSeqId, apache::thrift::ContextStack* ctx, int32_t const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodD(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_methodE(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodE(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_methodE(int32_t protoSeqId, apache::thrift::ContextStack* ctx,  ::test_cpp2::cpp_reflection::struct2 const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodE(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_methodF(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodF(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_methodF(int32_t protoSeqId, apache::thrift::ContextStack* ctx,  ::test_cpp2::cpp_reflection::struct3 const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodF(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  service3AsyncProcessor(service3SvIf* iface) :
      iface_(iface) {}

  virtual ~service3AsyncProcessor() {}
};

}} // test_cpp2::cpp_reflection
