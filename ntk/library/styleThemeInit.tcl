array set colors {
        -frame          "#d9d9d9"
        -window         "#ffffff"
        -activebg       "#ececec"
        -selectbg       "#4a6984"
        -selectfg       "#ffffff"
        -darker         "#c3c3c3"
        -disabledfg     "#a3a3a3"
        -indicator      "#4a6984"
}

set defaultTheme [::ntk::classes::styleTheme ::ntk::theme::default default [array get colors]]
$defaultTheme configure TButton \
    -anchor center -padding "3 3" -width -9 \
    -relief raised -shiftrelief 1
$defaultTheme map TButton -relief [list {!disabled pressed} sunken]

array set colors {
        -frame          "#d9d9d9"
        -window         "#ffffff"
        -activebg       "#ececec"
        -troughbg       "#c3c3c3"
        -selectbg       "#c3c3c3"
        -selectfg       "#000000"
        -disabledfg     "#a3a3a3"
        -indicator      "#b03060"
}

set classicTheme [::ntk::classes::styleTheme ::ntk::theme::classic classic [array get colors]]
$classicTheme configure TButton \
    -anchor center -padding "3m 1m" -relief raised -shiftrelief 1
$classicTheme map TButton -relief [list {!disabled pressed} sunken]

array set colors {
        -disabledfg     "#999999"
        -frame          "#dcdad5"
        -window         "#ffffff"
        -dark           "#cfcdc8"
        -darker         "#bab5ab"
        -darkest        "#9e9a91"
        -lighter        "#eeebe7"
        -lightest       "#ffffff"
        -selectbg       "#4a6984"
        -selectfg       "#ffffff"
}

set clamTheme [::ntk::classes::styleTheme ::ntk::theme::clam clam [array get colors]]
$clamTheme configure TButton \
    -anchor center -width -11 -padding 5 -relief raised
$clamTheme map TButton \
            -background [list \
                             disabled $colors(-frame) \
                             pressed $colors(-darker) \
                             active $colors(-lighter)] \
            -lightcolor [list pressed $colors(-darker)] \
            -darkcolor [list pressed $colors(-darker)] \
            -bordercolor [list alternate "#000000"]

::ntk::classes::styleTheme::registerElement default background ::ntk::classes::defaultBackgroundElement
::ntk::classes::styleTheme::registerElement default border ::ntk::classes::defaultBorderElement
::ntk::classes::styleTheme::registerElement default focus ::ntk::classes::defaultFocusElement
::ntk::classes::styleTheme::registerElement default padding ::ntk::classes::defaultPaddingElement
::ntk::classes::styleTheme::registerElement default text ::ntk::classes::defaultTextElement
::ntk::classes::styleTheme::registerElement default image ::ntk::classes::defaultImageElement
::ntk::classes::styleTheme::registerElement default label ::ntk::classes::defaultLabelElement
::ntk::classes::styleTheme::registerElement default textarea ::ntk::classes::defaultTextareaElement

::ntk::classes::styleTheme::registerLayout default TButton \
[list Button.border [list -sticky nswe -border 1 -children \
    [list Button.focus [list -sticky nswe -children \
        [list Button.padding [list -sticky nswe -children \
	    [list Button.label [list -sticky nswe]] \
	]] \
    ]] \
]]
