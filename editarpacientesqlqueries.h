#ifndef EDITARPACIENTESQLQUERIES_H
#define EDITARPACIENTESQLQUERIES_H

#include <QObject>

class EditarPacienteSQLQueries : public QObject
{
    Q_OBJECT
public:
    ~EditarPacienteSQLQueries()=default;
    static EditarPacienteSQLQueries &Instance();

    Q_INVOKABLE QString retrieveEntry(QString celular, QString column);
    Q_INVOKABLE void retrieveAllEntries(QString celular);

private:
    EditarPacienteSQLQueries()=default;
    EditarPacienteSQLQueries(EditarPacienteSQLQueries const&)=delete;
    void operator = (EditarPacienteSQLQueries const&)=delete;
};

#endif // EDITARPACIENTESQLQUERIES_H
