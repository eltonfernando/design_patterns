add_executable(adapter main.cpp Adapter.cpp Adapter.hpp)

target_include_directories(adapter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
