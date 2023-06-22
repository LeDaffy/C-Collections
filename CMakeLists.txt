cmake_minimum_required(VERSION 3.26)

project(ctest)

set(CMAKE_C_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

add_executable(ctest main.c funs.c)
# target_include_directories(vector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vec/include)


add_subdirectory(collections)
target_link_libraries(ctest PUBLIC collections)

add_compile_options(-g3 -ggdb)





