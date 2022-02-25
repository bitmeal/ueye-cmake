# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at https://mozilla.org/MPL/2.0/.
# 
# Copyright (C) 2022, Arne Wendt
#


cmake_minimum_required(VERSION 3.12.0)
project(ueye-cmake-test)

## configure/setup
# make CMake find our find-script
get_filename_component(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)
set (CMAKE_MODULE_PATH ${PROJECT_ROOT})

# find SDK with or without specific version
if(DEFINED SDK-VERSION)
    find_package( uEye-SDK ${SDK-VERSION} REQUIRED )
else()
    find_package( uEye-SDK REQUIRED )
endif()


## build
add_executable( test-version test.cpp )
target_link_libraries( test-version uEye-SDK )


## testing
enable_testing()

# test by comparing library version
message(STATUS "using uEye-SDK version: ${uEye-SDK_VERSION}")
string(REGEX MATCH "[0-9]+\\.[0-9]+" uEye-SDK_VERSION_MAJOR_MINOR "${uEye-SDK_VERSION}")
message(STATUS "using uEye-SDK <major>.<minor> for comparison: ${uEye-SDK_VERSION_MAJOR_MINOR}")
string(REPLACE "." "\\." uEye-SDK_VERSION_MAJOR_MINOR_REGEX "${uEye-SDK_VERSION_MAJOR_MINOR}")

add_test(NAME test-version COMMAND test-version)
set_property(TEST test-version PROPERTY PASS_REGULAR_EXPRESSION "${uEye-SDK_VERSION_MAJOR_MINOR_REGEX}")