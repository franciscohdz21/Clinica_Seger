import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2

Window {
    width: 1366
    minimumWidth: 1366
    maximumWidth: 1366
    height: 728
    minimumHeight: 728
    maximumHeight: 728
    title: "Manipulacion de Base de Datos"

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
    PacientePendiente {
        id: pacientePendiente
        visible: false
    }
    SeleccionarCabina {
        id : seleccionarCabina
        visible: true
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
                    onClicked: {
                        cabinaviewmodel.clienteEsNuevo = true
                        conexionabasededatos.refreshAll()
                        conexionabasededatos.buildCurrentServicios(0)
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
                        cabinaviewmodel.clienteEsNuevo = false
                        conexionabasededatos.refreshAll()
                        conexionabasededatos.buildCurrentServicios(0)
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
                        clientesviewmodel.updateQuery()
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
                        buscarOCancelarCita.show()
                        cabinaviewmodel.updateQuery("");
                        ventanaDeManipulacionSQL.hide()
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
                text: conexionabasededatos.usuario
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
                text: conexionabasededatos.ubicacion
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
                text: conexionabasededatos.permiso
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
            Button {
                text: "Cerrar"
                onClicked: {
                    Qt.quit()
                }
            }
        }
    }
}
