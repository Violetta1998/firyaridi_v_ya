project(computerVision)
add_executable(computerVision videoPLay.cpp)
find_package( OpenCV REQUIRED )
target_link_libraries( computerVision ${OpenCV_LIBS} )
