add_executable(abstract_factory main.cpp LinuxGui.cpp WindowsGui.cpp
                                GuiFactory.h LinuxGui.h WindowsGui.h)

target_include_directories(abstract_factory PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
