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
#include "ApplyList.h"
#include "List.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace typepack {
namespace detail {
    template <typename T> struct push_front_impl {
        template <typename... Ts> using apply = list<T, Ts...>;
    };
} // namespace detail

template <typename List, typename T>
using push_front = apply_list<detail::push_front_impl<T>, List>;
} // namespace typepack
