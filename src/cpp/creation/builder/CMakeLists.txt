add_executable(builder
    main.cpp
    Dialog.cpp
    LinuxDialog.cpp
    Director.cpp
)

target_include_directories(builder PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
