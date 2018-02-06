#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "conexionabasededatos.h"
#include "calendarfunctions.h"

ConexionABaseDeDatos &ConexionABaseDeDatos::Instance()
{
    static ConexionABaseDeDatos instance; //Guaranteed to be destroyed
    return instance;
}
bool ConexionABaseDeDatos::establecerConexion(const QString IP, const int puerto, const QString contrasena)
{
    QSqlDatabase sqlDatabse;
    sqlDatabse = QSqlDatabase::addDatabase("QMYSQL");
    sqlDatabse.setHostName(IP);
    sqlDatabse.setDatabaseName("Clinica");
    sqlDatabse.setPort(puerto);
    sqlDatabse.setUserName("root");
    sqlDatabse.setPassword(contrasena);
    setConnectedToServer(sqlDatabse.open());
    return m_connectedToServer;
}
int ConexionABaseDeDatos::loginAPrograma(const QString usuario, const QString contrasena)
{
    QString query;
    query.append("SELECT Permiso FROM personal WHERE Usuario = '" + usuario + "'");
    query.append(" AND Contrasena = '"+ contrasena + "'");
    QSqlQuery sqlQuery(query);
    setPermiso(-1);
    while (sqlQuery.next()) {
        setPermiso(sqlQuery.value(0).toInt());
    }
    qDebug () << "Valor: " << m_permiso;
    if (m_permiso == -1)
        return -1;
    else
    {
        //init calendar/date
        CalendarFunctions::Instance().init();
        setUsuario(usuario);
        //query ubicacion
        query.clear();
        query.append("SELECT Ubicacion FROM personal WHERE Usuario = '" + usuario + "'");
        query.append(" AND Contrasena = '"+ contrasena + "'");
        QSqlQuery sqlQuery(query);
        setUbicacion("");
        while (sqlQuery.next())
        {
            setUbicacion(sqlQuery.value(0).toString());
        }
        qDebug () << "Ubicacion: " << m_ubicacion;

        //query cabinas
        query.clear();
        query.append("SELECT Cabinas FROM personal WHERE Usuario = '" + usuario + "'");
        query.append(" AND Contrasena = '"+ contrasena + "'");
        QSqlQuery sqlQuery2(query);
        m_cabinas.clear();
        while (sqlQuery2.next())
        {
            buildCabinas(sqlQuery2.value(0).toString());
        }
        qDebug () << "Cabinas: " << m_cabinas;

        //set tratamientos and servicios
        QStringList tmp;
        setTratamientos(tmp);
        setServicios();
        return m_permiso;
    }
}
QString ConexionABaseDeDatos::usuario() const
{
    return m_usuario;
}
void ConexionABaseDeDatos::setUsuario(const QString usuario)
{
    if (usuario != m_usuario)
    {
        m_usuario = usuario;
        emit usuarioChanged();
    }
}
int ConexionABaseDeDatos::permiso() const
{
    return m_permiso;
}
void ConexionABaseDeDatos::setPermiso(const int permiso)
{
    if (permiso != m_permiso)
    {
        m_permiso = permiso;
        emit permisoChanged();
    }
}
QString ConexionABaseDeDatos::ubicacion() const
{
    return m_ubicacion;
}
void ConexionABaseDeDatos::setUbicacion(const QString ubicacion)
{
    if (ubicacion != m_ubicacion)
    {
        m_ubicacion = ubicacion;
        emit ubicacionChanged();
    }
}
QStringList ConexionABaseDeDatos::cabinas() const
{
    return m_cabinas;
}
void ConexionABaseDeDatos::setCabinas(const QStringList cabinas)
{
    if (cabinas != m_cabinas)
    {
        m_cabinas = cabinas;
        emit cabinasChanged();
    }
}
void ConexionABaseDeDatos::buildCabinas(const QString cabinas)
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
QStringList ConexionABaseDeDatos::tratamientos() const
{
    return m_tratamientos;
}
void ConexionABaseDeDatos::setTratamientos(QStringList tratamientos)
{
    tratamientos.clear();
    QString query;
    query.append("SELECT Tratamiento FROM terapia");
    QSqlQuery sqlQuery(query);
    while (sqlQuery.next())
    {
        tratamientos.push_back(sqlQuery.value(0).toString());
        //qDebug () << "Tratamientos: " << sqlQuery.value(0).toString();
    }

    if (tratamientos != m_tratamientos)
    {
        m_tratamientos = tratamientos;
        emit tratamientosChanged();
    }
}
QVector<QVector<QString> > ConexionABaseDeDatos::getServicios() const
{
    return m_servicios;
}
void ConexionABaseDeDatos::setServicios()
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
            //qDebug () << sqlQuery.value(0).toString();
            serviciosPorTratamiento.push_back(sqlQuery.value(0).toString());
        }
        m_servicios.push_back(serviciosPorTratamiento);
    }
}
QStringList ConexionABaseDeDatos::currentServicios() const
{
    return m_currentServicios;
}
void ConexionABaseDeDatos::setCurrentServicios(QStringList currentServicios)
{
    if (currentServicios != m_currentServicios)
    {
        m_currentServicios = currentServicios;
        emit currentServiciosChanged();
    }
}
bool ConexionABaseDeDatos::connectedToServer() const
{
    return m_connectedToServer;
}
void ConexionABaseDeDatos::setConnectedToServer(bool trueOrFalse)
{
    if (trueOrFalse != m_connectedToServer)
    {
        m_connectedToServer = trueOrFalse;
        emit connectedToServerChanged();
    }
}
void ConexionABaseDeDatos::buildCurrentServicios(int tratamientoIndex)
{
    if (tratamientoIndex == -1 || m_servicios.isEmpty())
        return;
    QStringList currentServicios;
    for (int i = 0; i < m_servicios.at(tratamientoIndex).size(); ++i)
    {
        currentServicios.push_back(m_servicios.at(tratamientoIndex).at(i));
        //qDebug () << m_servicios.at(tratamientoIndex).at(i);
    }
    setCurrentServicios(currentServicios);
}
void ConexionABaseDeDatos::refreshAll()
{
    emit usuarioChanged();
    emit permisoChanged();
    emit ubicacionChanged();
    emit cabinasChanged();
    emit tratamientosChanged();
    emit currentServiciosChanged();
}
