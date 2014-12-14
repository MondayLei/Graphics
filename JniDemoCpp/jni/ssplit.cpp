#include "jni.cpp"
#include <android/log.h>
// #include <stddef.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>

#define LOG_TAG "JNI_CPP"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

bool isLeft = true;

void drawTwoEye(int x, int y, int screenheight, int screenwidth) {
	glViewport(x, y, screenwidth, screenheight / 2);
}

/*
 * Class:     com_intel_s3d_S3D
 * Method:    RenderS3D
 * Signature: (Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_intel_s3d_S3D_RenderS3D
(JNIEnv *env, jclass cls, jobject owner, jstring javaMethodName, jobjectArray args) {
	const char *nativeMethodName = (*env).GetStringUTFChars(javaMethodName, 0);

	jclass mcls = env->GetObjectClass(owner);
	LOGD("Method Name: %s", nativeMethodName);
	jmethodID jmid = env->GetMethodID(mcls, nativeMethodName, "([Ljava/lang/Object;)V");

	int w,h;
	EGLDisplay display = eglGetCurrentDisplay();
	EGLSurface surface = eglGetCurrentSurface(EGL_READ);
	eglQuerySurface(display,surface, EGL_WIDTH, &w);
	eglQuerySurface(display,surface, EGL_HEIGHT, &h);
	LOGD("Width: %d, Height: %d", w, h);

	/* The first call, draw the upper part */
	isLeft = true;
	drawTwoEye(0, 0, h, w);
	(*env).CallVoidMethod(owner, jmid, args);

	/* The second call, draw the lowerer part */
	isLeft = false;
	drawTwoEye(0, h/2, h, w);
	env->CallVoidMethod( owner, jmid, args);
}

/*
 * Class:     com_intel_s3d_S3D
 * Method:    D3DXProjMatrixToS3D
 * Signature: ([F)[F
 */
JNIEXPORT jfloatArray JNICALL Java_com_intel_s3d_S3D_D3DXProjMatrixToS3D
  (JNIEnv *, jclass, jfloatArray) {
	if ( isLeft ) {

	} else {

	}
	return NULL;

}

