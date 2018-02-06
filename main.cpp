#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "conexionabasededatos.h"
#include "cabinaviewmodel.h"
#include "clientesviewmodel.h"
#include "pacientependienteviewmodel.h"
#include "editarpacienteviewmodel.h"
#include "calendarfunctions.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //Set context properties
    QQmlContext* conexionABaseDeDatosCtx = engine.rootContext();
    conexionABaseDeDatosCtx->setContextProperty("conexionabasededatos", &ConexionABaseDeDatos::Instance());

    QQmlContext* cabinaViewModelCtx = engine.rootContext();
    cabinaViewModelCtx->setContextProperty("cabinaviewmodel", &CabinaViewModel::Instance());

    QQmlContext* clientesViewModelCtx = engine.rootContext();
    clientesViewModelCtx->setContextProperty("clientesviewmodel", &ClientesViewModel::Instance());

    QQmlContext* pacientePendienteViewModelCtx = engine.rootContext();
    pacientePendienteViewModelCtx->setContextProperty("pacientependienteviewmodel", &PacientePendienteViewModel::Instance());

    QQmlContext* editarPacienteViewModelCtx = engine.rootContext();
    editarPacienteViewModelCtx->setContextProperty("editarpacienteviewmodel", &EditarPacienteViewModel::Instance());

    QQmlContext* calendarFunctionsCtx = engine.rootContext();
    calendarFunctionsCtx->setContextProperty("calendarfunctions", &CalendarFunctions::Instance());

    //Load engine
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
