add_executable(proxy main.cpp Proxy.cpp Proxy.hpp)

target_include_directories(proxy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
