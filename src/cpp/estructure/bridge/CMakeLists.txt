add_executable(bridge main.cpp Bridge.cpp Bridge.hpp)

target_include_directories(bridge PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
