import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.3

Window {
    width: 350
    minimumWidth: 350
    maximumWidth: 350
    height: 300
    minimumHeight: 300
    maximumHeight: 300
    title: "Iniciar Sesion"

    VentanaDeManipulacionSQL {
        id: ventanaDeManipulacionSQL
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
                text: "Usuario:"
            }
            TextField {
                id: usuarioTextField
                text: {
                    if (clinicacore.developerMode === true)
                        return "root"
                    else
                        return ""
                }
            }
            Text {
                text: "Contrasena:"
            }
            TextField {
                id: contrasena2TextField
                text: {
                    if (clinicacore.developerMode === true)
                        return "HEadzx12"
                    else
                        return ""
                }
                echoMode: TextInput.Password
            }
            Rectangle {
                width: 20
                color: "black"
            }
            RowLayout {
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
                        Qt.quit()
                    }
                }
                Button {
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
                        if (establishconnection.loginAPrograma(usuarioTextField.text,
                                                            contrasena2TextField.text) !== -1)
                        {
                            ventanaDeLogin.hide()
                            ventanaDeManipulacionSQL.show()
                        }
                        else {
                            errorAlLogin.visible = true
                        }
                    }
                }
            }
        }
    }
    MessageDialog {
        id: errorAlLogin
        title: "Error al intentar ingresar"
        text: "Usuario y/o contrasena equivocado, intentelo de nuevo."
        icon: StandardIcon.Critical
        onAccepted: {
            errorAlLogin.close()
            contrasena2TextField.text = ""
        }
        Component.onCompleted: visible = false
    }
}
