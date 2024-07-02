# in this way we can specify the include directly with the .hpp without the folder name
# add_subdirectory(stupid_library)

# by including this folder we can specify the header
# location by using "stupid_library/print.hpp"
target_include_directories(${LIB_NAME} PUBLIC "./")