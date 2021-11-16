# 搜索当前目录下的所有.cpp文件
aux_source_directory(. SOURCE_FILES)
add_executable(xdisk_server ${SOURCE_FILES})

# 指定编译 target 所需要的头文件
target_include_directories(xdisk_server PUBLIC ../build/include)

# 1、如果 target 是一个 library，该命令可以用来指定依赖本仓库的 target 还需要链接另外的仓库，用于解决循环依赖。
# 2、如果 target 是可执行文件，则该命令用于指定其需要链接的库。
target_link_libraries(xdisk_server xcom)

