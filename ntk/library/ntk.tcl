#---------------------------------------------------------------------------
# ntkWidget ntk.tcl --
#
# This file contains a namespace ensemble for the subcommands of ntkWidget
# ntkWidget is derived from the NexTk implementation written by
# George Peter Staplin
#
# ntkWidget is a reimplementation of Tk based on megapkg, ntk and freetypeext
# written by George Peter Staplin
#
# Copyright (c) 2007 by Arnulf P. Wiedemann and George Peter Staplin
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: ntk.tcl,v 1.1.2.17 2007/11/23 21:02:56 wiede Exp $
#--------------------------------------------------------------------------

package require TclGL
package require GlmwfwX11
package require Glmwfw
package require ntkWidgetImage

namespace eval ::ntk {
    namespace ensemble create -map [list \
        button ::ntk::classes::button \
        clock ::ntk::classes::clock \
        entry ::ntk::classes::entry \
        focus ::ntk::focus \
        frame ::ntk::classes::frame \
        grid ::ntk::::classes::grid::grid \
        input ::ntk::classes::input \
        label ::ntk::classes::label \
        listbox ::ntk::classes::listbox \
        checkbox ::ntk::classes::checkbox \
        spinbox ::ntk::classes::spinbox \
        menu ::ntk::classes::menu \
        render ::ntk::::classes::render::render \
        scrollbar ::ntk::classes::scrollbar \
        text ::ntk::classes::text \
        theme ::ntk::classes::theme \
        toplevel ::ntk::classes::toplevel \
        window ::ntk::classes::window \
        keyPress ::ntk::classes::input::inputKeyPress \
        keyRelease ::ntk::classes::input::inputKeyRelease \
        mousePress ::ntk::classes::input::inputMousePress \
        mouseRelease ::ntk::classes::input::inputMouseRelease \
        motion ::ntk::classes::input::inputMotion \
        widget ::ntk::widget::Widget \
    ]
}

set myDir [file dirname [::info script]]

# the order of the following lines is relevant!!
source [file join $myDir ntkHelpers.tcl]
source [file join $myDir ntkRender.tcl]
source [file join $myDir ntkGrid.tcl]
source [file join $myDir ntkGridManager.tcl]
source [file join $myDir ntkGridData.tcl]
source [file join $myDir ntkInput.tcl]
source [file join $myDir ntkWindow.tcl]
source [file join $myDir ntkTheme.tcl]
source [file join $myDir ntkButton.tcl]
source [file join $myDir ntkScrollbarButton.tcl]
source [file join $myDir ntkScrollbar.tcl]
source [file join $myDir ntkEntry.tcl]
source [file join $myDir ntkFrame.tcl]
source [file join $myDir ntkLabel.tcl]
source [file join $myDir ntkText.tcl]
source [file join $myDir ntkListbox.tcl]
source [file join $myDir ntkToplevel.tcl]
source [file join $myDir ntkClock.tcl]
source [file join $myDir ntkBox.tcl]
source [file join $myDir ntkCheckbox.tcl]
source [file join $myDir ntkSpinbox.tcl]
source [file join $myDir ntkMenu.tcl]

package provide ntkWidget 0.1

