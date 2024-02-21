# include all headers here, this tell cmake where to find the 
# headers, if include directy this subdirectory we don't have to 
# specify the path just "#include "print.hpp"

target_include_directories(${LIB_NAME} PUBLIC "./")