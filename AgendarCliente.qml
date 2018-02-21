import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4 as QuickControls_1_4
import QtQuick.Controls 2.3 as QuickControls_2_3

Window {
    id: agendarCliente
    width: 1366
    minimumWidth: 1366
    maximumWidth: 1366
    height: 728
    minimumHeight: 728
    maximumHeight: 728
    title: "Agendar Cliente"
    color: "#DABDDC"
    Component.onCompleted: {
        agendarClienteServicioComboBox.currentIndex = -1
        agendarClienteDuracionComboBox.currentIndex = -1
        agendarClienteEstatusComboBox.currentIndex = -1
    }

    onClosing: {
        close.accepted = false
        cambiarAno.hide()
        agendarCliente.hide()
        ventanaDeManipulacionSQL.show()
    }

    Rectangle {
        anchors.fill: parent
        anchors.topMargin: 10
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        color: "#DABDDC"

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
                    if ( agendarClienteNombreTextField.text === "" ||
                            agendarClienteApellidosTextField.text === "" ||
                            agendarClienteCelularTextField.text === "" ||
                            agendarClienteZonasTextField.text === "" ||
                            agendarClienteDuracionComboBox.currentIndex === -1 ||
                            agendarClientePrecioTextField.text === "" ||
                            agendarClienteImporteCobradoTextField.text === "" ||
                            agendarClienteSesionTextField.text === "" ||
                            agendarClienteSesionesPagadasTextField.text === "" ||
                            agendarClienteTotalPagadoTextField.text === "" ||
                            agendarClienteEstatusComboBox.currentIndex === -1)
                    {
                        return false
                    }
                    else
                    {
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
                            agendarClienteImporteCobradoTextField.text === "" ||
                            agendarClienteSesionTextField.text === "" ||
                            agendarClienteSesionesPagadasTextField.text === "" ||
                            agendarClienteTotalPagadoTextField.text === "" ||
                            agendarClienteEstatusComboBox.currentIndex === -1)
                    {
                        return false
                    }
                    else
                    {
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
                QuickControls_2_3.TextField {
                    id: agendarClienteNombreTextField
                    enabled: agendarclienteviewdata.clienteEsNuevo
                    visible: agendarclienteviewdata.clienteEsNuevo
                    implicitWidth: 150
                    implicitHeight: 25
                }
                QuickControls_2_3.TextField {
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
                QuickControls_2_3.TextField {
                    id: agendarClienteApellidosTextField
                    enabled: agendarclienteviewdata.clienteEsNuevo
                    visible: agendarclienteviewdata.clienteEsNuevo
                    implicitWidth: 150
                    implicitHeight: 25
                }
                QuickControls_2_3.TextField {
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
                QuickControls_2_3.TextField {
                    id: agendarClienteCelularTextField
                    enabled: agendarclienteviewdata.clienteEsNuevo
                    visible: agendarclienteviewdata.clienteEsNuevo
                    implicitWidth: 150
                    implicitHeight: 25
                    maximumLength: 10
                }
                QuickControls_2_3.TextField {
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
            QuickControls_2_3.ComboBox {
                id: agendarClienteTratamientoComboBox
                enabled: false
                model: clinicacore.tratamientos
                implicitWidth: 150
                onCurrentIndexChanged: clinicacore.buildCurrentServicios(agendarClienteTratamientoComboBox.currentIndex)
                implicitHeight: 25
                currentIndex: agendarclienteviewdata.tratamientoCurrentIndex
            }
            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }
            Text {
                text: "Servicio:"
            }
            QuickControls_2_3.ComboBox {
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
            QuickControls_2_3.TextField {
                id: agendarClienteZonasTextField
                implicitWidth: 150
                implicitHeight: 25
            }
            //3
            Text {
                text: "Duracion:"
            }
            QuickControls_2_3.ComboBox {
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
            QuickControls_2_3.TextField {
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
            QuickControls_2_3.TextField {
                id: agendarClienteImporteCobradoTextField
                implicitWidth: 150
                implicitHeight: 25
            }
            //4
            Text {
                text: "Sesion:"
            }
            QuickControls_2_3.TextField {
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
            QuickControls_2_3.TextField {
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
            QuickControls_2_3.TextField {
                id: agendarClienteTotalPagadoTextField
                implicitWidth: 150
                implicitHeight: 25
            }
            //6
            Text {
                text: "Estatus de Cita:"
            }
            QuickControls_2_3.ComboBox {
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
            QuickControls_2_3.TextField {
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
        QuickControls_1_4.Calendar {
            id: calendar
            weekNumbersVisible: true
            anchors.left: agendarClienteGrid.right
            anchors.top: agendarClienteGrid.top
            minimumDate: {
                datemanipulation.lowerBoundDate
            }
            maximumDate: {
                datemanipulation.upperBoundDate
            }
            onClicked: {
                if (clinicacore.developerMode === true)
                    console.log(date)
                agendarClienteTableView.positionViewAtRow(datemanipulation.daysToSelection(date)*22, ListView.Contain)
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
            QuickControls_2_3.Button {
                text:"Mes anterior"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.positionViewAtRow(currentRow - (22*31), ListView.Contain)
                    agendarClienteTableView.currentRow =  currentRow - (22*31)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow - (22*31))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
            QuickControls_2_3.Button {
                text:"Semana anterior"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.positionViewAtRow(currentRow - (22*7), ListView.Contain)
                    agendarClienteTableView.currentRow =  currentRow - (22*7)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow - (22*7))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
            QuickControls_2_3.Button {
                text:"Dia anterior"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.positionViewAtRow(currentRow - (22*1), ListView.Contain)
                    agendarClienteTableView.currentRow =  currentRow - (22*1)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow - (22*1))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
            QuickControls_2_3.Button {
                text:"Dia siguiente"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.positionViewAtRow(currentRow + (22*1), ListView.Contain)
                    agendarClienteTableView.currentRow =  currentRow + (22*1)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow + (22*1))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
            QuickControls_2_3.Button {
                text:"Semana siguiente"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.positionViewAtRow(currentRow + (22*7), ListView.Contain)
                    agendarClienteTableView.currentRow =  currentRow + (22*7)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow + (22*7))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
            QuickControls_2_3.Button {
                text:"Mes siguiente"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    var currentRow = agendarClienteTableView.currentRow
                    agendarClienteTableView.positionViewAtRow(currentRow + (22*31), ListView.Contain)
                    agendarClienteTableView.currentRow =  currentRow + (22*31)
                    agendarClienteTableView.selection.clear()
                    agendarClienteTableView.selection.select(currentRow + (22*31))
                    agendarClienteTableView.forceActiveFocus()
                }
            }
        }

        QuickControls_1_4.TableView {
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
                        if (clinicacore.developerMode === true)
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
                if (clinicacore.developerMode === true)
                    console.log("Current Row: " + currentRow)
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
            anchors.top: agendarClienteTableView.bottom
            anchors.left: parent.left
            anchors.topMargin: 10
            anchors.leftMargin: 950
            spacing: 15
            QuickControls_2_3.Button {
                text: "Cambiar año"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#F0A693"
                    border.color: "black"
                    border.width: 1
                    radius: 4
                }
                onPressed: {
                    agendarClienteTableView.selection.clear()
                    cambiarAno.show()
                }
            }

            Rectangle {
                color: "grey"
                height: 25
                width: 2
            }

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
                    agendarClienteTableView.selection.clear()
                    cambiarAno.hide()
                    //clear text
                    agendarClienteNombreTextField.text = ""
                    agendarClienteApellidosTextField.text = ""
                    agendarClienteCelularTextField.text = ""
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
            QuickControls_2_3.Button {
                id: agendarClienteAceptarButton
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
                    if (agendarClienteGrid.acceptEnabled === false ||
                                 agendarClienteTableView.activeFocus === false)
                             return false
                    else
                             return true
                }
                onPressed: {
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
                            if (clinicacore.developerMode === true)
                                console.log("Nombre is NULL")
                        }
                        //error - fila ocupada
                        else
                        {
                            if (clinicacore.developerMode === true)
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
                            if (clinicacore.developerMode === true)
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

                    agendarClienteTableView.selection.clear()
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
