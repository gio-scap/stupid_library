#        function name      parameters            
function(add_git_submodule dir)
    find_package(Git REQUIRED)

    if(NOT EXISTS ${dir}/CMakelists.txt)
        # try to update the rsubmodule
        execute_process(COMMAND ${GIT_EXECUTABLE} 
            submodule update --init --recursive -- ${dir}
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
    endif()

    #include the CMakeList.txt
    add_subdirectory(${dir})
    
endfunction()
