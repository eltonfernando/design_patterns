add_executable(command_ main.cpp Command.cpp Command.hpp)

target_include_directories(command_ PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
