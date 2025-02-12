/*
 * Copyright 2020-2022 Hewlett Packard Enterprise Development LP
 * Copyright 2004-2019 Cray Inc.
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

#include <string>

extern const char* yychpl_get_text(yyscan_t scanner);

void yychpl_error(YYLTYPE*       loc,
                  ParserContext* context,
                  const char*    errorMessage) {
  std::string msg;
  bool isEmptyOrDefaultError = !strcmp("syntax error", errorMessage) ||
                               !strlen(errorMessage);

  // If Bison reported a generic "syntax error", leave message empty.
  if (isEmptyOrDefaultError) {
    const char* tokenText = yychpl_get_text(context->scanner);

    // But append info about nearest token.
    if (strlen(tokenText) > 0) {
      msg += "near '";
      msg += tokenText;
      msg += "'";
    }

  // TODO: Also print nearest token?
  } else {
    msg = errorMessage;
  }

  auto err = ParserError(*loc, msg, ErrorMessage::SYNTAX);
  context->noteSyntaxError(std::move(err));
}

