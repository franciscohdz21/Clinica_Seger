#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "cabinasqlqueries.h"
#include "cabinaviewmodel.h"
#include "clientessqlqueries.h"
#include "clientesviewmodel.h"
#include "clinicacore.h"
#include "datemanipulation.h"
#include "editarpacientesqlqueries.h"
#include "editarpacienteviewdata.h"
#include "establishconnection.h"
#include "agendarclienteviewdata.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //Context Properties
    QQmlContext* agendarClienteViewDataCtx = engine.rootContext();
    agendarClienteViewDataCtx->setContextProperty("agendarclienteviewdata", &AgendarClienteViewData::Instance());

    QQmlContext* cabinaSQLQueriesCtx = engine.rootContext();
    cabinaSQLQueriesCtx->setContextProperty("cabinasqlqueries", &CabinaSQLQueries::Instance());

    QQmlContext* cabinaViewModelCtx = engine.rootContext();
    cabinaViewModelCtx->setContextProperty("cabinaviewmodel", &CabinaViewModel::Instance());

    QQmlContext* clientesSQLQueriesCtx = engine.rootContext();
    clientesSQLQueriesCtx->setContextProperty("clientessqlqueries", &ClientesSQLQueries::Instance());

    QQmlContext* clientesViewModelCtx = engine.rootContext();
    clientesViewModelCtx->setContextProperty("clientesviewmodel", &ClientesViewModel::Instance());

    QQmlContext* clinicaCoreCtx = engine.rootContext();
    clinicaCoreCtx->setContextProperty("clinicacore", &ClinicaCore::Instance());

    QQmlContext* dateManipulationCtx = engine.rootContext();
    dateManipulationCtx->setContextProperty("datemanipulation", &DateManipulation::Instance());

    QQmlContext* editarPacienteSQLQueriesCtx = engine.rootContext();
    editarPacienteSQLQueriesCtx->setContextProperty("editarpacientesqlqueries", &EditarPacienteSQLQueries::Instance());

    QQmlContext* editarPacienteViewDataCtx = engine.rootContext();
    editarPacienteViewDataCtx->setContextProperty("editarpacienteviewdata", &EditarPacienteViewData::Instance());

    QQmlContext* establishConnectionCtx = engine.rootContext();
    establishConnectionCtx->setContextProperty("establishconnection", &EstablishConnection::Instance());
    EstablishConnection::Instance().start();


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
