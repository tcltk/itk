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
