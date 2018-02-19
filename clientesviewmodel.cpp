#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QModelIndex>
#include "clientesviewmodel.h"
#include "datemanipulation.h"
#include "agendarclienteviewdata.h"
#include "clinicacore.h"

ClientesViewModel &ClientesViewModel::Instance()
{
    static ClientesViewModel instance; //Guaranteed to be destroyed
    return instance;
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
void ClientesViewModel::setClientesProperties(int row)
{
    if ( (!this->record().isGenerated("Nombre")) || (!this->record().isGenerated("Apellidos")) ||
         (!this->record().isGenerated("Celular")) )
    {
        if (ClinicaCore::Instance().developerMode() == true)
            qDebug() << "Error setting nombre, apellidos o celular";
    }
    else
    {
        if (!this->query().seek(row))
            return;
        AgendarClienteViewData::Instance().setNombre(this->query().value("Nombre").toString());
        AgendarClienteViewData::Instance().setApellidos(this->query().value("Apellidos").toString());
        AgendarClienteViewData::Instance().setCelular(this->query().value("Celular").toString());
    }
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
