import QtQuick 2.3

Rectangle {

    id:tileContainer


    property alias myScore: score.text
    property alias myBestScore: bestScore.text
    property alias myStep: step.text
    property alias myTotalStep: totalStep.text

    width: 550
    height: 100
    color: "#cdc0b4"



    FontLoader { id: localFont; source: "qrc:///fonts/DroidSansFallback.ttf" }

/*
    Text {
        id: gameName
        font.family: localFont.name
        font.pixelSize: 55
        font.bold: true
        text: "2048"
        color: helper.myColors.fgdark
        }
*/

    Grid {
        columns: 4

        Text {
            width: 100; height: 50
            text: "Score:"
            color: "black"
            font.pixelSize: 20
            font.family: localFont.name
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: score
            width: 100; height: 50
            font.bold: true
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft


        }
        Text {
            width: 100; height: 50
            text: "Best Score:"
            color: "white"
            font.pixelSize: 20
            font.family: localFont.name
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: bestScore
            width: 100; height: 50
            font.bold: true
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
        }
        Text {
            width: 100; height: 50
            text: "Step:"
            color: "black"
            font.pixelSize: 20
            font.family: localFont.name
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: step
            width: 100; height: 50
            font.bold: true
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
        }
        Text {
            width: 100; height: 50
            text: "Total Step:"
            color: "white"
            font.pixelSize: 20
            font.family: localFont.name
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: totalStep
            width: 100; height: 50
            font.bold: true
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
        }
    }
}

