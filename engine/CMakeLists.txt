add_library(CanEngine STATIC
    src/Engine.cpp
    src/Application.cpp
    include/CanEngine/Engine.h
    include/CanEngine/Application.h
)

target_compile_features(CanEngine PUBLIC cxx_std_20)

target_include_directories(CanEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
