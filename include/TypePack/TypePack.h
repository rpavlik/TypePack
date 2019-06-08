/** @file
    @brief Header including all of a simple C++11 template-parameter-pack-based
   metaprogramming library inspired by/based on Eric Niebler's `meta`

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
// Copyright 2015 Sensics, Inc.
//
// SPDX-License-Identifier: BSL-1.0
//
// TypePack was originally developed as part of OSVR-Core.
//
// Some files in this library incorporate code from "meta":
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

/// @brief A simple argument-pack-based metaprogramming library, inspired by
/// and based partially on https://ericniebler.github.io/meta
///
/// It includes an as-needed subset of the features of meta, modified as needed
/// to build on MSVC 2013, as well as additional functionality not found in
/// meta.
namespace typepack {
// NOTE: Everything in this file up through the preceding line
// will be included, in perhaps slightly-modified form,
// in the combined headers generated from this library.

} // namespace typepack

// Full-include list simply generated as follows. (Yes, topological sort would
// be preferred, I think.)
// $ ls *.h | grep -v TypePack.h | sort | sed -e 's/^/#include "/' -e 's/$/"/'

#include "Always.h"
#include "And.h"
#include "Apply.h"
#include "ApplyList.h"
#include "Bool.h"
#include "CoerceList.h"
#include "Compose.h"
#include "Concat.h"
#include "Contains.h"
#include "Defer.h"
#include "FindFirst.h"
#include "Fold.h"
#include "ForEachType.h"
#include "HasType.h"
#include "If.h"
#include "List.h"
#include "Not.h"
#include "Or.h"
#include "PushBack.h"
#include "PushFront.h"
#include "Quote.h"
#include "QuoteTrait.h"
#include "Size.h"
#include "SizeT.h"
#include "SplitList.h"
#include "T.h"
#include "Transform.h"
#include "TypeKeyed.h"
#include "TypeKeyedMap.h"
#include "TypeKeyedTuple.h"
#include "Void.h"
