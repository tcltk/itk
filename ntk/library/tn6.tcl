# Tk9 Demo
# By George Peter Staplin
#
# Note: eventually this existing Tk . window and the event system 
# will be replaced.
#
# Steps
#  1. render.img
#  2. better entry widget design
#  3. listbox 
#  4. tabbed notebook
#
# adapted to ntkWidget by Arnulf Wiedemann

package require Itcl 4.0
package require megaimage
package require freetypeext
package require pngext2
package require jpegext2
package require ntk
lappend auto_path .
package require ntkWidget

set ::env(NEXTK_DISABLE_XV) 1

set fullscreen 0
if {"-fullscreen" eq [lindex $argv 0]} {
 set fullscreen 1
}

lappend ::auto_path [file join [file dirname [info script]] lib]
#package require math::geometry

set tmp /tmp
if {[info exists ::env(TEMP)]} {
 set tmp $::env(TEMP)
}

#
# Override the tk9.vfs/main.tcl font.
#
#file copy -force [file join $::demo_dir Vera.ttf] [set font [file join $tmp Vera.ttf]]
set font ./Vera.ttf
set ::ntk_default_font $font

set ::state {}
set ::selected {}
set ::startx 0
set ::starty 0

set ::base [megaimage-blank 800 600]
set ::background_color [list 16 33 65 255]

set ::rendering 0

proc topConfigure {winid x y width height} {
#puts stderr "global configure called"
    global cfg configure_pending

    if {$width == [. cget -width] && $height == [. cget -height]} {
        return
    }
    set cfg [list $width $height]
    if {$configure_pending} {
        return
    }
    set configure_pending 1
#    after idle [list configureNow $winid]
}

proc configureNow {winid} {
#puts stderr "global configureNow called"
    global cfg configure_pending

    lassign $cfg w h
    set obj [. obj]
    $obj setsize $w $h
    . configure -width $w -height $h
    set rat [expr {$width / 7.0}]
    ntk_request-size .left [expr {int($rat)}] $h
    ntk_request-size .right [expr {round($rat * 6)}] $h
    set configure_pending 0
}

proc doRendernow {} {
    global base rendering

    [. obj] setall $::background_color
    ::ntk::classes::render::renderTree [. obj] .
    set rendering 0
}

proc vfspng f {
    set fd [open $f r]
    fconfigure $fd -translation binary
    set data [read $fd]
    close $fd
    pngext2:decode data $data
}

proc continuousRotation {obj incr delay} {
    set r [expr {[$obj rotate] + $incr}]

    #
    # XXX Weird stuff happens in rotate in megaimage with large angles...
    # TODO fix this. 
    # XXX it's caused by the calculation for the new size overflowing...
    #
    if {$r < 360} {
        set r [expr {$r + 360}]
    } else {
        if {$r > 360} {
            set r [expr {$r - 360}]
	}
    }
    $obj rotate $r
    ntk render $obj
    after $delay [list continuousRotation $obj $incr $delay]
}

array set ::draginfo {}

proc setSelected {w button x y globalx globaly} {
    global selected draginfo

#puts stderr "W:$w BUTTON:$button X:$x Y:$y"
    switch -- $button {
    1 {
        set draginfo(selected) $w
        set draginfo(state) pressed
        set draginfo(startx) $globalx 
        set draginfo(starty) $globaly
        $w raise $w
        #TODO ntk render $toplevel
        ntk render $w
      }
    2 {
        puts [$w rotate]
      }
    3 {
        if {![info exists draginfo(selected)]} {
            return
        }
        set s $draginfo(selected)
        set r [expr {[$s rotate] + 20}]
        if {$r > 360} {
            set r [expr {$r % 360}]
        }
        $s rotate $r
        ntk render $s
      }
    }
}

proc drag {path x y globalx globaly} {
    global draginfo

    if {![info exists draginfo(startx)]} {
        # It hasn't been pressed yet.
        return
    }
    if {"pressed" ne $draginfo(state)} {
        return
    }
    $path configure \
        -x [expr {[$path cget -x] + ($globalx - $draginfo(startx))}] \
        -y [expr {[$path cget -y] + ($globaly - $draginfo(starty))}]
    set draginfo(startx) $globalx
    set draginfo(starty) $globaly
    ntk render $path
}

