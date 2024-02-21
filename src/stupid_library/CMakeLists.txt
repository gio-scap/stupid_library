#define variable for source
set(LIB_SOURCES 
    print.cpp
    )

add_library(${LIB_NAME} STATIC ${LIB_SOURCES})

# link external libraries
target_link_libraries(${LIB_NAME} 
        PUBLIC  
            cxxopts
            Catch2::Catch2
            fmt
            spdlog
)

