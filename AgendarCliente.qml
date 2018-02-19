import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1

Window {
    id: agendarCliente
    width: 1366
    minimumWidth: 1366
    maximumWidth: 1366
    height: 728
    minimumHeight: 728
    maximumHeight: 728
    title: {
        if (clinicacore.currentCabina === "e_light")
            return "Agendar - E-Light"
        else
            return "Agendar - Corporal y Facial"
    }

    color: "lightyellow"
    Component.onCompleted: {
        agendarClienteTratamientoComboBox.currentIndex = -1
        agendarClienteServicioComboBox.currentIndex = -1
        agendarClienteDuracionComboBox.currentIndex = -1
        agendarClienteEstatusComboBox.currentIndex = -1
    }

    onClosing: {
        close.accepted = false
        agendarCliente.hide()
        ventanaDeManipulacionSQL.show()
    }

    Rectangle {
        anchors.fill: parent
        anchors.topMargin: 10
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        color: "lightyellow"

        GridLayout {
            id: agendarClienteGrid
            height: parent.height/4.5
            width: parent.width - 250
            columns: 8
            columnSpacing: 20
            property bool acceptEnabled: {
                //cliente nuevo
                if (agendarclienteviewdata.clienteEsNuevo === true)
                {
                    if ( agendarClienteNombreTextField.text === "" /*||
                            agendarClienteApellidosTextField.text === "" ||
                            agendarClienteCelularTextField.text === "" ||
                            agendarClienteZonasTextField.text === "" ||
                            agendarClienteDuracionComboBox.currentIndex === -1 ||
                            agendarClienteSesionTextField.text === "" ||
                            agendarClienteSesionesPagadasTextField.text === "" ||
                            agendarClienteTotalPagadoTextField.text === "" ||
                            agendarClienteEstatusComboBox.currentIndex === -1*/)
                    {
                        console.log("False")
                        return false
                    }
                    else
                    {
                        console.log("true")
                        return true
                    }
                }
                //cliente existente
                else
                {
                    if ( agendarClienteExistenteNombreTextField.text === "" ||
                            agendarClienteExistenteApellidosTextField.text === "" ||
                            agendarClienteExistenteCelularTextField.text === "" ||
                            agendarClienteZonasTextField.text === "" ||
                            agendarClienteDuracionComboBox.currentIndex === -1 ||
                            agendarClientePrecioTextField.text === "" ||
                            agendarClienteSesionTextField.text === "" ||
                            agendarClienteSesionesPagadasTextField.text === "" ||
                            agendarClienteTotalPagadoTextField.text === "" ||
                            agendarClienteEstatusComboBox.currentIndex === -1)
                    {
                        console.log("False")
                        return false
                    }
                    else
                    {
                        console.log("true")
                        return true
                    }
                }
            }

            //1
            Text {
                text: "Nombre:"
            }
            Item {
                id: nombreItem
                height: 20
                width: 150
                TextField {
                    id: agendarClienteNombreTextField
                    enabled: agendarclienteviewdata.clienteEsNuevo
                    visible: agendarclienteviewdata.clienteEsNuevo
                    implicitWidth: 150
                    implicitHeight: 25
                }
                TextField {
                    id: agendarClienteExistenteNombreTextField
                    enabled: agendarclienteviewdata.clienteEsNuevo
                    visible: !agendarclienteviewdata.clienteEsNuevo
                    text: agendarclienteviewdata.nombre
                    implicitWidth: 150
                    implicitHeight: 25
                }
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Apellidos:"
            }
            Item {
                id: apellidosItem
                height: 20
                width: 150
                TextField {
                    id: agendarClienteApellidosTextField
                    enabled: agendarclienteviewdata.clienteEsNuevo
                    visible: agendarclienteviewdata.clienteEsNuevo
                    implicitWidth: 150
                    implicitHeight: 25
                }
                TextField {
                    id: agendarClienteExistenteApellidosTextField
                    enabled: agendarclienteviewdata.clienteEsNuevo
                    visible: !agendarclienteviewdata.clienteEsNuevo
                    text: agendarclienteviewdata.apellidos
                    implicitWidth: 150
                    implicitHeight: 25
                }
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Celular:"
            }
            Item {
                id: celularItem
                height: 20
                width: 150
                TextField {
                    id: agendarClienteCelularTextField
                    enabled: agendarclienteviewdata.clienteEsNuevo
                    visible: agendarclienteviewdata.clienteEsNuevo
                    implicitWidth: 150
                    implicitHeight: 25
                    maximumLength: 10
                }
                TextField {
                    id: agendarClienteExistenteCelularTextField
                    enabled: agendarclienteviewdata.clienteEsNuevo
                    visible: !agendarclienteviewdata.clienteEsNuevo
                    text: agendarclienteviewdata.celular
                    implicitWidth: 150
                    implicitHeight: 25
                    maximumLength: 10
                }
            }
            //2
            Text {
                text: "Tratamiento:"
            }
            ComboBox {
                id: agendarClienteTratamientoComboBox
                model: clinicacore.tratamientos
                implicitWidth: 150
                onCurrentIndexChanged: clinicacore.buildCurrentServicios(agendarClienteTratamientoComboBox.currentIndex)
                implicitHeight: 25
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Servicio:"
            }
            ComboBox {
                id: agendarClienteServicioComboBox
                model: clinicacore.currentServicios
                implicitWidth: 150
                implicitHeight: 25
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Zonas:"
            }
            TextField {
                id: agendarClienteZonasTextField
                implicitWidth: 150
                implicitHeight: 25
            }
            //3
            Text {
                text: "Duracion:"
            }
            ComboBox {
                id: agendarClienteDuracionComboBox
                model:[ "30 min", "1 hora", "1.5 horas", "2 horas", "2.5 horas", "3 horas", "3.5 horas"]
                implicitWidth: 150
                implicitHeight: 25
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Precio:"
            }
            TextField {
                id: agendarClientePrecioTextField
                implicitWidth: 150
                implicitHeight: 25
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Importe:"
            }
            TextField {
                id: agendarClienteImporteCobradoTextField
                implicitWidth: 150
                implicitHeight: 25
            }
            //4
            Text {
                text: "Sesion:"
            }
            TextField {
                id: agendarClienteSesionTextField
                implicitWidth: 150
                implicitHeight: 25
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
                id: agendarClienteSesionesPagadasTextField
                implicitWidth: 150
                implicitHeight: 25
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Total Pagado:"
            }
            TextField {
                id: agendarClienteTotalPagadoTextField
                implicitWidth: 150
                implicitHeight: 25
            }
            //6
            Text {
                text: "Estatus de Cita:"
            }
            ComboBox {
                id: agendarClienteEstatusComboBox
                model: ["1 - Agendado", "2 - 1 Llamada", "3 - 2 Llamadas", "4 - Whatsapp Enviado",
                "5 - Sms enviado", "6 - Cita Cambiada", "7 - Cita Cancelada", "8 - Cita Confirmada"]
                implicitWidth: 150
                implicitHeight: 25
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 25
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 25
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 25
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 25
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 25
            }
        }
        GridLayout {
            id: observacionesGrid
            height: 20
            width: parent.width - 250
            anchors.top: agendarClienteGrid.bottom
            anchors.topMargin: 10
            columns: 4
            columnSpacing: 50

            //1
            Text {
                text: "Observaciones:"
            }
            TextField {
                id: agendarClienteObservacionesTextField
                implicitWidth: 900
                implicitHeight: 25
            }
            Rectangle {
                color: "transparent"
                height: 25
                width: 2
            }
            Rectangle {
                color: "transparent"
                width: 300
            }
        }
        Calendar {
            id: calendar
            weekNumbersVisible: true
            anchors.left: agendarClienteGrid.right
            anchors.top: agendarClienteGrid.top
            minimumDate: {
                datemanipulation.init()
                datemanipulation.getTodaysDate()
            }
            maximumDate: {
                datemanipulation.init()
                datemanipulation.getUpperBoundDate()
            }
            onClicked: {
                console.log(date)
                agendarClienteTableView.currentRow = datemanipulation.daysToSelection(date)*22
                agendarClienteTableView.selection.clear()
                agendarClienteTableView.selection.select(datemanipulation.daysToSelection(date)*22)
                agendarClienteTableView.forceActiveFocus()
            }
        }

        Rectangle {
            id: separadorDatosTabla
            anchors.top: observacionesGrid.bottom
            anchors.left: observacionesGrid.left
            anchors.topMargin: 25
            height: 2
            width: 1025
            color: "grey"
        }

        RowLayout {
            id: botonesLayout
            anchors.top: observacionesGrid.bottom
            anchors.left: observacionesGrid.left
            anchors.topMargin: 50
            anchors.leftMargin: observacionesGrid.width/5.5
            spacing: 15
            Button {
                text:"Mes anterior"
                onClicked: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.currentRow =  currentRow - (22*31+1)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow - (22*31))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
            Button {
                text:"Semana anterior"
                onClicked: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.currentRow =  currentRow - (22*7+1)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow - (22*7))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
            Button {
                text:"Dia anterior"
                onClicked: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.currentRow =  currentRow - (22*1+1)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow - (22*1))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
            Button {
                text:"Dia siguiente"
                onClicked: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.currentRow =  currentRow + (22*1)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow + (22*1))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
            Button {
                text:"Semana siguiente"
                onClicked: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.currentRow =  currentRow + (22*7)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow + (22*7))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
            Button {
                text:"Mes siguiente"
                onClicked: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.currentRow =  currentRow + (22*31)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow + (22*31))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
        }

        TableView {
            id: agendarClienteTableView
            anchors.top: botonesLayout.bottom
            anchors.topMargin: 20
            width: parent.width
            height: (parent.height/5)*2.5
            model: cabinaviewmodel
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
                        agendarClienteTableView.selection.clear()
                        agendarClienteTableView.currentRow = styleData.row
                        agendarClienteTableView.selection.select (styleData.row)
                        agendarclienteviewdata.setID(styleData.row)
                        agendarClienteTableView.forceActiveFocus()
                        console.log(styleData.value)
                    }
                }
            }
            onCurrentRowChanged: {
                var currentRow =  agendarClienteTableView.currentRow
                agendarClienteTableView.selection.clear()
                agendarClienteTableView.selection.select (currentRow)
                agendarclienteviewdata.setID(currentRow)
                agendarClienteTableView.forceActiveFocus()
                console.log("Current Row: " + currentRow)
            }
            TableViewColumn {
                role: "id"
                title: "ID"
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
            anchors.top: agendarClienteTableView.bottom
            anchors.left: parent.right
            anchors.topMargin: 10
            anchors.leftMargin: -230
            Button {
                text: "Cancelar"
                onClicked: {
                    //clear text
                    agendarClienteNombreTextField.text = ""
                    agendarClienteApellidosTextField.text = ""
                    agendarClienteCelularTextField.text = ""
                    agendarClienteTratamientoComboBox.currentIndex = -1
                    agendarClienteServicioComboBox.currentIndex = -1
                    agendarClienteDuracionComboBox.currentIndex = -1
                    agendarClienteZonasTextField.text = ""
                    agendarClientePrecioTextField.text = ""
                    agendarClienteSesionTextField.text = ""
                    agendarClienteSesionesPagadasTextField.text = ""
                    agendarClienteTotalPagadoTextField.text = ""
                    agendarClienteEstatusComboBox.currentIndex = -1
                    agendarClienteObservacionesTextField.text = ""
                    agendarClienteImporteCobradoTextField.text = ""

                    agendarClienteNombreTextField.forceActiveFocus()
                    ventanaDeManipulacionSQL.show()
                    agendarCliente.hide()
                }
            }
            Button {
                id: agendarClienteAceptarButton
                text: "Aceptar"
                anchors.leftMargin: 20
                enabled: {
                    if (agendarClienteGrid.acceptEnabled === false ||
                                 agendarClienteTableView.activeFocus === false)
                             return false
                    else
                             return true
                }
                onClicked: {
                    datemanipulation.clearIDsQueued()
                    var i;
                    var lastRowOfDay = false;
                    var nombre;
                    var apellidos;
                    var celular;

                    //assign nombre, apellidos, celular
                    if (agendarclienteviewdata.clienteEsNuevo === true)
                    {
                        nombre = agendarClienteNombreTextField.text
                        apellidos = agendarClienteApellidosTextField.text
                        celular = agendarClienteCelularTextField.text
                    }
                    else
                    {
                        nombre = agendarClienteExistenteNombreTextField.text
                        apellidos = agendarClienteExistenteApellidosTextField.text
                        celular = agendarClienteExistenteCelularTextField.text
                    }

                    //iterate over cita duration
                    for (i = 0; i < agendarClienteDuracionComboBox.currentIndex+1; i++)
                    {
                        cabinasqlqueries.updateID()
                        datemanipulation.addCurrentIDToIDsQueued()
                        cabinasqlqueries.updateQuery(clinicacore.currentCabina)
                        //fila disponible
                        if (cabinasqlqueries.rowIsEmpty() === true)
                        {
                            console.log("Nombre is NULL")
                        }
                        //error - fila ocupada
                        else
                        {
                            console.log("Error - fila ocupada")
                            cabinasqlqueries.clearRowsDueToBusyRow()
                            errorMessageBusyRow.visible = true
                            break;
                        }
                        if (lastRowOfDay == true)
                        {
                            cabinasqlqueries.clearRowsDueToBusyRow()
                            errorMessageExceedingLastRow.visible = true
                            break;
                        }
                        //error - de dia para otro dia
                        if (agendarclienteviewdata.isLastRowOfDay() === true)
                        {
                            console.log("Last Day")
                            lastRowOfDay = true
                        }
                        cabinasqlqueries.updateRowInTable(nombre, apellidos, celular,
                                                         agendarClienteTratamientoComboBox.currentText,
                                                         agendarClienteServicioComboBox.currentText,
                                                         agendarClienteZonasTextField.text,
                                                         agendarClientePrecioTextField.text,
                                                         agendarClienteSesionTextField.text,
                                                         agendarClienteSesionesPagadasTextField.text,
                                                         agendarClienteTotalPagadoTextField.text,
                                                         agendarClienteEstatusComboBox.currentText,
                                                         agendarClienteObservacionesTextField.text,
                                                         agendarClienteImporteCobradoTextField.text,
                                                         agendarClienteDuracionComboBox.currentIndex)
                        if (agendarClienteDuracionComboBox.currentIndex > 0)
                        {
                            agendarClienteTableView.currentRow = agendarClienteTableView.currentRow + 1
                        }
                    }

                    cabinasqlqueries.updateQuery(clinicacore.currentCabina)

                    //Agregar cliente a base de datos si es nuevo
                    if (agendarclienteviewdata.clienteEsNuevo === true)
                    {
                        clientessqlqueries.addPaciente(agendarClienteNombreTextField.text,
                                                      agendarClienteApellidosTextField.text,
                                                      agendarClienteCelularTextField.text)
                    }

                    //clear text
                    agendarClienteNombreTextField.text = ""
                    agendarClienteApellidosTextField.text = ""
                    agendarClienteCelularTextField.text = ""
                    agendarClienteTratamientoComboBox.currentIndex = -1
                    agendarClienteServicioComboBox.currentIndex = -1
                    agendarClienteDuracionComboBox.currentIndex = -1
                    agendarClienteZonasTextField.text = ""
                    agendarClientePrecioTextField.text = ""
                    agendarClienteSesionTextField.text = ""
                    agendarClienteSesionesPagadasTextField.text = ""
                    agendarClienteTotalPagadoTextField.text = ""
                    agendarClienteEstatusComboBox.currentIndex = -1
                    agendarClienteObservacionesTextField.text = ""
                    agendarClienteImporteCobradoTextField.text = ""

                    agendarClienteNombreTextField.forceActiveFocus()
                }
            }
        }
    }
    //error messages
    MessageDialog {
        id: errorMessageBusyRow
        title: "Accion invalida"
        text: "No se puede agendar en un horario ocupado."
        icon: StandardIcon.Warning
        onAccepted: {
            errorMessageBusyRow.close()
        }
        Component.onCompleted: visible = false
    }
    MessageDialog {
        id: errorMessageExceedingLastRow
        title: "Accion invalida"
        text: "No se puede agendar despues de las 8:00 pm."
        icon: StandardIcon.Warning
        onAccepted: {
            errorMessageExceedingLastRow.close()
        }
        Component.onCompleted: visible = false
    }
}
