#ifndef CABINAVIEWMODEL_H
#define CABINAVIEWMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class CabinaViewModel : public QSqlQueryModel
{
    Q_OBJECT
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

    //Other
    QString validateOutputString(QString &output, QString fieldName) const;

protected:
     QHash<int, QByteArray> roleNames() const;

private:
    CabinaViewModel()=default;
    CabinaViewModel(CabinaViewModel const&)=delete;
    void operator = (CabinaViewModel const&)=delete;
};

#endif // CABINAVIEWMODEL_H
