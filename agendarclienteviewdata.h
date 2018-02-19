#ifndef AGENDARCLIENTEVIEWDATA_H
#define AGENDARCLIENTEVIEWDATA_H

#include <QObject>

class AgendarClienteViewData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged)
    Q_PROPERTY(QString apellidos READ apellidos WRITE setApellidos NOTIFY apellidosChanged)
    Q_PROPERTY(QString celular READ celular WRITE setCelular NOTIFY celularChanged)
    Q_PROPERTY(bool clienteEsNuevo READ clienteEsNuevo WRITE setClienteEsNuevo NOTIFY clienteEsNuevoChanged)
    Q_PROPERTY(int tratamientoCurrentIndex READ tratamientoCurrentIndex WRITE setTratamientoCurrentIndex NOTIFY tratamientoCurrentIndexChanged)

public:
    ~AgendarClienteViewData()=default;
    static AgendarClienteViewData &Instance();

    //Q_Properties
    QString nombre()const;
    void setNombre(const QString nuevoNombre);
    QString apellidos()const;
    void setApellidos(const QString nuevosApellidos);
    QString celular()const;
    void setCelular(const QString nuevoCelular);
    bool clienteEsNuevo()const;
    void setClienteEsNuevo(bool trueOrFalse);
    int tratamientoCurrentIndex()const;
    void setTratamientoCurrentIndex(int index);


    //Other
    Q_INVOKABLE void clearNombreApellidosCelular();
    QString getNombreDeTabla();
    void setNombreDeTabla(QString nombreDeTabla);
    Q_INVOKABLE QString getHoraInicioForID()const;
    void setHoraInicioForID(QString horaInicio);
    Q_INVOKABLE void setID(int row);
    Q_INVOKABLE bool isLastRowOfDay()const;

signals:
    void nombreChanged();
    void apellidosChanged();
    void celularChanged();
    void clienteEsNuevoChanged();
    void tratamientoCurrentIndexChanged();

private:
    AgendarClienteViewData()=default;
    AgendarClienteViewData(AgendarClienteViewData const&)=delete;
    void operator = (AgendarClienteViewData const&)=delete;

    QString m_nombre;
    QString m_apellidos;
    QString m_celular;
    bool m_clienteEsNuevo;
    int m_tratamientoCurrentIndex;
    QString m_nombreDeTabla;
    QString m_horaInicioForID;

};

#endif // AGENDARCLIENTEVIEWDATA_H
