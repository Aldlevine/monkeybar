cmake_minimum_required(VERSION 2.8)
project (MONKEYBAR)


# Version {{{
  set (MONKEYBAR_VERSION_MAJOR 0)
  set (MONKEYBAR_VERSION_MINOR 0)
  set (MONKEYBAR_VERSION_PATCH 0)
# }}} Version


# Directory setup {{{
  set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
  set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
  set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
# }}} Directory setup


# Configuration {{{
  configure_file (
    "${CMAKE_SOURCE_DIR}/config.h.in"
    "${CMAKE_BINARY_DIR}/config.h"
    )

  # Options
  option (DEBUG "Builds for debug" OFF)
  option (DISABLE_LOG "Disables logging (I also like to live dangerously)" OFF)
# }}} Configuration


# Build {{{
  # include
  include_directories ("${CMAKE_SOURCE_DIR}/include")
  include_directories (${CMAKE_BINARY_DIR})

  # source
  file (GLOB SOURCES "src/*.c")

  # executable
  add_executable (monkeybar ${SOURCES})

  # system pkgs
  find_package (PkgConfig REQUIRED)
  pkg_search_module (XCB REQUIRED xcb)
  target_link_libraries (monkeybar ${XCB_LIBRARIES})
  target_include_directories (monkeybar PUBLIC ${XCB_INCLUDE_DIRS})
# }}} Build


# compile_commands.json {{{
  set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
  if ( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
    execute_process ( COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
  endif ()
# }}} compile_commands.json
