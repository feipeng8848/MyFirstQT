import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("Home")

    Label {
        text: context.Name
        anchors.centerIn: parent
    }

    Button {
        id: button
        x: 91
        y: 254
        text: qsTr("Button")
    }

    DelayButton {
        id: delayButton
        x: 311
        y: 301
        text: qsTr("Delay Button")
    }

    Switch {
        id: element
        x: 44
        y: 70
        text: qsTr("Switch")
    }

    ToolButton {
        id: toolButton
        x: 340
        y: 111
        text: qsTr("Tool Button")
    }

    Text {
        id: element1
        x: 87
        y: 153
        text: qsTr("Text")
        font.pixelSize: 12
    }
}
