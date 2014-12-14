LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)
 
LOCAL_MODULE    := ssplit
LOCAL_CFLAGS    := -Wall -Wextra
LOCAL_SRC_FILES := ssplit.cpp
LOCAL_LDLIBS := -lGLESv2 -llog -lEGL

include $(BUILD_SHARED_LIBRARY)