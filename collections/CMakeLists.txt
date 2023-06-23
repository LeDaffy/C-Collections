add_library(collections vec.c string.c)
target_include_directories(collections PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
