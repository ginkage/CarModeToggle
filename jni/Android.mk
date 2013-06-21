# A simple test for the minimal standard C++ library
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := dockstate
LOCAL_SRC_FILES := dockstate.c
include $(BUILD_EXECUTABLE)
