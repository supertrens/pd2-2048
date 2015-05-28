import QtQuick 2.3

//done
Rectangle {
    id: origin

    property var numInterieur: repeater

    y: 170
    width: 500    //My gameView size
    height: 500
    color: "#bbada0"
    radius:6

    Grid {

        id: grid
        x:15;  y:15;
        anchors.centerIn: parent
        columns: 4 ; rows:4; spacing: 15

        Repeater {
            id: repeater
            model: 16

            EItem { //each square size
                width: 425 / 4;
                height: 425 / 4;
                radius: 5


            }
        }
    }
}
