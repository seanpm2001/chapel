/*
 * Copyright 2021-2022 Hewlett Packard Enterprise Development LP
 * Other additional copyright holders may be indicated within.
 *
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 *
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

#include "chpl/uast/New.h"
#include "chpl/uast/Builder.h"

namespace chpl {
namespace uast {


const char* New::managementToString(New::Management management) {
  switch (management) {
    case DEFAULT_MANAGEMENT: return ""; // TODO: "default"?
    case OWNED: return "owned";
    case SHARED: return "shared";
    case BORROWED: return "borrowed";
    case UNMANAGED: return "unmanaged";
    default: break;
  }

  assert(false && "Should not reach here");
  return nullptr;
}

owned<New> New::build(Builder* builder,
                      Location loc,
                      owned<AstNode> typeExpression,
                      New::Management management) {
  AstList lst;

  lst.push_back(std::move(typeExpression));

  New* ret = new New(std::move(lst), management);
  builder->noteLocation(ret, loc);
  return toOwned(ret);
}


} // namespace uast
} // namespace chpl
