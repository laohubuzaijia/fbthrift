/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/sink/gen-cpp2/SinkService.h"
#include "thrift/compiler/test/fixtures/sink/gen-cpp2/SinkService.tcc"
#include "thrift/compiler/test/fixtures/sink/gen-cpp2/module_metadata.h"
#include <thrift/lib/cpp2/gen/service_cpp.h>

namespace cpp2 {
std::unique_ptr<apache::thrift::AsyncProcessor> SinkServiceSvIf::getProcessor() {
  return std::make_unique<SinkServiceAsyncProcessor>(this);
}


::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvIf::method() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("method");
}

folly::SemiFuture<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::semifuture_method() {
  return apache::thrift::detail::si::semifuture([&] {
    return method();
  });
}

folly::Future<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::future_method() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto scope = getRequestContext()->getRequestExecutionScope();
  auto ka = getThreadManager()->getKeepAlive(std::move(scope), Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_method(), std::move(ka));
}

void SinkServiceSvIf::async_tm_method(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_method();
  });
}

::apache::thrift::ResponseAndSinkConsumer<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvIf::methodAndReponse() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodAndReponse");
}

folly::SemiFuture<::apache::thrift::ResponseAndSinkConsumer<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::semifuture_methodAndReponse() {
  return apache::thrift::detail::si::semifuture([&] {
    return methodAndReponse();
  });
}

folly::Future<::apache::thrift::ResponseAndSinkConsumer<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::future_methodAndReponse() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto scope = getRequestContext()->getRequestExecutionScope();
  auto ka = getThreadManager()->getKeepAlive(std::move(scope), Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodAndReponse(), std::move(ka));
}

void SinkServiceSvIf::async_tm_methodAndReponse(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ResponseAndSinkConsumer<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodAndReponse();
  });
}

::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvIf::methodThrow() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodThrow");
}

folly::SemiFuture<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::semifuture_methodThrow() {
  return apache::thrift::detail::si::semifuture([&] {
    return methodThrow();
  });
}

folly::Future<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::future_methodThrow() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto scope = getRequestContext()->getRequestExecutionScope();
  auto ka = getThreadManager()->getKeepAlive(std::move(scope), Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodThrow(), std::move(ka));
}

void SinkServiceSvIf::async_tm_methodThrow(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodThrow();
  });
}

::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvIf::methodSinkThrow() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodSinkThrow");
}

folly::SemiFuture<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::semifuture_methodSinkThrow() {
  return apache::thrift::detail::si::semifuture([&] {
    return methodSinkThrow();
  });
}

folly::Future<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::future_methodSinkThrow() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto scope = getRequestContext()->getRequestExecutionScope();
  auto ka = getThreadManager()->getKeepAlive(std::move(scope), Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodSinkThrow(), std::move(ka));
}

void SinkServiceSvIf::async_tm_methodSinkThrow(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodSinkThrow();
  });
}

::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvIf::methodFinalThrow() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodFinalThrow");
}

folly::SemiFuture<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::semifuture_methodFinalThrow() {
  return apache::thrift::detail::si::semifuture([&] {
    return methodFinalThrow();
  });
}

folly::Future<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::future_methodFinalThrow() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto scope = getRequestContext()->getRequestExecutionScope();
  auto ka = getThreadManager()->getKeepAlive(std::move(scope), Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodFinalThrow(), std::move(ka));
}

void SinkServiceSvIf::async_tm_methodFinalThrow(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodFinalThrow();
  });
}

::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvIf::methodBothThrow() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodBothThrow");
}

folly::SemiFuture<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::semifuture_methodBothThrow() {
  return apache::thrift::detail::si::semifuture([&] {
    return methodBothThrow();
  });
}

folly::Future<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>> SinkServiceSvIf::future_methodBothThrow() {
  using Source = apache::thrift::concurrency::ThreadManager::Source;
  auto scope = getRequestContext()->getRequestExecutionScope();
  auto ka = getThreadManager()->getKeepAlive(std::move(scope), Source::INTERNAL);
  return apache::thrift::detail::si::future(semifuture_methodBothThrow(), std::move(ka));
}

void SinkServiceSvIf::async_tm_methodBothThrow(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_methodBothThrow();
  });
}

void SinkServiceSvIf::async_eb_methodFast(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) {
  callback->exception(apache::thrift::TApplicationException("Function methodFast is unimplemented"));
}

::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvNull::method() {
  return {};
}

::apache::thrift::ResponseAndSinkConsumer<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvNull::methodAndReponse() {
  return {};
}

::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvNull::methodThrow() {
  return {};
}

::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvNull::methodSinkThrow() {
  return {};
}

::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvNull::methodFinalThrow() {
  return {};
}

::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse> SinkServiceSvNull::methodBothThrow() {
  return {};
}



const char* SinkServiceAsyncProcessor::getServiceName() {
  return "SinkService";
}

void SinkServiceAsyncProcessor::getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) {
  ::apache::thrift::detail::md::ServiceMetadata<SinkServiceSvIf>::gen(*response.metadata_ref(), *response.context_ref());
}

void SinkServiceAsyncProcessor::processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(serializedRequest), protType, context, eb, tm);
}

std::shared_ptr<folly::RequestContext> SinkServiceAsyncProcessor::getBaseContextForRequest() {
  return iface_->getBaseContextForRequest();
}

const SinkServiceAsyncProcessor::ProcessMap& SinkServiceAsyncProcessor::getBinaryProtocolProcessMap() {
  return binaryProcessMap_;
}

const SinkServiceAsyncProcessor::ProcessMap SinkServiceAsyncProcessor::binaryProcessMap_ {
  {"method", &SinkServiceAsyncProcessor::setUpAndProcess_method<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodAndReponse", &SinkServiceAsyncProcessor::setUpAndProcess_methodAndReponse<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodThrow", &SinkServiceAsyncProcessor::setUpAndProcess_methodThrow<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodSinkThrow", &SinkServiceAsyncProcessor::setUpAndProcess_methodSinkThrow<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodFinalThrow", &SinkServiceAsyncProcessor::setUpAndProcess_methodFinalThrow<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodBothThrow", &SinkServiceAsyncProcessor::setUpAndProcess_methodBothThrow<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodFast", &SinkServiceAsyncProcessor::setUpAndProcess_methodFast<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
};

const SinkServiceAsyncProcessor::ProcessMap& SinkServiceAsyncProcessor::getCompactProtocolProcessMap() {
  return compactProcessMap_;
}

const SinkServiceAsyncProcessor::ProcessMap SinkServiceAsyncProcessor::compactProcessMap_ {
  {"method", &SinkServiceAsyncProcessor::setUpAndProcess_method<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodAndReponse", &SinkServiceAsyncProcessor::setUpAndProcess_methodAndReponse<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodThrow", &SinkServiceAsyncProcessor::setUpAndProcess_methodThrow<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodSinkThrow", &SinkServiceAsyncProcessor::setUpAndProcess_methodSinkThrow<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodFinalThrow", &SinkServiceAsyncProcessor::setUpAndProcess_methodFinalThrow<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodBothThrow", &SinkServiceAsyncProcessor::setUpAndProcess_methodBothThrow<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodFast", &SinkServiceAsyncProcessor::setUpAndProcess_methodFast<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
};

} // cpp2
