add_library(CanEngine STATIC
    src/Engine.cpp
    include/CanEngine/Engine.h
)

target_compile_features(CanEngine PUBLIC cxx_std_20)

target_include_directories(CanEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
