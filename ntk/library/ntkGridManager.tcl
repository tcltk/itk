#---------------------------------------------------------------------------
# ntkWidget ntkGridManager.tcl --
#
# This file contains a ntkWidget window command implementation
#
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
# RCS: @(#) $Id: ntkGridManager.tcl,v 1.1.2.3 2007/10/14 23:42:56 wiede Exp $
#--------------------------------------------------------------------------

::itcl::eclass ::ntk::classes::gridManager {
    inherit ::ntk::classes::helpers ::ntk::classes::render ::ntk::classes::grid

    public component mySelf

    private variable constructing 1

    protected variable grid [list]
    protected variable remanage layout
    protected variable peakrow 0
    protected variable peakcolumn 0
    protected variable free gridFree

    delegate method grid to mySelf as {setGet grid}
    delegate method remanage to mySelf as {setGet remanage}
    delegate method peakrow to mySelf as {setGet peakrow}
    delegate method peakcolumn to mySelf as {setGet peakcolumn}
    delegate method free to mySelf as {setGet free}

    public option -sticky -default {} -configuremethod gridManagerConfig
    public option -columnspan -default 1 \
            -configuremethod gridManagerConfig
    public option -rowspan -default 1 \
            -configuremethod gridManagerConfig
    public option -columnratio -default 0 \
            -configuremethod gridManagerConfig
    public option -rowratio -default 0 \
            -configuremethod gridManagerConfig
    public option -slot -default [list 0 0] \
            -configuremethod gridManagerConfig

    public method gridManagerConfig {option value} {
#puts stderr "gridManagerConfig!$option!$value!"
        set itcl_options($option) $value
        if {!$constructing} {
#	    uplevel 1 $remanage
        }
    }

    public method setGet {what {value {}}} {
	if {$value eq ""} {
            return [set $what]
	} else {
	    set $what $value
	}
    }

    constructor {path args} {
	set mySelf $this

	::itcl::setcomponent $path geometryManager $this
	::itcl::adddelegatedoption $path delegate option -sticky \
	        to geometryManager
	::itcl::adddelegatedoption $path delegate option -columnspan \
	        to geometryManager
	::itcl::adddelegatedoption $path delegate option -rowspan \
	        to geometryManager
	::itcl::adddelegatedoption $path delegate option -columnratio \
	        to geometryManager
	::itcl::adddelegatedoption $path delegate option -rowratio \
	        to geometryManager
	::itcl::adddelegatedoption $path delegate option -slot \
	        to geometryManager
	::itcl::adddelegatedmethod $path delegate method peakcolumn \
	        to geometryManager
	::itcl::adddelegatedmethod $path delegate method peakrow \
	        to geometryManager
        set constructing 0
#       $remanage
        return $this
    }
}

