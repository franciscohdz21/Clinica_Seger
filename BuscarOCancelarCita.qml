import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1


Window {
    id: buscarOCancelarCita
    width: 1366
    minimumWidth: 1366
    maximumWidth: 1366
    height: 720
    minimumHeight: 720
    maximumHeight: 720
    title: "Buscar O Cancelar Cita"
    color: "lightyellow"
    onClosing: {
        close.accepted = false
        buscarOCancelarCita.hide()
        ventanaDeManipulacionSQL.show()
    }

    Rectangle {
        anchors.fill: parent
        anchors.topMargin: 10
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        color: "lightyellow"

        GridLayout {
            id: buscarCitaGrid
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
                id: buscarCitaCelularTextField
                implicitWidth: 200
                implicitHeight: 25
                onTextChanged: {
                    buscarCitaTableView.selection.clear()
                    if (buscarCitaCelularTextField.text === "")
                        cabinasqlqueries.updateQuery(clinicacore.currentCabina)
                    else
                    {
                        cabinasqlqueries.filterQueryByCellphone(buscarCitaCelularTextField.text)
                    }
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
                id: buscarCitaApellidosTextField
                implicitWidth: 200
                implicitHeight: 25
                onTextChanged: {
                    buscarCitaTableView.selection.clear()
                    if (buscarCitaApellidosTextField.text === "")
                        cabinasqlqueries.updateQuery(clinicacore.currentCabina)
                    else
                    {
                        cabinasqlqueries.filterQueryByLastName(buscarCitaApellidosTextField.text)
                    }
                }
            }
            Rectangle {
                color: "transparent"
                width: 300
            }
        }

        TableView {
            id: buscarCitaTableView
            model: cabinaviewmodel
            height: (parent.height/6) * 4
            width: parent.width
            anchors.top: buscarCitaGrid.bottom
            anchors.left: buscarCitaGrid.left
            anchors.topMargin: 20
            onClicked: {
                console.log("Clicked")
            }

            TableViewColumn {
                role: "id"
                title: "ID"
                visible: clinicacore.developerMode
                width: 120
            }
            TableViewColumn {
                role: "fecha"
                title: "Fecha"
                width: 100
            }
            TableViewColumn {
                role: "horaInicio"
                title: "Hora Inicio"
                width: 80
            }
            TableViewColumn {
                role: "horaTermino"
                title: "Hora Termino"
                width: 80
            }
            TableViewColumn {
                role: "nombre"
                title: "Nombre"
                width: 100
            }
            TableViewColumn {
                role: "apellidos"
                title: "Apellidos"
                width: 150
            }
            TableViewColumn {
                role: "celular"
                title: "Celular"
                width: 120
            }
            TableViewColumn {
                role: "tratamiento"
                title: "Tratamiento"
                width: 120
            }
            TableViewColumn {
                role: "servicio"
                title: "Servicio"
                width: 120
            }
            TableViewColumn {
                role: "zonas"
                title: "Zonas"
                width: 100
            }
            TableViewColumn {
                role: "precio"
                title: "Precio"
                width: 80
            }
            TableViewColumn {
                role: "importeCobrado"
                title: "Importe Cobrado"
                width: 80
            }
            TableViewColumn {
                role: "sesion"
                title: "Sesion"
                width: 60
            }
            TableViewColumn {
                role: "sesionesPagadas"
                title: "Sesiones Pagadas"
                width: 60
            }
            TableViewColumn {
                role: "totalPagado"
                title: "Total Pagado"
                width: 60
            }
            TableViewColumn {
                role: "estatusDeCita"
                title: "Estatus de Cita"
                width: 60
            }
            TableViewColumn {
                role: "observaciones"
                title: "Observaciones"
                width: 200
            }
        }

        RowLayout {
            anchors.top: buscarCitaTableView.bottom
            anchors.left: parent.right
            anchors.topMargin: 30
            anchors.leftMargin: -230
            Button {
                text: "Cerrar"
                anchors.leftMargin: 20
                onClicked: {
                    buscarCitaCelularTextField.text = ""
                    buscarCitaApellidosTextField.text = ""
                    buscarOCancelarCita.hide()
                    ventanaDeManipulacionSQL.show()
                }
            }
            Button {
                text: "Cancelar Cita"
                enabled: {
                    if (buscarCitaTableView.currentRow === -1)
                        return false
                    else return true
                }

                onClicked: {
                    cabinasqlqueries.initCitaDeletion(buscarCitaTableView.currentRow)
                    buscarCitaCelularTextField.text = ""
                    buscarCitaApellidosTextField.text = ""
                    cabinasqlqueries.updateQuery(clinicacore.currentCabina)
                }
            }
        }
    }
}
