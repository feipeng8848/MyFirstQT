import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3

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
        text: qsTr("ChangeName")
    }

    //连接c++函数
    Connections {
        target: button
        //函数名不能以大写字母开头，否则会报错
        //这里修改之后，UI上会同步更新
        onClicked: context.newName("我已经更新了")
    }
}
