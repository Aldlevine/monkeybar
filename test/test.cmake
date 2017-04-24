cmake_minimum_required(VERSION 3.7)
project (test_suite)

### PkgConfig {{{

find_package (PkgConfig REQUIRED)

### }}}
### Testing {{{

enable_testing ()
pkg_search_module (CHECK check)

function (add_check_test target)
  file (GLOB TEST_SOURCES "${target}.c")
  set (TEST_NAME "test_${target}")

  add_executable (${TEST_NAME} "${TEST_SOURCES}")

  target_link_libraries (${TEST_NAME} ${ARGN})
  target_link_libraries (${TEST_NAME} ${CHECK_LIBRARIES})

  set (PROJECT_LIB_DIR "../lib")
  include_directories (test_suite "./")
  include_directories (${TEST_NAME} "${PROJECT_LIB_DIR}")
  include_directories (${TEST_NAME} PUBLIC ${CHECK_INCLUDE_DIRS})

  add_test (${TEST_NAME} "${CMAKE_BINARY_DIR}/test/${TEST_NAME}")
endfunction ()

add_check_test (trie trie)
add_check_test (vector vector)
add_check_test (vector_iterator vector)

### }}}

