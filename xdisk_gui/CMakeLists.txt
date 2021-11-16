set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Qt5_DIR "/Users/bijh/Qt5.13.0/5.13.0/clang_64/lib/cmake/Qt5")
find_package(
        Qt5
        COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

aux_source_directory(. SOURCE_FILES)
add_executable(xdisk_gui ${SOURCE_FILES})

# 指定编译 target 所需要的头文件
target_include_directories(xdisk_gui PUBLIC ../build/include)

target_link_libraries(xdisk_gui
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        xcom
        )

