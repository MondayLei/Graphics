package com.intel.s3d;

public class S3D {
	static {
		System.loadLibrary("ssplit");
	}

	public static native void RenderS3D(Object owner, String methodName,
			Object... args);
	
	public static native float[] D3DXViewMatrixToS3D(float[] mView);

	public static native float[] D3DXProjMatrixToS3D(float[] mProj);
}
