This directory contains little demo programs for showing the functionality
of the ntkWidget package. ntkWidget is a complete rewrite of the TK 
functionality based on images for windows and using OpenGL and glmwfw (a
modified version of GLFW) and drivers for X11, win32 and MAC OSX (the last
2 are only partial ready at the moment)

These demos all need Tcl 8.5.0 and tclOO 0.1 as well as Itcl 4.0 (from the
itcl-ng branch of [incr tcl] on Sourceforge.net). In the subdirectory itk
the packages tclGL, glmwfw and glmwfwx11 are needed too.

ntkWidget does only use Tcl and Itcl. Tk is not needed at all and
does not work together with ntkWidget!!

At the moment the demos are only tested on a SuSE Linux 10.0.

To start the demos just type:
tclsh8.5 <dema name>
i.e.: tclsh8.5 button_1.tcl

Some of the demos have optional command line parameters, see in the sources for
these parameters
