include(GNUInstallDirs)
project(AvCapture VERSION 0.1 DESCRIPTION "Capture library")

add_library(AvCapture AvCapture.cpp)
target_include_directories(AvCapture PUBLIC include)

# message(FATAL_ERROR " MESSAGE ${OpenCV_LIBS}")
target_link_libraries( AvCapture ${OpenCV_LIBS} )
# public api
set_target_properties(AvCapture PROPERTIES PUBLIC_HEADER include/AvCapture.hpp)


