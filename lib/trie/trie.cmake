cmake_minimum_required(VERSION 3.7)
project (trie)

### Include {{{

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

# find_package (PkgConfig REQUIRED)

### }}}
