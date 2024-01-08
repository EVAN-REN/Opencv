cmake_minimum_required(VERSION 3.0.0)
project(opencv VERSION 0.1.0 LANGUAGES C CXX)

set(OpenCV_DIR /opt/homebrew/Cellar/opencv/4.8.1_5)

find_package(OpenCV REQUIRED)

#设置exe输出目录
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")  

set(DIR_SRCS
    ./src/newImage09.cpp  
)

# 指定生成目标
add_executable(main_executable ${DIR_SRCS})
#add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(main_executable PRIVATE ${OpenCV_LIBS})



