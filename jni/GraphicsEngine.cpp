#include "GraphicsEngine.h"

void GraphicsEngine::handleCmd(struct android_app* app, int32_t cmd)
{
	GraphicsEngine* eng = (GraphicsEngine*) app->userData;
    switch (cmd) {
        case APP_CMD_INIT_WINDOW:
            // The window is being shown, get it ready.
            if (app->window != NULL) {
                eng->init_display();
                //engine_draw_frame();
                eng->animating = true;
            }
            break;
        case APP_CMD_TERM_WINDOW:
            // The window is being hidden or closed, clean it up.
            eng->term_display();
            break;
    }
}

int32_t GraphicsEngine::handleInput(struct android_app* app, AInputEvent* event)
{
	GraphicsEngine* eng = (GraphicsEngine*) app->userData;
    if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION) {
    	eng->animating = true;
    	eng->pos.x = AMotionEvent_getX(event, 0);
    	eng->pos.y = AMotionEvent_getY(event, 0);
        return 1;
    }
    return 0;
}
void GraphicsEngine::init_display()
{
	if (context_) {
		context_->Init(app_->window);
		glDisable( GL_DEPTH_TEST );
		glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	}
}

void GraphicsEngine::term_display()
{
	if (context_) {
		context_->Invalidate();
	}
}

void GraphicsEngine::drawAFrame()
{
	static GLfloat c = 0.01;
	glClearColor(c, c, c, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	c += 0.01f;
	if (c > 1.f) c = 0;
	context_->Swap();
}
