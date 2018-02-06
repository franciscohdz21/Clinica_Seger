#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "editarpacienteviewmodel.h"
#include "clientesviewmodel.h"

EditarPacienteViewModel &EditarPacienteViewModel::Instance()
{
    static EditarPacienteViewModel instance;
    return instance;
}

QString EditarPacienteViewModel::retrieveEntry(QString celular, QString column)
{
    QSqlQuery query("SELECT " + column + " FROM clientes WHERE celular LIKE " + celular);
    qDebug () << "Last error: " << query.lastError();
    while (query.next())
    {
        QString queryValue = query.value(0).toString();
        qDebug () << queryValue;
        return queryValue;
    }
    return "";
}
void EditarPacienteViewModel::retrieveAllEntries(QString celular)
{
    qDebug () << "CALLED";
    setNombre(retrieveEntry(celular, "Nombre"));
    setApellidos(retrieveEntry(celular, "Apellidos"));
    setCelular(retrieveEntry(celular, "Celular"));
    setTelefono(retrieveEntry(celular, "Telefono"));
    setCorreo(retrieveEntry(celular, "Correo"));
    setFechaDeNacimiento(retrieveEntry(celular, "Fecha_De_Nacimiento"));
    setCalleYNumero(retrieveEntry(celular, "Calle_Y_Numero"));
    setColonia(retrieveEntry(celular, "Colonia"));
    setCiudad(retrieveEntry(celular, "Ciudad"));
    setEstado(retrieveEntry(celular, "Estado"));
    setSesionesPagadas(retrieveEntry(celular, "Sesiones_Pagadas"));
    setSaldoAFavor(retrieveEntry(celular, "Saldo_A_Favor"));
    setSesionesDeGarantia(retrieveEntry(celular, "Sesiones_de_Garantia"));
}
void EditarPacienteViewModel::splitFecha(QString fecha)
{
    //ano
    QString tmp = fecha.left(4);
    setAnoFechaDeNacimiento(tmp);
    qDebug () << "1: " << tmp;
    fecha.remove(0, 5);
    //mes
    tmp = fecha.left(2);
    setMesFechaDeNacimientoIndex(tmp.toInt()-1);
    qDebug () << "2: " << tmp.toInt();
    fecha.remove(0, 3);
    //dia
    tmp = fecha;
    qDebug () << "3: " << tmp.toInt();
    setDiaFechaDeNacimientoIndex(tmp.toInt()-1);
}
QString EditarPacienteViewModel::nombre() const
{
    return m_nombre;
}
void EditarPacienteViewModel::setNombre(QString nombre)
{
    qDebug() << " setNombre called " << nombre;
    if (nombre != m_nombre)
    {
        m_nombre = nombre;
        emit nombreChanged();
    }
}
QString EditarPacienteViewModel::apellidos()
{
    return m_apellidos;
}
void EditarPacienteViewModel::setApellidos(QString apellidos)
{
    if (apellidos != m_apellidos)
    {
        m_apellidos = apellidos;
        emit apellidosChanged();
    }
}
QString EditarPacienteViewModel::celular() const
{
    return m_celular;
}
void EditarPacienteViewModel::setCelular(QString celular)
{
    if (celular != m_celular)
    {
        m_celular = celular;
        emit celularChanged();
    }
}
QString EditarPacienteViewModel::telefono() const
{
    return m_telefono;
}
void EditarPacienteViewModel::setTelefono(QString telefono)
{
    if (telefono != m_telefono)
    {
        m_telefono = telefono;
        emit telefonoChanged();
    }
}
QString EditarPacienteViewModel::correo() const
{
    return m_correo;
}
void EditarPacienteViewModel::setCorreo(QString correo)
{
    if (correo != m_correo)
    {
        m_correo = correo;
        emit correoChanged();
    }
}
QString EditarPacienteViewModel::fechaDeNacimiento() const
{
    return m_fechaDeNacimiento;
}
void EditarPacienteViewModel::setFechaDeNacimiento(QString fechaDeNacimiento)
{
    if (fechaDeNacimiento != m_fechaDeNacimiento)
    {
        m_fechaDeNacimiento = fechaDeNacimiento;
        emit fechaDeNacimientoChanged();
        //process date, format: YYYY-MM-DD
        QString fecha = m_fechaDeNacimiento;
        qDebug () << "Fecha: " << fecha;
        splitFecha(fecha);
    }
}
int EditarPacienteViewModel::diaFechaDeNacimientoIndex() const
{
    return m_diaFechaDeNacimientoIndex;
}

