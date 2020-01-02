import QtQuick 2.0
import QtQuick.XmlListModel 2.0
import QtWebEngine 1.0

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

/*
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
*/

/*
//Text
Rectangle {
    width: 200; height: 200; color: "lightgreen"
    FontLoader {id:fixedFont; name:"Courier"}
    Text {
        width: 100; height: 100; x: 50; y: 50;
        color: "red"

        font.family: fixedFont.name
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        //文本换行
        wrapMode: Text.WordWrap
        //链接信号 link表示被单击时的连接
        textFormat: Text.RichText
        text: "<a href = \"http://www.baidus.com\">here</a>"
        onLinkActivated: console.log(link+" link activated")
    }
}
*/

/*
//TextEdit TextInput
Column {
    Text {
        id: name
        text: qsTr("<b>Hello</b> <i>World!</i>")
    }
    TextEdit {
        width: 200
        text: qsTr("<b>Hello</b> <i>World!</i>")
        font.family: "Helvetica"
        font.pointSize: 20;
        color: "blue"
        focus: true
    }
    TextInput {
        width: 50; height: 50
        validator: IntValidator{ bottom: 11; top: 31;}
        focus: true
    }
}
*/

/*
//鼠标点击、拖拽、按键等
Rectangle {
    id: rect
    width: 400; height: 400; color: "#e8dedc"

    Rectangle {
        id: btn
        x: 10; y: 10; width: 80; height: 30; color: "#1cf39a"
        focus: true
        //透明度
        opacity: (rect.width - btn.x)/rect.width
        Text {
            anchors.fill: parent
            text: qsTr("Button")
            color: "#000000"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        MouseArea {
            anchors.fill: parent
            drag.target: btn
            drag.axis: Drag.XandYAxis
            drag.minimumX: 0
            drag.maximumX: rect.width - btn.width
            drag.minimumY: 0
            drag.maximumY: rect.height - btn.height
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {
                if (mouse.button === Qt.LeftButton)
                {
                    parent.color = "blue"
                }
                else if ((mouse.button === Qt.RightButton) && (mouse.modifiers & Qt.ShiftModifier))
                {
                    parent.color = "red"
                }
                else
                {
                    parent.color = "#1cf39a";
                }
            }
        }
        Keys.onPressed: {
            if (event.key === Qt.Key_D)
            {
                btn.x += 2;
            }
            if (event.key === Qt.Key_A)
            {
                btn.x -= 2;
            }
            if (event.key === Qt.Key_S)
            {
                btn.y += 2;
            }
            if (event.key === Qt.Key_W)
            {
                btn.y -= 2;
            }
            //event.accepted设置为true可以防止事件向上层传播
            event.accepted = true;
        }
    }
}
*/

/*
//方向键
Grid {
    width: 100; height: 400;
    columns: 2

    Rectangle {
        id: topLeft
        width: 50; height: 50;
        color: focus ? "red" : "lightgray"
        focus: true
        KeyNavigation.right: topRight
        KeyNavigation.down: bottomLeft
    }
    Rectangle {
        id: topRight
        width: 50; height: 50;
        color: focus ? "red" : "lightgray"
        KeyNavigation.left: topLeft
        KeyNavigation.down: bottomRight
    }
    Rectangle {
        id: bottomLeft
        width: 50; height: 50;
        color: focus ? "red" : "lightgray"
        KeyNavigation.right: bottomRight
        KeyNavigation.up: topLeft
    }
    Rectangle {
        id: bottomRight
        width: 50; height: 50;
        color: focus ? "red" : "lightgray"
        KeyNavigation.left: bottomLeft
        KeyNavigation.up: topRight
    }
}
*/

/*
//定时器
Rectangle {
    Timer {
        interval: 500; running: true; repeat: true
        onTriggered: time.text = Date().toString()
    }
    Text {id: time; styleColor: "#f70c0c"}
}
*/

/*
//渐变
Rectangle {
    width: 100; height: 400;
    gradient: Gradient {
        GradientStop { position: 0.0; color: "red" }
        GradientStop { position: 0.3; color: "yellow" }
        GradientStop { position: 1.0; color: "green" }
    }
}
*/

