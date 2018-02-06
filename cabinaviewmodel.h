#ifndef CABINAVIEWMODEL_H
#define CABINAVIEWMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class CabinaViewModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged)
    Q_PROPERTY(QString apellidos READ apellidos WRITE setApellidos NOTIFY apellidosChanged)
    Q_PROPERTY(QString celular READ celular WRITE setCelular NOTIFY celularChanged)
    Q_PROPERTY(bool clienteEsNuevo READ clienteEsNuevo WRITE setClienteEsNuevo NOTIFY clienteEsNuevoChanged)
public:
    ~CabinaViewModel()=default;
    static CabinaViewModel &Instance();

    enum CabinaRoles {
        IDRole = Qt::UserRole + 1,
        NombreRole,
        ApellidosRole,
        CelularRole,
        TratamientoRole,
        ServicioRole,
        ZonasRole,
        SesionRole,
        PrecioRole,
        ImporteCobradoRole,
        FechaRole,
        HoraInicioRole,
        HoraTerminoRole,
        DuracionRole,
        SesionesPagadasRole,
        TotalPagadoRole,
        EstatusDeCitaRole,
        ObservacionesRole
    };

    //AbastractListModel
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const;

    //Others
    QString validateOutputString(QString &output, QString fieldName) const;
    Q_INVOKABLE void clearNombreApellidosCelular();
    QString getNombreDeTabla();
    Q_INVOKABLE void setID(int row);
    Q_INVOKABLE void initCitaDeletion(int row);
    Q_INVOKABLE QString getHoraInicioForID()const;
    void setHoraInicioForID(QString horaInicio);

    //SQL
    Q_INVOKABLE void filterQueryByCellphone(QString celular);
    Q_INVOKABLE void filterQueryByLastName(const QString apellidos);
    Q_INVOKABLE void updateQuery(const QString tabla);
    Q_INVOKABLE void updateID();
    Q_INVOKABLE void updateRowInTable(QString nombre, QString apellidos,
                                      QString celular, QString tratamiento, QString servicio,
                                      QString zonas, QString precio, QString sesion,
                                      QString sesionesPagadas, QString totalPagado,
                                      QString estatusDeCita, QString observaciones, QString importeCobrado,
                                      int duracionIndex);
    Q_INVOKABLE void clearRowsDueToBusyRow();
    Q_INVOKABLE bool isLastRowOfDay()const;
    Q_INVOKABLE void deleteCita(QString fecha, QString celular, QString servicio);

    //Q_Properties
    QString nombre()const;
    void setNombre(const QString nuevoNombre);
    QString apellidos()const;
    void setApellidos(const QString nuevosApellidos);
    QString celular()const;
    void setCelular(const QString nuevoCelular);
    bool clienteEsNuevo()const;
    void setClienteEsNuevo(bool trueOrFalse);

signals:
    void nombreChanged();
    void apellidosChanged();
    void celularChanged();
    void clienteEsNuevoChanged();

public slots:

protected:
     QHash<int, QByteArray> roleNames() const;

private:
    CabinaViewModel()=default;
    CabinaViewModel(CabinaViewModel const&)=delete;
    void operator = (CabinaViewModel const&)=delete;

    QString m_nombreDeTabla;
    bool m_clienteEsNuevo;
    QString m_nombre;
    QString m_apellidos;
    QString m_celular;
    QString m_horaInicioForID;

};

#endif // CABINAVIEWMODEL_H
