cmake_minimum_required(VERSION 3.10)
project(PadroesDeProjeto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona subdiretórios
add_subdirectory(creation/abstract_factory)
add_subdirectory(creation/builder)
add_subdirectory(creation/factory_method)
add_subdirectory(creation/prototype)

# Se quiser adicionar os outros futuramente: add_subdirectory(estructure/...)
# add_subdirectory(comportamentais/...)
