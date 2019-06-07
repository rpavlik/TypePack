#!/bin/sh
# Copyright 2019, Collabora, Ltd.
# SPDX-License-Identifier: BSL-1.0
(
    dirs="include"
    cd $(dirname $0) && \
    find $dirs \
      \( -name "*.cpp" -o -name "*.h" \) \
      -exec clang-format -i -style=file \{\} +
)
