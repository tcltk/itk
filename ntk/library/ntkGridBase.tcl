::itcl::eclass ::ntk::classes::gridBase {
    inherit ::ntk::classes::render

    public variable grid [list]
    public variable remanage [list]
    public variable peakrow [list]
    public variable peakcolumn [list]
    public variable free [list]
    public variable removeFromManager [list]

    public option -sticky [list]
    public option -columnspan 1
    public option -rowspan 1
    public option -slot [list 0 0]
    public option -columnratio 0
    public option -rowratio 0

if {0} {
    constructor {remanage free removeFromManager {peekrow 0} {peekcolumn 0}} {
        configure -path $path
        configure -remanage $remanage
        configure -free $free
        configure -removeFromManager $removeFromManager
        configure -peekrow $peekrow
        configure -peekcolumn $peekcolumn
    }
}
}

