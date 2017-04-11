cmake_minimum_required(VERSION 3.7)
project (component)

### Include {{{

set (PROJECT_INCLUDE_DIR "include")
include_directories (component ${PROJECT_INCLUDE_DIR})

### }}}
### Sources {{{

file (GLOB SOURCES "src/*.c")
add_library (component ${SOURCES})

### }}}
### Libraries {{{

target_link_libraries (component trie)

### }}}
### PkgConfig {{{

# find_package (PkgConfig REQUIRED)

### }}}
### Testing {{{

# if (${ENABLE_TESTING})
  # enable_testing ()
  # set (PROJECT_TEST_DIR "test")
  # file (GLOB TEST_SOURCES "test/*.c")
  # add_executable (check_component ${TEST_SOURCES})

  # target_link_libraries (check_component component)

  # pkg_search_module (CHECK check)
  # target_link_libraries (check_component ${CHECK_LIBRARIES})
  # include_directories (check_component PUBLIC ${CHECK_INCLUDE_DIRS})

  # add_test (check_component "${CMAKE_BINARY_DIR}/bin/check_component")
# endif ()

### }}}
