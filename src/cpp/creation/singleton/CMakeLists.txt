add_executable(singleton main.cpp Singleton.cpp Singleton.hpp)

target_include_directories(singleton PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
