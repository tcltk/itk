scanHeaderFile.tcl < /usr/include/GL/gl.h > scannedGLDotH.txt
makeDefineGroups.tcl < scannedGLDotH.txt
makeFuncGroups.tcl < scannedGLDotH.txt
scanHeaderFile.tcl < /usr/include/GL/glext.h > scannedGLextDotH.txt
makeExtDefineGroups.tcl < scannedGLextDotH.txt
makeExtFuncGroups.tcl < scannedGLextDotH.txt
