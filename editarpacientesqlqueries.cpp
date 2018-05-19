#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "editarpacientesqlqueries.h"
#include "editarpacienteviewdata.h"
#include "clinicacore.h"

EditarPacienteSQLQueries &EditarPacienteSQLQueries::Instance()
{
    static EditarPacienteSQLQueries instance; //Guaranteed to be destroyed
    return instance;
}
QString EditarPacienteSQLQueries::retrieveEntry(QString celular, QString column)
{
    QSqlQuery query("SELECT " + column + " FROM clientes WHERE celular LIKE " + celular);

    ClinicaCore::Instance().consoleOut("EditarPacienteSQLQueries::retrieveEntry - Last error: " + query.lastError().text());

    while (query.next())
    {
        QString queryValue = query.value(0).toString();
        return queryValue;
    }
    return "";
}
void EditarPacienteSQLQueries::retrieveAllEntries(QString celular)
{
    EditarPacienteViewData::Instance().setNombre(retrieveEntry(celular, "Nombre"));
    EditarPacienteViewData::Instance().setApellidos(retrieveEntry(celular, "Apellidos"));
    EditarPacienteViewData::Instance().setCelular(retrieveEntry(celular, "Celular"));
    EditarPacienteViewData::Instance().setTelefono(retrieveEntry(celular, "Telefono"));
    EditarPacienteViewData::Instance().setCorreo(retrieveEntry(celular, "Correo"));
    EditarPacienteViewData::Instance().setFechaDeNacimiento(retrieveEntry(celular, "Fecha_De_Nacimiento"));
    EditarPacienteViewData::Instance().setCalleYNumero(retrieveEntry(celular, "Calle_Y_Numero"));
    EditarPacienteViewData::Instance().setColonia(retrieveEntry(celular, "Colonia"));
    EditarPacienteViewData::Instance().setCiudad(retrieveEntry(celular, "Ciudad"));
    EditarPacienteViewData::Instance().setEstado(retrieveEntry(celular, "Estado"));
    EditarPacienteViewData::Instance().setSesionesPagadas(retrieveEntry(celular, "Sesiones_Pagadas"));
    EditarPacienteViewData::Instance().setSaldoAFavor(retrieveEntry(celular, "Saldo_A_Favor"));
    EditarPacienteViewData::Instance().setSesionesDeGarantia(retrieveEntry(celular, "Sesiones_de_Garantia"));
}
