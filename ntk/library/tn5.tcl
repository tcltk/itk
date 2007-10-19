package require Itcl 4.0
package require megaimage
package require freetypeext
package require pngext2
package require jpegext2
package require ntk
lappend auto_path .
package require ntkWidget

proc eval_stdin {} {
    set cmd [gets stdin]
    catch {uplevel #0 $cmd} result
    puts $result
    puts -nonewline "% "
    flush stdout
}

set wdth 800
set hght 600
set configure_pending 0

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
    after idle [list configureNow $winid]
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

proc endImageDrag {path button x y globalx globaly} {
    global imagedrag

puts stderr "endImageDrag"
    if {$button == 1} {
        unset imagedrag($path)
    }
}

proc imageDrag {path x y globalx globaly} {
    global imagedrag

puts stderr "imageDrag"
    if {![info exists imagedrag($path)]} {
        return
    }
    lassign $imagedrag($path) oldx oldy
    set xd [expr {$x - $oldx}]
    set yd [expr {$y - $oldy}]
    set newx [expr {[$path cget -x] + $xd}] 
    set newy [expr {[$path cget -y] + $yd}]
    lassign [[$path obj] getsize] width height
    lassign [[[$path windowParent] obj] getsize] pwidth pheight
    set minx [expr {-($width - $pwidth)}]
    set miny [expr {-($height - $pheight)}]
    if {$newx > 0} {
        set newx 0
    }
    if {$newy > 0} {
        set newy 0
    }
    if {$newx < $minx} {
        set newx $minx
    }
    if {$newy < $miny} {
        set newy $miny
    }

    if {$pwidth > $width} {
        set newx 0
    }
    if {$pheight > $height} {
        set newy 0
    }
    $path x $newx y $newy
    ntk render $path
}

array set imagedrag {}
proc startImageDrag {path button x y globalx globaly} {
    global imagedrag

puts stderr "startImageDrag"
    if {$button == 1} {
        set imagedrag($path) [list $x $y]
    }
}

proc fillListbox {listbox} {
    $listbox delete 0 end
    $listbox insert end ..
    foreach f [lsort -dictionary [glob -nocomplain *]] {
        if {[file isdirectory $f]} {
            $listbox insert end $f 
        } else {
            switch -- [string tolower [file extension $f]] {
            .jpeg -
            .jpg -
            .png {
                $listbox insert end $f
              }
           }
        }
    }
}

proc selectedImage {listbox i value} {
puts stderr "selectedImage $listbox $i $value"

   if {$value eq ".."} {
      cd ..
      fillListbox $listbox
      return
   } 

   if {[file isdirectory $value]} {
      cd $value
      fillListbox $listbox
   } else {
       set fd [open $value r]
       fconfigure $fd -translation binary
       set rawdata [read $fd]
       close $fd
       switch [string tolower [file extension $value]] {
       .jpeg -
       .jpg {
           set rgba [jpegext2:decode $rawdata]
         }
       .png {
           set rgba [pngext2:decode data $rawdata]
         }
       }
       [.right.image obj] setdata $rgba
       lassign [[.right.image obj] getsize] w h
puts stderr "image size: $w $h"
       .right.image configure -width $w -height $h -x 0 -y 0
       ntk render .right.image
   }
}


proc createUI {width height} {
    ntk grid [ntk frame .left] -slot {0 0} -sticky height
#    ntk grid [ntk frame .right -bg [list 255 255 255 0] ] -slot {1 0} -sticky height
    ntk grid [ntk frame .right] -slot {1 0} -sticky height
    set rat [expr {$width / 7}]
    .left requestSize $rat $height
    .right requestSize [expr {$rat * 6}] $height

    ntk grid [ntk scrollbar .left.yview \
            -command [list .left.list yview]] -slot {0 0} -sticky height
    ntk grid [ntk scrollbar .left.xview -orient horizontal \
            -command [list .left.list xview]] -slot {1 1} -sticky width
    ntk grid [ntk listbox .left.list \
        -fontsize 14 \
        -xscrollcommand [list .left.xview setView] \
        -yscrollcommand [list .left.yview setView]] \
        -slot {1 0} -sticky [list width height]

    ntk window .right.image -width 1 -height 1
    .right.image configure -buttonpress [list startImageDrag .right.image] \
        -motion [list imageDrag .right.image] -buttonrelease [list endImageDrag .right.image]
}

proc main {} {
    upvar wdth wdth
    upvar hght hght

    set id [ntk-create-sys-window $wdth $hght]
    ntk-set-title $id "ntkWidget Image Viewer Demo"

    set top [ntk toplevel . -width $wdth -height $hght -bg [list 255 255 255 0]]
    . id $id
    ntk-create-event-handler $id [list ntk keyPress .] \
           [list ntk keyRelease .] [list ntk motion .] \
           [list ntk mousePress .] [list ntk mouseRelease .] \
           [list topConfigure .]
    ntk-move-sys-window $id 200 200
    ntk-map-sys-window $id
    createUI 800 600
    fillListbox .left.list
    .left.list configure -selectioncallback [list selectedImage]
    ntk render .
}

main
if {1} {
puts stderr "setting eval-stdin"
fileevent stdin readable eval_stdin
vwait forever
}
puts stderr "END !!!"
