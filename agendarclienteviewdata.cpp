#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QDate>
#include <QSqlQueryModel>
#include "cabinaviewmodel.h"
#include "agendarclienteviewdata.h"
#include "datemanipulation.h"
#include "clinicacore.h"

AgendarClienteViewData &AgendarClienteViewData::Instance()
{
    static AgendarClienteViewData instance; //Guaranteed to be destroyed
    return instance;
}
QString AgendarClienteViewData::nombre() const
{
    return m_nombre;
}
void AgendarClienteViewData::setNombre(const QString nuevoNombre)
{
    if (nuevoNombre != m_nombre)
    {
        m_nombre = nuevoNombre;
        emit nombreChanged();
    }
}
QString AgendarClienteViewData::apellidos() const
{
    return m_apellidos;
}
void AgendarClienteViewData::setApellidos(const QString nuevosApellidos)
{
    if (nuevosApellidos != m_apellidos)
    {
        m_apellidos = nuevosApellidos;
        emit apellidosChanged();
    }
}
QString AgendarClienteViewData::celular() const
{
    return m_celular;
}
void AgendarClienteViewData::setCelular(const QString nuevoCelular)
{
    if (nuevoCelular != m_celular)
    {
        m_celular = nuevoCelular;
        emit celularChanged();
    }
}
bool AgendarClienteViewData::clienteEsNuevo() const
{
    return m_clienteEsNuevo;
}

void AgendarClienteViewData::setClienteEsNuevo(bool trueOrFalse)
{
    if (trueOrFalse != m_clienteEsNuevo)
    {
        m_clienteEsNuevo = trueOrFalse;
        emit clienteEsNuevoChanged();
    }
}
void AgendarClienteViewData::clearNombreApellidosCelular()
{
    setNombre("");
    setApellidos("");
    setCelular("");
}
QString AgendarClienteViewData::getNombreDeTabla()
{
    return m_nombreDeTabla;
}
void AgendarClienteViewData::setNombreDeTabla(QString nombreDeTabla)
{
    m_nombreDeTabla = nombreDeTabla;
}
QString AgendarClienteViewData::getHoraInicioForID() const
{
    return m_horaInicioForID;
}
void AgendarClienteViewData::setHoraInicioForID(QString horaInicio)
{
    m_horaInicioForID = horaInicio;
}
void AgendarClienteViewData::setID(int row)
{
    //no selection
    if (row == -1)
        return;

    //get row values
    if (!CabinaViewModel::Instance().query().seek(row))
        return;

    if ( (!CabinaViewModel::Instance().record().isGenerated("Fecha")) || (!CabinaViewModel::Instance().record().isGenerated("Hora_Inicio")) ||
         (!CabinaViewModel::Instance().record().isGenerated("Hora_Termino")) )
    {
        if (ClinicaCore::Instance().developerMode() == true)
            qDebug() << "AgendarClienteViewData::setID - Error setting fecha, hora inicio o hora termino";
    }
    else
    {
        QString tmpHoraInicio = CabinaViewModel::Instance().query().value("Hora_Inicio").toString();
        tmpHoraInicio.chop(3);
        tmpHoraInicio.remove(2, 1);
        setHoraInicioForID(tmpHoraInicio);
        if (ClinicaCore::Instance().developerMode() == true)
            qDebug() << "AgendarClienteViewData::setID - Hora for ID: " << m_horaInicioForID;

        //Fecha
        if (ClinicaCore::Instance().developerMode() == true)
            qDebug() << "AgendarClienteViewData::setID - Fecha: " << CabinaViewModel::Instance().query().value("Fecha").toString();
        QDate date;
        DateManipulation::Instance().generateID(date.fromString(CabinaViewModel::Instance().query().value("Fecha").toString(), "yyyy-MM-dd"),
                                                 m_horaInicioForID);
    }
}
bool AgendarClienteViewData::isLastRowOfDay() const
{
    QString ID = QString::number(DateManipulation::Instance().getCurrentID());
    ID.remove(0, 8);
    if (ID.compare("1930", Qt::CaseInsensitive) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
