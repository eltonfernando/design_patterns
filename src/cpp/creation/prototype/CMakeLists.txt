add_executable(prototype main.cpp Car.cpp Car.hpp)

target_include_directories(prototype PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
