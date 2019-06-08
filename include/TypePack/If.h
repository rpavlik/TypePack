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
#include "Bool.h"
#include "T.h"

// Library/third-party includes
// - none

// Standard includes
#include <type_traits>

namespace typepack {
/// \cond
namespace detail {
    template <typename...> struct if_impl {};

    template <typename If>
    struct if_impl<If> : std::enable_if<If::type::value> {};

    template <typename If, typename Then>
    struct if_impl<If, Then> : std::enable_if<If::type::value, Then> {};

    template <typename If, typename Then, typename Else>
    struct if_impl<If, Then, Else>
        : std::conditional<If::type::value, Then, Else> {};
} // namespace detail
/// \endcond

/// Select one type or another depending on a compile-time Boolean integral
/// constant type.
template <typename... Args> using if_ = t_<detail::if_impl<Args...>>;

/// Select one type or another depending on a compile-time Boolean value.
template <bool If, typename... Args>
using if_c = t_<detail::if_impl<bool_<If>, Args...>>;
} // namespace typepack
