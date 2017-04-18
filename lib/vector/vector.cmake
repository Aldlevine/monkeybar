cmake_minimum_required(VERSION 3.7)
project (vector)

### Include {{{

set (PROJECT_INCLUDE_DIR "include")
include_directories (vector ${PROJECT_INCLUDE_DIR})

### }}}
### Sources {{{

file (GLOB SOURCES "src/*.c")
add_library (vector ${SOURCES})

### }}}
### Libraries {{{

### }}}
### PkgConfig {{{

# find_package (PkgConfig REQUIRED)

### }}}
### Testing {{{

# if (${ENABLE_TESTING})
  # enable_testing ()
  # set (PROJECT_TEST_DIR "test")
  # file (GLOB TEST_SOURCES "test/*.c")
  # add_executable (check_vector ${TEST_SOURCES})

  # target_link_libraries (check_vector vector)

  # pkg_search_module (CHECK check)
  # target_link_libraries (check_vector ${CHECK_LIBRARIES})
  # include_directories (check_vector PUBLIC ${CHECK_INCLUDE_DIRS})

  # add_test (check_vector "${CMAKE_BINARY_DIR}/bin/check_vector")
# endif ()

### }}}
