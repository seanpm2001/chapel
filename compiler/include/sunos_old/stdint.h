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

#ifndef _SUN_STDINT_H_
#define _SUN_STDINT_H_

// The existence of this file is a stupid hack because our Suns don't
// seem to support stdint.h

#include <inttypes.h>

//
// our Suns don't define these macros, so we'll do it here, even
// though it would be more appropriate in inttypes.h
//

#ifndef SCNd8
#define SCNd8 "hhd"
#endif

#ifndef SCNu8
#define SCNu8 "hhu"
#endif

#endif
