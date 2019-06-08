#!/bin/sh
# Copyright 2019, Collabora, Ltd.
# SPDX-License-Identifier: BSL-1.0
(
    cd $(dirname $0) && \
    find include tests generated \
      \( -name "*.cpp" -o -name "*.h" \) \
      -exec clang-format -i -style=file \{\} +
)
