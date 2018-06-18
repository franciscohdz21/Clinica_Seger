#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <thread>
#include <iostream>
#include "clinicacore.h"

ClinicaCore &ClinicaCore::Instance()
{
    static ClinicaCore instance; //Guaranteed to be destroyed
    return instance;
}
QString ClinicaCore::usuario() const
{
    return m_usuario;
}
void ClinicaCore::setUsuario(const QString usuario)
{
    if (usuario != m_usuario)
    {
        m_usuario = usuario;
        emit usuarioChanged();
    }
}
int ClinicaCore::permiso() const
{
    return m_permiso;
}
void ClinicaCore::setPermiso(const int permiso)
{
    if (permiso != m_permiso)
    {
        m_permiso = permiso;
        emit permisoChanged();
    }
}
QString ClinicaCore::ubicacion() const
{
    return m_ubicacion;
}
void ClinicaCore::setUbicacion(const QString ubicacion)
{
    if (ubicacion != m_ubicacion)
    {
        m_ubicacion = ubicacion;
        emit ubicacionChanged();
    }
}
QStringList ClinicaCore::cabinas() const
{
    return m_cabinas;
}
void ClinicaCore::setCabinas(const QStringList cabinas)
{
    if (cabinas != m_cabinas)
    {
        m_cabinas = cabinas;
        emit cabinasChanged();
    }
}
QStringList ClinicaCore::tratamientos() const
{
    return m_tratamientos;
}
void ClinicaCore::setTratamientos(QStringList tratamientos)
{
    tratamientos.clear();
    QString query;
    query.append("SELECT Tratamiento FROM terapia");
    QSqlQuery sqlQuery(query);
    while (sqlQuery.next())
    {
        tratamientos.push_back(sqlQuery.value(0).toString());

        ClinicaCore::Instance().consoleOut("ClinicaCore::setTratamientos - Tratamientos: " + sqlQuery.value(0).toString());
    }

    if (tratamientos != m_tratamientos)
    {
        m_tratamientos = tratamientos;
        emit tratamientosChanged();
    }
}
QStringList ClinicaCore::currentServicios() const
{
    return m_currentServicios;
}
void ClinicaCore::setCurrentServicios(QStringList currentServicios)
{
    if (currentServicios != m_currentServicios)
    {
        m_currentServicios = currentServicios;
        emit currentServiciosChanged();
    }
}
bool ClinicaCore::connectedToServer() const
{
    return m_connectedToServer;
}
void ClinicaCore::setConnectedToServer(bool trueOrFalse)
{
    if (trueOrFalse != m_connectedToServer)
    {
        m_connectedToServer = trueOrFalse;
        emit connectedToServerChanged();
    }
}
QString ClinicaCore::currentCabina() const
{
    return m_currentCabina;
}
void ClinicaCore::setCurrentCabina(QString cabina)
{
    if (cabina != m_currentCabina)
    {
        m_currentCabina = cabina;
        emit currentCabinaChanged();
    }
}
void ClinicaCore::buildCabinas(const QString cabinas)
{
    QStringList tmp;
    if (cabinas.compare("0", Qt::CaseInsensitive) == 0)
    {
        tmp.push_back("Cabina N/A");
        return;
    }
    else
    {
        if (cabinas.compare("2EM", Qt::CaseInsensitive) == 0)
        {
            tmp.push_back("E-Light");
            tmp.push_back("MultiShape");
        }
        setCabinas(tmp);
    }
}
QVector<QVector<QString> > ClinicaCore::getServicios() const
{
    return m_servicios;
}
void ClinicaCore::setServicios()
{
    //servicios
    QVector<QString> serviciosPorTratamiento;
    for (int i = 0; i < m_tratamientos.size(); i++)
    {
        QString query;
        serviciosPorTratamiento.clear();
        query.clear();
        query.append("SELECT Servicio FROM ");
        query.append(m_tratamientos.at(i));
        QSqlQuery sqlQuery(query);
        while (sqlQuery.next())
        {
            ClinicaCore::Instance().consoleOut("ClinicaCore::setServicios - " + sqlQuery.value(0).toString());

            serviciosPorTratamiento.push_back(sqlQuery.value(0).toString());
        }
        m_servicios.push_back(serviciosPorTratamiento);
    }
}
void ClinicaCore::buildCurrentServicios(int tratamientoIndex)
{
    if (tratamientoIndex == -1 || m_servicios.isEmpty())
        return;
    QStringList currentServicios;
    for (int i = 0; i < m_servicios.at(tratamientoIndex).size(); ++i)
    {
        currentServicios.push_back(m_servicios.at(tratamientoIndex).at(i));

        ClinicaCore::Instance().consoleOut("ClinicaCore::buildCurrentServicios - " + m_servicios.at(tratamientoIndex).at(i));
    }
    setCurrentServicios(currentServicios);
}
bool ClinicaCore::getCancelarCita() const
{
    return m_cancelarCita;
}
void ClinicaCore::setCancelarCita(bool cancelarCita)
{
    m_cancelarCita = cancelarCita;
}
bool ClinicaCore::developerMode() const
{
    return m_developerMode;
}
void ClinicaCore::setDeveloperMode(bool trueOrFalse)
{
    if (trueOrFalse != m_developerMode)
    {
        m_developerMode = trueOrFalse;
        emit developerModeChanged();
    }
}
void ClinicaCore::init(bool devMode)
{
    setDeveloperMode(devMode);
}
void ClinicaCore::consoleOut(QString message)
{
    if (m_developerMode == false)
        return;
    else
    {
        qDebug () << message;
    }
}
void ClinicaCore::consoleOut(QString message, QStringList message2)
{
    if (m_developerMode == false)
        return;
    else
    {
        qDebug () << message << message2;
    }
}
ClinicaCore::ClinicaCore()
{
    init(false);
}
