cmake_minimum_required(VERSION 3.7)
project (component)

### Include {{{

set (PROJECT_LIB_DIR "../")
include_directories (event "${PROJECT_LIB_DIR}")
set (PROJECT_INCLUDE_DIR "include")
include_directories (component ${PROJECT_INCLUDE_DIR})

### }}}
### Sources {{{

file (GLOB SOURCES "src/*.c")
add_library (component ${SOURCES})

### }}}
### Libraries {{{

target_link_libraries (component event)

### }}}
### PkgConfig {{{

# find_package (PkgConfig REQUIRED)

### }}}
