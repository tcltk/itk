lappend auto_path .
namespace eval ::ntk {}
package require TclGL

puts stderr "VERSION![set ::ntk::gl::version]!"
puts stderr "INF![::info vars ::ntk::gl::*]!"
puts stderr "V2![set ::ntk::gl::patchLevel]!"
::ntk::gl::GL glClearColor 75.0 75.0 75.0 100.0
::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
::ntk::gl::GL glIndexMask
puts stderr "D1![::ntk::gl::GL glDefine2Str 0x2600]!"
puts stderr "D2![::ntk::gl::GL glStr2Define GL_MODULATE]!"
::ntk::gl::GL xx
