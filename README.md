# auto-visual

This is the autonomous driving research project home

# Required Packages 
* GCC 4.4.x or later
* CMake 3.14 or higher
* Git
* GTK+2.x or higher, including headers (libgtk2.0-dev)
* pkg-config
* Python 2.6 or later and Numpy 1.5 or later with developer packages (python-dev, python-numpy)
* ffmpeg or libav development packages: libavcodec-dev, libavformat-dev, libswscale-dev

```shell
[required] sudo apt-get install build-essential
[required] snap install cmake --classic
[required] sudo apt-get install git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev libiconv-hook-dev libopenjp2-7-dev
```
# Build Instructions
## Fetch the repo 
```shell
 git clone git@gitlab.com:azizbahri90/auto-visual.git
 git checkout remotes/origin/dev
```
## build OpenCV
This step will build OpenCV Library. For build variables see **third_party/opencv/CMakeLists.txt**
> Note: this will take 30~ mins, but only needs to be built once. 
```shell
 mkdir build && cd build
 cmake -DBUILD_OPENCV=1 ../
 make
```
## Check if build went well
### Run CMake
```shell
 cd build
 cmake -DBUILD_APP=1 ../
```
### Now build and run demo
video capture demo.
```shell
make demo_capture
./build/source/demo/demo_capture
```
video capture performance demo, press pace for video processing.

```shell
make demo_capture_perf
./build/source/demo/demo_capture_perf
```
smile detection demo.
```shell
make demo_smiledetect
export HAAR_DATA=../../../build/third_party/opencv/opencv-core-prefix/src/opencv-core/data/haarcascades
export VIDEO_SRC=0
./build/source/demo/demo_smiledetect --cascade=${HAAR_DATA}/haarcascade_frontalface_alt.xml --smile-cascade=${HAAR_DATA}/haarcascade_smile.xml ${VIDEO_SRC}
```

# Debugging using Eclipse 
1. follow above setup to build OpenCV
2. Create new folder under Eclipse Workspace

> Note: Eclipse does not like build folder to be a subfolder of the source repo, so we create a new workspace folder.

    ```
    cd ~/workspaces/auto-v
    mkdir cmake
    cd cmake
    cmake -DBUILD_APP=1 -G "Eclipse CDT4 - Unix Makefiles" path/to/auto-v/repo
    ```
3. in your Eclipse workspace, do:

    File > Import... > General > Existing Projects into Workspace

    Check Select root directory and choose ~/workspaces/auto-v/cmake. Make sure Copy projects into workspace is NOT checked.

    Click Finish and you have a CMake project in your workspace.

4. Add debugging configuration.
