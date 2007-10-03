namespace eval ::ntk {
namespace ensemble create -map [list \
button ::ntk::button \
clock ::ntk::clock \
entry ::ntk::entry \
focus ::ntk::focus \
frame ::ntk::frame \
input ::ntk::input \
label ::ntk::label \
listbox ::ntk::listbox \
render ::ntk::render \
scrollbar ::ntk::scrollbar \
test ::ntk::test \
theme ::ntk::theme \
toplevel ::ntk::toplevel \
window ::ntk::window]
}

proc ::ntk::button {args} {
    puts stderr "::ntk::button called !$args!"
    return [uplevel 1 ::ntk::classes::button {*}$args]
}
    
proc ::ntk::clock {args} {
    puts stderr "::ntk::clock called !$args!"
}
    
proc ::ntk::entry {args} {
    puts stderr "::ntk::entry called !$args!"
}
    
proc ::ntk::focus {args} {
    puts stderr "::ntk::focus called !$args!"
}
    
proc ::ntk::frame {args} {
#    puts stderr "::ntk::frame called !$args!"
    return [uplevel 1 ::ntk::classes::frame {*}$args]
}
    
proc ::ntk::input {args} {
    puts stderr "::ntk::input called !$args!"
}
    
proc ::ntk::label {args} {
    puts stderr "::ntk::label called !$args!"
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
    puts stderr "::ntk::toplevel called !$args!"
    return [uplevel 1 ::ntk::classes::window {*}$args]
}
    
proc ::ntk::window {args} {
#    puts stderr "::ntk::window called !$args!"
    return [uplevel 1 ::ntk::classes::window {*}$args]
}
    

