cmake_minimum_required(VERSION 2.8)
project (Monkeybar)


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
    "${CMAKE_SOURCE_DIR}/include/config.h.in"
    "${CMAKE_BINARY_DIR}/config.h"
    )

  # Options
  # option (MONKEYBAR_IS_AWESOME "Lets the user know that monkeybar is awesome" ON)
# }}} Configuration


# Includes {{{
  include_directories ("${CMAKE_SOURCE_DIR}/include")
  include_directories (${CMAKE_BINARY_DIR})
# }}} Includes


# Executable {{{
  file (GLOB SOURCES "src/*.c")
  add_executable (monkeybar ${SOURCES})
# }}} Executable


# compile_commands.json {{{
  set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
  if ( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
    execute_process ( COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
  endif ()
# }}} compile_commands.json
