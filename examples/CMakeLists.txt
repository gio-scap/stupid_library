set(EXE_NAME "example")

add_executable(${EXE_NAME} main.cpp)

# linking the library make it usable by the executable
target_link_libraries(${EXE_NAME}
    PUBLIC
        ${LIB_NAME}
        nlohmann_json

        )

target_set_warnings(${EXE_NAME} ${ENABLE_WARNINGS} ${ENABLE_WARNINGS_AS_ERROR})
