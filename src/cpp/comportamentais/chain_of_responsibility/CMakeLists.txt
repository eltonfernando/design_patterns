add_executable(chain main.cpp ChainOfResponsibility.cpp
                     ChainOfResponsibility.hpp)

target_include_directories(chain PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