void EditarPacienteViewModel::setDiaFechaDeNacimientoIndex(int fechaDeNacimientoIndex)
{
    if (fechaDeNacimientoIndex != m_diaFechaDeNacimientoIndex)
    {
        m_diaFechaDeNacimientoIndex = fechaDeNacimientoIndex;
        emit diaFechaDeNacimientoIndexChanged();
    }
}
int EditarPacienteViewModel::mesFechaDeNacimientoIndex() const
{
    return m_mesFechaDeNacimientoIndex;
}
void EditarPacienteViewModel::setMesFechaDeNacimientoIndex(int mesFechaDeNacimientoIndex)
{
    if (mesFechaDeNacimientoIndex != m_mesFechaDeNacimientoIndex)
    {
        m_mesFechaDeNacimientoIndex = mesFechaDeNacimientoIndex;
        emit mesFechaDeNacimientoIndexChanged();
    }
}
QString EditarPacienteViewModel::anoFechaDeNacimiento() const
{
    return m_anoFechaDeNacimiento;
}
void EditarPacienteViewModel::setAnoFechaDeNacimiento(QString anoFechaDeNacimiento)
{
    if (anoFechaDeNacimiento != m_anoFechaDeNacimiento)
    {
        m_anoFechaDeNacimiento = anoFechaDeNacimiento;
        emit anoFechaDeNacimientoChanged();
    }
}
QString EditarPacienteViewModel::calleYNumero() const
{
    return m_calleYNumero;
}
void EditarPacienteViewModel::setCalleYNumero(QString calleYNumero)
{
    if (calleYNumero != m_calleYNumero)
    {
        m_calleYNumero = calleYNumero;
        emit calleYNumeroChanged();
    }
}
QString EditarPacienteViewModel::colonia() const
{
    return m_colonia;
}
void EditarPacienteViewModel::setColonia(QString colonia)
{
    if (colonia != m_colonia)
    {
        m_colonia = colonia;
        emit coloniaChanged();
    }
}
QString EditarPacienteViewModel::ciudad() const
{
    return m_ciudad;
}
void EditarPacienteViewModel::setCiudad(QString ciudad)
{
    if (ciudad != m_ciudad)
    {
        m_ciudad = ciudad;
        emit ciudadChanged();
    }
}
QString EditarPacienteViewModel::estado() const
{
    return m_estado;
}
void EditarPacienteViewModel::setEstado(QString estado)
{
    if (estado != m_estado)
    {
        m_estado = estado;
        emit estadoChanged();
    }
}
QString EditarPacienteViewModel::sesionesPagadas() const
{
    return m_sesionesPagadas;
}
void EditarPacienteViewModel::setSesionesPagadas(QString sesionesPagadas)
{
    if (sesionesPagadas != m_sesionesPagadas)
    {
        m_sesionesPagadas = sesionesPagadas;
        emit sesionesPagadasChanged();
    }
}
QString EditarPacienteViewModel::saldoAFavor() const
{
    return m_saldoAFavor;
}
void EditarPacienteViewModel::setSaldoAFavor(QString saldoAFavor)
{
    if (saldoAFavor != m_saldoAFavor)
    {
        m_saldoAFavor = saldoAFavor;
        emit saldoAFavorChanged();
    }
}
QString EditarPacienteViewModel::sesionesDeGarantia() const
{
    return m_sesionesDeGarantia;
}
void EditarPacienteViewModel::setSesionesDeGarantia(QString sesionesDeGarantia)
{
    if (sesionesDeGarantia != m_sesionesDeGarantia)
    {
        m_sesionesDeGarantia = sesionesDeGarantia;
        emit sesionesDeGarantiaChanged();
    }
}
QString EditarPacienteViewModel::currentCelular() const
{
    return m_currentCelular;
}
void EditarPacienteViewModel::setCurrentCelular(QString currentCelular)
{
    if (currentCelular != m_currentCelular)
    {
        m_currentCelular = currentCelular;
        emit currentCelularChanged();
    }
}

