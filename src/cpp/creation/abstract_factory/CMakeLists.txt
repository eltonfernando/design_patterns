add_executable(abstract_factory main.cpp LinuxGui.cpp WindowsGui.cpp
                                GuiFactory.hpp LinuxGui.hpp WindowsGui.hpp)

target_include_directories(abstract_factory PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
