import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

Window {
    width: 310
    minimumWidth: 310
    maximumWidth: 310
    height: 140
    minimumHeight: 140
    maximumHeight: 140
    title: "Cambiar año"
    Component.onCompleted: visible = false
    onClosing: {
        close.accepted = false
        cambiarAno.hide()
    }

    Rectangle {
        anchors.fill: parent
        color: "#DABDDC"

        ColumnLayout {
            anchors.fill: parent
            anchors.topMargin: 20
            anchors.bottomMargin: 20
            anchors.leftMargin: 30
            anchors.rightMargin: 30

            RowLayout {
                id: cambiarAnoRowLayoutComboBox
                spacing: 15

                Text {
                    text: qsTr("Seleccionar año")
                }
                ComboBox {
                    id: anoComboBox
                    model: datemanipulation.getYearRange()
                    implicitWidth: 150
                    implicitHeight: 25
                }
            }

            Rectangle {
                width: 100
                height: 30
                color: "transparent"
            }

            RowLayout {
                id: cambiarAnoRowLayoutButtons
                spacing: 15

                Rectangle {
                    height: 10
                    width: 1
                    color: "transparent"
                }

                Button {
                    id: cancelarButton
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
                        cambiarAno.hide()
                        anoComboBox.currentIndex = 0
                    }
                }
                Button {
                    id: aceptarButton
                    text: "Aceptar"
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 40
                        color: "#F0A693"
                        border.color: "black"
                        border.width: 1
                        radius: 4
                    }
                    onPressed: {
                        var ano;
                        if (anoComboBox.currentText === "Presente")
                            ano = 0
                        else
                            ano = anoComboBox.currentText
                        datemanipulation.buildDateBounds(ano)
                        cabinasqlqueries.updateQuery(clinicacore.currentCabina)
                        cambiarAno.hide()
                        anoComboBox.currentIndex = 0
                    }
                }
            }
        }
    }
}
