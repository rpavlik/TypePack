# Copyright (c) 2018-2019 Collabora, Ltd.
#
# SPDX-License-Identifier: BSL-1.0
cmake_minimum_required(VERSION 3.7)
project(TypePack)

include(GNUInstallDirs)

# Optional, for unit tests
find_package(Catch2 CONFIG QUIET)
find_package(Threads)

set(SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Always.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/And.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Apply.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/ApplyList.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Bool.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/CoerceList.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Compose.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Concat.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Contains.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Defer.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/FindFirst.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Fold.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/ForEachType.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/HasType.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/If.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/List.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Not.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Or.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/PushBack.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/PushFront.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Quote.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/QuoteTrait.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Size.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/SizeT.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/SplitList.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/T.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Transform.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/TypeKeyed.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/TypeKeyedMap.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/TypeKeyedTuple.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/TypePack.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/TypePack/Void.h")

add_library(TypePack-MultiFile INTERFACE)
target_include_directories(TypePack-MultiFile
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features(TypePack-MultiFile INTERFACE cxx_std_11)
target_sources(TypePack-MultiFile INTERFACE ${SOURCES})

add_library(TypePack INTERFACE)
target_sources(TypePack INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/generated/TypePack.h")
target_include_directories(TypePack
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/generated>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_features(TypePack INTERFACE cxx_std_11)

if(TARGET Catch2::Catch2)
    include(CTest)
    option(BUILD_COMBINED_HEADER_TESTING "Should the generated, combined single-header version be tested?" OFF)
    if(BUILD_TESTING)
        add_subdirectory(tests)
    endif()
endif()
