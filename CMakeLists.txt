# 参考博客地址
# https://www.cnblogs.com/hbccdf/p/introduction_of_cmake.html#%E4%BA%8C%E3%80%81cmake%E5%85%B8%E5%9E%8B%E7%A4%BA%E4%BE%8B
# https://zhjwpku.com/2019/11/15/cmake-basic-commands-intro.html
#

cmake_minimum_required(VERSION 3.20)
project(network_disk_project)

set(CMAKE_CXX_STANDARD 14)

# 设置静态库的输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)
# 设置动态库的输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)
# 设置可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/build/include)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DEBUG")

include_directories(/usr/local/Cellar/libevent/2.1.12/include/)
link_directories(/usr/local/Cellar/libevent/2.1.12/lib)

# 添加一个子目录到构建，该目录下必须有 CMakeLists.txt 文件。
add_subdirectory(xcom)
add_subdirectory(xdisk_server)
add_subdirectory(xdisk_gui)

# 指定可执行文件。
add_executable(network_disk_project main.cpp)

# 1、如果 target 是一个 library，该命令可以用来指定依赖本仓库的 target 还需要链接另外的仓库，用于解决循环依赖。
# 2、如果 target 是可执行文件，则该命令用于指定其需要链接的库。
target_link_libraries(network_disk_project xcom)
