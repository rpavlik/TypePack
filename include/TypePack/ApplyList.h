/** @file
    @brief Header

    @date 2015-2019

    @author
    Ryan Pavlik
    <ryan.pavlik@collabora.com>

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>

    @author
    Eric Niebler
*/

// Copyright 2019 Collabora, Ltd.
// Copyright 2015-2017 Sensics, Inc.
//
// SPDX-License-Identifier: BSL-1.0
//
// TypePack was originally developed as part of OSVR-Core.
//
// This file incorporates code from "meta":
// Copyright Eric Niebler 2014-2015
//
// Use, modification and distribution is subject to the
// Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/ericniebler/meta
//

#pragma once

// Internal Includes
#include "Apply.h"
#include "List.h"
#include "T.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace typepack {
namespace detail {
    /// General/dummy case.
    template <typename F, typename List> struct apply_list_;
    template <typename F, typename... Args>
    struct apply_list_<F, list<Args...>> {
        // the simpler solution doesn't build with MSVC 2013
        template <typename...> using apply = typepack::apply<F, Args...>;
    };
} // namespace detail

/// Apply an alias class, exploding the list of args
template <typename F, typename Args>
using apply_list = apply<detail::apply_list_<F, Args>>;
} // namespace typepack
