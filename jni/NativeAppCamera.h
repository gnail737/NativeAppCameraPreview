#ifndef _GLOBAL_HEADER
#define _GLOBAL_HEADER
#include <jni.h>
#include <errno.h>

#include <EGL/egl.h>
#include <GLES2/gl2.h>

#include <android/log.h>
#include <android_native_app_glue.h>
#include <android/native_window_jni.h>
#include <string>
#include <vector>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-activity", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "native-activity", __VA_ARGS__))


#endif
