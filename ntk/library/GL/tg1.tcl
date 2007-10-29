package require TclGL

puts stderr "VERSION![set ::ntk::gl::version]!"
puts stderr "PATCHLEVEL![set ::ntk::gl::patchLevel]!"
::ntk::gl::GL glClearColor 75.0 75.0 75.0 100.0
::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
puts stderr "D1![::ntk::gl::GL glDefine2Str 0x2600]!"
puts stderr "D2![::ntk::gl::GL glStr2Define GL_MODULATE]!"

# check for usage string
if {[catch {::ntk::gl::GL glIndexMask} err]} {
    puts stderr "USAGE!$err!"
}

# get all the commands with their syntax
puts stderr COMMANDS
::ntk::gl::GL xx
