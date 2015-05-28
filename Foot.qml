import QtQuick 2.3
import QtQuick.Controls 1.2

Item {
    property alias marcheArriere: undo.enabled

    signal eStart()
    signal eBack()


    width: 360; height: 100

    Button {
        width: 129;
        height: 40
        x:110
        text: qsTr("New Game")
        onClicked: parent.eStart()
    }

    Button {
        id: undo
        enabled: false
        x: 300
        width: 129; height: 40
        text: qsTr("Undo")
        onClicked: parent.eBack()
    }

    Text {
        anchors.bottom: parent.Center
        anchors.centerIn : parent.Center
        font.family: localFont.name
        font.pixelSize: 18
        font.bold: true
        font.italic: true
        font.underline: true
        color: "#8f7a66"
    }
}
