import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4

Window {
    id: editarPaciente
    width: 1200
    minimumWidth: 1200
    maximumWidth: 1200
    height: 400
    minimumHeight: 400
    maximumHeight: 400
    title: "Editar Paciente"
    color: "lightyellow"
    onClosing: {
        close.accepted = false
        editarPaciente.hide()
        buscarOEditarPaciente.show()
    }

    Rectangle {
        anchors.fill: parent
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        color: "lightyellow"

        GridLayout {
            id: datosPacienteGridLayout
            height: (parent.height/8) * 7
            width: parent.width
            columns: 8
            columnSpacing: 15

            //1
            Text {
                text: "Nombre:"
            }
            TextField {
                id: nombreTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.nombre
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Apellidos:"
            }
            TextField {
                id: apellidosTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.apellidos
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Celular:"
            }
            TextField {
                id: celularTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.celular
            }
            //2
            Text {
                text: "Telefono:"
            }
            TextField {
                id: telefonoTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.telefono
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Correo:"
            }
            TextField {
                id: correoTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.correo
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Fecha de Nacimiento:"
            }
            RowLayout {
                id: fechaDeNacimientoLayout
                spacing: 1
                ComboBox {
                    id: diaComboBox
                    width: 30
                    model: [ "01", "02", "03", "04", "05", "06", "07", "08", "09", "10",
                    "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                    "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"]
                    currentIndex: editarpacienteviewmodel.diaFechaDeNacimientoIndex
                }
                ComboBox {
                    id: mesComboBox
                    width: 140
                    model: [ "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                    "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"]
                    currentIndex: editarpacienteviewmodel.mesFechaDeNacimientoIndex
                }
                TextField {
                    id: anoTextInput
                    implicitWidth: 50
                    text: editarpacienteviewmodel.anoFechaDeNacimiento
                }
            }
            //3
            Text {
                text: "Calle y Numero:"
            }
            TextField {
                id: calleYNumeroTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.calleYNumero
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Colonia:"
            }
            TextField {
                id: coloniaTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.colonia
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Ciudad:"
            }
            TextField {
                id: ciudadTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.ciudad
            }
            //4
            Text {
                text: "Estado:"
            }
            TextField {
                id: estadoTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.estado
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Sesiones Pagadas:"
            }
            TextField {
                id: sesionesPagadasTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.sesionesPagadas
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Saldo a Favor:"
            }
            TextField {
                id: saldoAFavorTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.saldoAFavor
            }
            //5
            Text {
                text: "Sesiones de Garantia:"
            }
            TextField {
                id: sesionesDeGarantiaTextField
                implicitWidth: 200
                text: editarpacienteviewmodel.sesionesDeGarantia
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 2
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 2
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 2
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 2
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 2
            }
        }
        RowLayout {
            anchors.top: datosPacienteGridLayout.bottom
            anchors.left: parent.right
            anchors.topMargin: 10
            anchors.leftMargin: -180
            Button {
                text: "Cancelar"
                onClicked: {
                    editarPaciente.hide()
                    buscarOEditarPaciente.show()
                }
            }
            Button {
                id: okButton
                text: "Aceptar"
                anchors.leftMargin: 20
                onClicked: {
                    console.log("I am called");
                    //update data
                    clientesviewmodel.updatePaciente(nombreTextField.text, apellidosTextField.text,
                                                           celularTextField.text, telefonoTextField.text,
                                                           correoTextField.text, diaComboBox.currentIndex,
                                                           mesComboBox.currentIndex, anoTextInput.text,
                                                           calleYNumeroTextField.text, coloniaTextField.text,
                                                           ciudadTextField.text, estadoTextField.text,
                                                           sesionesPagadasTextField.text, saldoAFavorTextField.text,
                                                           sesionesDeGarantiaTextField.text, editarpacienteviewmodel.currentCelular)
                    editarPaciente.hide()
                    ventanaDeManipulacionSQL.show()
                }
            }
        }
    }
}
