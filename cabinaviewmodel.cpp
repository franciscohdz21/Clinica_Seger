#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QDate>
#include <QSqlQueryModel>
#include "cabinaviewmodel.h"

CabinaViewModel &CabinaViewModel::Instance()
{
    static CabinaViewModel instance; //Guaranteed to be destroyed
    return instance;
}
QVariant CabinaViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QString fieldName;
    switch (role)
    {
        case IDRole: fieldName = QStringLiteral("ID"); break;
        case FechaRole: fieldName = QStringLiteral("Fecha"); break;
        case HoraInicioRole: fieldName = QStringLiteral("Hora_Inicio"); break;
        case HoraTerminoRole: fieldName = QStringLiteral("Hora_Termino"); break;
        case NombreRole: fieldName = QStringLiteral("Nombre"); break;
        case ApellidosRole: fieldName = QStringLiteral("Apellidos"); break;
        case CelularRole: fieldName = QStringLiteral("Celular"); break;
        case TratamientoRole: fieldName = QStringLiteral("Tratamiento"); break;
        case ServicioRole: fieldName = QStringLiteral("Servicio"); break;
        case ZonasRole: fieldName = QStringLiteral("Zonas"); break;
        case PrecioRole: fieldName = QStringLiteral("Precio"); break;
        case ImporteCobradoRole: fieldName = QStringLiteral("Importe_Cobrado"); break;
        case SesionRole: fieldName = QStringLiteral("Sesion"); break;
        case SesionesPagadasRole: fieldName = QStringLiteral("Sesiones_Pagadas"); break;
        case TotalPagadoRole: fieldName = QStringLiteral("Total_Pagado"); break;
        case EstatusDeCitaRole: fieldName = QStringLiteral("Estatus_de_Cita"); break;
        case ObservacionesRole: fieldName = QStringLiteral("Observaciones"); break;
    }
    //not generated
    if (!this->record().isGenerated(fieldName))
    {
        qDebug () << "Record not generated";
        return QVariant();
    }
    //generated
    else
    {
        QModelIndex item = indexInQuery(index);
        if (!this->query().seek(item.row()) )
            return QVariant();
        //output string validation
        QString output = this->query().value(fieldName).toString();
        return validateOutputString(output, fieldName);
    }
    return QVariant();
}
int CabinaViewModel::rowCount(const QModelIndex &parent) const
{
    return this->query().size();
}
QString CabinaViewModel::validateOutputString(QString &output, QString fieldName) const
{
    if (output.compare("0", Qt::CaseInsensitive) == 0)
    {
        return "";
    }
    else if (fieldName.compare("ID", Qt::CaseInsensitive) == 0)
    {
        if (output.compare("0", Qt::CaseInsensitive) == 0)
        {
            return "";
        }
        else
        {
            return output;
        }
    }
    else if (fieldName.compare("Fecha", Qt::CaseInsensitive) == 0)
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
    return output;
}
QHash<int, QByteArray> CabinaViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IDRole] = "id";
    roles[NombreRole] = "nombre";
    roles[ApellidosRole] = "apellidos";
    roles[CelularRole] = "celular";
    roles[TratamientoRole] = "tratamiento";
    roles[ServicioRole] = "servicio";
    roles[ZonasRole] = "zonas";
    roles[SesionRole] = "sesion";
    roles[PrecioRole] = "precio";
    roles[ImporteCobradoRole] = "importeCobrado";
    roles[FechaRole] = "fecha";
    roles[HoraInicioRole] = "horaInicio";
    roles[HoraTerminoRole] = "horaTermino";
    roles[DuracionRole] = "duracion";
    roles[SesionesPagadasRole] = "sesionesPagadas";
    roles[TotalPagadoRole] = "totalPagado";
    roles[EstatusDeCitaRole] = "estatusDeCita";
    roles[ObservacionesRole] = "observaciones";
    return roles;
}
