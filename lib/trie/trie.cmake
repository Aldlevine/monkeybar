cmake_minimum_required(VERSION 3.7)
project (trie)

### Include {{{

set (PROJECT_LIB_DIR "../lib")
include_directories (trie "${PROJECT_LIB_DIR}")
set (PROJECT_INCLUDE_DIR "include")
include_directories (trie "${PROJECT_INCLUDE_DIR}")

### }}}
### Sources {{{

file (GLOB SOURCES "src/*.c")
add_library (trie ${SOURCES})

### }}}
### Libraries {{{

### }}}
### PkgConfig {{{

find_package (PkgConfig REQUIRED)

### }}}
### Testing {{{

if (${ENABLE_TESTING})
  enable_testing ()
  set (PROJECT_TEST_DIR "test")
  file (GLOB TEST_SOURCES "test/*.c")
  add_executable (check_trie ${TEST_SOURCES})

  target_link_libraries (check_trie trie)

  pkg_search_module (CHECK check)
  target_link_libraries (check_trie ${CHECK_LIBRARIES})
  include_directories (check_trie PUBLIC ${CHECK_INCLUDE_DIRS})

  add_test (check_trie "${CMAKE_BINARY_DIR}/bin/check_trie")
endif ()

### }}}
