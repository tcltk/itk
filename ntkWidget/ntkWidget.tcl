package require Itcl 4.0
package require ntkWidget

::itcl::extendedclass ntkWidget {
    private variable constructing 1
    private variable widget 

    public option -width -default 20 -configuremethod ntkWidgetConfigure
    public option -height -default 20 -configuremethod ntkWidgetConfigure
    public option -itemsize -default [list 4 8] -configuremethod ntkWidgetConfigure

    protected method ntkWidgetConfigure {option value} {
	set itcl_options($option) $value
	if {!$constructing} {
        switch -- $option {
	-width {
	    ::ntk::widget::Widget setsize $value $itcl_options(-height)
	  }
	-height {
	    ::ntk::widget::Widget setsize $itcl_options(-width) $value 
	  }
	}
	}
    }
    
    constructor {args} {
        configure {*}$args
	set widget [::ntk::widget::Widget create $itcl_options(-width) $itcl_options(-height) $itcl_options(-itemsize)]
	set constructing 0
	return $widget
    }

    public method widget {} {
        return $widget
    }

    public method line {x1 y1 x2 y2 rgbaList} {
        return [::ntk::widget::Widget line $widget $x1 $y1 $x2 $y2 $rgbaList]
    }

    public method fill {rgbaList} {
        return [::ntk::widget::Widget fill $widget $rgbaList]
    }

    public method getsize {} {
        return [::ntk::widget::Widget getsize $widget]
    }

    public method getdata {} {
        return [::ntk::widget::Widget getdata $widget]
    }

    public method blendwidget {args} {
        return [::ntk::widget::Widget blendwidget $widget {*}$args]
    }

    public method rotate {degrees} {
        return [::ntk::widget::Widget rotate $widget $degrees]
    }

}
