import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Window 2.10
import QtQuick.Templates 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Universal 2.0

Item {
    width: 400
    height: 400

    StackLayout {
        id: stackLayout
        x: 0
        y: 40
        width: 400
        height: 360
    }

    RowLayout {
        x: 0
        y: 0
        width: 400
        height: 40

        TabButton {
            id: beginnerMode
            text: qsTr("Tab Button")
            Layout.preferredHeight: 40
            Layout.preferredWidth: 201
        }

        TabButton {
            id: expertMode
            text: qsTr("Tab Button")
            Layout.preferredHeight: 40
            Layout.preferredWidth: 199
        }
    }
}
