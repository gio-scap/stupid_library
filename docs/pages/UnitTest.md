# Unit Test

We use Catch 2.

## main CMakeLists.txt

we add (append) to the `CMAKE_MODULE_PATH` variable the location of the modules define inside the Catch2 library to use `include(Catch)` in the CMakeLists.txt of tests
```cmake

list(APPEND CMAKE_MODULE_PATH ${catch_SOURCE_DIR}/extras) 

```
- create a subdirectory called "Test"

### enable Ctest of cmake 

```cmake
if(ENABLE_TESTING)
    include(CTest)
    enable_testing() # needed to enable the testing
    add_subdirectory(test)
endif()
```

## CMakeLists.txt test

```cmake

include(Catch)  

catch_discover_tests(${TEST_MAIN}) # allow to make the test visible to Ctest

```

## Ctest
It make more easy to run test: go to the build directory and call `ctest` , this will run all test at once. With the vscode cmake extension this is even more easy since there are buttons that do this
