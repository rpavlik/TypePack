# Copyright (c) 2019 Collabora, Ltd.
#
# SPDX-License-Identifier: BSL-1.0

add_library(tp-catch STATIC Main.cpp)
target_link_libraries(tp-catch PUBLIC Catch2::Catch2)

foreach(testname
    Apply
    BasicListStructure
    BooleanAnd
    BooleanOr
    Contains
    Fold
    IfExpressions
    Push
    SplitList)
    add_executable(TypePack-${testname} ${testname}.cpp)
    target_link_libraries(TypePack-${testname} TypePack-MultiFile tp-catch)
    if(BUILD_COMBINED_HEADER_TESTING)
        add_executable(TypePack-combined-${testname} ${testname}.cpp)
        target_link_libraries(TypePack-combined-${testname} TypePack tp-catch)
        target_compile_definitions(TypePack-combined-${testname} PRIVATE USE_SINGLE_HEADER)
    endif()
endforeach()
