cmake_minimum_required(VERSION 3.0.0)
project(stupid_library VERSION 0.1.0 LANGUAGES C CXX)

# c++ default standard 
set(CMAKE_CXX_STANDARD 17)
# compiler extension
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# cmake module path
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

# project build settings
set(LIB_NAME "stupid_library")


#############################
## Add external libraries ###
#############################

# git submodule 
include(AddGitSubmodule) #include the function
add_git_submodule(external/json)

# cmake native way
include(FetchContent)

FetchContent_Declare( 
    FMT
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG  10.2.1
    GIT_SHALLOW TRUE 
)
FetchContent_MakeAvailable(FMT)


FetchContent_Declare( 
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG  v1.13.0
    GIT_SHALLOW TRUE 
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare( 
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts
    GIT_TAG  v3.2.0
    GIT_SHALLOW TRUE 
)
FetchContent_MakeAvailable(cxxopts)

FetchContent_Declare( 
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG  v2.13.9
    GIT_SHALLOW TRUE 
)
FetchContent_MakeAvailable(Catch2)

##################
# doxygen automation
##################
include(Docs)



add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(configured)

# option of what to compile
# in the command line add D<var-name>=ON/OFF to set the option

option(COMPILE_EXAMPLES "wheter to compile examples or not" ON)
if(COMPILE_EXAMPLES)
    message("compiling also examples")
    add_subdirectory(examples)
endif()

