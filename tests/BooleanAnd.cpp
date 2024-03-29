/** @file
    @brief Test Implementation

    @date 2015

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>

*/

// Copyright 2015 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Internal Includes
#include "TypePackTestShared.h"

#ifndef USE_SINGLE_HEADER
#include <TypePack/And.h>
#include <TypePack/Bool.h>
#endif // !USE_SINGLE_HEADER

// Yes, I know these are all static (compile-time) tests, but using the Catch2
// structure to split them into logical units.

TEST_CASE("TypePack-booleanAnd") {
    /// empty list - defined to be true
    static_assert(tp::and_<>::value == true, "Empty list");

    /// one argument
    static_assert(tp::and_<tp::bool_<true>>::value == true, "Single true");
    static_assert(tp::and_<tp::bool_<false>>::value == false, "Single false");

    /// two arguments
    static_assert(tp::and_<tp::bool_<true>, tp::bool_<true>>::value == true,
                  "Two true");
    static_assert(tp::and_<tp::bool_<false>, tp::bool_<false>>::value == false,
                  "Two false");

    static_assert(tp::and_<tp::bool_<false>, tp::bool_<true>>::value == false,
                  "1 true 1 false");
    static_assert(tp::and_<tp::bool_<true>, tp::bool_<false>>::value == false,
                  "1 true 1 false");

    /// three arguments
    static_assert(tp::and_<true_type, true_type, true_type>::value == true,
                  "Three true");
    static_assert(tp::and_<false_type, false_type, false_type>::value == false,
                  "Three false");

    static_assert(tp::and_<false_type, true_type, true_type>::value == false,
                  "2 true 1 false");
    static_assert(tp::and_<true_type, false_type, true_type>::value == false,
                  "2 true 1 false");
    static_assert(tp::and_<true_type, true_type, false_type>::value == false,
                  "2 true 1 false");

    static_assert(tp::and_<true_type, false_type, false_type>::value == false,
                  "1 true 2 false");
    static_assert(tp::and_<false_type, true_type, false_type>::value == false,
                  "1 true 2 false");
    static_assert(tp::and_<false_type, false_type, true_type>::value == false,
                  "1 true 2 false");
}
