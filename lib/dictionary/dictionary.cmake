cmake_minimum_required(VERSION 3.7)
project (dictionary)

### Include {{{

set (PROJECT_LIB_DIR "../")
include_directories (dictionary "${PROJECT_LIB_DIR}")
set (PROJECT_INCLUDE_DIR "include")
include_directories (dictionary "${PROJECT_INCLUDE_DIR}")

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
