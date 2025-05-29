cmake_minimum_required(VERSION 3.10)
project(PadroesDeProjeto LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona subdiretórios
add_subdirectory(creation/abstract_factory)
add_subdirectory(creation/builder)
add_subdirectory(creation/factory_method)
add_subdirectory(creation/prototype)

add_subdirectory(estructure/adapter)
add_subdirectory(estructure/bridge)
add_subdirectory(estructure/compose)
add_subdirectory(estructure/decoretor)
add_subdirectory(estructure/facade)

# Se quiser adicionar os outros futuramente: add_subdirectory(estructure/...)
# add_subdirectory(comportamentais/...)
