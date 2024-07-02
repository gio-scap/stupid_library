cmake_minimum_required(VERSION 3.9.0)
project(stupid_library VERSION 0.1.0 LANGUAGES  CXX)

# c++ default standard
set(CMAKE_CXX_STANDARD 17)
# compiler extension
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# cmake module path
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

# project build settings
set(LIB_NAME "stupid_library")

message(STATUS "compiler ${CMAKE_CXX_COMPILER_ID}")

## option of what to compile
# in the command line add D<var-name>=ON/OFF to set the option
option(COMPILE_EXAMPLES "Wheter to compile examples or not" ON)
option(ENABLE_TESTING "Enable Unit Testing" ON)
option(ENABLE_WARNINGS "Enable warnings" ON)
option(ENABLE_WARNINGS_AS_ERROR "Enable warnings as error" OFF)

option(ENABLE_SANITIZE_ADDR "Enable address sanatizer" ON)
option(ENABLE_SANITIZE_UNDEF "Enable undefined sanatizer" ON)

option(ENABLE_LTO "Link time optimization" ON)

# external library manager
option(USE_CPM "wheter to use CPM" ON)


include(Warnings)

if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizers)
    add_sanitizer_flags(ENABLE_SANITIZE_ADDR ENABLE_SANITIZE_UNDEF)
endif()



#############################
## Add external libraries ###
#############################

# git submodule
include(AddGitSubmodule) #include the functions
add_git_submodule(external/json)

if(USE_CPM)
    include(CPM)
    message(STATUS "using CPM")

    CPMAddPackage("gh:fmtlib/fmt#10.2.1") # gh: stand for "github"
    CPMAddPackage("gh:gabime/spdlog#v1.14.1")
    CPMAddPackage("gh:jarro2783/cxxopts#v3.2.0")
    CPMAddPackage("gh:catchorg/Catch2#v3.5.3")
    if(ENABLE_TESTING)
        cpmaddpackage("gh:catchorg/Catch2#v3.5.3")
        list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
    endif()

else()
    # cmake native way
    message(STATUS "using FetchContent")
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

    if(ENABLE_TESTING)
        FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2
            GIT_TAG  v3.5.3
            GIT_SHALLOW TRUE
        )
        FetchContent_MakeAvailable(Catch2)
        list(APPEND CMAKE_MODULE_PATH ${catch_SOURCE_DIR}/extras) # allow to include catch2 modules
    endif()

endif(USE_CPM)

# include(Docs) # doxygen automation

include(LTO) # link time optimization

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(configured)

if(ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(test)
endif()


if(COMPILE_EXAMPLES)
    message("-- Compiling also examples")
    add_subdirectory(examples)
endif()
