int _glmwfwPlatformOpenWindow(GlmwfwWindow *winPtr, int width, int height,
        int redbits, int greenbits, int bluebits, int alphabits,
	int depthbits, int stencilbits, int mode, GlmwfwHints *hints);
int _glmwfwPlatformRefreshWindowParams(GlmwfwWindow *winPtr);
int _glmwfwPlatformCloseWindow(GlmwfwWindow *winPtr);
int _glmwfwPlatformSetWindowTitle(GlmwfwWindow *winPtr, const char *title);
int _glmwfwPlatformSetWindowSize(GlmwfwWindow *winPtr, int width, int height);
int _glmwfwPlatformSwapBuffers(GlmwfwWindow *winPtr);
int _glmwfwPlatformSetWindowPos(GlmwfwWindow *winPtr, int x, int y);
int _glmwfwPlatformIconifyWindow(GlmwfwWindow *winPtr);
int _glmwfwPlatformRestoreWindow(GlmwfwWindow *winPtr);
int _glmwfwPlatformSwapInterval(GlmwfwWindow *winPtr, int interval);
int _glmwfwPlatformPollEvents(GlmwfwWindow *winPtr);
int _glmwfwPlatformWaitEvents(GlmwfwWindow *winPtr);
int _glmwfwPlatformShowMouseCursor(GlmwfwWindow *winPtr);
int _glmwfwPlatformSetMouseCursorPos(GlmwfwWindow *winPtr, int CenterPosX,
        int CenterPosY);
int _glmwfwPlatformHideMouseCursor(GlmwfwWindow *winPtr);
int _glmwfwPlatformSetMouseCursorPos(GlmwfwWindow *winPtr, int width,
        int height);
int _glmwfwPlatformEnableSystemKeys(GlmwfwWindow *winPtr);
int _glmwfwPlatformDisableSystemKeys(GlmwfwWindow *winPtr);
int _glmwfwPlatformInit(void);
int _glmwfwPlatformTerminate(GlmwfwInfo *infoPtr);
int _glmwfwPlatformGetVideoModes(Glmwfwvidmode *list, int maxcount);
int _glmwfwPlatformGetDesktopMode(Glmwfwvidmode *mode);
int _glmwfwPlatformExtensionSupported(GlmwfwWindow *winPtr,
        const char *extension);
void *_glmwfwPlatformGetProcAddress(GlmwfwWindow *winPtr,
        const char *procname);
int _glmwfwPlatformGetJoystickParam(GlmwfwWindow *winPtr, int joy, int param);
int _glmwfwPlatformGetJoystickPos(GlmwfwWindow *winPtr, int joy, float *pos,
        int numaxes);
int _glmwfwPlatformGetJoystickButtons(GlmwfwWindow *winPtr, int joy,
        unsigned char *buttons, int numbuttons);
double _glmwfwPlatformGetTime(GlmwfwWindow *winPtr);
void _glmwfwPlatformSetTime(GlmwfwWindow *winPtr, double time);
