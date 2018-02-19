#ifndef CABINASQLQUERIES_H
#define CABINASQLQUERIES_H

#include <QObject>

class CabinaSQLQueries : public QObject
{
    Q_OBJECT
public:
    ~CabinaSQLQueries()=default;
    static CabinaSQLQueries &Instance();

    //SQL
    Q_INVOKABLE void initCitaDeletion(int row);
    Q_INVOKABLE void filterQueryByCellphone(QString celular);
    Q_INVOKABLE void filterQueryByLastName(const QString apellidos);
    Q_INVOKABLE void updateQuery(const QString cabina);
    Q_INVOKABLE void updateID();
    Q_INVOKABLE void updateRowInTable(QString nombre, QString apellidos,
                                      QString celular, QString tratamiento, QString servicio,
                                      QString zonas, QString precio, QString sesion,
                                      QString sesionesPagadas, QString totalPagado,
                                      QString estatusDeCita, QString observaciones, QString importeCobrado,
                                      int duracionIndex);
    Q_INVOKABLE void clearRowsDueToBusyRow();
    Q_INVOKABLE void deleteCita(QString fecha, QString celular, QString servicio);
    Q_INVOKABLE bool rowIsEmpty()const;

private:
    CabinaSQLQueries()=default;
    CabinaSQLQueries(CabinaSQLQueries const&)=delete;
    void operator = (CabinaSQLQueries const&)=delete;
};

#endif // CABINASQLQUERIES_H
