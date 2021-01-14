/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/basic-annotations/gen-cpp2/MyService.h"
#include "thrift/compiler/test/fixtures/basic-annotations/gen-cpp2/MyService.tcc"
#include "thrift/compiler/test/fixtures/basic-annotations/gen-cpp2/module_metadata.h"
#include <thrift/lib/cpp2/gen/service_cpp.h>

namespace cpp2 {
std::unique_ptr<apache::thrift::AsyncProcessor> MyServiceSvIf::getProcessor() {
  return std::make_unique<MyServiceAsyncProcessor>(this);
}


void MyServiceSvIf::ping() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("ping");
}

folly::SemiFuture<folly::Unit> MyServiceSvIf::semifuture_ping() {
  return apache::thrift::detail::si::semifuture([&] {
    return ping();
  });
}

folly::Future<folly::Unit> MyServiceSvIf::future_ping() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_ping(), std::move(ka));
}

void MyServiceSvIf::async_tm_ping(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_ping();
  });
}

void MyServiceSvIf::getRandomData(::std::string& /*_return*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("getRandomData");
}

folly::SemiFuture<std::unique_ptr<::std::string>> MyServiceSvIf::semifuture_getRandomData() {
  return apache::thrift::detail::si::semifuture_returning_uptr([&](::std::string& _return) { getRandomData(_return); });
}

folly::Future<std::unique_ptr<::std::string>> MyServiceSvIf::future_getRandomData() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_getRandomData(), std::move(ka));
}

void MyServiceSvIf::async_tm_getRandomData(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr<::std::string>>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_getRandomData();
  });
}

bool MyServiceSvIf::hasDataById(int64_t /*id*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("hasDataById");
}

folly::SemiFuture<bool> MyServiceSvIf::semifuture_hasDataById(int64_t p_id) {
  return apache::thrift::detail::si::semifuture([&] {
    return hasDataById(p_id);
  });
}

folly::Future<bool> MyServiceSvIf::future_hasDataById(int64_t p_id) {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_hasDataById(p_id), std::move(ka));
}

void MyServiceSvIf::async_tm_hasDataById(std::unique_ptr<apache::thrift::HandlerCallback<bool>> callback, int64_t p_id) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_hasDataById(p_id);
  });
}

void MyServiceSvIf::getDataById(::std::string& /*_return*/, int64_t /*id*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("getDataById");
}

folly::SemiFuture<std::unique_ptr<::std::string>> MyServiceSvIf::semifuture_getDataById(int64_t p_id) {
  return apache::thrift::detail::si::semifuture_returning_uptr([&](::std::string& _return) { getDataById(_return, p_id); });
}

folly::Future<std::unique_ptr<::std::string>> MyServiceSvIf::future_getDataById(int64_t p_id) {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_getDataById(p_id), std::move(ka));
}

void MyServiceSvIf::async_tm_getDataById(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr<::std::string>>> callback, int64_t p_id) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_getDataById(p_id);
  });
}

void MyServiceSvIf::putDataById(int64_t /*id*/, std::unique_ptr<::std::string> /*data*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("putDataById");
}

folly::SemiFuture<folly::Unit> MyServiceSvIf::semifuture_putDataById(int64_t p_id, std::unique_ptr<::std::string> p_data) {
  return apache::thrift::detail::si::semifuture([&] {
    return putDataById(p_id, std::move(p_data));
  });
}

folly::Future<folly::Unit> MyServiceSvIf::future_putDataById(int64_t p_id, std::unique_ptr<::std::string> p_data) {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_putDataById(p_id, std::move(p_data)), std::move(ka));
}

void MyServiceSvIf::async_tm_putDataById(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback, int64_t p_id, std::unique_ptr<::std::string> p_data) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_putDataById(p_id, std::move(p_data));
  });
}

void MyServiceSvIf::lobDataById(int64_t /*id*/, std::unique_ptr<::std::string> /*data*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("lobDataById");
}

folly::SemiFuture<folly::Unit> MyServiceSvIf::semifuture_lobDataById(int64_t p_id, std::unique_ptr<::std::string> p_data) {
  return apache::thrift::detail::si::semifuture([&] {
    return lobDataById(p_id, std::move(p_data));
  });
}

folly::Future<folly::Unit> MyServiceSvIf::future_lobDataById(int64_t p_id, std::unique_ptr<::std::string> p_data) {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_lobDataById(p_id, std::move(p_data)), std::move(ka));
}

void MyServiceSvIf::async_tm_lobDataById(std::unique_ptr<apache::thrift::HandlerCallbackBase> callback, int64_t p_id, std::unique_ptr<::std::string> p_data) {
  apache::thrift::detail::si::async_tm_oneway(this, std::move(callback), [&] {
    return future_lobDataById(p_id, std::move(p_data));
  });
}

void MyServiceSvIf::cppDoNothing() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("doNothing");
}

folly::SemiFuture<folly::Unit> MyServiceSvIf::semifuture_cppDoNothing() {
  return apache::thrift::detail::si::semifuture([&] {
    return cppDoNothing();
  });
}

folly::Future<folly::Unit> MyServiceSvIf::future_cppDoNothing() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto pri = getRequestContext()->getRequestPriority();
  auto ka = getThreadManager()->getKeepAlive(pri, Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_cppDoNothing(), std::move(ka));
}

void MyServiceSvIf::async_tm_cppDoNothing(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_cppDoNothing();
  });
}

void MyServiceSvNull::ping() {
  return;
}

void MyServiceSvNull::getRandomData(::std::string& /*_return*/) {}

