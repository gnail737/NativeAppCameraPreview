#ifndef _GRAPHIC_ENGINE
#define _GRAPHIC_ENGINE

#include "NativeAppCamera.h"
#include "glContext.h"

struct TouchPoint {
	int32_t x;
	int32_t y;
};
class GraphicsEngine{

public:
    static void handleCmd( struct android_app* app,
            int32_t cmd );
    static int32_t handleInput( android_app* app,
            AInputEvent* event );

	GraphicsEngine(android_app* state):
		app_(state), context_(NULL),
		animating(false) {
		pos.x = pos.y = 0;
		context_ = ndk_helper::GLContext::GetInstance();
	}

	~GraphicsEngine() {
		app_ = NULL;
		context_ = NULL;

	}

	void init_display();
	void term_display();

	void drawAFrame();
	android_app* app_;
	ndk_helper::GLContext * context_;
	bool animating;
	struct TouchPoint pos;


};

#endif
