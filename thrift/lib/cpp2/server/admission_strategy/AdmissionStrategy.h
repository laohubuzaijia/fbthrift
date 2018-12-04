/*
 * Copyright 2018-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <memory>

#include <thrift/lib/cpp2/async/ResponseChannel.h>
#include <thrift/lib/cpp2/server/AdmissionController.h>

namespace apache {
namespace thrift {

class BaseThriftServer;

class AdmissionStrategy {
 public:
  enum Type { ACCEPT_ALL = 0, GLOBAL = 1, PER_CLIENT_ID = 2, PRIORITY = 3 };

  using MetricReportFn =
      folly::Function<void(const std::string&, double) const>;

  virtual ~AdmissionStrategy() {}

  /**
   * Select an AdmissionController to be used for this specific request
   */
  virtual std::shared_ptr<AdmissionController> select(
      const ResponseChannelRequest& request,
      const Cpp2ConnContext& connContext) = 0;

  virtual void reportMetrics(
      const MetricReportFn&,
      const std::string& prefix) = 0;

  virtual Type getType() = 0;

 protected:
  static constexpr const char* kWildcard = "*";
};

} // namespace thrift
} // namespace apache
