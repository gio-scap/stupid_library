# configure the .in file: 
# specify where to put it

configure_file(
    "config.hpp.in"
    "${CMAKE_BINARY_DIR}/configured_files/include/config.hpp"
    ESCAPE_QUOTES
    )

# add to include dir

target_include_directories(${LIB_NAME} PUBLIC
     "${CMAKE_BINARY_DIR}/configured_files/include" )