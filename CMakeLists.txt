cmake_minimum_required(VERSION 3.13.0)
project(auto-v VERSION 0.1.0)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

## Set number of cores used to build
include(ProcessorCount)
ProcessorCount(N)
if(${N} GREATER 1)
    math(EXPR NCORES "${N} - 1")
endif()
message(STATUS "Number of Cores: ${N}")


## Globals
set(DIR_BUILD "${PROJECT_SOURCE_DIR}/build")
set(DIR_OPENCV_BUILD ${DIR_BUILD}/third_party)
set(OPENCV_INSTALL_DIR "${DIR_OPENCV_BUILD}/opencv-install")
set(OPENCV_CMAKE_FIND "${OPENCV_INSTALL_DIR}/lib/cmake/opencv4/OpenCVConfig.cmake")

if(BUILD_OPENCV)
    ## Build OpenCV ## TODO turn this into a process
    add_subdirectory(third_party)
endif()


if(BUILD_APP)
    # check if opencv has been built yet.
    if(EXISTS ${OPENCV_CMAKE_FIND})
        message(STATUS "FOUND OPENCV CMAKE FILE")
        include(${OPENCV_CMAKE_FIND})
        # If the package has been found, several variables will
        # be set, you can find the full list with descriptions
        # in the OpenCVConfig.cmake file.
        # Print some message showing some of them
        message(STATUS "OpenCV library status:")
        message(STATUS "    version: ${OpenCV_VERSION}")
        message(STATUS "    libraries: ${OpenCV_LIBS}")
        message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
        message(STATUS "BUILD DIR: ${DIR_BUILD}")
        message(STATUS "OPENCV_LIB DIR: ${OPENCV_INSTALL_DIR}")
    else()
        message(FATAL_ERROR "OpenCV Not Found, please build it first")
    endif()

    # setup compiler
    set(CMAKE_CXX_FLAGS "-O0 -g3 -Wall")

    ## Build main application
    include_directories( ${OpenCV_INCLUDE_DIRS} )
    add_subdirectory(source)
endif()