/*
//图片、gif
Grid
{
    height: 400
    columns: 2
    Image {
        id: image
        width: 120; height: 120
        fillMode: Image.PreserveAspectFit
        source: "http://www.baidu.com/img/bd_logo1.png"
        onStatusChanged: {
            if (image.status == Image.Ready) console.log("Loaded")
            else if (image.status === Image.Loading) console.log("Loading")
        }
    }
    //九宫格分割
    BorderImage {
        id: borderImage
        source: "http://www.baidu.com/img/bd_logo1.png"
        width: 200; height: 120
        border.left: 30; border.top: 30
        border.right: 30; border.bottom: 30
        horizontalTileMode: BorderImage.Stretch
        verticalTileMode: BorderImage.Stretch
    }
    //Gig
    Rectangle {
        id: rect
        width: animation.width; height: animation.height+8; color: "#c2f3a5"
        AnimatedImage { id: animation; width:120; height: 120; source: "file:///E:/ywy/work/QT/test/QTTest/QSS/Gig.gif"
        }
        Rectangle {
            property int frames: animation.frameCount
            width: 4; height: 8;
            x: (animation.width-width) * animation.currentFrame / frames
            y: animation.height
            color: "red"
        }
    }
}
*/

/*
//缩放、旋转
Grid {
    height: 400
    columns: 4
    spacing: 5
    Rectangle {
        width: 50; height: 50; color: "#789011"
        gradient: Gradient {
            GradientStop { position: 0.0; color: "red" }
            GradientStop { position: 0.3; color: "yellow" }
            GradientStop { position: 1.0; color: "green" }
        }
    }
    Rectangle {
        width: 50; height: 50; color: "#d73636"
        scale: 1.3 //放大
        transformOrigin: "TopLeft"
    }
    Rectangle {
        width: 50; height: 50; color: "#3bc863"
        scale: 0.7 //缩小
        transformOrigin: "TopLeft"
    }
    Rectangle {
        width: 50; height: 50; color: "#aabbcc"
        scale: -1   //镜像
        gradient: Gradient {
            GradientStop { position: 0.0; color: "red" }
            GradientStop { position: 0.3; color: "yellow" }
            GradientStop { position: 1.0; color: "green" }
        }
    }
    Rectangle {
        width: 50; height: 50; color: "#6565ec"
        transform: Rotation {
            origin.x: 30; origin.y: 30;
            axis {x:1; y: 1; z: 0;} angle: 72
        }
    }
}
*/

/*
//状态
Rectangle {
    width: 400; height: 400;
    Rectangle {
        id: myRect
        width: 50; height: 50; color: "red";
        MouseArea {
            anchors.fill: parent
            onClicked: myRect.state = "moved"
        }
        states: [
            State {
                name: "moved"
                PropertyChanges {
                    target: myRect;
                    x: 50; y: 50;
                }
            }
        ]
    }
}
*/

/*
//动画
Rectangle {
    height: 400
    Rectangle {
        width: 100; height: 100; color: "red"
        PropertyAnimation on x {from: 0; to: 150; duration: 1000; loops: Animation.Infinite }
        PropertyAnimation on y {from: 0; to: 150; duration: 1000; loops: Animation.Infinite }
    }
    Rectangle {
        id: rect
        width: 50; height: 50; color: "lightgreen"; anchors.centerIn: parent
        //属性发生改变时触发该动画
        Behavior on x { PropertyAnimation {duration: 500} }
        Behavior on y { PropertyAnimation {duration: 500} }
        //颜色变化
        ColorAnimation on color { from: "lightgreen"; to: "red";
            duration: 2000
            loops: Animation.Infinite
        }
        //旋转动画
        RotationAnimation on rotation { to: 135; duration: 2000; direction: RotationAnimation.Clockwise; loops: Animation.Infinite }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {rect.x = mouse.x; rect.y = mouse.y }
    }
}
*/

/*
//组合动画
Rectangle {
    id: rect
    height: 400
    Rectangle {
        id: img
        width: 50; height: 50; color: "red"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 0

        SequentialAnimation on y {
            loops: Animation.Infinite
            NumberAnimation { to: rect.height - img.height; easing.type: Easing.OutBounce; duration: 2000 }
            PauseAnimation  { duration: 1000 }
            NumberAnimation { to: 0; easing.type: Easing.OutQuad; duration: 1000 }
        }
    }
}
*/

/*
//嵌套动画(顺序、并行)
Rectangle {
    id: redRect
    width: 100; height: 100; color: "red"

    MouseArea { id: mouseArea; anchors.fill: parent }
    states: State {
        name: "pressed"; when: mouseArea.pressed
        PropertyChanges {
            target: redRect; color: "blue";
            y: mouseArea.mouseY; width: mouseArea.mouseX
        }
    }
    transitions: Transition {
        SequentialAnimation {
            //顺序动画
            ColorAnimation { duration: 200 }
            PauseAnimation { duration: 100 }
            //并行动画
            ParallelAnimation {
                NumberAnimation {
                    duration: 500
                    easing.type: Easing.OutBounce
                    targets: redRect
                    properties: "y"
                }
                NumberAnimation {
                    duration: 800
                    easing.type: Easing.InOutQuad
                    targets: redRect
                    properties: "width"
                }
            }
        }
    }
}
*/

