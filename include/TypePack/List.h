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
// - none

// Library/third-party includes
// - none

// Standard includes
// - none

namespace typepack {

namespace detail {
    struct list_base_ {};
} // namespace detail

/// @brief A wrapper for a template parameter pack of types.
///
/// Note that passing a single list<...> as the parameter to list<> will not
/// change the type (doesn't nest the lists), so this is safe. If you need
/// to ensure some argument is just a list, see typepack::coerce_list.
template <typename... Ts> struct list : detail::list_base_ {
    using type = list;
};
template <typename... Ts> struct list<list<Ts...>> : list<Ts...>::type {};

} // namespace typepack
