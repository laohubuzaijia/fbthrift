/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/compiler/ast/t_typedef.h>

#include <thrift/compiler/ast/t_program.h>

namespace apache {
namespace thrift {
namespace compiler {

bool t_typedef::resolve_placeholder() {
  assert(type_.get_type() == nullptr);
  assert(!defined_);
  type_.set_type(scope_->get_type(get_program()->name() + "." + symbolic_));
  return type_.get_type() != nullptr;
}

const std::string* t_typedef::get_first_annotation_or_null(
    const t_type* type, alias_span name) {
  const std::string* result = nullptr;
  find_type_if(type, [&result, name](const t_type* type) {
    return (result = type->get_annotation_or_null(name)) != nullptr;
  });
  return result;
}

} // namespace compiler
} // namespace thrift
} // namespace apache
