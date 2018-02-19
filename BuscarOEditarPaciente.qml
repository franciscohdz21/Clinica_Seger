import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1

Window {
    id: buscarOEditarPaciente
    width: 1150
    minimumWidth: 1150
    height: 720
    minimumHeight: 720
    title: "Buscar O Editar Paciente"
    color: "lightyellow"
    onClosing: {
        close.accepted = false
        buscarOEditarPaciente.hide()
        ventanaDeManipulacionSQL.show()
    }

    EditarPaciente {
        id: editarPaciente
        visible: false
    }

    Rectangle {
        anchors.fill: parent
        anchors.topMargin: 10
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        color: "lightyellow"

        GridLayout {
            id: buscarPacienteGrid
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
                id: buscarExistenteCelularTextInput
                implicitWidth: 200
                implicitHeight: 25
                onTextChanged: {
                    buscarPacienteTableView.selection.clear()
                    clientessqlqueries.filterQueryByCellphone(buscarExistenteCelularTextInput.text)
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
                id: buscarExistenteApellidosTextInput
                implicitWidth: 200
                implicitHeight: 25
                onTextChanged: {
                    buscarPacienteTableView.selection.clear()
                    clientessqlqueries.filterQueryByLastName(buscarExistenteApellidosTextInput.text)
                }
            }
            Rectangle {
                color: "transparent"
                width: 300
            }
        }


        TableView {
            id: buscarPacienteTableView
            width: parent.width
            height: (parent.height/6) * 4
            anchors.top: buscarPacienteGrid.bottom
            anchors.topMargin: 30
            selectionMode: SelectionMode.SingleSelection
            model: clientesviewmodel
            onClicked: {
                editarpacienteviewdata.currentCelular = clientesviewmodel.retrieveCelular(buscarPacienteTableView.currentRow)
                if (clinicacore.developerMode === true)
                    console.log("Current Celular " + editarpacienteviewdata.currentCelular)
            }
            TableViewColumn
            {
                title: "Nombre"
                role: "nombre"
                width: 60
            }
            TableViewColumn
            {
                title: "Apellidos"
                role: "apellidos"
                width: 110
            }
            TableViewColumn
            {
                id: celularTableViewColumn
                title: "Celular"
                role: "celular"
                width: 80
            }
            TableViewColumn
            {
                title: "Telefono"
                role: "telefono"
                width: 80
            }
            TableViewColumn
            {
                title: "Correo"
                role: "correo"
                width: 100
            }
            TableViewColumn
            {
                title: "Fecha de Nacimiento"
                role: "fechaDeNacimiento"
                width: 100
            }
            TableViewColumn
            {
                title: "Calle Y Numero"
                role: "calleYNumero"
                width: 100
            }
            TableViewColumn
            {
                title: "Colonia"
                role: "colonia"
                width: 70
            }
            TableViewColumn
            {
                title: "Ciudad"
                role: "ciudad"
                width: 70
            }
            TableViewColumn
            {
                title: "Estado"
                role: "estado"
                width: 70
            }
            TableViewColumn
            {
                title: "Sesiones Pagadas"
                role: "sesionesPagadas"
                width: 85
            }
            TableViewColumn
            {
                title: "Saldo A Favor"
                role: "saldoAFavor"
                width: 85
            }
            TableViewColumn
            {
                title: "Sesiones de Garantia"
                role: "sesionesDeGarantia"
                width: 85
            }
        }
        RowLayout {
            anchors.top: buscarPacienteTableView.bottom
            anchors.left: parent.right
            anchors.topMargin: 20
            anchors.leftMargin: -230
            Button {
                text: "Cancelar"
                anchors.leftMargin: 20
                onClicked: {
                    buscarOEditarPaciente.hide()
                    buscarExistenteCelularTextInput.text = ""
                    buscarExistenteApellidosTextInput.text = ""
                    buscarPacienteTableView.selection.clear()
                    ventanaDeManipulacionSQL.show()
                }
            }
            Button {
                text: "Editar"
                onClicked: {
                    buscarOEditarPaciente.hide()
                    buscarExistenteCelularTextInput.text = ""
                    buscarExistenteApellidosTextInput.text = ""
                    buscarPacienteTableView.selection.clear()
                    editarpacientesqlqueries.retrieveAllEntries(editarpacienteviewdata.currentCelular)
                    editarPaciente.show()
                }
            }
        }
    }
}
