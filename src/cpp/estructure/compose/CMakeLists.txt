add_executable(compose main.cpp Compose.cpp Compose.hpp)

target_include_directories(compose PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
