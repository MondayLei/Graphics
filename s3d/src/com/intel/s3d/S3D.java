package com.intel.s3d;

public class S3D {
	static {
		System.out.println("S3D Breakpoint");
		System.loadLibrary("ssplit");
	}

	public static native void RenderS3D(Object owner, String methodName, Object... args);
}