/*
//视图
Item
{
    width: 200; height: 250;
    ListModel {
        id: myModel
        ListElement { type: "Dog"; age: 8 }
        ListElement { type: "Cat"; age: 5 }
    }
    Component {
        id: myDelegate
        Text { text: type + "," + age }
    }
    ListView {
        anchors.fill: parent
        model: myModel
//        delegate: myDelegate
        delegate: Row {
            Text { text: "type:" + type }
            Text { text: "age:" + age }
        }
    }
}
*/

/*
//翻转动画
Flipable {
    id: flipable
    width: 240; height: 240
    property bool flipped: false
//    front: Image { source: "qrc:/qss/QSS/5_heart.png"; anchors.centerIn: parent}
    front: Image { id: img; source: "file:./../QSS/5_heart.png"; anchors.centerIn: parent}
    back: Image { source: "file:./../QSS/back.png"; anchors.centerIn: parent}
    transform: Rotation {
        id: rotation
        origin.x: flipable.width/2
        origin.y: flipable.height/2
        axis.x: 0; axis.y: 1; axis.z: 0
        angle: 0
    }
    states: State {
        name: "back"
        PropertyChanges {
            target: rotation; angle: 180
        }
        when: flipable.flipped
    }
    transitions: Transition {
//        NumberAnimation { target: rotation; property: "angle"; duration: 2000}
        ParallelAnimation {
            NumberAnimation { target: rotation; properties: "angle"; duration: 600 }
            SequentialAnimation {
                NumberAnimation { target: flipable; property: "scale"; to: 0.75; duration: 300 }
                NumberAnimation { target: flipable; property: "scale"; to: 1.0; duration: 300 }
            }
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: { flipable.flipped = !flipable.flipped }
    }
}
*/

/*
//XmlListModel
Rectangle {
    width: 360; height: 360; color: "lightgreen"

    XmlListModel {
        id: feedModel
        source: "file:./../QSS/test.xml"
        query: "/videos/video"
        XmlRole { name: "name"; query: "@name/string()" }
        XmlRole { name: "date"; query: "@date/string()" }
        XmlRole { name: "DY_tag"; query: "attr[1]/@tag/string()" }
        XmlRole { name: "DY"; query: "attr[1]/string()" }
        XmlRole { name: "YU_tag"; query: "attr[2]/@tag/string()" }
        XmlRole { name: "YU"; query: "attr[2]/string()" }
        XmlRole { name: "PF_tag"; query: "attr[3]/@tag/string()" }
        XmlRole { name: "PF"; query: "attr[3]/string()" }
        XmlRole { name: "JJ_tag"; query: "attr[4]/@tag/string()" }
        XmlRole { name: "JJ"; query: "attr[4]/string()" }
    }
    ListView
    {
        anchors.fill: parent
        model: feedModel
        delegate: Column {
            Text { text: name }
            Text { text: date }
            Text { text: DY_tag + ": " + DY }
            Text { text: YU_tag + ": " + YU }
            Text { text: PF_tag + ": " + PF }
            Text { text: JJ_tag + ": " + JJ }
        }
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true;
    }
    MouseArea {
        anchors.fill: parent
        onClicked: { console.log(feedModel.status)
        console.log(feedModel.errorString())
        }
    }
}
*/

/*
//网页
Flickable {
    width: 400; height: 300
    contentWidth: webView.width; contentHeight: webView.height

    WebEngineView {
        id: webView
        url: "https://www.baidu.com/"
    }
}
*/

//测试
Rectangle {
    id: root
    color: "green"
    width: 200
    height: 200

    // 发送给 Qt Widgets 的信号
    signal qmlSignal(int number, string str)
    // 从 Qt Widgets 接收到的信号
    signal cSignal

    Text {
        id: myText
        text: "Click me"
        font.pointSize: 14
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.qmlSignal(1, "FROM QML")
    }

    // 信号处理程序（处理从 Qt Widgets 接收到的信号）
    onCSignal: {
        //root.color = "blue"
        myText.text = "Call the qml signal handler"
    }
}
