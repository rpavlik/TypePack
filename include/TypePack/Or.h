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
#include "If.h"

// Library/third-party includes
// - none

// Standard includes
#include <type_traits>

namespace typepack {

/// \cond
namespace detail {
    template <typename... Bools> struct or_impl;

    template <> struct or_impl<> : std::false_type {};

    template <typename Bool, typename... Bools>
    struct or_impl<Bool, Bools...>
        : if_c<Bool::type::value, std::true_type, or_impl<Bools...>> {};
} // namespace detail
/// \endcond

/// Logically or together all the integral constant-wrapped Boolean
/// parameters, \e with short-circuiting.
template <typename... Bools> using or_ = t_<detail::or_impl<Bools...>>;

} // namespace typepack
