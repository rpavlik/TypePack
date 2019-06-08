/** @file
    @brief Header

    @date 2015

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>
*/

// Copyright 2019 Collabora, Ltd
// Copyright 2015 Sensics, Inc.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

// Internal Includes
#ifdef USE_SINGLE_HEADER
#include <TypePack.h>
#else
#include <TypePack/CoerceList.h>
#include <TypePack/List.h>
#endif

// Library/third-party includes
#include <catch2/catch.hpp>

// Standard includes
#include <stdint.h>
#include <string>
#include <type_traits>

using std::false_type;
using std::is_same;
using std::true_type;
namespace tp = typepack;

// THIS SECTION MUST BE MANUALLY KEPT IN-SYNC!
using myhead = uint32_t;
using myelt1 = myhead;
using myelt2 = int16_t;
using myelt3 = bool;
using mytail = tp::list<myelt2, myelt3>;
using myhead2 = tp::list<myelt1, myelt2>;
using mylist = tp::list<myelt1, myelt2, myelt3>;

static const size_t mylist_len = 3;
static_assert(is_same<mylist, tp::coerce_list<myelt1, myelt2, myelt3>>::value,
              "Coerce list from type pack");
// END MANUAL SYNC
