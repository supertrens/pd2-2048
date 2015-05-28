import QtQuick 2.3

Rectangle {
    id: contenuCasier
    width:  430/4  //size of the number container
    height: 430/4
    radius: 3
    color: "#cdc0b4" // default color

    property alias numero: nomCasier.text
    property alias eNumColor: nomCasier.color

    property string indiceCasier: ""   //label
    property int largueurCasier: 55
    property color couleurCasier: "#776e62"
    property int moveAnimTime: 100
    property int newTileAnimTime: 200
    property bool runNewTileAnim: false
    property bool destroyFlag: false



    Text {

        id: nomCasier                   //tileLabel
        text: indiceCasier
        color: couleurCasier
        font.pixelSize: largueurCasier  // la taille du numero
        font.family: localFont.name
        font.bold: true
        anchors.centerIn: parent

        Behavior on text {
            PropertyAnimation { target: contenuCasier
                property: "opacity"
                from: 0.5
                to: 1
                duration: moveAnimTime
        }
      }
    }  //TEXT CLOSED

    ParallelAnimation
    {
        running: runNewTileAnim
        NumberAnimation
        {
            target: contenuCasier
            property: "opacity"
            from: 0.0
            to: 1.0
            duration: newTileAnimTime
        }

        ScaleAnimator
        {
            target: contenuCasier
            from: 0
            to: 1
            duration: newTileAnimTime
            easing.type: Easing.OutQuad
        }
    } // ParallelAnimation closed


    Behavior on color
    {
        ColorAnimation
        {
            duration: moveAnimTime
        }
    } // Behaviour Closed



    Behavior on y
    {
        NumberAnimation
        {
            duration: moveAnimTime
            onRunningChanged:
            {
                if ((!running) && destroyFlag)
                {
                    contenuCasier.destroy();
                }
            }
        }
    } //closed Behavior on y


    Behavior on x
    {
        NumberAnimation
        {
            duration: moveAnimTime
            onRunningChanged:
            {
                if ((!running) && destroyFlag)
                {
                    contenuCasier.destroy();
                }
            }
        }
    } //Behavior on X closed

} // RECTANGLE CLOSED

