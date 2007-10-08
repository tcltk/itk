namespace eval ::ntk {
    namespace ensemble create -map [list \
        button ::ntk::button \
        clock ::ntk::clock \
        entry ::ntk::entry \
        focus ::ntk::focus \
        frame ::ntk::frame \
        grid ::ntk::grid \
        input ::ntk::input \
        label ::ntk::label \
        listbox ::ntk::listbox \
        render ::ntk::render \
        scrollbar ::ntk::scrollbar \
        text ::ntk::text \
        theme ::ntk::theme \
        toplevel ::ntk::toplevel \
        window ::ntk::window \
    ]
}

set myDir [file dirname [::info script]]
source [file join $myDir ntkHelpers.tcl]
source [file join $myDir ntkRender.tcl]
source [file join $myDir ntkGridBase.tcl]
source [file join $myDir ntkWindow.tcl]
source [file join $myDir ntkTheme.tcl]
source [file join $myDir ntkScrollbar.tcl]
source [file join $myDir ntkButton.tcl]
#source [file join $myDir ntkClock.tcl]
source [file join $myDir ntkEntry.tcl]
source [file join $myDir ntkFrame.tcl]
#source [file join $myDir ntkGrid.tcl]
#source [file join $myDir ntkInput.tcl]
source [file join $myDir ntkLabel.tcl]
#source [file join $myDir ntkListbox.tcl]
#source [file join $myDir ntkText.tcl]
source [file join $myDir ntkToplevel.tcl]

proc ::ntk::button {args} {
    puts stderr "::ntk::button called !$args!"
    return [uplevel 1 ::ntk::classes::button {*}$args]
}
    
proc ::ntk::clock {args} {
    puts stderr "::ntk::clock called !$args!"
}
    
proc ::ntk::entry {args} {
    puts stderr "::ntk::entry called !$args!"
    return [uplevel 1 ::ntk::classes::entry {*}$args]
}
    
proc ::ntk::focus {args} {
    puts stderr "::ntk::focus called !$args!"
    return [uplevel 1 ::ntk::classes::focus {*}$args]
}
    
proc ::ntk::frame {args} {
    return [uplevel 1 ::ntk::classes::frame {*}$args]
}
    
proc ::ntk::grid {args} {
    return [uplevel 1 ::ntk::classes::grid {*}$args]
}
    
proc ::ntk::input {args} {
    puts stderr "::ntk::input called !$args!"
}
    
proc ::ntk::label {args} {
    puts stderr "::ntk::label called !$args!"
    return [uplevel 1 ::ntk::classes::label {*}$args]
}
    
proc ::ntk::listbox {args} {
    puts stderr "::ntk::listbox called !$args!"
}
    
proc ::ntk::render {args} {
    puts stderr "::ntk::render called !$args!"
}
    
proc ::ntk::scrollbar {args} {
    puts stderr "::ntk::scrollbar called !$args!"
}
    
proc ::ntk::text {args} {
    puts stderr "::ntk::text called !$args!"
}
    
proc ::ntk::theme {args} {
    puts stderr "::ntk::theme called !$args!"
}
    
proc ::ntk::toplevel {args} {
    return [uplevel 1 ::ntk::classes::toplevel {*}$args]
}
    
proc ::ntk::window {args} {
    return [uplevel 1 ::ntk::classes::window {*}$args]
}
    
package provide ntkWidget 0.1

