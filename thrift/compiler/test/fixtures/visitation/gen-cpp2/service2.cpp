/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/visitation/gen-cpp2/service2.h"
#include "thrift/compiler/test/fixtures/visitation/gen-cpp2/service2.tcc"
#include "thrift/compiler/test/fixtures/visitation/gen-cpp2/module_metadata.h"
#include <thrift/lib/cpp2/gen/service_cpp.h>

namespace test_cpp2 { namespace cpp_reflection {
std::unique_ptr<apache::thrift::AsyncProcessor> service2SvIf::getProcessor() {
  return std::make_unique<service2AsyncProcessor>(this);
}


void service2SvIf::methodA() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodA");
}

folly::SemiFuture<folly::Unit> service2SvIf::semifuture_methodA() {
  return apache::thrift::detail::si::semifuture([&] {
    return methodA();
  });
}

folly::Future<folly::Unit> service2SvIf::future_methodA() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodA(), std::move(ka));
}

void service2SvIf::async_tm_methodA(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodA();
  });
}

void service2SvIf::methodB(int32_t /*x*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*y*/, double /*z*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodB");
}

folly::SemiFuture<folly::Unit> service2SvIf::semifuture_methodB(int32_t p_x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_y, double p_z) {
  return apache::thrift::detail::si::semifuture([&] {
    return methodB(p_x, std::move(p_y), p_z);
  });
}

folly::Future<folly::Unit> service2SvIf::future_methodB(int32_t p_x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_y, double p_z) {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodB(p_x, std::move(p_y), p_z), std::move(ka));
}

void service2SvIf::async_tm_methodB(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback, int32_t p_x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_y, double p_z) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodB(p_x, std::move(p_y), p_z);
  });
}

int32_t service2SvIf::methodC() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodC");
}

folly::SemiFuture<int32_t> service2SvIf::semifuture_methodC() {
  return apache::thrift::detail::si::semifuture([&] {
    return methodC();
  });
}

folly::Future<int32_t> service2SvIf::future_methodC() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodC(), std::move(ka));
}

void service2SvIf::async_tm_methodC(std::unique_ptr<apache::thrift::HandlerCallback<int32_t>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodC();
  });
}

int32_t service2SvIf::methodD(int32_t /*i*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*j*/, double /*k*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodD");
}

folly::SemiFuture<int32_t> service2SvIf::semifuture_methodD(int32_t p_i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_j, double p_k) {
  return apache::thrift::detail::si::semifuture([&] {
    return methodD(p_i, std::move(p_j), p_k);
  });
}

folly::Future<int32_t> service2SvIf::future_methodD(int32_t p_i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_j, double p_k) {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodD(p_i, std::move(p_j), p_k), std::move(ka));
}

void service2SvIf::async_tm_methodD(std::unique_ptr<apache::thrift::HandlerCallback<int32_t>> callback, int32_t p_i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_j, double p_k) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodD(p_i, std::move(p_j), p_k);
  });
}

void service2SvIf::methodE( ::test_cpp2::cpp_reflection::struct2& /*_return*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodE");
}

folly::SemiFuture<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> service2SvIf::semifuture_methodE() {
  return apache::thrift::detail::si::semifuture_returning_uptr([&]( ::test_cpp2::cpp_reflection::struct2& _return) { methodE(_return); });
}

folly::Future<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> service2SvIf::future_methodE() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodE(), std::move(ka));
}

void service2SvIf::async_tm_methodE(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodE();
  });
}

void service2SvIf::methodF( ::test_cpp2::cpp_reflection::struct2& /*_return*/, int32_t /*l*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*m*/, double /*n*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodF");
}

folly::SemiFuture<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> service2SvIf::semifuture_methodF(int32_t p_l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_m, double p_n) {
  return apache::thrift::detail::si::semifuture_returning_uptr([&]( ::test_cpp2::cpp_reflection::struct2& _return) { methodF(_return, p_l, std::move(p_m), p_n); });
}

folly::Future<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> service2SvIf::future_methodF(int32_t p_l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_m, double p_n) {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodF(p_l, std::move(p_m), p_n), std::move(ka));
}

void service2SvIf::async_tm_methodF(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>>> callback, int32_t p_l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> p_m, double p_n) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodF(p_l, std::move(p_m), p_n);
  });
}

void service2SvNull::methodA() {
  return;
}

void service2SvNull::methodB(int32_t /*x*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*y*/, double /*z*/) {
  return;
}

int32_t service2SvNull::methodC() {
  return 0;
}

int32_t service2SvNull::methodD(int32_t /*i*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*j*/, double /*k*/) {
  return 0;
}

void service2SvNull::methodE( ::test_cpp2::cpp_reflection::struct2& /*_return*/) {}

void service2SvNull::methodF( ::test_cpp2::cpp_reflection::struct2& /*_return*/, int32_t /*l*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*m*/, double /*n*/) {}



const char* service2AsyncProcessor::getServiceName() {
  return "service2";
}

void service2AsyncProcessor::getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) {
  ::apache::thrift::detail::md::ServiceMetadata<service2SvIf>::gen(*response.metadata_ref(), *response.context_ref());
}

void service2AsyncProcessor::processSerializedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(serializedRequest), protType, context, eb, tm);
}

std::shared_ptr<folly::RequestContext> service2AsyncProcessor::getBaseContextForRequest() {
  return iface_->getBaseContextForRequest();
}

const service2AsyncProcessor::ProcessMap& service2AsyncProcessor::getBinaryProtocolProcessMap() {
  return binaryProcessMap_;
}

const service2AsyncProcessor::ProcessMap service2AsyncProcessor::binaryProcessMap_ {
  {"methodA", &service2AsyncProcessor::setUpAndProcess_methodA<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodB", &service2AsyncProcessor::setUpAndProcess_methodB<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodC", &service2AsyncProcessor::setUpAndProcess_methodC<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodD", &service2AsyncProcessor::setUpAndProcess_methodD<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodE", &service2AsyncProcessor::setUpAndProcess_methodE<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodF", &service2AsyncProcessor::setUpAndProcess_methodF<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
};

const service2AsyncProcessor::ProcessMap& service2AsyncProcessor::getCompactProtocolProcessMap() {
  return compactProcessMap_;
}

const service2AsyncProcessor::ProcessMap service2AsyncProcessor::compactProcessMap_ {
  {"methodA", &service2AsyncProcessor::setUpAndProcess_methodA<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodB", &service2AsyncProcessor::setUpAndProcess_methodB<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodC", &service2AsyncProcessor::setUpAndProcess_methodC<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodD", &service2AsyncProcessor::setUpAndProcess_methodD<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodE", &service2AsyncProcessor::setUpAndProcess_methodE<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodF", &service2AsyncProcessor::setUpAndProcess_methodF<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
};

}} // test_cpp2::cpp_reflection
