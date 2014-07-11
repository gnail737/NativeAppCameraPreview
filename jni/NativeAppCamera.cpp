#include "NativeAppCamera.h"
#include "GraphicsEngine.h"

struct android_app;


void runOnUI( android_app* state )
{
	 JNIEnv *jni;
	 state->activity->vm->AttachCurrentThread( &jni, NULL );

	    //Default class retrieval
	    jclass clazz = jni->GetObjectClass( state->activity->clazz );
	    jmethodID methodID = jni->GetMethodID( clazz, "showToast", "()V" );
	    jni->CallVoidMethod( state->activity->clazz, methodID );

	    state->activity->vm->DetachCurrentThread();
	    return;
}
/**
 * This is the main entry point of a native application that is using
 * android_native_app_glue.  It runs in its own thread, with its own
 * event loop for receiving input events and doing other things.
 */
/*
 * This function is run on another thread different from Main Activity Thread
 * so to use JNI need to attach this thread to JVM
 */
void android_main( android_app* state )
{
    app_dummy();

    LOGI("Inside androidmain..");
    //initialize GraphicEngine
    GraphicsEngine engine(state);

    //setup callbacks
    state->userData = &engine;
    state->onAppCmd = GraphicsEngine::handleCmd;
    state->onInputEvent = GraphicsEngine::handleInput;

    runOnUI(state);
    //loop waiting for stuff to do
    while (1) {
    	//read pending event
    	int32_t eId, event;
    	struct android_poll_source* source;

    	//if not animating will block forever until events happen
    	//if animating no-blocking poll is called read all events and finish all callbacks
    	//then draw one frame
    	while((eId = ALooper_pollAll(engine.animating ? 0: -1, NULL, &event,
    			(void **)&source )))
    	{
            // Process this event.
            if (source != NULL) {
            	//this process func ptr is a wrapper used by native_app_glue
            	//eventually this wrapper calls our regiesterd callback function
                source->process(state, source);
            }
            //check to see if need to exit
            if(state->destroyRequested != 0) {
            	engine.term_display();
            	return;
            }

            //all done start drawing
            if (engine.animating)
            	engine.drawAFrame();
    	}

    }


}
