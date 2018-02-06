#ifndef CONEXIONABASEDEDATOS_H
#define CONEXIONABASEDEDATOS_H

#include <QObject>
#include <QVector>

class ConexionABaseDeDatos: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString usuario READ usuario WRITE setUsuario NOTIFY usuarioChanged)
    Q_PROPERTY(int permiso READ permiso WRITE setPermiso NOTIFY permisoChanged)
    Q_PROPERTY(QString ubicacion READ ubicacion WRITE setUbicacion NOTIFY ubicacionChanged)
    Q_PROPERTY(QStringList cabinas READ cabinas WRITE setCabinas NOTIFY cabinasChanged)
    Q_PROPERTY(QStringList tratamientos READ tratamientos WRITE setTratamientos NOTIFY tratamientosChanged)
    Q_PROPERTY(QStringList currentServicios READ currentServicios WRITE setCurrentServicios NOTIFY currentServiciosChanged)
    Q_PROPERTY(bool connectedToServer READ connectedToServer WRITE setConnectedToServer NOTIFY connectedToServerChanged)

public:
    ~ConexionABaseDeDatos()=default;
    static ConexionABaseDeDatos &Instance();
    Q_INVOKABLE bool establecerConexion(const QString IP, const int puerto, const QString contrasena);
    Q_INVOKABLE int loginAPrograma(const QString usuario, const QString contrasena);
    QString usuario()const;
    void setUsuario(const QString usuario);
    int permiso()const;
    void setPermiso(const int permiso);
    QString ubicacion()const;
    void setUbicacion(const QString ubicacion);
    QStringList cabinas()const;
    void setCabinas(const QStringList cabinas);
    void buildCabinas(const QString cabinas);
    QStringList tratamientos()const;
    void setTratamientos(QStringList tratamientos);
    QVector <QVector <QString>> getServicios()const;
    void setServicios();
    QStringList currentServicios()const;
    void setCurrentServicios(QStringList currentServicio);
    bool connectedToServer()const;
    void setConnectedToServer(bool trueOrFalse);

    Q_INVOKABLE void buildCurrentServicios(int tratamientoIndex);
    Q_INVOKABLE void refreshAll();

signals:
    void usuarioChanged();
    void permisoChanged();
    void ubicacionChanged();
    void cabinasChanged();
    void tratamientosChanged();
    void currentServiciosChanged();
    void connectedToServerChanged();

private:
    ConexionABaseDeDatos()=default;
    ConexionABaseDeDatos(ConexionABaseDeDatos const&)=delete;
    void operator = (ConexionABaseDeDatos const&)=delete;

    QString m_usuario;
    int m_permiso;
    QString m_ubicacion;
    QStringList m_cabinas;
    QStringList m_tratamientos;
    QVector <QVector <QString> > m_servicios;
    QStringList m_currentServicios;
    bool m_connectedToServer;

};

#endif // CONEXIONABASEDEDATOS_H
