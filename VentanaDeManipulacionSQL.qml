import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4 as QuickControls_1_4
import QtQuick.Controls 2.3 as QuickControls_2_3

Window {
    width: 1340
    minimumWidth: 1340
    maximumWidth: 1340
    height: 680
    minimumHeight: 680
    maximumHeight: 680
    title: "Clinica Seger 1.0"

    AgendarCliente {
        id: agendarCliente
        visible: false
    }
    BuscarExistente {
        id: buscarExistente
        visible: false
    }
    BuscarOEditarPaciente {
        id: buscarOEditarPaciente
        visible: false
    }
    BuscarOCancelarCita {
        id: buscarOCancelarCita
        visible: false
    }
//    PacientePendiente {
//        id: pacientePendiente
//        visible: false
//    }
    SeleccionarCabina {
        id : seleccionarCabina
        visible: true
    }
    CambiarAno {
        id: cambiarAno
        visible: false
    }

    //no backend logic implemented
    MessageDialog {
        id: messageDialog
        title: "Error fatal"
        text: "Conexion ha sido interrumpida, reinicie programa."
        icon: StandardIcon.Critical
        visible: false
        onAccepted: {
            Qt.quit()
        }
        Component.onCompleted: visible = false
    }

    Rectangle {
        anchors.fill: parent
        color: "lightyellow"

        Image {
            id: fondo
            source: "Fotos/Fondo.png"
        }

        GridLayout {
            id: conexionGrid
            anchors.leftMargin: 20
            anchors.topMargin: 15
            anchors.fill: parent
            columns: 6
            columnSpacing: 15

            //1
            Rectangle{
                color: "transparent"
                width: 100
                height: 140
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            //2
            Rectangle{
                color: "transparent"
                width: 100
            }
            Image {
                id: agendarNuevoBoton
                source: "Fotos/Agendar_Nuevo.png"
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        agendarclienteviewdata.clienteEsNuevo = true
                        clinicacore.buildCurrentServicios(0)
                        seleccionarCabina.show()
                    }
                }
            }
            Image {
                id: agendarExistenteBoton
                source: "Fotos/Agendar_Existente.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        agendarclienteviewdata.clienteEsNuevo = false
                        clinicacore.buildCurrentServicios(0)
                        seleccionarCabina.show()
                    }
                }
            }
            Image {
                id: buscarOEditarPacienteBoton
                source: "Fotos/Buscar_O_Editar_Paciente.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        clientessqlqueries.updateQuery()
                        buscarOEditarPaciente.show()
                        ventanaDeManipulacionSQL.hide()
                    }
                }
            }
            Image {
                id: buscarOCancelarCitaBoton
                source: "Fotos/Buscar_Cancelar_Cita.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        clinicacore.setCancelarCita(true)
                        seleccionarCabina.show()
                    }
                }
            }
            Image {
                id: pacientePendienteBoton
                source: "Fotos/Paciente_Pendiente.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        //pacientePendiente.show()
                        //ventanaDeManipulacionSQL.hide()
                    }
                }
            }
            //3
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Text {
                text: "Usuario:"
                font.bold: true
                font.pixelSize: 14
            }
            Text {
                text: clinicacore.usuario
                font.bold: true
                font.pixelSize: 14
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            //4
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Text {
                text: "Ubicacion:"
                font.bold: true
                font.pixelSize: 14
            }
            Text {
                text: clinicacore.ubicacion
                font.bold: true
                font.pixelSize: 14
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            //5
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Text {
                text: "Permiso:"
                font.bold: true
                font.pixelSize: 14
            }
            Text {
                text: clinicacore.permiso
                font.bold: true
                font.pixelSize: 14
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            //6
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            Rectangle{
                color: "transparent"
                width: 100
            }
            QuickControls_2_3.Button {
                text: "Cerrar"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onClicked: {
                    Qt.quit()
                }
            }
        }
    }
}
