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

set defaultTheme [::ntk::classes::styleTheme ::ntk::theme::default default "" [array get colors]]
$defaultTheme styleConfigure . \
            -borderwidth        1 \
            -background         $colors(-frame) \
            -foreground         black \
            -troughcolor        $colors(-darker) \
            -font               Vera.ttf \
            -selectborderwidth  1 \
            -selectbackground   $colors(-selectbg) \
            -selectforeground   $colors(-selectfg) \
            -insertwidth        1 \
            -indicatordiameter  10
$defaultTheme styleConfigure TButton \
    -anchor center -padding "3 3" -width -9 \
    -relief raised -shiftrelief 1
$defaultTheme styleMap TButton -relief [list {!disabled pressed} sunken]

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

set classicTheme [::ntk::classes::styleTheme ::ntk::theme::classic classic default [array get colors]]
$classicTheme styleConfigure TButton \
    -anchor center -padding "3m 1m" -relief raised -shiftrelief 1
$classicTheme styleMap TButton -relief [list {!disabled pressed} sunken]

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

set clamTheme [::ntk::classes::styleTheme ::ntk::theme::clam clam default [array get colors]]
$clamTheme styleConfigure TButton \
    -anchor center -width -11 -padding 5 -relief raised
$clamTheme styleMap TButton \
            -background [list \
                             disabled $colors(-frame) \
                             pressed $colors(-darker) \
                             active $colors(-lighter)] \
            -lightcolor [list pressed $colors(-darker)] \
            -darkcolor [list pressed $colors(-darker)] \
            -bordercolor [list alternate "#000000"]

::ntk::classes::styleTheme::registerElement default background ::ntk::classes::defaultBackgroundElement
::ntk::classes::styleTheme::registerElement default border ::ntk::classes::defaultBorderElement
::ntk::classes::styleTheme::registerElement default focusring ::ntk::classes::defaultFocusringElement
::ntk::classes::styleTheme::registerElement default padding ::ntk::classes::defaultPaddingElement
::ntk::classes::styleTheme::registerElement default text ::ntk::classes::defaultTextElement
::ntk::classes::styleTheme::registerElement default image ::ntk::classes::defaultImageElement
::ntk::classes::styleTheme::registerElement default label ::ntk::classes::defaultLabelElement
::ntk::classes::styleTheme::registerElement default textarea ::ntk::classes::defaultTextareaElement

::ntk::classes::styleTheme::registerElement classic background ::ntk::classes::classicBackgroundElement
::ntk::classes::styleTheme::registerElement classic border ::ntk::classes::classicBorderElement
::ntk::classes::styleTheme::registerElement classic focusring ::ntk::classes::classicFocusringElement
::ntk::classes::styleTheme::registerElement classic padding ::ntk::classes::classicPaddingElement
::ntk::classes::styleTheme::registerElement classic text ::ntk::classes::classicTextElement
::ntk::classes::styleTheme::registerElement classic image ::ntk::classes::classicImageElement
::ntk::classes::styleTheme::registerElement classic label ::ntk::classes::classicLabelElement
::ntk::classes::styleTheme::registerElement classic textarea ::ntk::classes::classicTextareaElement

::ntk::classes::styleTheme::registerElement clam background ::ntk::classes::clamBackgroundElement
::ntk::classes::styleTheme::registerElement clam border ::ntk::classes::clamBorderElement
::ntk::classes::styleTheme::registerElement clam focusring ::ntk::classes::clamFocusringElement
::ntk::classes::styleTheme::registerElement clam padding ::ntk::classes::clamPaddingElement
::ntk::classes::styleTheme::registerElement clam text ::ntk::classes::clamTextElement
::ntk::classes::styleTheme::registerElement clam image ::ntk::classes::clamImageElement
::ntk::classes::styleTheme::registerElement clam label ::ntk::classes::clamLabelElement
::ntk::classes::styleTheme::registerElement clam textarea ::ntk::classes::clamTextareaElement

::ntk::classes::styleTheme::registerLayout default TButton \
[list Button.background [list -sticky nswe -border 1 -children \
  [list Button.border [list -sticky nswe -border 1 -children \
    [list Button.focusring [list -sticky nswe -children \
        [list Button.padding [list -sticky nswe -children \
	    [list Button.label [list -sticky nswe]] \
	]] \
    ]] \
  ]] \
]]

::ntk::classes::styleTheme::registerLayout clam TButton \
[list Button.background [list -sticky nswe -border 1 -children \
  [list Button.border [list -sticky nswe -border 1 -children \
    [list Button.focusring [list -sticky nswe -children \
        [list Button.padding [list -sticky nswe -children \
	    [list Button.label [list -sticky nswe]] \
	]] \
    ]] \
  ]] \
]]

::ntk::classes::styleTheme::registerLayout classic TButton \
[list Button.background [list -sticky nswe -border 1 -children \
  [list Button.border [list -sticky nswe -border 1 -children \
    [list Button.focusring [list -sticky nswe -children \
        [list Button.padding [list -sticky nswe -children \
	    [list Button.label [list -sticky nswe]] \
	]] \
    ]] \
  ]] \
]]
