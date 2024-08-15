# 设置自定义路劲 
# 顶层通过 include($ENV{IDF_PATH}/tools/cmake/project.cmake) 进行工程的cmake编译顺序

idf_component_register(SRCS "main.c"
                       INCLUDE_DIRS ".")