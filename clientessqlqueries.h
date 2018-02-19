#ifndef CLIENTESSQLQUERIES_H
#define CLIENTESSQLQUERIES_H

#include <QObject>

class ClientesSQLQueries : public QObject
{
    Q_OBJECT
public:
    ~ClientesSQLQueries()=default;
    static ClientesSQLQueries &Instance();

    //SQL
    Q_INVOKABLE void updateQuery();
    Q_INVOKABLE void filterQueryByCellphone(QString celular);
    Q_INVOKABLE void filterQueryByLastName(const QString apellidos);
    Q_INVOKABLE void updatePaciente(QString nombre, QString apellidos, QString celular, QString telefono,
                                   QString correo, int diaFechaDeNacimientoIndex, int mesFechaDeNacimientoIndex,
                                   QString anoFechaDeNacimiento, QString calleYNumero, QString colonia,
                                   QString ciudad, QString estado, QString sesionesPagadas, QString saldoAFavor,
                                   QString sesionesDeGarantia, QString currentCelular);
    Q_INVOKABLE void addPaciente(QString nombre, QString apellidos, QString celular);

private:
    ClientesSQLQueries()=default;
    ClientesSQLQueries(ClientesSQLQueries const&)=delete;
    void operator = (ClientesSQLQueries const&)=delete;


};

#endif // CLIENTESSQLQUERIES_H
