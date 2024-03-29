/** @file
    @brief Header

    @date 2015-2019

    @author
    Ryan Pavlik
    <ryan.pavlik@collabora.com>

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>
*/

// Copyright 2019 Collabora, Ltd.
// Copyright 2015-2017 Sensics, Inc.
//
// SPDX-License-Identifier: BSL-1.0
//
// TypePack was originally developed as part of OSVR-Core.
//
// Use, modification and distribution is subject to the
// Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

// Internal Includes
#include "Apply.h"
#include "List.h"
#include "SplitList.h"
#include "T.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace typepack {

namespace detail {
    // Fold: Forward declaration of general form
    template <typename List, typename State, typename Fun> struct fold_;

    // Fold: Recurse
    template <typename List, typename State, typename Fun>
    struct fold_ : fold_<tail<List>, t_<apply<Fun, State, head<List>>>, Fun> {};

    // Fold: base case
    template <typename State, typename Fun> struct fold_<list<>, State, Fun> {
        using type = State;
    };

} // namespace detail

/// @brief Fold the list (right) with the given alias class and initial
/// state.
template <typename List, typename State, typename Fun>
using fold = t_<detail::fold_<List, State, Fun>>;

} // namespace typepack