proc makeDraggable path {
    $path configure -buttonpress [list setSelected $path]
    $path configure -buttonrelease "[list set ::draginfo(state) {}] ;#"
    $path configure -motion [list drag $path]
}

proc setWindowImage {w img} {
    [$w obj] setdata $img
    lassign [[$w obj] getsize] width height
    $w configure -width $width -height $height
}


proc spinme {w counter} {
    $w rotate [expr {([$w rotate] - 40) % 360}]
    $w render $w
    set counter [expr {$counter - 40}]
    if {$counter <= 0} {
        return
    }
    after 1 [list spinme $w $counter]
}

proc spin {w} {
    spinme $w 360
}


proc selectedImage {listbox display i value} {
    if {[file isdirectory $value]} {
        cd $value
#puts stderr PWD:[pwd]
        set newdata [list ..]
        foreach f [lsort -dictionary [glob -nocomplain *]] {
            if {[file isdirectory $f]} {
                lappend newdata $f
            } else {
                switch -- [file extension $f] {
                .jpeg -
                .jpg - 
                .png {
                    lappend newdata $f
                  } 
                }
            }  
        }  
        $listbox delete 0 end
        $listbox insert end {*}$newdata
        $listbox yoffset 0 ;#XXX hack
        return
    }
    set fd [open $value r]
    fconfigure $fd -translation binary
    set rawdata [read $fd]
    close $fd
    switch [file extension $value] {
    .jpeg -
    .jpg {
        set rgba [jpegext2:decode $rawdata]
      }
    .png {
        set rgba [pngext2:decode data $rawdata]
      }
    }
    [$display obj] setdata $rgba
    lassign [[$display obj] getsize] width height
    $display configure -width $width -height $height
    ntk render $display
}

proc makeTitlebar {titlepath toppath} {
    $titlepath configure -buttonpress [list setSelected $toppath]
    $titlepath configure -buttonrelease "[list set ::draginfo(state) {}] ;#"
    $titlepath configure -motion [list drag $toppath]
}

set demo_dir .
source 3D_Box.tcl
source 3D_ViewPort.tcl
source OverAndOut.tcl
#foreach f [glob [file join $::demo_dir .tcl]] {
# source $f
#}

