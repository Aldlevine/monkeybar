cmake_minimum_required(VERSION 3.7)
project (dictionary)

### Include {{{

set (PROJECT_INCLUDE_DIR "include")
include_directories (dictionary ${PROJECT_INCLUDE_DIR})

### }}}
### Sources {{{

file (GLOB SOURCES "src/*.c")
add_library (dictionary ${SOURCES})

### }}}
### Libraries {{{

target_link_libraries (dictionary trie)

### }}}
### PkgConfig {{{

# find_package (PkgConfig REQUIRED)

### }}}
### Testing {{{

# if (${ENABLE_TESTING})
  # enable_testing ()
  # set (PROJECT_TEST_DIR "test")
  # file (GLOB TEST_SOURCES "test/*.c")
  # add_executable (check_dictionary ${TEST_SOURCES})

  # target_link_libraries (check_dictionary dictionary)

  # pkg_search_module (CHECK check)
  # target_link_libraries (check_dictionary ${CHECK_LIBRARIES})
  # include_directories (check_dictionary PUBLIC ${CHECK_INCLUDE_DIRS})

  # add_test (check_dictionary "${CMAKE_BINARY_DIR}/bin/check_dictionary")
# endif ()

### }}}
