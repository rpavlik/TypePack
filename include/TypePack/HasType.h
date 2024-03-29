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
#include "Void.h"

// Library/third-party includes
// - none

// Standard includes
#include <type_traits>

namespace typepack {
/// \cond
namespace detail {
    template <typename, typename = void> struct has_type_ {
        using type = std::false_type;
    };

    template <typename T> struct has_type_<T, void_<typename T::type>> {
        using type = std::true_type;
    };

} // namespace detail
/// \endcond

/// An alias for `std::true_type` if `T::type` exists and names a type;
/// otherwise, it's an alias for `std::false_type`.
template <typename T> using has_type = t_<detail::has_type_<T>>;
} // namespace typepack
