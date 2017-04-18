cmake_minimum_required(VERSION 3.7)
project (monkeybar-and-friends)

### Debug {{{

set (DEBUG OFF)
if ("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
  set (DEBUG ON)
endif ()

### }}}
### Compile Commands {{{

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
IF ( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS ( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF ()

### }}}
### Testing {{{

if (${ENABLE_TESTING})
  enable_testing ()
endif ()

### }}}
### Options {{{

option (ENABLE_TESTING "Enable building and running tests" OFF)

### }}}
### Paths {{{

set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

### }}}
### Libraries {{{

set (LIBRARY_DIR "${CMAKE_SOURCE_DIR}/lib")
add_subdirectory ("${LIBRARY_DIR}/trie")
add_subdirectory ("${LIBRARY_DIR}/dictionary")
add_subdirectory ("${LIBRARY_DIR}/event")
add_subdirectory ("${LIBRARY_DIR}/component")
# add_subdirectory ("${LIBRARY_DIR}/window")

### }}}
### Executables {{{

set (MONKEYBAR_DIR "${CMAKE_SOURCE_DIR}/monkeybar")
add_subdirectory (${MONKEYBAR_DIR})

### }}}
