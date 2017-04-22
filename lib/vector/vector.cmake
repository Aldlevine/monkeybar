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

find_package (PkgConfig REQUIRED)

### }}}
### Testing {{{

if (${ENABLE_TESTING})
  enable_testing ()
  set (PROJECT_TEST_DIR "test")
  pkg_search_module (CHECK check)

  file (GLOB TEST_SOURCES "test/check_vector.c")
  add_executable (check_vector ${TEST_SOURCES})
  target_link_libraries (check_vector vector)
  target_link_libraries (check_vector ${CHECK_LIBRARIES})
  include_directories (check_vector PUBLIC ${CHECK_INCLUDE_DIRS})
  add_test (check_vector "${CMAKE_BINARY_DIR}/bin/check_vector")

  file (GLOB TEST_SOURCES "test/check_vector_iterator.c")
  add_executable (check_vector_iterator ${TEST_SOURCES})
  target_link_libraries (check_vector_iterator vector)
  target_link_libraries (check_vector_iterator ${CHECK_LIBRARIES})
  include_directories (check_vector_iterator PUBLIC ${CHECK_INCLUDE_DIRS})
  add_test (check_vector_iterator "${CMAKE_BINARY_DIR}/bin/check_vector_iterator")
endif ()

### }}}