proc evalStdin {} {
    catch {uplevel #0 [gets stdin]} result
    puts $result
    puts -nonewline %
    flush stdout 
}

proc rotateBoxStep {box n offset} {
    set keys [list -rotatexy -rotatexz -rotateyz]
    $box begin
    set val [$box cget -rotatexy]
    incr val 3
    $box configure -rotatexy $val
    set val [$box cget -rotatexz] 
    incr val 5
    $box configure -rotatexz $val
    set val [$box cget -rotateyz]
    incr val 7
    $box configure -rotateyz $val
    $box end
    incr n
    after 50 [list rotateBoxStep $box $n $offset]
}

proc rotateBox box {
    rotateBoxStep $box 1 0
}

proc box {} {
    set box [ntk box -polygons [list \
        [list \
         [list 1 1 1] \
         [list 100 1 1] \
         [list 100 100 1] \
         [list 1 100 1] [list 255 0 0 255]] \
        [list \
         [list 100 1 1] \
         [list 100 1 100] \
         [list 100 100 100] \
         [list 100 100 1] [list 0 255 0 255]] \
        [list \
          [list 100 1 100] \
          [list 1 1 100] \
          [list 1 100 100] \
          [list 100 100 100] [list 0 0 255 255]] \
        [list \
          [list 1 1 100] \
          [list 1 1 1] \
          [list 1 100 1] \
          [list 1 100 100] [list 200 200 100 255]]]
    return $box
}

proc viewportAnimate {master b1 b2 b3 a} {
    $b1 -rotatexz $a 
    $b2 -rotatexz $a -rotatexy $a
    $b3 -rotatexz $a -rotateyz $a
#puts stderr "MASTER_DRAW:[time {$master draw}]"
    $master draw
    incr a 10
    if {$a >= 360} {
        set a 0
    }
    after 100 [list viewportAnimate $master $b1 $b2 $b3 $a]
}

proc main {} {
    set wdth 800
    set hght 600
    set configure_pending 0

set demo_dir .
    set id [ntk-create-sys-window $wdth $hght]
    ntk-set-title $id "ntkWidget Demo"

#    set top [ntk toplevel . -width $wdth -height $hght -bg [list 255 255 255 0]]
    set top [ntk toplevel . -width $wdth -height $hght -bg [list 16 33 65 255]]
    . id $id
    ntk-create-event-handler $id [list ntk keyPress .] \
           [list ntk keyRelease .] [list ntk motion .] \
           [list ntk mousePress .] [list ntk mouseRelease .] \
           [list topConfigure .]
    ntk-move-sys-window $id 200 200
    ntk-map-sys-window $id

if {0} {
    ntk window .w2 -width 200 -height 200
    [.w2 obj] setall [list 255 0 255 120]
    makeDraggable .w2
}

if {0} {
    #Grid test
    ntk window .gridtest -width 60 -height 60
    [.gridtest obj] setall [list 255 255 255 255]
    ntk frame .gridtest.10 -bg [list 255 0 0 255]
    ntk frame .gridtest.50 -bg [list 0 0 255 255]
    ntk frame .gridtest.60 -bg [list 0 255 0 255]

    .gridtest.10 reqwidth 10
    .gridtest.10 reqheight 30
puts stderr "10![.gridtest.10 reqwidth]![.gridtest.10 reqheight]!"
    .gridtest.10 requestSize 10 30
ntk render .gridtest
    .gridtest.50 reqwidth 50
    .gridtest.50 reqheight 30
    .gridtest.60 reqwidth 60
    .gridtest.60 reqheight 30
    ntk grid .gridtest.10 -slot [list 0 0]
    ntk grid .gridtest.50 -slot [list 1 0] 
    ntk grid .gridtest.60 -slot [list 0 1] -columnspan 2
 
    foreach subwin [.gridtest windowChildren .gridtest] {
        makeDraggable $subwin
    }
}

if {0} {
    ntk text .text 
    .text configure -insert [list 1.0 0 "hello world"]
    .text configure -insert [list 2.0 0 "my name is HAL"]
    .text configure -insert [list 3.0 0 "I like peanut butter.\nI like cheese!\nMe too!"]
puts stderr --
puts stderr [.text text]

    set fd [open [file join $::demo_dir Poe.txt] r]
puts stderr [time {.text configure -insert [list 6.0 0 [read $fd]]}]
puts stderr [llength [.text text]]
    #puts [.text text]
}


if {1} {
    ntk window .w3 -width 300 -height 150
    [.w3 obj] setall [list 180 206 0 200] 
    #ntk window .w4 -width 230 -height 230
    #[.w4 obj] setall [list 127 127 255 160]
    #ntk window .w5 -width 400 -height 285
}

if {1} {
    ntk window .w6 -width 400 -height 400
    [.w6 obj] setall [list 255 255 255 255]
#    [.w6 obj] setall [list 0 0 0 50]
    ntk window .w6.r -width 20 -height 20 ;# -bg [list 255 0 255 0]
    ntk window .w6.g -width 40 -height 50 ;# -bg [list 255 125 255 125]
    ntk window .w6.b -width 60 -height 70 ;# -bg [list 255 125 125 125]
    ntk window .w6.a -width 50 -height 20 ;#TODO handle in the grid code this being 400
puts stderr ".w6 done"
 }
 
if {0} {
    set width 400
    set height 400
    ntk window .oao_top -width $width -height $height
    set 3rd [expr {$width / 3}]
    set rad [expr {$3rd / 2}]
puts stderr "3rd!$3rd!$rad!"
    ntk grid [overAndOut .oao_top.oao] -slot [list 0 0] -sticky [list width height]
    [.oao_top obj] clipcopyobj 0 0 $width $height [.oao_top.oao obj]
    [.oao_top obj] fillcircle $rad $rad $rad [list 255 255 100 200]
    makeDraggable .oao_top
}

if {0} {
 #3d_box .box; .box x 200 y 200
 #makeDraggable .box
 #rotateBox .box
}


if {1} {
    ntk grid .w6.r -slot [list 0 0] -sticky [list width height]
    ntk grid .w6.g -slot [list 1 0] -sticky [list width height]
    ntk grid .w6.b -slot [list 0 1] -sticky [list width height]
    ntk grid .w6.a -slot [list 1 1] -sticky [list width height]
   
    # .w6.a -slot [list 2 1]

#    .w6 configure -x 200 -y 100
#    [.w6.r obj] setall [list 255 0 0 255]
    .w6.r configure -bg [list 255 0 0 255]
#    [.w6.g obj] setall [list 0 255 0 255]
    .w6.g configure -bg [list 0 255 0 255]
#    [.w6.b obj] setall [list 0 0 255 100]
    .w6.b configure -bg [list 0 0 255 100]
#    [.w6.a obj] setall [list 255 255 255 255]
    .w6.a configure -bg [list 255 255 255 255]

    .w6 configure -x 200 -y 100

    ntk grid [ntk entry .w6.r.e -bg [list 255 255 255 255] \
            -textcolor [list 0 0 0 255]] -slot [list 0 0] -sticky [list width]

set b [ntk button .w6.g.hello -text Hello -bg royalblue \
            -command {puts Hello}]
#puts stderr "B![$b cget -width]![$b cget -height]![$b reqwidth]![$b reqheight]!"
ntk grid $b -slot [list 0 0] -sticky [list width]
#    ntk grid [ntk button .w6.g.hello -text Hello -bg royalblue \
#            -command {puts Hello}] -slot [list 0 0] -sticky [list width]

    ntk grid [ntk button .w6.g.exit -text Exit -bg orange -command {exit 0}] \
            -slot [list 1 0] -sticky [list width]

    ntk grid [ntk button .w6.b.spin -text Spin -command {spin .w6}] \
            -slot [list 0 0] -sticky [list width]

    .w6.b.spin rotate 45
    foreach subwin [.w6 windowChildren .w6] {
        makeDraggable $subwin
    }
puts stderr ".w6 2 done"
}
 

 #
 # Create the grid test area for ratios.
 #

if 0 {
 ntk window .gridtest -width 400 -height 400 ; [.gridtest obj] setall [list 255 255 255 255]

 ntk grid [ntk button .gridtest.b75 -text 75%] -columnratio 75 -slot [list 0 0]
 ntk grid [ntk button .gridtest.b90 -text 80%] -rowratio 80 -slot [list 1 0]
 ntk grid [ntk button .gridtest.bb -text "-columnspan 2"] -slot [list 0 1] -columnspan 2
 makeDraggable .gridtest
}

 #
 # Create the image selector
 # 
if {1} {
 ntk window .wimgsel -width 200 -height 300
 [.wimgsel obj] setall [list 255 255 255 150]

 ntk grid [ntk frame .wimgsel.grip] -slot [list 0 0] -sticky [list width]
 .wimgsel.grip requestSize 200 20
 ntk grid [ntk button .wimgsel.up -text "Scroll Up" -fontsize 12 \
  -command {
puts stderr "Scroll Up called"
   .wimgsel.list yview scroll -1 units
  }] -slot [list 0 1] -sticky [list width]
 ntk grid [ntk listbox .wimgsel.list] -slot [list 0 2] -sticky [list width height]
 ntk grid [ntk button .wimgsel.down -text "Scroll Down" -fontsize 12 \
  -command {
puts stderr "Scroll Down called"
   .wimgsel.list yview scroll 1 units
  }] -slot [list 0 3] -sticky [list width]

 makeTitlebar .wimgsel.grip .wimgsel
 #makeDraggable .wimgsel
}

if {0} {
 #
 # Create the display widget
 #
 ntk window .wimgdisplay -width 400 -height 300
 [.wimgdisplay obj] setall [list 0 0 0 127]
 .wimgdisplay x 200 y 200

 makeDraggable .wimgdisplay

 #
 # Setup the listbox initial directory.
 #

 cd $demo_dir
 .wimgsel.list insert end ..
 .wimgsel.list insert end {*}[glob -nocomplain -tails -directory $demo_dir *.png *.jpg]
 .wimgsel.list configure -selectioncallback [list selected.image .wimgsel.list .wimgdisplay]
}


if {0} {
 ntk clock .clock 
 .clock x 600 y 150

 makeDraggable .clock
}

if {0} {
 ntk window .fscroll -width 200 -height 200
 [.fscroll obj] setall [list 255 0 0 255]
 .fscroll y 300

 ntk grid [ntk scrollbar .fscroll.yview] -slot {0 0} -sticky height
 ntk grid [ntk frame .fscroll.f -bg [list 0 0 255 255]] -slot {1 0} \
  -sticky [list width height]
 .fscroll.f requestSize 170 170
 ntk grid [ntk scrollbar .fscroll.xview -orient horizontal] -slot {1 1} \
  -sticky width
}

if {0} {
 set w6Width [.w6 cget -width]
 set w6Height [.w6 cget -height]
 set w6Obj [.w6 obj]
 set w6aWidth [.w6.a cget -width]
 set w6aHeight [.w6.a cget -height]
 set w6aX [.w6.a cget -x]
 set w6aY [.w6.a cget -y]
 for {set y 0} {$y < $w6aHeight} {incr y} {
  for {set x 0} {$x < $w6aWidth} {incr x} {
   set xp [expr {$x + $w6aX}]
   set yp [expr {$y + $w6aY}]

   if {$xp >= 0 && $xp < $w6Width && $yp >= 0 && $yp < $w6Height} {
    lassign [$w6Obj pixel $xp $yp] r g b a
    $w6Obj pixel $xp $yp [list $r $g $b 100]
   }
  }
 }

 set w6rHeight [.w6.r cget -height]
 set w6rWidth [.w6.r cget -width]
 set w6rX [.w6.r cget -x]
 set w6rY [.w6.r cget -y]
 for {set y 0} {$y < $w6rHeight} {incr y} {
  for {set x 0} {$x < $w6rWidth} {incr x} {
   set xp [expr {$x + $w6rX}]
   set yp [expr {$y + $w6rY}]
   if {$xp >= 0 && $xp < $w6Width && $yp >= 0 && $yp < $w6Height} { 
    lassign [$w6Obj pixel $xp $yp] r g b a
    $w6Obj pixel $x $yp [list $r $g $b 200]
   }
  }
 }

 #continuousRotation .w2 -20 300
}

if {0} {
 [.w3 obj] setdata [vfspng [file join $demo_dir header3.png]]
 lassign [[.w3 obj] getsize] width height
 .w3 configure -width $width -height $height -x 70
}

if {0} {
 ntk frame .big -bg [list 120 120 140 255]
 .big requestSize 400 400
  
 ntk grid [ntk label .big.l1 -text "Hello from NexTk"] -slot {0 0} -sticky width
 ntk grid [ntk label .big.l2 -text "I'm a label"] -slot {1 0} -sticky width
 ntk grid [ntk button .big.b1 -text "I'm a button!"] -slot {0 1} -sticky width
 ntk grid [ntk button .big.b2 -text "I'm another button!"] -slot {1 1} -sticky width
 ntk grid [ntk label .big.l3 -text "I'm a label with -bd 1" -bd 1] -slot {0 2} -sticky width
 ntk grid [ntk label .big.l4 -text "I'm a label with -bd 2" -bd 2] -slot {1 2} -sticky width


 makeDraggable .big
}

if {0} {
 set b1 [box]
 $b1 -x -50 -rotateyz 45

 set b2 [box]
 $b2 -x 100 -rotatexz 45 -rotateyz 45

 set b3 [box]
 $b3 -x -200 -rotatexz 45 -rotateyz 45
puts stderr 3
}

if {0} {
 3D_ViewPort .viewport 400 400
 .viewport append-object $b1
 .viewport append-object $b2
 .viewport append-object $b3
 viewport-animate .viewport $b1 $b2 $b3 0
puts stderr 4
 makeDraggable .viewport
}



puts stderr "render"
 ntk render .
}

main

if {1} {
puts stderr "setting evalStdin"
fileevent stdin readable evalStdin
vwait forever
}
puts stderr "END !!!"

