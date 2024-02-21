# External Library

[TOC]

there are different way to add external library to our library. In any case add them in the external folder

### git-submodule

*example with nlohmann lib*

1. initialize the repository to be a git repo
2.  add the submodule
    ``` bash 
    git submodule add https://github.com/nlohmann/json external/json
    ```
    this create a .gitmodules where is list the submodule added
3. create a cmake folder to store cmake module which are custom cmake function
4. create a AddGitSubmodule.cmake to manage the submodule with cmake
5. run the function in the cmakelist.txt 
6. now we can link that library to a target

when cloning the repo we have to add the submodules:
```
git clone --recursice <github-link>
```

if we performed a checkout to a specific version this will also made when cloning recursive.

**when to use git submodule ??**
- the library is a github/gitlab repository
- can manage also non cmake library 

### Fetch-Content
is a built in function of cmake, so **only work with cmake project**
1. first of all it has to be included:
```cmake
include(FetchContent)
```
2. declare the github link of the library
    ```cmake
    FetchContent_Declare(<project_name of the repo's cmakelist.txt> 
    GIT_REPOSITORY <link github>
    GIT_TAG <tag>
    GIT_SHALLOW TRUE ) ## clone recursive
    ```
3. Make available to the current project the library
    ```cmake
    FetchContent_MakeAvailable(<project_name of the repo's cmakelist.txt>)

Fetch content works best with github/gitlab project using cmake. It download the repo inside the build/_deps and build it automatically

### How to use external libraries in our own Project?
just link our own camke librart target with the other library
```cmake
target_link_libraries(<my_lib> <external_lib_name>)
```

