# OpenCV Starter Project
A Starter OpenCV project which can be used as a template

## Prerequisites
Install common dependencies for `OpenCV` on your system

```
sudo apt install build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
```

## Install OpenCV

```bash
# !/bin/bash
# Script to Install OpenCV
# Author: Salvador Zendejas.

set -e


CV_VER=4.6.0
SRC_DIR=./opencv-${CV_VER}
OUT_DIR=./build_opencv-${CV_VER}
CORES=$(nproc)

if [ $# -lt 1 ]
then
	echo "Using default OpenCV ${CV_VER}"
else
	CV_VER=$1
	echo "Installing OpenCV ${CV_VER} "
fi

if [[ ! -d "${SRC_DIR}" ]]; then
	echo "Downloading OpenCV ${CV_VER} in ${SRC_DIR}"
	if [[ ! -e opencv_${CV_VER}.zip ]]; then
		wget -O opencv_${CV_VER}.zip https://github.com/opencv/opencv/archive/${CV_VER}.zip
	fi
	if [[ ! -e opencv_contrib_${CV_VER}.zip ]]; then
		wget -O opencv_contrib_${CV_VER}.zip https://github.com/opencv/opencv_contrib/archive/${CV_VER}.zip
	fi
	unzip opencv_${CV_VER}.zip
	unzip opencv_contrib_${CV_VER}.zip
fi

if [[ ! -d "${OUT_DIR}" ]]; then
	mkdir -p ${OUT_DIR} && cd ${OUT_DIR}
	#Configure
	cmake -D OPENCV_EXTRA_MODULES_PATH=../opencv_contrib-${CV_VER}/modules ../opencv-${CV_VER}
	#Build
	make -j${CORES}
	# Install
	echo "Installing OpenCV ${CV_VER} in $HOME/.local"
	make install
	echo "OpenCV ${CV_VER} ready to be used"
fi

```
