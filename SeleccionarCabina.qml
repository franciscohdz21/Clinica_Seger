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
        color: "#DABDDC"

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
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    datemanipulation.buildDateBounds(0)
                    seleccionarCabina.hide()
                    //set cabina
                    clinicacore.currentCabina = "e_light"
                    agendarclienteviewdata.tratamientoCurrentIndex = 0
                    //load view
                    if (clinicacore.getCancelarCita() === true)
                    {
                        buscarOCancelarCita.show()
                        cabinasqlqueries.updateQuery(clinicacore.currentCabina);
                        ventanaDeManipulacionSQL.hide()
                        clinicacore.setCancelarCita(false)
                    }
                    else if (agendarclienteviewdata.clienteEsNuevo === true)
                    {
                        agendarclienteviewdata.clearNombreApellidosCelular()
                        cabinasqlqueries.updateQuery(clinicacore.currentCabina)
                        agendarCliente.show()
                        ventanaDeManipulacionSQL.hide()
                    }
                    else
                    {
                        clientessqlqueries.updateQuery()
                        buscarExistente.show()
                        ventanaDeManipulacionSQL.hide()
                    }
                }
            }
            Button {
                text: "Corporal y Facial"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    datemanipulation.buildDateBounds(0)
                    seleccionarCabina.hide()
                    //set cabina
                    clinicacore.currentCabina = "corporal_y_facial"
                    agendarclienteviewdata.tratamientoCurrentIndex = 1
                    //load view
                    if (clinicacore.getCancelarCita() === true)
                    {
                        buscarOCancelarCita.show()
                        cabinasqlqueries.updateQuery(clinicacore.currentCabina);
                        ventanaDeManipulacionSQL.hide()
                        clinicacore.setCancelarCita(false)
                    }
                    else if (agendarclienteviewdata.clienteEsNuevo === true)
                    {
                        agendarclienteviewdata.clearNombreApellidosCelular()
                        cabinasqlqueries.updateQuery(clinicacore.currentCabina)
                        agendarCliente.show()
                        ventanaDeManipulacionSQL.hide()
                    }
                    else
                    {
                        clientessqlqueries.updateQuery()
                        buscarExistente.show()
                        ventanaDeManipulacionSQL.hide()
                    }
                }
            }
            Button {
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
                    seleccionarCabina.hide()
                }
            }
        }
    }
    Component.onCompleted: visible = false
}
