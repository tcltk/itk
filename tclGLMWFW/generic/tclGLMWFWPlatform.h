int glmwfwPlatformOpenWindow(int width, int height, int redbits, int greenbits,
        int bluebits, int alphabits, int depthbits, int stencilbits, int mode,
	GLMWFWHints *hints);
int _glmwfwPlatformRefreshWindowParams(GLMWFWWindow *winPtr);
int _glmwfwPlatformCloseWindow(GLMWFWWindow *winPtr);
int _glmwfwPlatformSetWindowTitle(GLMWFWWindow *winPtr, const char *title);
int _glmwfwPlatformSetWindowSize(GLMWFWWindow *winPtr, int width, int height);
int _glmwfwPlatformSwapBuffers(GLMWFWWindow *winPtr);
int _glmwfwPlatformSetWindowPos(GLMWFWWindow *winPtr, int x, int y);
int _glmwfwPlatformIconifyWindow(GLMWFWWindow *winPtr);
int _glmwfwPlatformRestoreWindow(GLMWFWWindow *winPtr);
int _glmwfwPlatformSwapInterval(GLMWFWWindow *winPtr, int interval);
int _glmwfwPlatformPollEvents(GLMWFWWindow *winPtr);
int _glmwfwPlatformWaitEvents(GLMWFWWindow *winPtr);
int _glmwfwPlatformShowMouseCursor(GLMWFWWindow *winPtr);
int _glmwfwPlatformSetMouseCursorPos(GLMWFWWindow *winPtr, int CenterPosX,
        int CenterPosY);
int _glmwfwPlatformHideMouseCursor(GLMWFWWindow *winPtr);
int _glmwfwPlatformSetMouseCursorPos(GLMWFWWindow *winPtr, int width,
        int height);
int _glmwfwPlatformEnableSystemKeys(GLMWFWWindow *winPtr);
int _glmwfwPlatformDisableSystemKeys(GLMWFWWindow *winPtr);
int _glmwfwPlatformInit(void);
int _glmwfwPlatformTerminate(GLMWFWWindow *winPtr);
int _glmwfwPlatformGetVideoModes(GLMWFWvidmode *list, int maxcount);
int _glmwfwPlatformGetDesktopMode(GLMWFWvidmode *mode);
int _glmwfwPlatformExtensionSupported(GLMWFWWindow *winPtr,
        const char *extension);
void *_glmwfwPlatformGetProcAddress(GLMWFWWindow *winPtr,
        const char *procname);
int _glmwfwPlatformGetJoystickParam(GLMWFWWindow *winPtr, int joy, int param);
int _glmwfwPlatformGetJoystickPos(GLMWFWWindow *winPtr, int joy, float *pos,
        int numaxes);
int _glmwfwPlatformGetJoystickButtons(GLMWFWWindow *winPtr, int joy,
        unsigned char *buttons, int numbuttons);
double _glmwfwPlatformGetTime(GLMWFWWindow *winPtr);
void _glmwfwPlatformSetTime(GLMWFWWindow *winPtr, double time);
