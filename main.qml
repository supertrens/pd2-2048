import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Window 2.1

import CppToQml 2.0 // The Library I create in c++ codes // main.cpp


ApplicationWindow
{
    id: mainWindow
    visible: true
    width: 550
    height: 740
    title: qsTr(" Project-2 2048 Game");


    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2

    ExclusiveGroup { id: labelSettingsGroup }
    ExclusiveGroup { id: languageSettingsGroup }

    menuBar: MenuBar {

        Menu { // Menu 1

            title: qsTr("FILE")
            MenuItem {
                text: qsTr("New Game")
                shortcut: "Ctrl+N"
                onTriggered:  {
                                 game.startUpFunction()
                                 origin.qmlShow();
                                 origin.focus = true;
                }
            }
            MenuItem {
                text: qsTr("Exit")
                shortcut: "Ctrl+Q"
                onTriggered:{
                    game.finishGame()

               }
            }

            MenuItem {
                text: qsTr("Undo")
                shortcut: "Ctrl+Z"
                onTriggered:  {
                    game.undo();
                    origin.qmlShow();
                if(!game.GetStep) {
                    footer.marcheArriere = true;
               }
             }
           }
         }//Menu 1 Closed

        Menu {// Menu 2

            title: qsTr("LANGUAGE")
            MenuItem {
                text: "English"
                checkable: true
                exclusiveGroup: languageSettingsGroup
                checked: settings.value("language") === "en_US" ? true : false
                onTriggered: {
                    if (settings.value("language") !== "en_US") {
                        settings.setValue("language", "en_US");
                        game.restartGame()

                    }
                }
            }
            MenuItem {
                text: "简体中文"
                checkable: true
                exclusiveGroup: languageSettingsGroup
                checked: settings.value("language") === "zh_TW" ? true : false
                onTriggered: {
                    if (settings.value("language") !== "zh_TW") {
                        settings.setValue("language", "zh_TW");
                       game.restartGame()
                    }
                }
            }
            MenuItem {
                text: "Francais"
                checkable: true
                exclusiveGroup: languageSettingsGroup
                checked: settings.value("language") === "fr_FR" ? true : false
                onTriggered: {
                    if (settings.value("language") !== "fr_FR") {
                        settings.setValue("language", "fr_FR");
                        game.restartGame();
                    }
                }
            }
        } // Menu 2 closed

        Menu { //Menu 3

            id: helpMenu
            title: qsTr("CONTACT")
            MenuItem {
                text: qsTr("About Me")
                onTriggered: aboutDialog.open();
            }

          } //Menu 3Closed

      } //MenuBar CLosed









/**************************************************************************/


Item {
    id: origin

    property int casier

    function qmlClear()
    {
        for(casier = 0 ; casier < 16; casier++)
        {
            myBoard.numInterieur.itemAt(casier).numero = "";
            myBoard.numInterieur.itemAt(casier).color = "#cdc0b4";
            myBoard.numInterieur.itemAt(casier).eNumColor= "black";
        }
    }

    function qmlShow()
    {
        qmlClear();

        for(casier = 0; casier < 16; casier++) {
            if(game.showBoard(casier))
            {
                myBoard.numInterieur.itemAt(casier).numero = game.showBoard(casier);
                myBoard.numInterieur.itemAt(casier).color = game.color(casier);
                myBoard.numInterieur.itemAt(casier).eNumColor = game.numColor(casier);
            }
        }
          infomation.myScore    =  game.getScore;
          infomation.myStep     =  game.getStep;
          infomation.myBestScore=  game.getBestScore;
          infomation.myTotalStep=  game.getTotalStep;
        if( game.getStep > 0)
        {
            footer.marcheArriere = true;
        }
    }

    width: 550 ; height: 740

    Keys.onPressed: {
        switch(event.key) {
        case Qt.Key_Up:
            game.moveDir(GamePlay.Move_Up);
            origin.qmlShow();
            break;
        case Qt.Key_Down:
            game.moveDir(GamePlay.Move_Down);
            origin.qmlShow();
            break;
        case Qt.Key_Left:
            game.moveDir(GamePlay.Move_Left);
            origin.qmlShow();
            break;
        case Qt.Key_Right:
            game.moveDir(GamePlay.Move_Right);
            origin.qmlShow();
            break;
        default:
            break;
        }
    }

    GamePlay { id: game }

    Rectangle {
        id: container
        anchors.fill: parent
        color: "#faf8ef" // the body color

      Display { id: infomation }

      BoardBody{
            id: myBoard //panel
            anchors.centerIn: parent
             }

      Foot {
            id: footer
            anchors.bottom: parent.bottom
            onEStart: {
                game.startUpFunction()
                origin.qmlShow();
                origin.focus = true;
                footer.marcheArriere = true;
            }
            onEBack: {
                game.undo();
                origin.qmlShow();
                if(!game.GetStep) {
                    footer.marcheArriere = true;
                }

            }
        }
    }


    MessageDialog
          {
              id: aboutDialog
              title: qsTr("About 2048-Qt")
              text: qsTr("<p style='font-weight: bold; font-size: 24px'>2048-Qt</p><p>Version " + settings.getVersion() + "</p><p>F74027036 皮宜恩 &lt;trens552@gmail.com&gt;</p>")
              standardButtons: StandardButton.Ok
          }

    MessageDialog
         {
              id:gameOver
              title: qsTr("Game Over")
              text: qsTr("Game Over!")
              standardButtons: StandardButton.Retry | StandardButton.Abort
              onAccepted: {
                 game.startUpFunction();
              }
              onRejected: game.finishGame();
          }

          MessageDialog {
              id: gamWin
              title: qsTr("You Win")
              text: qsTr("You win! do you want to Continue playing?")
              standardButtons: StandardButton.Yes | StandardButton.No
              onYes: {
                  game.addPoint = false;
                  close()
              }
              onNo: game.startUpFunction();
              onRejected: {
                  MyScript.checkTargetFlag = false;
                  close()
              }
          }


          FontLoader { id: localFont; source: "qrc:///fonts/DroidSansFallback.ttf" }
 }
} // End Of ApplicationWindow

