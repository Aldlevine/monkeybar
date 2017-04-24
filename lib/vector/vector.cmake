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
