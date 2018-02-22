import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.3
import QtQuick.Controls 1.4 as QuickControls_1_4
import QtQuick.Controls 2.3 as QuickControls_2_3

Window {
    id: ventanaDeConexion
    visible: true
    width: 350
    minimumWidth: 350
    maximumWidth: 350
    height: 300
    minimumHeight: 300
    maximumHeight: 300
    title: "Establecer Conexion"
    onClosing: {
        close.accepted = false
        establishconnection.terminate()
        Qt.quit()
    }

    VentanaDeLogin {
        id: ventanaDeLogin
        visible: false
    }

    Rectangle {
        anchors.fill: parent
        color: "#DABDDC"

        GridLayout {
            id: conexionGrid
            anchors.leftMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent
            columns: 2

            Text {
                text: "IP:"
            }
            QuickControls_2_3.TextField {
                id: ipTextField
                text: {
                    if (clinicacore.developerMode === true)
                        return "127.0.0.1"
                    else
                        return ""
                }
            }
            Text {
                text: "Puerto:"
            }
            QuickControls_2_3.TextField {
                id: puertoTextField
                text: "3306"
                readOnly: false
                enabled: false
            }
            Text {
                text: "Contrasena:"
            }
            QuickControls_2_3.TextField {
                id: contrasenaTextField
                text: "REadzx12"
                echoMode: TextInput.Password
                enabled: false
            }
            Rectangle {
                width: 20
                color: "black"
            }
            RowLayout {
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
                        establishconnection.terminate()
                        Qt.quit()
                    }
                }
                QuickControls_2_3.Button {
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
                        if (establishconnection.establecerConexion(ipTextField.text,
                                                                    puertoTextField.text,
                                                                    contrasenaTextField.text) === true)
                        {
                            ventanaDeConexion.hide()
                            ventanaDeLogin.show()
                        }
                        else
                        {
                            errorAlConectarse.visible = true
                        }
                    }
                }
            }
        }
    }
    MessageDialog {
        id: errorAlConectarse
        title: "Error al intentar conectarse"
        text: "IP y/o contrasena equivocado, intentelo de nuevo."
        icon: StandardIcon.Critical
        onAccepted: {
            errorAlConectarse.close()
        }
        Component.onCompleted: {
            visible = false
        }
    }
}
