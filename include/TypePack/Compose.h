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

// Library/third-party includes
// - none

// Standard includes
// - none

namespace typepack {

/// Compose the Alias Classes \p Fs in the parameter pack \p Ts.
template <typename... Fs> struct compose {};

template <typename F0> struct compose<F0> {
    template <typename... Ts> using apply = typepack::apply<F0, Ts...>;
};

template <typename F0, typename... Fs> struct compose<F0, Fs...> {
    template <typename... Ts>
    using apply = typepack::apply<F0, typepack::apply<compose<Fs...>, Ts...>>;
};
} // namespace typepack
