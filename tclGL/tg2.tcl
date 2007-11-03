package require math
package require TclGL
package require GlmwfwX11
package require Glmwfw

set M_PI 3.14159265358979323846

proc testTorus {innerRadius outerRadius sides rings} {
    set ringDelta [expr {2.0 * $::M_PI / $rings}]
    set sideDelta [expr {2.0 * $::M_PI / $sides}]
    set theta 0.0
    set cosTheta 1.0
    set sinTheta 0.0
    set i $rings
    incr i -1
    while {$i >= 0} {
        set theta1 [expr {$theta + $ringDelta}]
        set cosTheta1 [expr {cos($theta1)}]
        set sinTheta1 [expr {sin($theta1)}]
        set phi 0.0
        set j $sides
set sides 2
        ::ntk::gl::GL glBegin GL_QUAD_STRIP
        while {$j >= 0} {
            set phi [expr {$phi + $sideDelta}]
            set cosPhi [expr {cos($phi)}]
            set sinPhi [expr {sin($phi)}]
            set dist [expr {$outerRadius + $innerRadius * $cosPhi}]
            ::ntk::gl::GL glNormal3f [expr {$cosTheta1 * $cosPhi}] \
                    [expr {-$sinTheta1 * $cosPhi}] $sinPhi
            ::ntk::gl::GL glVertex3f [expr {$cosTheta1 * $dist}] \
                    [expr {-$sinTheta1 * $dist}] \
                    [expr {$innerRadius * $sinPhi}]
            ::ntk::gl::GL  glNormal3f [expr {$cosTheta * $cosPhi}] \
                    [expr {-$sinTheta * $cosPhi}] $sinPhi
            ::ntk::gl::GL glVertex3f [expr {$cosTheta * $dist}] \
                    [expr {-$sinTheta * $dist}] \
                    [expr {$innerRadius * $sinPhi}]
            incr j -1
        }
        ::ntk::gl::GL glEnd
        set theta $theta1
        set cosTheta $cosTheta1
        set sinTheta $sinTheta1
        incr i -1
    }
}

proc testRender {} {
    set light_ambient [::ntk::gl::GL makeFloatVector [list 0.0, 0.0, 0.0, 1.0]]
    set light_diffuse [::ntk::gl::GL makeFloatVector [list 1.0, 1.0, 1.0, 1.0]]
    set light_specular [::ntk::gl::GL makeFloatVector [list 1.0, 1.0, 1.0, 1.0]]
    set light_position [::ntk::gl::GL makeFloatVector [list 1.0, 1.0, 1.0, 0.0]]
    set red_mat [::ntk::gl::GL makeFloatVector [list 1.0, 0.2, 0.2, 1.0]]

    ::ntk::gl::GL glLightfv GL_LIGHT0 GL_AMBIENT $light_ambient
    ::ntk::gl::GL glLightfv GL_LIGHT0 GL_DIFFUSE $light_diffuse
    ::ntk::gl::GL glLightfv GL_LIGHT0 GL_SPECULAR $light_specular
    ::ntk::gl::GL glLightfv GL_LIGHT0 GL_POSITION $light_position

    ::ntk::gl::GL glEnable GL_LIGHTING
    ::ntk::gl::GL glEnable GL_LIGHT0
    ::ntk::gl::GL glEnable GL_DEPTH_TEST
    ::ntk::gl::GL glMatrixMode GL_PROJECTION
    ::ntk::gl::GL glLoadIdentity 
    ::ntk::gl::GL glClear "GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT"

    ::ntk::gl::GL glPushMatrix
#    ::ntk::gl::GL glTranslatef -0.75 0.5 0.0
#    ::ntk::gl::GL glRotatef 90.0 1.0 0.0 0.0
    ::ntk::gl::GL glMaterialfv GL_FRONT_AND_BACK GL_AMBIENT_AND_DIFFUSE $red_mat
    testTorus 0.275 0.85 20 20
    ::ntk::gl::GL glPopMatrix
}

::ntk::glmwfw::Glmwfw init
set win [::ntk::glmwfw::Glmwfw openWindow 500 400]
::ntk::glmwfw::Glmwfw setWindowTitle $win "Arnulf's torus Demo"

source tg2_inc.tcl
