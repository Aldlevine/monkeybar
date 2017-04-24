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

target_link_libraries (event dictionary vector)

### }}}
### PkgConfig {{{

# find_package (PkgConfig REQUIRED)

### }}}
