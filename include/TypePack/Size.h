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
#include "CoerceList.h"
#include "SizeT.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace typepack {
namespace detail {
    template <typename... Ts> struct size;

    // The following fails with clang due to a bug.
    // <https://llvm.org/bugs/show_bug.cgi?id=14858>
    // template <typename... Ts> using size_impl =
    // size_t_<sizeof...(Ts)>;
    // template <typename... Ts>
    // struct size<list<Ts...>> : size_impl<Ts...> {};
    template <typename... Ts>
    struct size<list<Ts...>> : size_t_<sizeof...(Ts)> {};
} // namespace detail

/// @brief Get the size of a list (number of elements.)
template <typename... Ts> using size = detail::size<coerce_list<Ts...>>;

} // namespace typepack
