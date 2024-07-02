# Linking type

A nice tool to visualize which link type is between library and/or executable is `graphviz`.

## Dependency Graph

useful to create a visualization of the dependency, we added a target on the Makefile

```make
make dependency
```

## Public - Inteface - Private

Which is the difference between this linking types?

### Public vs Private

This works like OOP Inheritance, make API public to end user or not.

```cmake
target_link_libraries(A PUBLIC fmt)
target_link_libraries(B PRIVATE spdlog)
```

suppose a end user library C

```cmake
target_link_libraries(C PUBLIC/PRIVATE A)
target_link_libraries(C PUBLIC/PRIVATE A)
```

**PUBLIC**:
Public means that the linked libraries is also used in the public API of A. So C can use directly fmt when link A since fmt is **part of the public A's API**.

**PRIVATE**:
Private means that the linked libraries is only used internally of the library B, **not in the public API**. So C when link B can't use spdlog library directly, it has to specifically link spdlog.

This work in cascade so if C link A as PUBLIC then user of C can directly use A public API.

### Interface

usually usd only for headers-only library where nothing need to be compiled.

```cmake
add_library(D INTERFACE)
target_include_directories(D INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
```
