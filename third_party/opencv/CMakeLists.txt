include(FetchContent)
include(ExternalProject)
message(STATUS "Build OpenCV libraries")
message(STATUS "CORES: ${NCORES}")

## Download OpenCV Contrib
ExternalProject_Add(opencv-contrib
  GIT_REPOSITORY    https://github.com/opencv/opencv_contrib.git
  GIT_TAG           4.10.0
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  # SOURCE_DIR        ${DIR_BUILD}/opencv-contrib-src
)
ExternalProject_Get_Property(opencv-contrib SOURCE_DIR)
set(DIR_OPENCV_CONTRIB ${SOURCE_DIR})

ExternalProject_Add_StepTargets(opencv-contrib build)

## build the opencv
set(CV_CONF_FLAG
    -DOPENCV_EXTRA_MODULES_PATH=${DIR_OPENCV_CONTRIB}/modules/
    -DCMAKE_INSTALL_PREFIX=${OPENCV_INSTALL_DIR}
    -DBUILD_DOCS:BOOL=OFF
    -DBUILD_EXAMPLES:BOOL=OFF
    -DBUILD_NEW_PYTHON_SUPPORT:BOOL=OFF
    -DBUILD_WITH_DEBUG_INFO=OFF
    -DBUILD_PACKAGE:BOOL=OFF
    -DBUILD_opencv_core=ON
    -DBUILD_opencv_imgproc=ON
    -DBUILD_opencv_highgui=ON
    -DBUILD_opencv_video=ON
    -DBUILD_opencv_apps=OFF
    -DBUILD_opencv_flann=ON
    -DBUILD_opencv_gpu=ON
    -DBUILD_opencv_ml=ON
    -DBUILD_opencv_legacy=OFF
    -DBUILD_opencv_calib3d=ON
    -DBUILD_opencv_features2d=ON
    -DBUILD_opencv_java=OFF
    -DBUILD_opencv_objdetect=ON
    -DBUILD_opencv_photo=ON
    -DBUILD_opencv_nonfree=ON
    -DBUILD_opencv_ocl=ON
    -DBUILD_opencv_stitching=ON
    -DBUILD_opencv_superres=ON
    -DBUILD_opencv_ts=OFF
    -DBUILD_opencv_videostab=OFF
    -DBUILD_opencv_wechat_qrcode=OFF
    -DBUILD_SHARED_LIBS:BOOL=OFF
    -DBUILD_TESTS:BOOL=OFF
    -DBUILD_PERF_TESTS:BOOL=OFF
    -DBUILD_opencv_contrib=ON
    -DBUILD_WITH_CAROTENE=OFF
    -DCMAKE_BUILD_TYPE:STRING=Release
    -DWITH_FFMPEG:BOOL=ON
    -DWITH_IPP:BOOL=OFF
    -DBUILD_PNG:BOOL=OFF
    -DBUILD_JPEG:BOOL=ON
    -DBUILD_ZLIB:BOOL=ON
    -DBUILD_WITH_STATIC_CRT:BOOL=ON
    -DBUILD_FAT_JAVA_LIB=OFF
    -DWITH_GTK=ON
)

ExternalProject_Add(opencv-core
  GIT_REPOSITORY    https://github.com/opencv/opencv.git
  GIT_TAG           4.10.0
  # SOURCE_DIR        ${DIR_BUILD}/opencv-core-src
  CMAKE_ARGS        ${CV_CONF_FLAG}
  INSTALL_DIR       ${OPENCV_INSTALL_DIR}
  BUILD_COMMAND     make -j${NCORES}
  DEPENDS           opencv-contrib
)

# create a target
ExternalProject_Add_StepTargets(opencv-core configure)
ExternalProject_Add_StepTargets(opencv-core build)
ExternalProject_Add_StepTargets(opencv-core install)
set( OPENCV_SOURCE_DIR ${SOURCE_DIR} CACHE INTERNAL "")
set( OPENCV_ROOT_DIR ${OPENCV_INSTALL_DIR} CACHE INTERNAL "")
set( OPENCV_DIR ${OPENCV_INSTALL_DIR} CACHE INTERNAL "")

set(OpenCV_INCLUDE_DIRS "${OPENCV_INSTALL_DIR}/include" CACHE INTERNAL "")
set(OpenCV_LIB_DIR "${OPENCV_INSTALL_DIR}/lib" CACHE INTERNAL "")

# ## Include directories
include_directories( ${OpenCV_INCLUDE_DIRS} )
link_directories(${OpenCV_LIB_DIR})
