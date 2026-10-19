add_library(CanEngine STATIC
    src/Engine.cpp
)

target_include_directories(CanEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
