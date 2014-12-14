package com.intel.ssg.monday.graphics.demo1;

import android.app.Activity;
import android.content.Context;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends Activity {

	private GLSurfaceView mGLSurfaceView;
	private static final String TAG = "SurfaceView";

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		mGLSurfaceView = new GLSurfaceView(this);
		
		mGLSurfaceView.setEGLContextClientVersion(2);
		mGLSurfaceView.setRenderer(new MRender(this));
		
		Log.e(TAG, String.class.getName());
		System.out.println(String.class.getName());

		setContentView(mGLSurfaceView);
	}
	
    @Override
    protected void onResume() {
        super.onResume();
        mGLSurfaceView.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mGLSurfaceView.onPause();
    }	
}
