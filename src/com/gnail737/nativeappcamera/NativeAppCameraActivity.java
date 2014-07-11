package com.gnail737.nativeappcamera;

import android.app.NativeActivity;
import android.hardware.Camera;
import android.os.Bundle;
import android.widget.Toast;

public class NativeAppCameraActivity extends NativeActivity {
	Camera mCId;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		
		super.onCreate(savedInstanceState);
		String something = "test";
		something.split(ACTIVITY_SERVICE);
	}
	
	protected void showToast() {
		 this.runOnUiThread(new Runnable()  {
	            @Override
	            public void run()  {
	            	Toast.makeText(getApplicationContext(), 
	            			"Test Message!", Toast.LENGTH_LONG).show();	
	            }
		});
	}
	protected void openCamera() {
		
	}
	
	protected void releaseCamera() {
		
	}
	
}
