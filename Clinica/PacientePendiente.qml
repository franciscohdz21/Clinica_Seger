import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4

Window {
    id: pacientePendiente
    width: 1100
    minimumWidth: 1100
    maximumWidth: 1100
    height: 720
    minimumHeight: 720
    maximumHeight: 720
    title: "Paciente Pendiente"
    color: "lightyellow"
    onClosing: {
        close.accepted = false
        pacientePendiente.hide()
        ventanaDeManipulacionSQL.show()
    }

    Rectangle {
        anchors.fill: parent
        anchors.topMargin: 10
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        color: "lightyellow"

        GridLayout {
            id: pacientePendienteGrid
            width: parent.width
            height: parent.height/6
            columns: 3
            //1
            Text {
                text: "Filtros"
                font.bold: true
            }
            Rectangle {
                color: "transparent"
                width: 300
            }
            Rectangle {
                color: "transparent"
                width: 300
            }
            //2
            Text {
                text: "Celular:"
            }
            TextField {
                id: buscarExistenteCelular
                implicitWidth: 200
                onTextChanged: {

                }
            }
            Rectangle {
                color: "transparent"
                width: 300
            }
            //3
            Text {
                text: "Apellidos:"
            }
            TextField {
                id: buscarExistenteApellidos
                implicitWidth: 200
                onTextChanged: {

                }
            }
            Rectangle {
                color: "transparent"
                width: 300
            }
        }

        TableView {
            id: pacientePendienteTableView
            //model:
            height: (parent.height/6) * 4
            width: parent.width
            anchors.top: pacientePendienteGrid.bottom
            anchors.left: pacientePendienteGrid.left
            anchors.topMargin: 20
            TableViewColumn {
                role: "id"
                title: "ID"
                width: 80
            }
            TableViewColumn {
                role: "nombre"
                title: "Nombre"
                width: 150
            }
            TableViewColumn {
                role: "apellidos"
                title: "Apellidos"
                width: 200
            }
            TableViewColumn {
                role: "celular"
                title: "Celular"
                width: 150
            }
            TableViewColumn {
                role: "telefono"
                title: "Telefono"
                width: 150
            }
            TableViewColumn {
                role: "fechaDeCancelacion"
                title: "Telefono"
                width: 150
            }
        }

        RowLayout {
            anchors.top: pacientePendienteTableView.bottom
            anchors.left: parent.right
            anchors.topMargin: 30
            anchors.leftMargin: -100
            Button {
                text: "Cerrar"
                anchors.leftMargin: 20
                onClicked: {
                    pacientePendiente.hide()
                    ventanaDeManipulacionSQL.show()
                }
            }
        }
    }
}
