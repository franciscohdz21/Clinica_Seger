#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QModelIndex>
#include "clientesviewmodel.h"
#include "cabinaviewmodel.h"

ClientesViewModel &ClientesViewModel::Instance()
{
    static ClientesViewModel instance; //Guaranteed to be destroyed
    return instance;
}
void ClientesViewModel::updateQuery()
{
    QString query = "SELECT * FROM clientes";
    this->setQuery(query);
    qDebug () << "Last error: " << this->lastError().text();

}
void ClientesViewModel::filterQueryByCellphone(QString celular)
{
    QString celularForQuery = "'%" + celular + "%'";
    QString query = "SELECT * FROM clientes WHERE celular LIKE ";
    query.append(celularForQuery);
    this->setQuery(query);

    qDebug () << "Last error: " << this->lastError().text();
}
void ClientesViewModel::filterQueryByLastName(const QString apellidos)
{
    QString lastNameForQuery = "'%" + apellidos + "%'";
    QString query = "SELECT * FROM clientes WHERE apellidos LIKE ";
    query.append(lastNameForQuery);
    this->setQuery(query);

    qDebug () << "Last error: " << this->lastError().text();
}
void ClientesViewModel::setClientesProperties(int row)
{
    QModelIndex index;
    if ( (!this->record().isGenerated("Nombre")) || (!this->record().isGenerated("Apellidos")) ||
         (!this->record().isGenerated("Celular")) )
    {
        qDebug() << "Error setting nombre, apellidos o celular";
    }
    else
    {
        if (!this->query().seek(row))
            return;
        CabinaViewModel::Instance().setNombre(this->query().value("Nombre").toString());
        CabinaViewModel::Instance().setApellidos(this->query().value("Apellidos").toString());
        CabinaViewModel::Instance().setCelular(this->query().value("Celular").toString());
    }
}
QVariant ClientesViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QString fieldName;
    switch (role) {
        case NombreRole: fieldName = QStringLiteral("Nombre"); break;
        case ApellidosRole: fieldName = QStringLiteral("Apellidos"); break;
        case CelularRole: fieldName = QStringLiteral("Celular"); break;
        case TelefonoRole: fieldName = QStringLiteral("Telefono"); break;
        case CorreoRole: fieldName = QStringLiteral("Correo"); break;
        case FechaDeNacimientoRole: fieldName = QStringLiteral("Fecha_de_Nacimiento"); break;
        case CalleYNumeroRole: fieldName = QStringLiteral("Calle_y_Numero"); break;
        case ColoniaRole: fieldName = QStringLiteral("Colonia"); break;
        case CiudadRole: fieldName = QStringLiteral("Ciudad"); break;
        case EstadoRole: fieldName = QStringLiteral("Estado"); break;
        case SesionesPagadasRole: fieldName = QStringLiteral("Sesiones_Pagadas"); break;
        case SaldoAFavorRole: fieldName = QStringLiteral("Saldo_a_Favor"); break;
        case SesionesDeGarantiaRole: fieldName = QStringLiteral("Sesiones_de_Garantia"); break;

    }
    if (!this->record().isGenerated(fieldName))
        return QVariant();
    else {
        QModelIndex item = indexInQuery(index);
        if (!this->query().seek(item.row()) )
            return QVariant();
        //output string validation
        QString output = this->query().value(fieldName).toString();
        return validateOutputString(output, fieldName);
        //return output;
    }
    return QVariant();
}
int ClientesViewModel::rowCount(const QModelIndex &parent) const
{
    return this->query().size();
}
QString ClientesViewModel::retrieveCelular(int row)
{
    return data(index(row, row, QModelIndex()), CelularRole).toString();
}
QString ClientesViewModel::validateOutputString(QString &output, QString fieldName) const
{
    if (fieldName.compare("Fecha_De_Nacimiento", Qt::CaseInsensitive) == 0)
    {
        //Orginal format: 2017-01-01 -ymd
        //Desired format: 01/Enero/2017
        QString copy, mes, dia, anho;
        //anho
        copy = output;
        copy.chop(6);
        anho = copy;
        //mes
        copy = output;
        copy.chop(3);
        copy.remove(0, 5);
        mes = copy;
        if (mes.compare("01", Qt::CaseInsensitive) == 0)
        {
            mes = "Enero";
        }
        else if (mes.compare("02", Qt::CaseInsensitive) == 0)
        {
            mes = "Febrero";
        }
        else if (mes.compare("03", Qt::CaseInsensitive) == 0)
        {
            mes = "Marzo";
        }
        else if (mes.compare("04", Qt::CaseInsensitive) == 0)
        {
            mes = "Abril";
        }
        else if (mes.compare("05", Qt::CaseInsensitive) == 0)
        {
            mes = "Mayo";
        }
        else if (mes.compare("06", Qt::CaseInsensitive) == 0)
        {
            mes = "Junio";
        }
        else if (mes.compare("07", Qt::CaseInsensitive) == 0)
        {
            mes = "Julio";
        }
        else if (mes.compare("08", Qt::CaseInsensitive) == 0)
        {
            mes = "Agosto";
        }
        else if (mes.compare("09", Qt::CaseInsensitive) == 0)
        {
            mes = "Septiembre";
        }
        else if (mes.compare("10", Qt::CaseInsensitive) == 0)
        {
            mes = "Octubre";
        }
        else if (mes.compare("11", Qt::CaseInsensitive) == 0)
        {
            mes = "Noviembre";
        }
        else if (mes.compare("12", Qt::CaseInsensitive) == 0)
        {
            mes = "Diciembre";
        }
        //dia
        copy = output;
        copy.remove(0, 8);
        dia = copy;
        //combine
        output.clear();
        output.append(dia);
        output.append("/");
        output.append(mes);
        output.append("/");
        output.append(anho);
        //Emtpy Date
        if (output.compare("//", Qt::CaseInsensitive) == 0)
        {
            return "";
        }
        return output;
    }
    else if (fieldName.compare("Hora_Inicio", Qt::CaseInsensitive) == 0)
    {
        output.chop(3);
        return output;
    }
    else if (fieldName.compare("Hora_Termino", Qt::CaseInsensitive) == 0)
    {
        output.chop(3);
        return output;
    }
    else if (fieldName.compare("Celular", Qt::CaseInsensitive) == 0)
    {
        if (output.compare("0", Qt::CaseInsensitive) == 0)
        {
            return "";
        }
    }
    else if (fieldName.compare("Telefono", Qt::CaseInsensitive) == 0)
    {
        if (output.compare("0", Qt::CaseInsensitive) == 0)
        {
            return "";
        }
    }
    else if (fieldName.compare("Sesiones_Pagadas", Qt::CaseInsensitive) == 0)
    {
        if (output.compare("0", Qt::CaseInsensitive) == 0)
        {
            return "";
        }
    }
    else if (fieldName.compare("Saldo_A_Favor", Qt::CaseInsensitive) == 0)
    {
        if (output.compare("0", Qt::CaseInsensitive) == 0)
        {
            return "";
        }
    }
    else if (fieldName.compare("Sesiones_De_Garantia", Qt::CaseInsensitive) == 0)
    {
        if (output.compare("0", Qt::CaseInsensitive) == 0)
        {
            return "";
        }
    }
    return output;
}
void ClientesViewModel::updatePaciente(QString nombre, QString apellidos, QString celular, QString telefono, QString correo,
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
void ClientesViewModel::addPaciente(QString nombre, QString apellidos, QString celular)
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
QHash<int, QByteArray> ClientesViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NombreRole] = "nombre";
    roles[ApellidosRole] = "apellidos";
    roles[CelularRole] = "celular";
    roles[TelefonoRole] = "telefono";
    roles[CorreoRole] = "correo";
    roles[FechaDeNacimientoRole] = "fechaDeNacimiento";
    roles[CalleYNumeroRole] = "calleYNumero";
    roles[ColoniaRole] = "colonia";
    roles[CiudadRole] = "ciudad";
    roles[EstadoRole] = "estado";
    roles[SesionesPagadasRole] = "sesionesPagadas";
    roles[SaldoAFavorRole] = "saldoAFavor";
    roles[SesionesDeGarantiaRole] = "sesionesDeGarantia";
    return roles;
}
