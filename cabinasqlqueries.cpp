#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QDate>
#include <QSqlQueryModel>
#include "cabinasqlqueries.h"
#include "cabinaviewmodel.h"
#include "agendarclienteviewdata.h"
#include "clinicacore.h"
#include "datemanipulation.h"

CabinaSQLQueries &CabinaSQLQueries::Instance()
{
    static CabinaSQLQueries instance; //Guaranteed to be destroyed
    return instance;
}
void CabinaSQLQueries::initCitaDeletion(int row)
{
    //no selection
    if (row == -1)
        return;

    //get row values
    if (!CabinaViewModel::Instance().query().seek(row))
        return;

    if ( (!CabinaViewModel::Instance().record().isGenerated("Fecha")) || (!CabinaViewModel::Instance().record().isGenerated("Celular")) ||
         (!CabinaViewModel::Instance().record().isGenerated("Servicio")) )
    {
        ClinicaCore::Instance().consoleOut("CabinaSQLQueries::initCitaDeletion - Error setting fecha, celular o servicio");
    }
    else
    {
        QString fecha =  CabinaViewModel::Instance().query().value("Fecha").toString();
        QString celular = CabinaViewModel::Instance().query().value("Celular").toString();
        QString servicio = CabinaViewModel::Instance().query().value("Servicio").toString();

        ClinicaCore::Instance().consoleOut("CabinaSQLQueries::initCitaDeletion - " + fecha + celular + servicio);

        deleteCita(fecha, celular, servicio);
    }
}
void CabinaSQLQueries::filterQueryByCellphone(QString celular)
{
    QString celularForQuery = "'%" + celular + "%'";
    QString query;
    query.append("SELECT * FROM " + AgendarClienteViewData::Instance().getNombreDeTabla() +
                 " WHERE celular LIKE " + celularForQuery +
                 " AND Fecha >= '" + DateManipulation::Instance().lowerBoundDate().toString("yyyy-MM-dd") +
                 "' AND Fecha <= '" + DateManipulation::Instance().upperBoundDate().toString("yyyy-MM-dd") + "'" +
                 "ORDER BY Fecha ASC");
    CabinaViewModel::Instance().setQuery(query);

    ClinicaCore::Instance().consoleOut("CabinaSQLQueries::filterQueryByCellphone - Last error: " +
                                       CabinaViewModel::Instance().lastError().text());
}
void CabinaSQLQueries::filterQueryByLastName(const QString apellidos)
{
    QString apellidosForQuery = "'%" + apellidos + "%'";
    QString query;
    query.append("SELECT * FROM " + AgendarClienteViewData::Instance().getNombreDeTabla() +
                 " WHERE apellidos LIKE " + apellidosForQuery +
                 " AND Fecha >= '" + DateManipulation::Instance().lowerBoundDate().toString("yyyy-MM-dd") +
                 "' AND Fecha <= '" + DateManipulation::Instance().upperBoundDate().toString("yyyy-MM-dd") + "'" +
                 "ORDER BY Fecha ASC");
    CabinaViewModel::Instance().setQuery(query);

    ClinicaCore::Instance().consoleOut("CabinaSQLQueries::filterQueryByLastName - Last error: " +
                                       CabinaViewModel::Instance().lastError().text());
}
void CabinaSQLQueries::updateQuery(const QString cabina)
{
    QString nombreDeTabla;
    //dev mode
    if(ClinicaCore::Instance().ubicacion().compare("Test", Qt::CaseInsensitive) == 0)
    {
        nombreDeTabla.append("template_cabina_test");
        AgendarClienteViewData::Instance().setNombreDeTabla(nombreDeTabla);
        //setup general cabina query (sorted)
        QString query = "SELECT * FROM " + AgendarClienteViewData::Instance().getNombreDeTabla() +
                " WHERE Fecha >= '" + DateManipulation::Instance().lowerBoundDate().toString("yyyy-MM-dd") +
                "' AND Fecha <= '" + DateManipulation::Instance().upperBoundDate().toString("yyyy-MM-dd") + "'" +
                "ORDER BY Fecha ASC";

        CabinaViewModel::Instance().setQuery(query);

        ClinicaCore::Instance().consoleOut("CabinaSQLQueries::updateQuery - Last error: " + CabinaViewModel::Instance().lastError().text());

        return;
    }
    else if (ClinicaCore::Instance().ubicacion().compare("La Capilla, 5 de Feb", Qt::CaseInsensitive) == 0)
    {
        nombreDeTabla.append("capilla_");
    }
    else if (ClinicaCore::Instance().ubicacion().compare("Colinas del Cimatario", Qt::CaseInsensitive) == 0)
    {
        nombreDeTabla.append("colinas_");
    }
    else if (ClinicaCore::Instance().ubicacion().compare("San Juan del Rio", Qt::CaseInsensitive) == 0)
    {
        nombreDeTabla.append("san_juan_");
    }
    else if (ClinicaCore::Instance().ubicacion().compare("Global", Qt::CaseInsensitive) == 0)
    {
        nombreDeTabla.append("admin");
        return;
    }
    nombreDeTabla.append("cabina_");
    nombreDeTabla.append(cabina);
    AgendarClienteViewData::Instance().setNombreDeTabla(nombreDeTabla);
    //setup general cabina query (sorted)
    QString query = "SELECT * FROM " + AgendarClienteViewData::Instance().getNombreDeTabla() +
            " WHERE Fecha >= '" + DateManipulation::Instance().lowerBoundDate().toString("yyyy-MM-dd") +
            "' AND Fecha <= '" + DateManipulation::Instance().upperBoundDate().toString("yyyy-MM-dd") + "'" +
            "ORDER BY Fecha ASC";
    CabinaViewModel::Instance().setQuery(query);

    ClinicaCore::Instance().consoleOut("CabinaSQLQueries::updateQuery - Last error: " + CabinaViewModel::Instance().lastError().text());
}
void CabinaSQLQueries::updateID()
{
    //ID
    QSqlQuery query;
    QString horaInicio;
    horaInicio = DateManipulation::Instance().getCurrentInitialTime();
    horaInicio.insert(2, QString(":"));
    QString updateString = "UPDATE ";
    updateString.append(AgendarClienteViewData::Instance().getNombreDeTabla());


    query.prepare(updateString +
                  " SET ID = :id "
                  "WHERE Fecha = :fecha "
                  "AND Hora_Inicio = :horaInicio;");
    query.bindValue(":id", QString::number(DateManipulation::Instance().getCurrentID()));
    query.bindValue(":fecha", DateManipulation::Instance().getCurrentDate());
    query.bindValue(":horaInicio", horaInicio);

    query.exec();

    ClinicaCore::Instance().consoleOut("CabinaSQLQueries::updateID - Last error: " + query.lastError().text());
}
void CabinaSQLQueries::updateRowInTable(QString nombre, QString apellidos,
                                       QString celular, QString tratamiento, QString servicio,
                                       QString zonas, QString precio, QString sesion,
                                       QString sesionesPagadas, QString totalPagado,
                                       QString estatusDeCita, QString observaciones,
                                       QString importeCobrado, int duracionIndex)
{
    //empty string handling
    if (nombre.compare("", Qt::CaseInsensitive) == 0)
    {
        nombre = " ";
    }
    if (apellidos.compare("", Qt::CaseInsensitive) == 0)
    {
        apellidos = " ";
    }
    if (celular.compare("", Qt::CaseInsensitive) == 0)
    {
        celular = " ";
    }
    if (tratamiento.compare("", Qt::CaseInsensitive) == 0)
    {
        tratamiento = " ";
    }
    if (servicio.compare("", Qt::CaseInsensitive) == 0)
    {
        servicio = " ";
    }
    if (zonas.compare("", Qt::CaseInsensitive) == 0)
    {
        zonas = " ";
    }
    if (precio.compare("", Qt::CaseInsensitive) == 0)
    {
        precio = " ";
    }
    if (sesion.compare("", Qt::CaseInsensitive) == 0)
    {
        sesion = " ";
    }
    if (sesionesPagadas.compare("", Qt::CaseInsensitive) == 0)
    {
        sesionesPagadas = " ";
    }
    if (totalPagado.compare("", Qt::CaseInsensitive) == 0)
    {
        totalPagado = " ";
    }
    if (estatusDeCita.compare("", Qt::CaseInsensitive) == 0)
    {
        estatusDeCita = " ";
    }
    if (observaciones.compare("", Qt::CaseInsensitive) == 0)
    {
        observaciones = " ";
    }
    if (importeCobrado.compare("", Qt::CaseInsensitive) == 0)
    {
        importeCobrado = " ";
    }

    //update query
    QSqlQuery query;
    QString updateString = "UPDATE ";
    updateString.append(AgendarClienteViewData::Instance().getNombreDeTabla() + " ");
    query.prepare(updateString +
                  "SET Nombre = :nombre, "
                  "    Apellidos = :apellidos, "
                  "    Celular = :celular, "
                  "    Tratamiento = :tratamiento, "
                  "    Servicio = :servicio, "
                  "    Zonas = :zonas, "
                  "    Precio = :precio, "
                  "    Sesion = :sesion, "
                  "    Sesiones_Pagadas = :sesionesPagadas, "
                  "    Total_Pagado = :totalPagado, "
                  "    Estatus_De_Cita = :estatusDeCita, "
                  "    Observaciones = :observaciones, "
                  "    Importe_Cobrado = :importeCobrado "
                  "WHERE ID = :id;");

    query.bindValue(":nombre", nombre);
    query.bindValue(":apellidos", apellidos);
    query.bindValue(":celular", celular);
    query.bindValue(":tratamiento", tratamiento);
    query.bindValue(":servicio", servicio);
    query.bindValue(":zonas", zonas);
    query.bindValue(":precio", precio);
    query.bindValue(":sesion", sesion);
    query.bindValue(":sesionesPagadas", sesionesPagadas);
    query.bindValue(":totalPagado", totalPagado);
    query.bindValue(":estatusDeCita", estatusDeCita);
    query.bindValue(":observaciones", observaciones);
    query.bindValue(":importeCobrado", importeCobrado);
    query.bindValue(":id", QString::number(DateManipulation::Instance().getCurrentID()));

    query.exec();

    ClinicaCore::Instance().consoleOut("CabinaSQLQueries::updateRowInTable - Last error: " + CabinaViewModel::Instance().lastError().text());
}
void CabinaSQLQueries::clearRowsDueToBusyRow()
{
    for (int i = 0; i < DateManipulation::Instance().getIDsQueued().size()-1; i++)
    {
        QString currentID = QString::number(DateManipulation::Instance().getIDsQueued().at(i));
        QString updateString = "UPDATE " + AgendarClienteViewData::Instance().getNombreDeTabla() + " ";
        QSqlQuery query;
        query.prepare(updateString +
                      "SET Nombre = :nombre, "
                      "     Apellidos = :apellidos, "
                      "     Celular = :celular, "
                      "     Tratamiento = :tratamiento, "
                      "     Servicio = :servicio, "
                      "     Zonas = :zonas, "
                      "     Precio = :precio, "
                      "     Sesion = :sesion, "
                      "     Sesiones_Pagadas = :sesionesPagadas, "
                      "     Total_Pagado = :totalPagado, "
                      "     Estatus_De_Cita = :estatusDeCita, "
                      "     Observaciones = :observaciones, "
                      "     Importe_Cobrado = :importeCobrado "
                      "WHERE ID = :id");

        query.bindValue(":nombre", "");
        query.bindValue(":apellidos", "");
        query.bindValue(":celular", 0);
        query.bindValue(":tratamiento", "");
        query.bindValue(":servicio", "");
        query.bindValue(":zonas", "");
        query.bindValue(":precio", 0);
        query.bindValue(":sesion", 0);
        query.bindValue(":sesionesPagadas", 0);
        query.bindValue(":totalPagado", 0);
        query.bindValue(":estatusDeCita", "");
        query.bindValue(":observaciones", "");
        query.bindValue(":importeCobrado", 0);
        query.bindValue(":id", currentID);

        query.exec();

        ClinicaCore::Instance().consoleOut("CabinaSQLQueries::clearRowsDueToBusyRow - Last error: " + query.lastError().text());
    }
}
void CabinaSQLQueries::deleteCita(QString fecha, QString celular, QString servicio)
{
    QString query;
    query.append("UPDATE " + AgendarClienteViewData::Instance().getNombreDeTabla() + " "
                 "SET Nombre = '',"
                 "    Apellidos = '',"
                 "    Celular = '0', "
                 "    Tratamiento = '', "
                 "    Servicio = '', "
                 "    Zonas = '', "
                 "    Precio = '0', "
                 "    Importe_Cobrado = '0', "
                 "    Sesion = '0', "
                 "    Sesiones_Pagadas = '0', "
                 "    Total_Pagado = '0', "
                 "    Estatus_de_Cita = '', "
                 "    Observaciones = '' "
                 "WHERE Fecha = '" + fecha + "'"
                 "AND   Celular = '" + celular + "'"
                 "AND   Servicio = '" + servicio + "'");
    CabinaViewModel::Instance().setQuery(query);

    ClinicaCore::Instance().consoleOut("CabinaSQLQueries::deleteCita - Last error: " + CabinaViewModel::Instance().lastError().text());
}
bool CabinaSQLQueries::rowIsEmpty() const
{
    QSqlQuery query;
    QString selectString = "SELECT Nombre FROM " + AgendarClienteViewData::Instance().getNombreDeTabla();
    query.prepare(selectString +
                  " WHERE ID = :id;");

    query.bindValue(":id", QString::number(DateManipulation::Instance().getCurrentID()));
    query.exec();

    while (query.next())
    {
        bool nombreEsNull = query.value(0).isNull();
        QString nombre = query.value(0).toString();
        nombre = nombre.simplified();
        nombre.replace( " ", "");
        if (nombreEsNull == true || nombre.compare("", Qt::CaseInsensitive) == 0)
            return true;
        else
            return false;
    }
    return true;
}
