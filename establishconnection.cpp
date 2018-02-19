#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "establishconnection.h"
#include "clinicacore.h"
#include "datemanipulation.h"

EstablishConnection &EstablishConnection::Instance()
{
    static EstablishConnection instance; //Guaranteed to be destroyed
    return instance;
}
bool EstablishConnection::establecerConexion(const QString IP, const int puerto, const QString contrasena)
{
    QSqlDatabase sqlDatabse;
    sqlDatabse = QSqlDatabase::addDatabase("QMYSQL");
    sqlDatabse.setHostName(IP);
    if (ClinicaCore::Instance().developerMode() == true)
        sqlDatabse.setDatabaseName("Clinica_test");
    else
        sqlDatabse.setDatabaseName("Clinica");
    sqlDatabse.setPort(puerto);
    sqlDatabse.setUserName("root");
    sqlDatabse.setPassword(contrasena);
    return sqlDatabse.open();
}
int EstablishConnection::loginAPrograma(const QString usuario, const QString contrasena)
{
    QString query;
    query.append("SELECT Permiso FROM personal WHERE Usuario = '" + usuario + "'");
    query.append(" AND Contrasena = '"+ contrasena + "'");
    QSqlQuery sqlQuery(query);
    ClinicaCore::Instance().setPermiso(-1);
    while (sqlQuery.next()) {
        ClinicaCore::Instance().setPermiso(sqlQuery.value(0).toInt());
    }
    if (ClinicaCore::Instance().developerMode() == true)
        qDebug () << "Permiso: " << ClinicaCore::Instance().permiso();
    if (ClinicaCore::Instance().permiso() == -1)
        return -1;
    else
    {
        //init calendar/date
        DateManipulation::Instance().init();
        ClinicaCore::Instance().setUsuario(usuario);
        //query ubicacion
        query.clear();
        query.append("SELECT Ubicacion FROM personal WHERE Usuario = '" + usuario + "'");
        query.append(" AND Contrasena = '"+ contrasena + "'");
        QSqlQuery sqlQuery(query);
        ClinicaCore::Instance().setUbicacion(""); // NEEDED?
        while (sqlQuery.next())
        {
            ClinicaCore::Instance().setUbicacion(sqlQuery.value(0).toString());
        }
        if (ClinicaCore::Instance().developerMode() == true)
            qDebug () << "Ubicacion: " << ClinicaCore::Instance().ubicacion();

        //query cabinas
        query.clear();
        query.append("SELECT Cabinas FROM personal WHERE Usuario = '" + usuario + "'");
        query.append(" AND Contrasena = '"+ contrasena + "'");
        QSqlQuery sqlQuery2(query);
        QStringList cabinas;
        ClinicaCore::Instance().setCabinas(cabinas);
        while (sqlQuery2.next())
        {
            ClinicaCore::Instance().buildCabinas(sqlQuery2.value(0).toString());
        }
        if (ClinicaCore::Instance().developerMode() == true)
            qDebug () << "Cabinas: " << ClinicaCore::Instance().cabinas();

        //set tratamientos and servicios
        QStringList tmp;
        ClinicaCore::Instance().setTratamientos(tmp);
        ClinicaCore::Instance().setServicios();
        return ClinicaCore::Instance().permiso();
    }
}
