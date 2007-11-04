package require TclGL
package require GlmwfwX11
package require Glmwfw

set vertices [::ntk::gl::GL makeFloatVector [list \
0.0 0.2 \
0.4 0.3 \
0.4 0.95 \
0.0 0.8 \
0.35 0.0 \
0.75 0.2 \
0.75 0.8 \
0.35 0.65]]

set colors [::ntk::gl::GL makeFloatVector [list \
1.0 0.2 0.2 \
0.0 0.75 0.75 \
0.5 0.0 0.5 \
0.0 0.0 0.5 \
0.0 0.4 0.4 \
0.45 0.0 0.0 \
1.0 0.5 0.5 \
0.6 0.6 0.6]]

set frontIndices [::ntk::gl::GL makeUnsignedByteVector [list 4 5 6 7]]
set rightIndices [::ntk::gl::GL makeUnsignedByteVector [list 1 2 6 5]]
set bottomIndices [::ntk::gl::GL makeUnsignedByteVector [list 0 1 5 4]]
set backIndices [::ntk::gl::GL makeUnsignedByteVector [list 0 3 2 1]]
set leftIndices [::ntk::gl::GL makeUnsignedByteVector [list 0 4 7 3]]
set topIndices [::ntk::gl::GL makeUnsignedByteVector [list 2 3 7 6]]

proc init {} {
    ::ntk::gl::GL glClearColor 0.55 0.55 0.55 0.0
    ::ntk::gl::GL glShadeModel GL_FLAT
puts stderr "init done"
}

proc display {win} {
    ::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
    ::ntk::gl::GL glColor3f 0.75 0.0 0.0

    ::ntk::gl::GL glBegin GL_LINES
    ::ntk::gl::GL glVertex3f 0.5 0.25 0.0
    ::ntk::gl::GL glVertex3f 0.75 0.25 0.0
    ::ntk::gl::GL glEnd
    ::ntk::gl::GL glFlush

    ::ntk::gl::GL glEnableClientState GL_COLOR_ARRAY
    ::ntk::gl::GL glEnableClientState GL_VERTEX_ARRAY
    ::ntk::gl::GL glColorPointer 3 GL_FLOAT 0 $::colors
    ::ntk::gl::GL glVertexPointer 2 GL_FLOAT 0 $::vertices
    ::ntk::gl::GL glColor3f 0.75 0.75 0.0

    ::ntk::gl::GL glDrawElements GL_QUADS 4 GL_UNSIGNED_BYTE $::frontIndices
    ::ntk::gl::GL glDrawElements GL_QUADS 4 GL_UNSIGNED_BYTE $::rightIndices
    ::ntk::gl::GL glDrawElements GL_QUADS 4 GL_UNSIGNED_BYTE $::bottomIndices
    ::ntk::gl::GL glDrawElements GL_QUADS 4 GL_UNSIGNED_BYTE $::backIndices
    ::ntk::gl::GL glDrawElements GL_QUADS 4 GL_UNSIGNED_BYTE $::leftIndices
    ::ntk::gl::GL glDrawElements GL_QUADS 4 GL_UNSIGNED_BYTE $::topIndices
    ::ntk::gl::GL glFlush
    ::ntk::glmwfw::Glmwfw swapBuffers $win 
#    after 50 [list display $win]
}

set win [::ntk::glmwfw::Glmwfw openWindow 500 400]
::ntk::glmwfw::Glmwfw setWindowTitle $win "Arnulf Cube with Numbered Vertices"
source tg_util.tcl
tgInit $win

init

display $win

set xx 1
vwait xx
after cancel $::afterWaitId
::ntk::glmwfw::Glmwfw terminate
exit 0
