#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "editarpacienteviewdata.h"
#include "clinicacore.h"

EditarPacienteViewData &EditarPacienteViewData::Instance()
{
    static EditarPacienteViewData instance; //Guaranteed to be destroyed
    return instance;
}
QString EditarPacienteViewData::nombre() const
{
    return m_nombre;
}
void EditarPacienteViewData::setNombre(QString nombre)
{
    if (nombre != m_nombre)
    {
        m_nombre = nombre;
        emit nombreChanged();
    }
}
QString EditarPacienteViewData::apellidos()
{
    return m_apellidos;
}
void EditarPacienteViewData::setApellidos(QString apellidos)
{
    if (apellidos != m_apellidos)
    {
        m_apellidos = apellidos;
        emit apellidosChanged();
    }
}
QString EditarPacienteViewData::celular() const
{
    return m_celular;
}
void EditarPacienteViewData::setCelular(QString celular)
{
    if (celular != m_celular)
    {
        m_celular = celular;
        emit celularChanged();
    }
}
QString EditarPacienteViewData::telefono() const
{
    return m_telefono;
}
void EditarPacienteViewData::setTelefono(QString telefono)
{
    if (telefono != m_telefono)
    {
        m_telefono = telefono;
        emit telefonoChanged();
    }
}
QString EditarPacienteViewData::correo() const
{
    return m_correo;
}
void EditarPacienteViewData::setCorreo(QString correo)
{
    if (correo != m_correo)
    {
        m_correo = correo;
        emit correoChanged();
    }
}
QString EditarPacienteViewData::fechaDeNacimiento() const
{
    return m_fechaDeNacimiento;
}
void EditarPacienteViewData::setFechaDeNacimiento(QString fechaDeNacimiento)
{
    if (fechaDeNacimiento != m_fechaDeNacimiento)
    {
        m_fechaDeNacimiento = fechaDeNacimiento;
        emit fechaDeNacimientoChanged();
        //process date, format: YYYY-MM-DD
        QString fecha = m_fechaDeNacimiento;
        if (ClinicaCore::Instance().developerMode() == true)
            qDebug () << "Fecha: " << fecha;
        splitFecha(fecha);
    }
}
int EditarPacienteViewData::diaFechaDeNacimientoIndex() const
{
    return m_diaFechaDeNacimientoIndex;
}

void EditarPacienteViewData::setDiaFechaDeNacimientoIndex(int fechaDeNacimientoIndex)
{
    if (fechaDeNacimientoIndex != m_diaFechaDeNacimientoIndex)
    {
        m_diaFechaDeNacimientoIndex = fechaDeNacimientoIndex;
        emit diaFechaDeNacimientoIndexChanged();
    }
}
int EditarPacienteViewData::mesFechaDeNacimientoIndex() const
{
    return m_mesFechaDeNacimientoIndex;
}
void EditarPacienteViewData::setMesFechaDeNacimientoIndex(int mesFechaDeNacimientoIndex)
{
    if (mesFechaDeNacimientoIndex != m_mesFechaDeNacimientoIndex)
    {
        m_mesFechaDeNacimientoIndex = mesFechaDeNacimientoIndex;
        emit mesFechaDeNacimientoIndexChanged();
    }
}
QString EditarPacienteViewData::anoFechaDeNacimiento() const
{
    return m_anoFechaDeNacimiento;
}
void EditarPacienteViewData::setAnoFechaDeNacimiento(QString anoFechaDeNacimiento)
{
    if (anoFechaDeNacimiento != m_anoFechaDeNacimiento)
    {
        m_anoFechaDeNacimiento = anoFechaDeNacimiento;
        emit anoFechaDeNacimientoChanged();
    }
}
QString EditarPacienteViewData::calleYNumero() const
{
    return m_calleYNumero;
}
void EditarPacienteViewData::setCalleYNumero(QString calleYNumero)
{
    if (calleYNumero != m_calleYNumero)
    {
        m_calleYNumero = calleYNumero;
        emit calleYNumeroChanged();
    }
}
QString EditarPacienteViewData::colonia() const
{
    return m_colonia;
}
void EditarPacienteViewData::setColonia(QString colonia)
{
    if (colonia != m_colonia)
    {
        m_colonia = colonia;
        emit coloniaChanged();
    }
}
QString EditarPacienteViewData::ciudad() const
{
    return m_ciudad;
}
void EditarPacienteViewData::setCiudad(QString ciudad)
{
    if (ciudad != m_ciudad)
    {
        m_ciudad = ciudad;
        emit ciudadChanged();
    }
}
QString EditarPacienteViewData::estado() const
{
    return m_estado;
}
void EditarPacienteViewData::setEstado(QString estado)
{
    if (estado != m_estado)
    {
        m_estado = estado;
        emit estadoChanged();
    }
}
QString EditarPacienteViewData::sesionesPagadas() const
{
    return m_sesionesPagadas;
}
void EditarPacienteViewData::setSesionesPagadas(QString sesionesPagadas)
{
    if (sesionesPagadas != m_sesionesPagadas)
    {
        m_sesionesPagadas = sesionesPagadas;
        emit sesionesPagadasChanged();
    }
}
QString EditarPacienteViewData::saldoAFavor() const
{
    return m_saldoAFavor;
}
void EditarPacienteViewData::setSaldoAFavor(QString saldoAFavor)
{
    if (saldoAFavor != m_saldoAFavor)
    {
        m_saldoAFavor = saldoAFavor;
        emit saldoAFavorChanged();
    }
}
QString EditarPacienteViewData::sesionesDeGarantia() const
{
    return m_sesionesDeGarantia;
}
void EditarPacienteViewData::setSesionesDeGarantia(QString sesionesDeGarantia)
{
    if (sesionesDeGarantia != m_sesionesDeGarantia)
    {
        m_sesionesDeGarantia = sesionesDeGarantia;
        emit sesionesDeGarantiaChanged();
    }
}
QString EditarPacienteViewData::currentCelular() const
{
    return m_currentCelular;
}
void EditarPacienteViewData::setCurrentCelular(QString currentCelular)
{
    if (currentCelular != m_currentCelular)
    {
        m_currentCelular = currentCelular;
        emit currentCelularChanged();
    }
}
void EditarPacienteViewData::splitFecha(QString fecha)
{
    //ano
    QString tmp = fecha.left(4);
    setAnoFechaDeNacimiento(tmp);
//    qDebug () << "1: " << tmp;
    fecha.remove(0, 5);
    //mes
    tmp = fecha.left(2);
    setMesFechaDeNacimientoIndex(tmp.toInt()-1);
//    qDebug () << "2: " << tmp.toInt();
    fecha.remove(0, 3);
    //dia
    tmp = fecha;
//    qDebug () << "3: " << tmp.toInt();
    setDiaFechaDeNacimientoIndex(tmp.toInt()-1);
}
