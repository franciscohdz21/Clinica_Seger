#ifndef CLIENTESVIEWMODEL_H
#define CLIENTESVIEWMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class ClientesViewModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    ~ClientesViewModel()=default;
    static ClientesViewModel &Instance();

    enum ClientesRoles {
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

    //QAbstractListModel
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;

    //Other
    Q_INVOKABLE void setClientesProperties(int row);
    Q_INVOKABLE QString retrieveCelular(int row);
    QString validateOutputString(QString &output, QString fieldName) const;

    //SQL
    Q_INVOKABLE void filterQueryByCellphone(QString celular);
    Q_INVOKABLE void filterQueryByLastName(const QString apellidos);
    Q_INVOKABLE void updateQuery();
    Q_INVOKABLE void updatePaciente(QString nombre, QString apellidos, QString celular, QString telefono,
                                   QString correo, int diaFechaDeNacimientoIndex, int mesFechaDeNacimientoIndex,
                                   QString anoFechaDeNacimiento, QString calleYNumero, QString colonia,
                                   QString ciudad, QString estado, QString sesionesPagadas, QString saldoAFavor,
                                   QString sesionesDeGarantia, QString currentCelular);
    Q_INVOKABLE void addPaciente(QString nombre, QString apellidos, QString celular);


protected:
    QHash<int, QByteArray> roleNames() const;

private:
    ClientesViewModel()=default;
    ClientesViewModel(ClientesViewModel const&)=delete;
    void operator = (ClientesViewModel const&)=delete;

};

#endif // CLIENTESVIEWMODEL_H
