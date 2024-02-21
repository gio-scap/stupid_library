# add_subdirectory(stupid_library)

# including this folder we can specify the header
# location by using "stupid_library/print.hpp"
target_include_directories(${LIB_NAME} PUBLIC "./")