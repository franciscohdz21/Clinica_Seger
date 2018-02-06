#ifndef PACIENTEPENDIENTEVIEWMODEL_H
#define PACIENTEPENDIENTEVIEWMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class PacientePendienteViewModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    ~PacientePendienteViewModel()=default;
    static PacientePendienteViewModel &Instance();

    enum PacienteRoles {
        NombreRole = Qt::UserRole + 1,
        ApellidosRole,
        CelularRole,
        TelefonoRole,
        CorreoRole,
        FechaDeNacimientoRole,
        CalleYNumeroRole,
        ColoniaRole,
        CiudadRole,
        EstadoRole,
        SesionesPagadasRole,
        SaldoAFavorRole,
        SesionesDeGarantiaRole
    };

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;

    Q_INVOKABLE void updateQuery(const QString ubicacion);
    Q_INVOKABLE void filterQueryByCellPhone(QString celular);
    //Q_INVOKABLE void filterQueryByLastName(const QString apellidos);


    signals:
        void currentRowChanged();

protected:
    QHash<int, QByteArray> roleNames()const;

private:
    PacientePendienteViewModel()=default;
    PacientePendienteViewModel(PacientePendienteViewModel const&)=delete;
    void operator = (PacientePendienteViewModel const&)=delete;


};

#endif // PACIENTEPENDIENTEVIEWMODEL_H
