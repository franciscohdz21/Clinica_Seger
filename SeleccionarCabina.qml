import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

Window {
    width: 350
    minimumWidth: 350
    maximumWidth: 350
    height: 140
    minimumHeight: 140
    maximumHeight: 140
    title: "Cabina"
    onClosing: {
        close.accepted = false
        seleccionarCabina.hide()
    }

    Rectangle {
        anchors.fill: parent
        color: "lightyellow"

        GridLayout {
            anchors.fill: parent
            id: cabinaLayout
            anchors.topMargin: 15
            anchors.leftMargin: 15
            anchors.rightMargin: 15
            anchors.bottomMargin: 15
            columns: 3
            columnSpacing: 10
            rowSpacing: 30

            Rectangle {
                color: "transparent"
                width: 50
            }
            Text {
                text: "Seleccionar cabina:"
                font.pointSize: 8
            }
            Rectangle {
                color: "transparent"
                width: 50
            }
            Button {
                text: "E-Light"
                onClicked: {
                    seleccionarCabina.hide()
                    //set cabina

                    //load view
                    if (cabinaviewmodel.clienteEsNuevo === true)
                    {
                        cabinaviewmodel.clearNombreApellidosCelular()
                        cabinaviewmodel.updateQuery("")
                        agendarCliente.show()
                        ventanaDeManipulacionSQL.hide()
                    }
                    else
                    {
                        clientesviewmodel.updateQuery()
                        buscarExistente.show()
                        ventanaDeManipulacionSQL.hide()
                    }
                }
            }
            Button {
                text: "Corporal y Facial"
                onClicked: {
                    seleccionarCabina.hide()
                    //set cabina

                    //load view
                    if (cabinaviewmodel.clienteEsNuevo === true)
                    {
                        cabinaviewmodel.clearNombreApellidosCelular()
                        cabinaviewmodel.updateQuery("")
                        agendarCliente.show()
                        ventanaDeManipulacionSQL.hide()
                    }
                    else
                    {
                        clientesviewmodel.updateQuery()
                        buscarExistente.show()
                        ventanaDeManipulacionSQL.hide()
                    }
                }
            }
            Button {
                text: "Cancelar"
                onClicked: {
                    seleccionarCabina.hide()
                }
            }
        }
    }
    Component.onCompleted: visible = false
}
