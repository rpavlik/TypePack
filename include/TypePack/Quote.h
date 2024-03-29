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
#include "Defer.h"
#include "T.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace typepack {

/// Turn a class template or alias template \p C into a Alias Class.
/// @todo doesn't work if used more than once in a single translation unit
/// on MSVC2013?
template <template <typename...> class C> struct quote {
    // Indirection through defer here needed to avoid Core issue 1430
    // http://open-std.org/jtc1/sc22/wg21/docs/cwg_active.html#1430
    template <typename... Ts> using apply = t_<defer<C, Ts...>>;
};

} // namespace typepack