bool MyServiceSvNull::hasDataById(int64_t /*id*/) {
  return 0;
}

void MyServiceSvNull::getDataById(::std::string& /*_return*/, int64_t /*id*/) {}

void MyServiceSvNull::putDataById(int64_t /*id*/, std::unique_ptr<::std::string> /*data*/) {
  return;
}

void MyServiceSvNull::lobDataById(int64_t /*id*/, std::unique_ptr<::std::string> /*data*/) {
  return;
}

void MyServiceSvNull::cppDoNothing() {
  return;
}



const char* MyServiceAsyncProcessor::getServiceName() {
  return "MyService";
}

void MyServiceAsyncProcessor::getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) {
  ::apache::thrift::detail::md::ServiceMetadata<MyServiceSvIf>::gen(*response.metadata_ref(), *response.context_ref());
}

void MyServiceAsyncProcessor::processSerializedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(serializedRequest), protType, context, eb, tm);
}

std::shared_ptr<folly::RequestContext> MyServiceAsyncProcessor::getBaseContextForRequest() {
  return iface_->getBaseContextForRequest();
}

const MyServiceAsyncProcessor::ProcessMap& MyServiceAsyncProcessor::getBinaryProtocolProcessMap() {
  return binaryProcessMap_;
}

const MyServiceAsyncProcessor::ProcessMap MyServiceAsyncProcessor::binaryProcessMap_ {
  {"ping", &MyServiceAsyncProcessor::setUpAndProcess_ping<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"getRandomData", &MyServiceAsyncProcessor::setUpAndProcess_getRandomData<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"hasDataById", &MyServiceAsyncProcessor::setUpAndProcess_hasDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"getDataById", &MyServiceAsyncProcessor::setUpAndProcess_getDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"putDataById", &MyServiceAsyncProcessor::setUpAndProcess_putDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"lobDataById", &MyServiceAsyncProcessor::setUpAndProcess_lobDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"doNothing", &MyServiceAsyncProcessor::setUpAndProcess_cppDoNothing<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
};

const MyServiceAsyncProcessor::ProcessMap& MyServiceAsyncProcessor::getCompactProtocolProcessMap() {
  return compactProcessMap_;
}

const MyServiceAsyncProcessor::ProcessMap MyServiceAsyncProcessor::compactProcessMap_ {
  {"ping", &MyServiceAsyncProcessor::setUpAndProcess_ping<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"getRandomData", &MyServiceAsyncProcessor::setUpAndProcess_getRandomData<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"hasDataById", &MyServiceAsyncProcessor::setUpAndProcess_hasDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"getDataById", &MyServiceAsyncProcessor::setUpAndProcess_getDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"putDataById", &MyServiceAsyncProcessor::setUpAndProcess_putDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"lobDataById", &MyServiceAsyncProcessor::setUpAndProcess_lobDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"doNothing", &MyServiceAsyncProcessor::setUpAndProcess_cppDoNothing<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
};

} // cpp2
