LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := NativeAppCamera
LOCAL_SRC_FILES := NativeAppCamera.cpp  \
                   GraphicsEngine.cpp   \
                   glContext.cpp 

LOCAL_C_INCLUDES := 
LOCAL_CPPFLAGS :=

LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv2

LOCAL_STATIC_LIBRARIES := android_native_app_glue

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)