/** @file
    @brief Header with run-time extensions to the TypePack simple
    template-parameter-pack-based metaprogramming library

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
#include "Contains.h"
#include "Size.h"
#include "TypeKeyed.h"

// Library/third-party includes
// - none

// Standard includes
#include <array>

namespace typepack {
/// @brief A class that uses types as an index into a container with
/// uniform-typed contents, somewhat like a map except all elements are
/// default-constructed rather than having an optional "not set" status.
/// (You may emulate this by providing a specialization of
/// boost::optional<> as your value type.)
///
/// Values can be accessed just as all other type-keyed containers.
///
/// Runtime performance of element access is constant (equal to array
/// element access with a constant index)
template <typename KeyList, typename ValueType>
class TypeKeyedMap : public TypeKeyedBase<TypeKeyedMap<KeyList, ValueType>> {
    using size_constant = size<KeyList>;

  public:
    using key_types = KeyList;
    using value_type = ValueType;

  private:
    template <typename, typename> friend struct typekeyed_detail::ValueAccessor;
    using container_type = std::array<value_type, size_constant::value>;
    /// Internal method/implementation detail, do not use in consuming code!
    container_type &nested_container() { return container_; }
    /// Internal method/implementation detail, do not use in consuming code!
    container_type const &nested_container() const { return container_; }

  private:
    container_type container_;
};

// Required traits
namespace typekeyed_detail {
    template <typename KeyList, typename ValueType, typename Key>
    struct ValueTypeAtKeyTraits<TypeKeyedMap<KeyList, ValueType>, Key> {
        using type = ValueType;
    };

} // namespace typekeyed_detail
} // namespace typepack
