import QtQuick 2.0
/*
//列布局
Column {
    spacing: 5 //间隔
    Rectangle { color: "red"; width: 50; height: 50 }
    Rectangle { color: "green"; width: 20; height: 50 }
    Rectangle { color: "blue"; width: 50; height: 20 }
   }
*/

/*
//行布局
//Row {
//    spacing: 5 //间隔
//    Rectangle { color: "red"; width: 50; height: 50 }
//    Rectangle { color: "green"; width: 20; height: 50 }
//    Rectangle { color: "blue"; width: 50; height: 20 }
//}
*/

/*
//网格布局
//Grid {
//    columns: 3  //列数
//    spacing: 5 //间隔
//    Rectangle { color: "red"; width: 50; height: 50 }
//    Rectangle { color: "green"; width: 20; height: 50 }
//    Rectangle { color: "blue"; width: 50; height: 20 }
//    Rectangle { color: "blue"; width: 30; height: 20 }
//    Rectangle { color: "blue"; width: 20; height: 50 }
//}
*/

/*
//Flow布局
Rectangle {
    color: "lightblue"
    width: 300; height: 200

    Flow {
        anchors.fill: parent
        anchors.margins: 4
        spacing: 10
        flow: Flow.TopToBottom  //从上到下相邻排列

        Text { text: qsTr("text1"); font.pixelSize: 40 }
        Text { text: qsTr("text2"); font.pixelSize: 40 }
        Text { text: qsTr("text3"); font.pixelSize: 40 }
        Text { text: qsTr("text4"); font.pixelSize: 40 }
        Text { text: qsTr("text5"); font.pixelSize: 40 }
        Rectangle { color: "blue"; width: 20; height: 50 }
        Text { text: qsTr("text6"); font.pixelSize: 40 }
        Text { text: qsTr("text7"); font.pixelSize: 40 }
    }
}
*/

/*
//重复器
Rectangle {
    width: 400; height: 400; color: "black"

    Grid {
        x: 5; y: 5
        rows: 5; columns: 5; spacing: 5;

        Repeater {
            model: 25;
            Rectangle {
                width: 70; height: 70; color: "lightgreen";

                Text {
                    text: index
                    font.pixelSize: 30
                    anchors.centerIn: parent
                }
            }
        }
    }
}
*/

/*
//锚布局(相对位置)
Rectangle {
    id: rect0; width: 400; height: 400; color: "black"
    Rectangle {
        x: 40; y: 40
        id: rect; width: 50; height: 50; color: "lightgreen"
    }
    Text {
        text: qsTr("text1"); font.pixelSize: 40; color: "red"

        anchors.horizontalCenter: rect.horizontalCenter;
        anchors.top: rect.bottom;
        anchors.topMargin: 5;
    }
    Text {
        text: qsTr("text2"); font.pixelSize: 40; color: "red"

        anchors.verticalCenter: rect.verticalCenter;
        anchors.left: rect.right;
        anchors.leftMargin: 5;
    }
}
*/


//堆叠顺序
Rectangle {
    id: rect0; width: 400; height: 400; color: "black"
    Rectangle {
        z: 1
        color: "red"
        width: 100; height: 100;        border.color: "lightgreen"
        border.width: 5
        radius: 10
    }
    Rectangle {
        color: "blue"
        x: 50; y: 50; width: 100; height: 100
    }
    Rectangle {
        color: "blue"
        x: 200; y: 200; width: 100; height: 100
        border.color: "lightgreen"
        border.width: 5
        radius: 10
        smooth: true

        Rectangle {
            z: -1
            color: "red"
            x: 50; y: 50; width: 100; height: 100
        }
    }
}


//测试
//Rectangle {
//    id: root
//    color: "green"
//    width: 200
//    height: 200

//    // 发送给 Qt Widgets 的信号
//    signal qmlSignal(int number, string str)
//    // 从 Qt Widgets 接收到的信号
//    signal cSignal

//    Text {
//        id: myText
//        text: "Click me"
//        font.pointSize: 14
//        anchors.centerIn: parent
//    }

//    MouseArea {
//        anchors.fill: parent
//        onClicked: root.qmlSignal(1, "FROM QML")
//    }

//    // 信号处理程序（处理从 Qt Widgets 接收到的信号）
//    onCSignal: {
//        //root.color = "blue"
//        myText.text = "Call the qml signal handler"
//    }
//}
