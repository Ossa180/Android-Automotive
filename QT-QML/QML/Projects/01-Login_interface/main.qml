import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 650
    title: "Welcome App"
    color: "white"  // Set the background color to white

    Grid {
        anchors.fill: parent
        anchors.margins: 10
        columns: 3
        rows: 3

        // Image at Top Left
        Image {
            source: "file:///home/mohamed/Pictures/iti.png"
            width: 180
            height: 150
            //fillMode: Image.Stretch
            fillMode: Image.PreserveAspectFit
            anchors.top: parent.top
            anchors.left: parent.left
            //anchors.horizontalCenter: parent.horizontalCenter

        }

        // Header at Mid Top
        Text {
            text: "Hello ITI"
            font.pixelSize: 24
            font.bold: true
            font.italic: true
            font.underline: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            //anchors.right: parent.right
            anchors.topMargin: 20
        }

        // Username Input at Center
        TextField {
            id: userNameInput
            placeholderText: "Enter your name"
            width: parent.width * 0.4
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        // Button under TextField
        Button {
            id: loginButton
            text: "Login"
            width: userNameInput.width*0.6
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: userNameInput.bottom
            anchors.topMargin: 20

            onClicked: {
                var name = userNameInput.text
                if (name) {
                    welcomeText.text = "Welcome, " + name
                }
            }
        }

        // Welcome Text outside the Button
        Text {
            id: welcomeText
            text: ""
            font.pixelSize: 18
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: loginButton.bottom
            anchors.topMargin: 20
        }
    }
}
