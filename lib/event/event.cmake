cmake_minimum_required(VERSION 3.7)
project (event)

### Include {{{

set (PROJECT_LIB_DIR "../")
include_directories (event "${PROJECT_LIB_DIR}")
set (PROJECT_INCLUDE_DIR "include")
include_directories (event ${PROJECT_INCLUDE_DIR})

### }}}
### Sources {{{

file (GLOB SOURCES "src/*.c")
add_library (event ${SOURCES})

### }}}
### Libraries {{{

# get_filename_component (PROJECT_LIB_DIR "../" ABSOLUTE)
# message ("Event - lib: " ${PROJECT_LIB_DIR})
target_link_libraries (event dictionary vector)
# include_directories (event "${PROJECT_LIB_DIR}/trie/include")
# include_directories (event "${PROJECT_LIB_DIR}/dictionary/include")

### }}}
### PkgConfig {{{

# find_package (PkgConfig REQUIRED)

### }}}
### Testing {{{

# if (${ENABLE_TESTING})
  # enable_testing ()
  # set (PROJECT_TEST_DIR "test")
  # file (GLOB TEST_SOURCES "test/*.c")
  # add_executable (check_event ${TEST_SOURCES})

  # target_link_libraries (check_event event)

  # pkg_search_module (CHECK check)
  # target_link_libraries (check_event ${CHECK_LIBRARIES})
  # include_directories (check_event PUBLIC ${CHECK_INCLUDE_DIRS})

  # add_test (check_event "${CMAKE_BINARY_DIR}/bin/check_event")
# endif ()

### }}}
