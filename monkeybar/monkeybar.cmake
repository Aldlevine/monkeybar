cmake_minimum_required(VERSION 3.7)
project (monkeybar)

### Version {{{

set (MONKEYBAR_VERSION_MAJOR 0)
set (MONKEYBAR_VERSION_MINOR 0)
set (MONKEYBAR_VERSION_PATCH 0)

### }}}
### Include {{{

set (PROJECT_INCLUDE_DIR "include")
include_directories (monkeybar ${PROJECT_INCLUDE_DIR})
set (PROJECT_LIB_DIR "../lib")
include_directories (monkeybar "${PROJECT_LIB_DIR}")

### }}}
### Sources {{{

file (GLOB SOURCES "src/*.c")
add_executable (monkeybar ${SOURCES})

### }}}
### Libraries {{{

# include_directories (monkeybar "${PROJECT_LIB_DIR}/trie/include")
target_link_libraries (monkeybar trie)
# include_directories (monkeybar "${PROJECT_LIB_DIR}/dictionary/include")
target_link_libraries (monkeybar dictionary)
# include_directories (monkeybar "${PROJECT_LIB_DIR}/event/include")
target_link_libraries (monkeybar event)
# include_directories (monkeybar "${PROJECT_LIB_DIR}/component/include")
target_link_libraries (monkeybar component)

### }}}
### Config {{{

include_directories (${CMAKE_BINARY_DIR})
configure_file (
  "${PROJECT_INCLUDE_DIR}/config.h.in"
  "${CMAKE_BINARY_DIR}/config.h"
  )
option (ENABLE_LOG "Disables logging (I also like to live dangerously)" ON)

### }}}
### PkgConfig {{{

find_package (PkgConfig REQUIRED)

### }}}
### XCB {{{

pkg_search_module (XCB REQUIRED xcb)
target_link_libraries (monkeybar ${XCB_LIBRARIES})
target_include_directories (monkeybar PUBLIC ${XCB_INCLUDE_DIRS})

### }}}
