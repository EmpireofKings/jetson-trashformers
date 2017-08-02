#!/bin/bash

#Download zigb files to a zip folder
wget -N http://support.robotis.com/en/baggage_files/zigbee_sdk/zigbee_sdk_linux_v1_00.zip

#extract the zip file to a folder
unzip ./zigbee_sdk_linux_v1_00.zip

#remove the zip file
rm ./zigbee_sdk_linux_v1_00.zip

#copy the zigbee header file to ./util
cp ./ZIGBEE_SDK_Linux_v1_00/include/zigbee.h ./util

#build zigbee binary
make -C ./ZIGBEE_SDK_Linux_v1_00/src

#copy the zigbee binary file to ./lib
cp ./ZIGBEE_SDK_Linux_v1_00/lib/libzgb.a ./lib

#remove ZIGBEE src folder
rm -rf ./ZIGBEE_SDK_Linux_v1_00



