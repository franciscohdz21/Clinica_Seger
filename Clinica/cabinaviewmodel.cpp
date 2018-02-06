#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QDate>
#include <QSqlQueryModel>
#include "cabinaviewmodel.h"
#include "conexionabasededatos.h"
#include "calendarfunctions.h"

#define ENTRADAS_POR_DIA 22
#define DIAS_DISPONIBLES_PARA_CITA 90

CabinaViewModel &CabinaViewModel::Instance()
{
    static CabinaViewModel instance; //Guaranteed to be destroyed
    return instance;
}
void CabinaViewModel::updateQuery(const QString tabla)
{
    //fix this
    QString nombreDeTabla;
    nombreDeTabla.append(tabla);
    nombreDeTabla.append("_");
    if (ConexionABaseDeDatos::Instance().ubicacion().compare("La Capilla, 5 de Feb", Qt::CaseInsensitive) == 0)
    {
        nombreDeTabla.append("capilla");
    }
    else if (ConexionABaseDeDatos::Instance().ubicacion().compare("Colinas del Cimatario", Qt::CaseInsensitive) == 0)
    {
        nombreDeTabla.append("colinas");
    }
    else if (ConexionABaseDeDatos::Instance().ubicacion().compare("San Juan del Rio", Qt::CaseInsensitive) == 0)
    {
        nombreDeTabla.append("san_juan");
    }
    else if(ConexionABaseDeDatos::Instance().ubicacion().compare("Global", Qt::CaseInsensitive) == 0)
    {
        nombreDeTabla.clear();
        nombreDeTabla.append("template_cabina");
    }
    m_nombreDeTabla = nombreDeTabla;
    //setup general cabina query (sorted)
    QString query = "SELECT * FROM " + m_nombreDeTabla + " WHERE Fecha >= '" + CalendarFunctions::Instance().getTodaysDate().toString("yyyy-MM-dd") +
            "' AND Fecha <= '" + CalendarFunctions::Instance().getUpperBoundDate().toString("yyyy-MM-dd") + "'" +
            "ORDER BY Fecha ASC";
    this->setQuery(query);
    qDebug () << "Last error: " << this->lastError().text();
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
void CabinaViewModel::clearNombreApellidosCelular()
{
    setNombre("");
    setApellidos("");
    setCelular("");
}
void CabinaViewModel::updateRowInTable(QString nombre, QString apellidos,
                                       QString celular, QString tratamiento, QString servicio,
                                       QString zonas, QString precio, QString sesion,
                                       QString sesionesPagadas, QString totalPagado,
                                       QString estatusDeCita, QString observaciones,
                                       QString importeCobrado, int duracionIndex)
{
    //empty string handling
    if (nombre.compare("", Qt::CaseInsensitive) == 0)
    {
        nombre = " ";
    }
    if (apellidos.compare("", Qt::CaseInsensitive) == 0)
    {
        apellidos = " ";
    }
    if (celular.compare("", Qt::CaseInsensitive) == 0)
    {
        celular = " ";
    }
    if (tratamiento.compare("", Qt::CaseInsensitive) == 0)
    {
        tratamiento = " ";
    }
    if (servicio.compare("", Qt::CaseInsensitive) == 0)
    {
        servicio = " ";
    }
    if (zonas.compare("", Qt::CaseInsensitive) == 0)
    {
        zonas = " ";
    }
    if (precio.compare("", Qt::CaseInsensitive) == 0)
    {
        precio = " ";
    }
    if (sesion.compare("", Qt::CaseInsensitive) == 0)
    {
        sesion = " ";
    }
    if (sesionesPagadas.compare("", Qt::CaseInsensitive) == 0)
    {
        sesionesPagadas = " ";
    }
    if (totalPagado.compare("", Qt::CaseInsensitive) == 0)
    {
        totalPagado = " ";
    }
    if (estatusDeCita.compare("", Qt::CaseInsensitive) == 0)
    {
        estatusDeCita = " ";
    }
    if (observaciones.compare("", Qt::CaseInsensitive) == 0)
    {
        observaciones = " ";
    }
    if (importeCobrado.compare("", Qt::CaseInsensitive) == 0)
    {
        importeCobrado = " ";
    }

    QSqlQuery query;
    QString updateString = "UPDATE ";
    updateString.append(CabinaViewModel::Instance().getNombreDeTabla() + " ");

    query.prepare(updateString +
                  "SET Nombre = :nombre, "
                  "     Apellidos = :apellidos, "
                  "     Celular = :celular, "
                  "     Tratamiento = :tratamiento, "
                  "     Servicio = :servicio, "
                  "     Zonas = :zonas, "
                  "     Precio = :precio, "
                  "     Sesion = :sesion, "
                  "     Sesiones_Pagadas = :sesionesPagadas, "
                  "     Total_Pagado = :totalPagado, "
                  "     Estatus_De_Cita = :estatusDeCita, "
                  "     Observaciones = :observaciones, "
                  "     Importe_Cobrado = :importeCobrado "
                  "WHERE ID = :id;");

    query.bindValue(":nombre", nombre);
    query.bindValue(":apellidos", apellidos);
    query.bindValue(":celular", celular);
    query.bindValue(":tratamiento", tratamiento);
    query.bindValue(":servicio", servicio);
    query.bindValue(":zonas", zonas);
    query.bindValue(":precio", precio);
    query.bindValue(":sesion", sesion);
    query.bindValue(":sesionesPagadas", sesionesPagadas);
    query.bindValue(":totalPagado", totalPagado);
    query.bindValue(":estatusDeCita", estatusDeCita);
    query.bindValue(":observaciones", observaciones);
    query.bindValue(":importeCobrado", importeCobrado);
    query.bindValue(":id", QString::number(CalendarFunctions::Instance().getCurrentID()));

    query.exec();
    qDebug () << "Last error: " << this->lastError().text();
}
void CabinaViewModel::clearRowsDueToBusyRow()
{
    for (int i = 0; i < CalendarFunctions::Instance().getIDsQueued().size()-1; i++)
    {
        QString currentID = QString::number(CalendarFunctions::Instance().getIDsQueued().at(i));
        QString updateString = "UPDATE " + CabinaViewModel::Instance().getNombreDeTabla() + " ";
        QSqlQuery query;
        query.prepare(updateString +
                      "SET Nombre = :nombre, "
                      "     Apellidos = :apellidos, "
                      "     Celular = :celular, "
                      "     Tratamiento = :tratamiento, "
                      "     Servicio = :servicio, "
                      "     Zonas = :zonas, "
                      "     Precio = :precio, "
                      "     Sesion = :sesion, "
                      "     Sesiones_Pagadas = :sesionesPagadas, "
                      "     Total_Pagado = :totalPagado, "
                      "     Estatus_De_Cita = :estatusDeCita, "
                      "     Observaciones = :observaciones, "
                      "     Importe_Cobrado = :importeCobrado "
                      "WHERE ID = :id");

        query.bindValue(":nombre", "");
        query.bindValue(":apellidos", "");
        query.bindValue(":celular", 0);
        query.bindValue(":tratamiento", "");
        query.bindValue(":servicio", "");
        query.bindValue(":zonas", "");
        query.bindValue(":precio", 0);
        query.bindValue(":sesion", 0);
        query.bindValue(":sesionesPagadas", 0);
        query.bindValue(":totalPagado", 0);
        query.bindValue(":estatusDeCita", "");
        query.bindValue(":observaciones", "");
        query.bindValue(":importeCobrado", 0);
        query.bindValue(":id", currentID);

        query.exec();
        qDebug () << "Last error: " << query.lastError();
    }
}
bool CabinaViewModel::isLastRowOfDay() const
{
    QString ID = QString::number(CalendarFunctions::Instance().getCurrentID());
    ID.remove(0, 8);
    if (ID.compare("1930", Qt::CaseInsensitive) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void CabinaViewModel::deleteCita(QString fecha, QString celular, QString servicio)
{
    QString query;
    query.append("UPDATE " + m_nombreDeTabla + " "
                 "SET Nombre = '',"
                 "    Apellidos = '',"
                 "    Celular = '0', "
                 "    Tratamiento = '', "
                 "    Servicio = '', "
                 "    Zonas = '', "
                 "    Precio = '0', "
                 "    Importe_Cobrado = '0', "
                 "    Sesion = '0', "
                 "    Sesiones_Pagadas = '0', "
                 "    Total_Pagado = '0', "
                 "    Estatus_de_Cita = '', "
                 "    Observaciones = '' "
                 "WHERE Fecha = '" + fecha + "'"
                 "AND   Celular = '" + celular + "'"
                 "AND   Servicio = '" + servicio + "'");
    this->setQuery(query);

    qDebug () << "Last error: " << this->lastError().text();
}
QString CabinaViewModel::getNombreDeTabla()
{
    return m_nombreDeTabla;
}
void CabinaViewModel::setID(int row)
{
    //no selection
    if (row == -1)
        return;

    //get row values
    if (!this->query().seek(row))
        return;

    if ( (!this->record().isGenerated("Fecha")) || (!this->record().isGenerated("Hora_Inicio")) ||
         (!this->record().isGenerated("Hora_Termino")) )
    {
        qDebug() << "Error setting fecha, hora inicio o hora termino";
    }
    else
    {
        QString tmpHoraInicio = this->query().value("Hora_Inicio").toString();
        tmpHoraInicio.chop(3);
        tmpHoraInicio.remove(2, 1);
        setHoraInicioForID(tmpHoraInicio);
        qDebug () << "Hora for ID: " << m_horaInicioForID;

        //Fecha
        qDebug () << "Fecha: " << this->query().value("Fecha").toString();
        QDate date;
        CalendarFunctions::Instance().generateID(date.fromString(this->query().value("Fecha").toString(), "yyyy-MM-dd"),
                                                 m_horaInicioForID);
    }
}
void CabinaViewModel::initCitaDeletion(int row)
{
    //no selection
    if (row == -1)
        return;

    //get row values
    if (!this->query().seek(row))
        return;

    if ( (!this->record().isGenerated("Fecha")) || (!this->record().isGenerated("Celular")) ||
         (!this->record().isGenerated("Servicio")) )
    {
        qDebug() << "Error setting fecha, celular o servicio";
    }
    else
    {
        QString fecha =  this->query().value("Fecha").toString();
        QString celular = this->query().value("Celular").toString();
        QString servicio = this->query().value("Servicio").toString();
        qDebug () << fecha << celular << servicio;
        deleteCita(fecha, celular, servicio);
    }
}
QString CabinaViewModel::getHoraInicioForID() const
{
    return m_horaInicioForID;
}
void CabinaViewModel::setHoraInicioForID(QString horaInicio)
{
    m_horaInicioForID = horaInicio;
}
void CabinaViewModel::filterQueryByCellphone(QString celular)
{
    QString celularForQuery = "'%" + celular + "%'";
    QString query;
    query.append("SELECT * FROM " + m_nombreDeTabla +
                 " WHERE celular LIKE " + celularForQuery +
                 " AND Fecha >= '" + CalendarFunctions::Instance().getTodaysDate().toString("yyyy-MM-dd") +
                 "' AND Fecha <= '" + CalendarFunctions::Instance().getUpperBoundDate().toString("yyyy-MM-dd") + "'" +
                 "ORDER BY Fecha ASC");
    this->setQuery(query);

    qDebug () << "Last error: " << this->lastError().text();
}
void CabinaViewModel::filterQueryByLastName(const QString apellidos)
{
    QString apellidosForQuery = "'%" + apellidos + "%'";
    QString query;
    query.append("SELECT * FROM " + m_nombreDeTabla +
                 " WHERE apellidos LIKE " + apellidosForQuery +
                 " AND Fecha >= '" + CalendarFunctions::Instance().getTodaysDate().toString("yyyy-MM-dd") +
                 "' AND Fecha <= '" + CalendarFunctions::Instance().getUpperBoundDate().toString("yyyy-MM-dd") + "'" +
                 "ORDER BY Fecha ASC");
    this->setQuery(query);

    qDebug () << "Last error: " << this->lastError().text();
}
void CabinaViewModel::updateID()
{
    //ID
    QSqlQuery query;
    QString horaInicio;
    horaInicio = CalendarFunctions::Instance().getCurrentInitialTime();
    horaInicio.insert(2, QString(":"));
    QString tmpFecha = "2018-01-10";
    QString updateString = "UPDATE ";
    updateString.append(CabinaViewModel::Instance().getNombreDeTabla());


    query.prepare(updateString +
                  " SET ID = :id "
                  "WHERE Fecha = :fecha "
                  "AND Hora_Inicio = :horaInicio;");
    query.bindValue(":id", QString::number(CalendarFunctions::Instance().getCurrentID()));
    query.bindValue(":fecha", CalendarFunctions::Instance().getCurrentDate());
    query.bindValue(":horaInicio", horaInicio);

    query.exec();
    qDebug () << query.lastError();
}
QString CabinaViewModel::nombre() const
{
    return m_nombre;
}
void CabinaViewModel::setNombre(const QString nuevoNombre)
{
    if (nuevoNombre != m_nombre)
    {
        m_nombre = nuevoNombre;
        emit nombreChanged();
    }
}
QString CabinaViewModel::apellidos() const
{
    return m_apellidos;
}
void CabinaViewModel::setApellidos(const QString nuevosApellidos)
{
    if (nuevosApellidos != m_apellidos)
    {
        m_apellidos = nuevosApellidos;
        emit apellidosChanged();
    }
}
QString CabinaViewModel::celular() const
{
    return m_celular;
}
void CabinaViewModel::setCelular(const QString nuevoCelular)
{
    if (nuevoCelular != m_celular)
    {
        m_celular = nuevoCelular;
        emit celularChanged();
    }
}
bool CabinaViewModel::clienteEsNuevo() const
{
    return m_clienteEsNuevo;
}

void CabinaViewModel::setClienteEsNuevo(bool trueOrFalse)
{
    if (trueOrFalse != m_clienteEsNuevo)
    {
        m_clienteEsNuevo = trueOrFalse;
        emit clienteEsNuevoChanged();
    }
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

