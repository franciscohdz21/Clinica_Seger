#ifndef EDITARPACIENTEVIEWDATA_H
#define EDITARPACIENTEVIEWDATA_H

#include <QObject>
#include <QVector>

class EditarPacienteViewData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged)
    Q_PROPERTY(QString apellidos READ apellidos WRITE setApellidos NOTIFY apellidosChanged)
    Q_PROPERTY(QString celular READ celular WRITE setCelular NOTIFY celularChanged)
    Q_PROPERTY(QString telefono READ telefono WRITE setTelefono NOTIFY telefonoChanged)
    Q_PROPERTY(QString correo READ correo WRITE setCorreo NOTIFY correoChanged)
    Q_PROPERTY(QString fechaDeNacimiento READ fechaDeNacimiento WRITE setFechaDeNacimiento NOTIFY fechaDeNacimientoChanged)
    Q_PROPERTY(int diaFechaDeNacimientoIndex READ diaFechaDeNacimientoIndex WRITE setDiaFechaDeNacimientoIndex NOTIFY diaFechaDeNacimientoIndexChanged)
    Q_PROPERTY(int mesFechaDeNacimientoIndex READ mesFechaDeNacimientoIndex WRITE setMesFechaDeNacimientoIndex NOTIFY mesFechaDeNacimientoIndexChanged)
    Q_PROPERTY(QString anoFechaDeNacimiento READ anoFechaDeNacimiento WRITE setAnoFechaDeNacimiento NOTIFY anoFechaDeNacimientoChanged)
    Q_PROPERTY(QString calleYNumero READ calleYNumero WRITE setCalleYNumero NOTIFY calleYNumeroChanged)
    Q_PROPERTY(QString colonia READ colonia WRITE setColonia NOTIFY coloniaChanged)
    Q_PROPERTY(QString ciudad READ ciudad WRITE setCiudad NOTIFY ciudadChanged)
    Q_PROPERTY(QString estado READ estado WRITE setEstado NOTIFY estadoChanged)
    Q_PROPERTY(QString sesionesPagadas READ sesionesPagadas WRITE setSesionesPagadas NOTIFY sesionesPagadasChanged)
    Q_PROPERTY(QString saldoAFavor READ saldoAFavor WRITE setSaldoAFavor NOTIFY saldoAFavorChanged)
    Q_PROPERTY(QString sesionesDeGarantia READ sesionesDeGarantia WRITE setSesionesDeGarantia NOTIFY sesionesDeGarantiaChanged)
    Q_PROPERTY(QString currentCelular READ currentCelular WRITE setCurrentCelular NOTIFY currentCelularChanged)
public:
    ~EditarPacienteViewData()=default;
    static EditarPacienteViewData &Instance();

    //Q_PROPERTIES
    QString nombre()const;
    void setNombre(QString nombre);
    QString apellidos();
    void setApellidos(QString apellidos);
    QString celular()const;
    void setCelular(QString celular);
    QString telefono()const;
    void setTelefono(QString telefono);
    QString correo()const;
    void setCorreo(QString correo);
    QString fechaDeNacimiento()const;
    void setFechaDeNacimiento(QString fechaDeNacimiento);
    int diaFechaDeNacimientoIndex()const;
    void setDiaFechaDeNacimientoIndex(int fechaDeNacimientoIndex);
    int mesFechaDeNacimientoIndex()const;
    void setMesFechaDeNacimientoIndex(int mesFechaDeNacimientoIndex);
    QString anoFechaDeNacimiento()const;
    void setAnoFechaDeNacimiento(QString anoFechaDeNacimiento);
    QString calleYNumero()const;
    void setCalleYNumero(QString calleYNumero);
    QString colonia()const;
    void setColonia(QString colonia);
    QString ciudad()const;
    void setCiudad(QString ciudad);
    QString estado()const;
    void setEstado(QString estado);
    QString sesionesPagadas()const;
    void setSesionesPagadas(QString sesionesPagadas);
    QString saldoAFavor()const;
    void setSaldoAFavor(QString saldoAFavor);
    QString sesionesDeGarantia()const;
    void setSesionesDeGarantia(QString sesionesDeGarantia);
    QString currentCelular()const;
    void setCurrentCelular(QString currentCelular);

    //OTHER
    void splitFecha(QString fecha);

signals:
    void nombreChanged();
    void apellidosChanged();
    void celularChanged();
    void telefonoChanged();
    void correoChanged();
    void fechaDeNacimientoChanged();
    void diaFechaDeNacimientoIndexChanged();
    void mesFechaDeNacimientoIndexChanged();
    void anoFechaDeNacimientoChanged();
    void calleYNumeroChanged();
    void coloniaChanged();
    void ciudadChanged();
    void estadoChanged();
    void sesionesPagadasChanged();
    void saldoAFavorChanged();
    void sesionesDeGarantiaChanged();
    void currentCelularChanged();

private:
    EditarPacienteViewData()=default;
    EditarPacienteViewData(EditarPacienteViewData const&)=delete;
    void operator = (EditarPacienteViewData const&)=delete;

    QString m_nombre;
    QString m_apellidos;
    QString m_celular;
    QString m_telefono;
    QString m_correo;
    QString m_fechaDeNacimiento;
    int m_diaFechaDeNacimientoIndex;
    int m_mesFechaDeNacimientoIndex;
    QString m_anoFechaDeNacimiento;
    QString m_calleYNumero;
    QString m_colonia;
    QString m_ciudad;
    QString m_estado;
    QString m_sesionesPagadas;
    QString m_saldoAFavor;
    QString m_sesionesDeGarantia;
    QString m_currentCelular;
};

#endif // EDITARPACIENTEVIEWDATA_H
