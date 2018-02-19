#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QModelIndex>
#include "clientessqlqueries.h"
#include "clientesviewmodel.h"

ClientesSQLQueries &ClientesSQLQueries::Instance()
{
    static ClientesSQLQueries instance; //Guaranteed to be destroyed
    return instance;
}
void ClientesSQLQueries::updateQuery()
{
    QString query = "SELECT * FROM clientes";
    ClientesViewModel::Instance().setQuery(query);
    qDebug () << "Last error: " << ClientesViewModel::Instance().lastError().text();

}
void ClientesSQLQueries::filterQueryByCellphone(QString celular)
{
    QString celularForQuery = "'%" + celular + "%'";
    QString query = "SELECT * FROM clientes WHERE celular LIKE ";
    query.append(celularForQuery);
    ClientesViewModel::Instance().setQuery(query);

    qDebug () << "Last error: " << ClientesViewModel::Instance().lastError().text();
}
void ClientesSQLQueries::filterQueryByLastName(const QString apellidos)
{
    QString lastNameForQuery = "'%" + apellidos + "%'";
    QString query = "SELECT * FROM clientes WHERE apellidos LIKE ";
    query.append(lastNameForQuery);
    ClientesViewModel::Instance().setQuery(query);

    qDebug () << "Last error: " << ClientesViewModel::Instance().lastError().text();
}
void ClientesSQLQueries::updatePaciente(QString nombre, QString apellidos, QString celular, QString telefono, QString correo,
                                             int diaFechaDeNacimientoIndex, int mesFechaDeNacimientoIndex, QString anoFechaDeNacimiento,
                                             QString calleYNumero, QString colonia, QString ciudad, QString estado,
                                             QString sesionesPagadas, QString saldoAFavor, QString sesionesDeGarantia, QString currentCelular)
{

    //nombre
    QSqlQuery query;
    query.prepare("UPDATE clientes "
                  "SET Nombre = :nombre, "
                      "Apellidos = :apellidos, "
                      "Celular = :celular "
                  "WHERE Celular = :currentCelular");
    query.bindValue(":nombre", nombre);
    query.bindValue(":apellidos", apellidos);
    query.bindValue(":celular", celular);
    query.bindValue(":currentCelular", currentCelular);
    query.exec();
    qDebug () << query.lastError();

    //apellidos
    QSqlQuery query2;
    query2.clear();
    query2.prepare("UPDATE clientes "
                  "SET Apellidos = :apellidos "
                  "WHERE Celular = :celular");

    query2.bindValue(":apellidos", apellidos);
    query2.bindValue(":celular", celular);
    query2.exec();
    qDebug () << query2.lastError();

    //celular
    QSqlQuery query3;
    QString queryStr = "UPDATE clientes "
                       "SET Celular = :celular "
                       "WHERE Celular = ";
    queryStr.append(currentCelular);
    query3.prepare(queryStr);
    query3.bindValue(":celular", celular);
    query3.exec();
    qDebug () << query3.lastError();

    //telefono
    query.clear();
    query.prepare("UPDATE clientes "
                  "SET Telefono = :telefono "
                  "WHERE Celular = :celular");

    query.bindValue(":telefono", telefono);
    query.bindValue(":celular", celular);
    query.exec();
    qDebug () << query.lastError();

    //correo
    query.clear();
    query.prepare("UPDATE clientes "
                  "SET Correo = :correo "
                  "WHERE Celular = :celular");

    query.bindValue(":correo", correo);
    query.bindValue(":celular", celular);
    query.exec();
    qDebug () << query.lastError();

    //fecha de nacimiento
    int dia = diaFechaDeNacimientoIndex + 1;
    QString diaString = QString::number(dia);
    if (diaString.size() == 1)
        diaString.prepend("0");

    int mes = mesFechaDeNacimientoIndex + 1;
    QString mesString = QString::number(mes);
    if (mesString.size() == 1)
        mesString.prepend("0");

    QString fecha;
    fecha.append(anoFechaDeNacimiento + "-");
    fecha.append(mesString + "-");
    fecha.append(diaString);
    qDebug () << "Fecha to update: " << fecha;
    query.clear();
    query.prepare("UPDATE clientes "
                  "SET Fecha_De_Nacimiento = :fechaDeNacimiento "
                  "WHERE Celular = :celular");

    query.bindValue(":fechaDeNacimiento", fecha);
    query.bindValue(":celular", celular);
    query.exec();
    qDebug () << query.lastError();

    //calle y numero
    query.clear();
    query.prepare("UPDATE clientes "
                  "SET Calle_Y_Numero = :calleYNumero "
                  "WHERE Celular = :celular");
    query.bindValue(":calleYNumero", calleYNumero);
    query.bindValue(":celular", celular);
    query.exec();
    qDebug () << query.lastError();

    //colonia
    query.clear();
    query.prepare("UPDATE clientes "
                  "SET Colonia = :colonia "
                  "WHERE Celular = :celular");
    query.bindValue(":colonia", colonia);
    query.bindValue(":celular", celular);
    query.exec();
    qDebug () << query.lastError();

    //ciudad
    query.clear();
    query.prepare("UPDATE clientes "
                  "SET Ciudad = :ciudad "
                  "WHERE Celular = :celular");
    query.bindValue(":ciudad", ciudad);
    query.bindValue(":celular", celular);
    query.exec();
    qDebug () << query.lastError();

    //estado
    query.clear();
    query.prepare("UPDATE clientes "
                  "SET Estado = :estado "
                  "WHERE Celular = :celular");
    query.bindValue(":estado", estado);
    query.bindValue(":celular", celular);
    query.exec();
    qDebug () << query.lastError();

    //sesiones pagadas
    query.clear();
    query.prepare("UPDATE clientes "
                  "SET Sesiones_Pagadas = :sesionesPagadas "
                  "WHERE Celular = :celular");

    query.bindValue(":sesionesPagadas", sesionesPagadas);
    query.bindValue(":celular", celular);
    query.exec();
    qDebug () << query.lastError();

    //saldo a favor
    query.clear();
    query.prepare("UPDATE clientes "
                  "SET Saldo_A_Favor = :saldoAFavor "
                  "WHERE Celular = :celular");
    query.bindValue(":saldoAFavor", saldoAFavor);
    query.bindValue(":celular", celular);
    query.exec();
    qDebug () << query.lastError();

    //sesiones de garantia
    query.clear();
    query.prepare("UPDATE clientes "
                  "SET Sesiones_De_Garantia = :sesionesDeGarantia "
                  "WHERE Celular = :celular");
    query.bindValue(":sesionesDeGarantia", sesionesDeGarantia);
    query.bindValue(":celular", celular);
    query.exec();
    qDebug () << query.lastError();

    updateQuery();
}
void ClientesSQLQueries::addPaciente(QString nombre, QString apellidos, QString celular)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Clientes "
                  "SET Nombre = :nombre, "
                  "    Apellidos = :apellidos, "
                  "    Celular = :celular;");
    query.bindValue(":nombre", nombre);
    query.bindValue(":apellidos", apellidos);
    query.bindValue(":celular", celular);

    query.exec();
    qDebug () << "Last error: " << query.lastError();
}