add_library(CanEngine STATIC
    src/Engine.cpp
    src/Application.cpp
    src/Log.cpp
    include/CanEngine/Engine.h
    include/CanEngine/Application.h
    include/CanEngine/Log.h
)

target_compile_features(CanEngine PUBLIC cxx_std_20)

target_include_directories(CanEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
