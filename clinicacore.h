#ifndef CLINICACORE_H
#define CLINICACORE_H

#include <QObject>
#include <QVector>

class ClinicaCore : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString usuario READ usuario WRITE setUsuario NOTIFY usuarioChanged)//core
    Q_PROPERTY(int permiso READ permiso WRITE setPermiso NOTIFY permisoChanged)//core
    Q_PROPERTY(QString ubicacion READ ubicacion WRITE setUbicacion NOTIFY ubicacionChanged)//core
    Q_PROPERTY(QStringList cabinas READ cabinas WRITE setCabinas NOTIFY cabinasChanged)//core
    Q_PROPERTY(QStringList tratamientos READ tratamientos WRITE setTratamientos NOTIFY tratamientosChanged)//core
    Q_PROPERTY(QStringList currentServicios READ currentServicios WRITE setCurrentServicios NOTIFY currentServiciosChanged)//core
    Q_PROPERTY(bool connectedToServer READ connectedToServer WRITE setConnectedToServer NOTIFY connectedToServerChanged)//core
    Q_PROPERTY(QString currentCabina READ currentCabina WRITE setCurrentCabina NOTIFY currentCabinaChanged)//core

public:
    ~ClinicaCore()=default;
    static ClinicaCore &Instance();

    //Q_PROPERTIES
    QString usuario()const;
    void setUsuario(const QString usuario);
    int permiso()const;
    void setPermiso(const int permiso);
    QString ubicacion()const;
    void setUbicacion(const QString ubicacion);
    QStringList cabinas()const;
    void setCabinas(const QStringList cabinas);
    QStringList tratamientos()const;
    void setTratamientos(QStringList tratamientos);
    QStringList currentServicios()const;
    void setCurrentServicios(QStringList currentServicio);
    bool connectedToServer()const;
    void setConnectedToServer(bool trueOrFalse);
    QString currentCabina()const;
    void setCurrentCabina(QString cabina);

    //Other
    void buildCabinas(const QString cabinas);
    QVector <QVector <QString>> getServicios()const;
    void setServicios();
    Q_INVOKABLE void buildCurrentServicios(int tratamientoIndex);
    Q_INVOKABLE bool getCancelarCita()const;
    Q_INVOKABLE void setCancelarCita(bool cancelarCita);
    Q_INVOKABLE bool developerMode()const;
    void setDeveloperMode(bool trueOrFalse);
    Q_INVOKABLE void init(bool devMode);

signals:
    void usuarioChanged();
    void permisoChanged();
    void ubicacionChanged();
    void cabinasChanged();
    void tratamientosChanged();
    void currentServiciosChanged();
    void connectedToServerChanged();
    void currentCabinaChanged();

private:
    ClinicaCore()=default;
    ClinicaCore(ClinicaCore const&)=delete;
    void operator = (ClinicaCore const&)=delete;

    QString m_usuario;
    int m_permiso;
    QString m_ubicacion;
    QStringList m_cabinas;
    QStringList m_tratamientos;
    QVector <QVector <QString> > m_servicios;
    QStringList m_currentServicios;
    bool m_connectedToServer;
    QString m_currentCabina;
    bool m_cancelarCita;
    bool m_developerMode;
};

#endif // CLINICACORE_H
