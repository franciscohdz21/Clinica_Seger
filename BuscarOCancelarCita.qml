import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4 as QuickControls_1_4
import QtQuick.Controls 2.3 as QuickControls_2_3


Window {
    id: buscarOCancelarCita
    width: 1340
    minimumWidth: 1340
    maximumWidth: 1340
    height: 680
    minimumHeight: 680
    maximumHeight: 680
    title: "Buscar O Cancelar Cita"
    color: "#DABDDC"
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
        color: "#DABDDC"

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
            QuickControls_2_3.TextField {
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
            QuickControls_2_3.TextField {
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

        QuickControls_1_4.TableView {
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

            QuickControls_1_4.TableViewColumn {
                role: "id"
                title: "ID"
                visible: clinicacore.developerMode
                width: 120
            }
            QuickControls_1_4.TableViewColumn {
                role: "fecha"
                title: "Fecha"
                width: 100
            }
            QuickControls_1_4.TableViewColumn {
                role: "horaInicio"
                title: "Hora Inicio"
                width: 80
            }
            QuickControls_1_4.TableViewColumn {
                role: "horaTermino"
                title: "Hora Termino"
                width: 80
            }
            QuickControls_1_4.TableViewColumn {
                role: "nombre"
                title: "Nombre"
                width: 100
            }
            QuickControls_1_4.TableViewColumn {
                role: "apellidos"
                title: "Apellidos"
                width: 150
            }
            QuickControls_1_4.TableViewColumn {
                role: "celular"
                title: "Celular"
                width: 120
            }
            QuickControls_1_4.TableViewColumn {
                role: "tratamiento"
                title: "Tratamiento"
                width: 120
            }
            QuickControls_1_4.TableViewColumn {
                role: "servicio"
                title: "Servicio"
                width: 120
            }
            QuickControls_1_4.TableViewColumn {
                role: "zonas"
                title: "Zonas"
                width: 100
            }
            QuickControls_1_4.TableViewColumn {
                role: "precio"
                title: "Precio"
                width: 80
            }
            QuickControls_1_4.TableViewColumn {
                role: "importeCobrado"
                title: "Importe Cobrado"
                width: 80
            }
            QuickControls_1_4.TableViewColumn {
                role: "sesion"
                title: "Sesion"
                width: 60
            }
            QuickControls_1_4.TableViewColumn {
                role: "sesionesPagadas"
                title: "Sesiones Pagadas"
                width: 60
            }
            QuickControls_1_4.TableViewColumn {
                role: "totalPagado"
                title: "Total Pagado"
                width: 60
            }
            QuickControls_1_4.TableViewColumn {
                role: "estatusDeCita"
                title: "Estatus de Cita"
                width: 60
            }
            QuickControls_1_4.TableViewColumn {
                role: "observaciones"
                title: "Observaciones"
                width: 200
            }
        }

        RowLayout {
            anchors.top: buscarCitaTableView.bottom
            anchors.left: parent.left
            anchors.topMargin: 30
            anchors.leftMargin: 950
            spacing: 15

            QuickControls_2_3.Button {
                text: "Cambiar año"
                enabled: {
                    if (clinicacore.permiso === 4)
                        return true
                    else
                        return false
                }
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    buscarCitaTableView.selection.clear()
                    cambiarAno.show()
                }
            }

            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            QuickControls_2_3.Button {
                text: "Cerrar"
                anchors.leftMargin: 20
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    buscarCitaCelularTextField.text = ""
                    buscarCitaApellidosTextField.text = ""
                    buscarOCancelarCita.hide()
                    ventanaDeManipulacionSQL.show()
                }
            }
            QuickControls_2_3.Button {
                text: "Cancelar Cita"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                enabled: {
                    if (buscarCitaTableView.currentRow === -1)
                        return false
                    else return true
                }

                onPressed: {
                    cabinasqlqueries.initCitaDeletion(buscarCitaTableView.currentRow)
                    buscarCitaCelularTextField.text = ""
                    buscarCitaApellidosTextField.text = ""
                    cabinasqlqueries.updateQuery(clinicacore.currentCabina)
                }
            }
        }
    }
}
