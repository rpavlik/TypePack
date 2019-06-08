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
#include "T.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace typepack {

/// @brief A Alias Class that always returns \p T.
template <typename T> struct always {
  private:
    // Redirect through a class template for compilers that have not
    // yet implemented CWG 1558:
    // <http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_defects.html#1558>
    template <typename...> struct impl { using type = T; };

  public:
    template <typename... Ts> using apply = t_<impl<Ts...>>;
};
} // namespace typepack
