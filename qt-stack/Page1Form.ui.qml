import QtQuick 2.12
import QtQuick.Controls 2.5

Page {

    title: qsTr("Page 1")

    Label {
        text: context.Name
    }

    Button {
        id: button
        x: 185
        y: 241
        text: context.Name
    }

    Connections{
        target: button
        onClicked:context.newName("我又变回来了")
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
