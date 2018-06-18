#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QModelIndex>
#include "clientessqlqueries.h"
#include "clientesviewmodel.h"
#include "clinicacore.h"

ClientesSQLQueries &ClientesSQLQueries::Instance()
{
    static ClientesSQLQueries instance; //Guaranteed to be destroyed
    return instance;
}
void ClientesSQLQueries::updateQuery()
{
    QString query = "SELECT * FROM " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion());
    ClientesViewModel::Instance().setQuery(query);

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updateQuery - Last error: " + ClientesViewModel::Instance().lastError().text());
}
void ClientesSQLQueries::filterQueryByCellphone(QString celular)
{
    QString celularForQuery = "'%" + celular + "%'";
    QString query = "SELECT * FROM " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " WHERE celular LIKE ";
    query.append(celularForQuery);
    ClientesViewModel::Instance().setQuery(query);

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::filterQueryByCellphone - Last error: " +
                                       ClientesViewModel::Instance().lastError().text());
}
void ClientesSQLQueries::filterQueryByLastName(const QString apellidos)
{
    QString lastNameForQuery = "'%" + apellidos + "%'";
    QString query = "SELECT * FROM " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " WHERE apellidos LIKE ";
    query.append(lastNameForQuery);
    ClientesViewModel::Instance().setQuery(query);

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::filterQueryByLastName - Last error: " +
                                       ClientesViewModel::Instance().lastError().text());
}
void ClientesSQLQueries::updatePaciente(QString nombre, QString apellidos, QString celular, QString telefono, QString correo,
                                             int diaFechaDeNacimientoIndex, int mesFechaDeNacimientoIndex, QString anoFechaDeNacimiento,
                                             QString calleYNumero, QString colonia, QString ciudad, QString estado,
                                             QString sesionesPagadas, QString saldoAFavor, QString sesionesDeGarantia, QString currentCelular)
{
    //empty string handling
    if (nombre.compare("", Qt::CaseInsensitive) == 0)
        nombre = " ";
    if (celular.compare("", Qt::CaseInsensitive) == 0)
        celular = " ";
    if (telefono.compare("", Qt::CaseInsensitive) == 0)
        telefono = " ";
    if (correo.compare("", Qt::CaseInsensitive) == 0)
        correo = " ";
    if (QString::number(diaFechaDeNacimientoIndex).compare("", Qt::CaseInsensitive) == 0)
        diaFechaDeNacimientoIndex = 0;
    if (QString::number(mesFechaDeNacimientoIndex).compare("", Qt::CaseInsensitive) == 0)
        mesFechaDeNacimientoIndex = 0;
    if (anoFechaDeNacimiento.compare("", Qt::CaseInsensitive) == 0)
        anoFechaDeNacimiento = " ";
    if (calleYNumero.compare("", Qt::CaseInsensitive) == 0)
        calleYNumero = " ";
    if (colonia.compare("", Qt::CaseInsensitive) == 0)
        colonia = " ";
    if (ciudad.compare("", Qt::CaseInsensitive) == 0)
        ciudad = " ";
    if (estado.compare("", Qt::CaseInsensitive) == 0)
        estado = " ";
    if (sesionesPagadas.compare("", Qt::CaseInsensitive) == 0)
        sesionesPagadas = " ";
    if (saldoAFavor.compare("", Qt::CaseInsensitive) == 0)
        saldoAFavor = " ";
    if (sesionesDeGarantia.compare("", Qt::CaseInsensitive) == 0)
        sesionesDeGarantia = " ";
    if (currentCelular.compare("", Qt::CaseInsensitive) == 0)
        currentCelular = " ";


    //nombre
    QSqlQuery query;
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Nombre = :nombre, "
                      "Apellidos = :apellidos, "
                      "Celular = :celular "
                  "WHERE Celular = :currentCelular");
    query.bindValue(":nombre", nombre);
    query.bindValue(":apellidos", apellidos);
    query.bindValue(":celular", celular);
    query.bindValue(":currentCelular", currentCelular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //apellidos
    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Apellidos = :apellidos "
                  "WHERE Celular = :celular");

    query.bindValue(":apellidos", apellidos);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //celular
    query.clear();
    QString queryStr = "UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                       "SET Celular = :celular "
                       "WHERE Celular = ";
    queryStr.append(currentCelular);
    query.prepare(queryStr);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //telefono
    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Telefono = :telefono "
                  "WHERE Celular = :celular");

    query.bindValue(":telefono", telefono);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //correo
    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Correo = :correo "
                  "WHERE Celular = :celular");

    query.bindValue(":correo", correo);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //fecha de nacimiento
    int dia = diaFechaDeNacimientoIndex + 1;
    QString diaString = QString::number(dia);
    if (diaString.size() == 1)
        diaString.prepend("0");

    int mes = mesFechaDeNacimientoIndex + 1;
    QString mesString = QString::number(mes);
    if (mesString.size() == 1)
        mesString.prepend("0");

    QString fecha;
    fecha.append(anoFechaDeNacimiento + "-");
    fecha.append(mesString + "-");
    fecha.append(diaString);

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Fecha to update: " + fecha);

    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Fecha_De_Nacimiento = :fechaDeNacimiento "
                  "WHERE Celular = :celular");

    query.bindValue(":fechaDeNacimiento", fecha);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //calle y numero
    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Calle_Y_Numero = :calleYNumero "
                  "WHERE Celular = :celular");
    query.bindValue(":calleYNumero", calleYNumero);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //colonia
    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Colonia = :colonia "
                  "WHERE Celular = :celular");
    query.bindValue(":colonia", colonia);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //ciudad
    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Ciudad = :ciudad "
                  "WHERE Celular = :celular");
    query.bindValue(":ciudad", ciudad);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //estado
    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Estado = :estado "
                  "WHERE Celular = :celular");
    query.bindValue(":estado", estado);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //sesiones pagadas
    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Sesiones_Pagadas = :sesionesPagadas "
                  "WHERE Celular = :celular");

    query.bindValue(":sesionesPagadas", sesionesPagadas);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //saldo a favor
    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Saldo_A_Favor = :saldoAFavor "
                  "WHERE Celular = :celular");
    query.bindValue(":saldoAFavor", saldoAFavor);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    //sesiones de garantia
    query.clear();
    query.prepare("UPDATE " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Sesiones_De_Garantia = :sesionesDeGarantia "
                  "WHERE Celular = :celular");
    query.bindValue(":sesionesDeGarantia", sesionesDeGarantia);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());

    updateQuery();
}
void ClientesSQLQueries::addPaciente(QString nombre, QString apellidos, QString celular)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " + getUbicacionForTableText(ClinicaCore::Instance().ubicacion()) + " "
                  "SET Nombre = :nombre, "
                  "    Apellidos = :apellidos, "
                  "    Celular = :celular;");
    query.bindValue(":nombre", nombre);
    query.bindValue(":apellidos", apellidos);
    query.bindValue(":celular", celular);
    query.exec();

    ClinicaCore::Instance().consoleOut("ClientesSQLQueries::updatePaciente - Last error: " + query.lastError().text());
}
QString ClientesSQLQueries::getUbicacionForTableText(QString ubicacionFromLogin)
{
    if (ubicacionFromLogin.compare("Test", Qt::CaseInsensitive) == 0)
        return "clientes_test";
    else if (ubicacionFromLogin.compare("La Capilla, 5 de Feb", Qt::CaseInsensitive) == 0)
        return "clientes_capilla";
    else if (ubicacionFromLogin.compare("Colinas del Cimatario", Qt::CaseInsensitive) == 0)
        return "clientes_colinas";
    else if (ubicacionFromLogin.compare("San Juan del Rio", Qt::CaseInsensitive) == 0)
        return "clientes_san_juan";
    else if (ubicacionFromLogin.compare("Global", Qt::CaseInsensitive) == 0)
        return "clientes_global";
    return "";
}
