# automatic doxygen generation

find_package(Doxygen)

if(DOXYGEN_FOUND)
    message("doxygen  found ")
    add_custom_target( # this create target that are not code but utility
        docs
        ${DOXYGEN_EXECUTABLE} Doxyfile_local
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docs  
    )

    else()
        message("doxygen not found ")

endif()