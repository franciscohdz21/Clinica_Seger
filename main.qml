import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2

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

    VentanaDeLogin {
        id: ventanaDeLogin
        visible: false
    }

    Rectangle {
        anchors.fill: parent
        color: "lightyellow"

        GridLayout {
            id: conexionGrid
            anchors.leftMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent
            columns: 2

            Text {
                text: "IP:"
            }
            TextField {
                id: ipTextField
                text: "127.0.0.1"
            }
            Text {
                text: "Puerto:"
            }
            TextField {
                id: puertoTextField
                text: "3306"
                readOnly: false
            }
            Text {
                text: "Contrasena:"
            }
            TextField {
                id: contrasenaTextField
                text: "REadzx12"
                echoMode: TextInput.Password
            }
            Rectangle {
                width: 20
                color: "black"
            }
            RowLayout {
                Button {
                    text: "Cancelar"
                    onClicked: {
                        Qt.quit()
                    }
                }
                Button {
                    text: "Aceptar"
                    onClicked: {
                        if (establishconnection.establecerConexion(ipTextField.text,
                                                                    puertoTextField.text,
                                                                    contrasenaTextField.text) === true)
                        {
                            ventanaDeConexion.close()
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
            contrasenaTextField.text = ""
        }
        Component.onCompleted: visible = false
    }
}
