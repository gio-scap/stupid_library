

add_executable(main main.cpp)

# linking the library make it usable by the executable
target_link_libraries(main 
    PUBLIC 
        ${LIB_NAME}
        nlohmann_json)