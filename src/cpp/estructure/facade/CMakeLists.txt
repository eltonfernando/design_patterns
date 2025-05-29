add_executable(facade main.cpp Facade.cpp Facade.hpp)

target_include_directories(facade PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
