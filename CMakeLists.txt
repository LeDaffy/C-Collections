cmake_minimum_required(VERSION 3.26)

project(c_collections)

set(CMAKE_C_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)
add_compile_options(-Wall
                    -g3 -ggdb -gdwarf-2
                    -fanalyzer
                    -Wanalyzer-double-fclose 
                    -Wanalyzer-double-free 
                    -Wanalyzer-exposure-through-output-file 
                    -Wanalyzer-file-leak 
                    -Wanalyzer-free-of-non-heap 
                    -Wno-analyzer-malloc-leak 
                    -Wanalyzer-mismatching-deallocation 
                    -Wanalyzer-possible-null-argument 
                    -Wanalyzer-possible-null-dereference 
                    -Wanalyzer-null-argument 
                    -Wanalyzer-null-dereference 
                    -Wanalyzer-shift-count-negative 
                    -Wanalyzer-shift-count-overflow 
                    -Wanalyzer-stale-setjmp-buffer 
                    -Wanalyzer-tainted-array-index 
                    -Wanalyzer-unsafe-call-within-signal-handler 
                    -Wanalyzer-use-after-free 
                    -Wanalyzer-use-of-pointer-in-stale-stack-frame 
                    -Wanalyzer-write-to-const 
                    -Wanalyzer-write-to-string-literal)
# -fanalyzer 
add_executable(c_collections main.c )
# target_include_directories(vector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vec/include)


add_subdirectory(collections)
target_link_libraries(c_collections PUBLIC collections)






