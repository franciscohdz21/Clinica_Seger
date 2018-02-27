import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4 as QuickControls_1_4
import QtQuick.Controls 2.3 as QuickControls_2_3


Window {
    id: buscarExistente
    width: 1150
    maximumWidth: 1150
    minimumWidth: 1150
    height: 680
    minimumHeight: 680
    maximumHeight: 680
    title: "Buscar Cliente Existente"
    color: "#DABDDC"
    onClosing: {
        close.accepted = false
        buscarExistente.hide()
        ventanaDeManipulacionSQL.show()
    }

    Rectangle {
        anchors.fill: parent
        anchors.topMargin: 10
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        color: "#DABDDC"

        GridLayout {
            id: buscarClienteGrid
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
            QuickControls_2_3.TextField {
                id: buscarExistenteCelular
                implicitWidth: 200
                implicitHeight: 25
                onTextChanged: {
                    clientessqlqueries.filterQueryByCellphone(buscarExistenteCelular.text)
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
            QuickControls_2_3.TextField {
                id: buscarExistenteApellidos
                implicitWidth: 200
                implicitHeight: 25
                onTextChanged: {
                    clientessqlqueries.filterQueryByLastName(buscarExistenteApellidos.text)
                }
            }
            Rectangle {
                color: "transparent"
                width: 300
            }
        }

        QuickControls_1_4.TableView {
            id: buscarClienteTableView
            width: parent.width
            height: (parent.height/6) * 4
            anchors.top: buscarClienteGrid.bottom
            anchors.topMargin: 30
            model: clientesviewmodel
            itemDelegate: Item {
                id: itemDelegate
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    color: styleData.textColor
                    elide: styleData.elideMode
                    text: styleData.value
                }
                MouseArea {
                    anchors.fill: parent
                    propagateComposedEvents: true
                    onClicked: {
                        buscarClienteTableView.selection.clear()
                        buscarClienteTableView.currentRow = styleData.row
                        buscarClienteTableView.selection.select (styleData.row)
                        clientesviewmodel.setClientesProperties(styleData.row)
                        buscarClienteTableView.forceActiveFocus()
                        if (clinicacore.developerMode === true)
                            console.log(styleData.value)
                    }
                }
            }
            QuickControls_1_4.TableViewColumn
            {
                title: "Nombre"
                role: "nombre"
                width: 110
            }
            QuickControls_1_4.TableViewColumn
            {
                title: "Apellidos"
                role: "apellidos"
                width: 150
            }
            QuickControls_1_4.TableViewColumn
            {
                title: "Celular"
                role: "celular"
                width: 110
            }
            QuickControls_1_4.TableViewColumn
            {
                title: "Telefono"
                role: "telefono"
                width: 110
            }
            QuickControls_1_4.TableViewColumn
            {
                title: "Correo"
                role: "correo"
                width: 150
            }
            QuickControls_1_4.TableViewColumn
            {
                title: "Fecha de Nacimiento"
                role: "fechaDeNacimiento"
                width: 150
            }
            QuickControls_1_4.TableViewColumn
            {
                title: "Direccion"
                role: "direccion"
                width: 300
            }
        }
        RowLayout {
            anchors.top: buscarClienteTableView.bottom
            anchors.left: parent.right
            anchors.topMargin: 20
            anchors.leftMargin: -230
            QuickControls_2_3.Button {
                text: "Cancelar"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    buscarClienteTableView.selection.clear()
                    buscarExistente.hide()
                    ventanaDeManipulacionSQL.show()
                }
            }
            QuickControls_2_3.Button {
                id: okButton
                text: "Aceptar"
                anchors.leftMargin: 20
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                enabled: {
                    if (buscarClienteTableView.currentRow !== -1)
                    {
                        return true
                    }
                    else
                    {
                        return false
                    }
                }
                onPressed: {
                    buscarClienteTableView.selection.clear()
                    buscarExistente.hide()
                    cabinasqlqueries.updateQuery(clinicacore.currentCabina);
                    agendarCliente.show()
                }
            }
        }
    }
}
