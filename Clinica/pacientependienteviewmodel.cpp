#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "pacientependienteviewmodel.h"

PacientePendienteViewModel &PacientePendienteViewModel::Instance()
{
    static PacientePendienteViewModel instance;
    return instance;
}
QVariant PacientePendienteViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QString fieldName;
    switch (role)
    {
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
    else
    {
        QModelIndex item = indexInQuery(index);
        if (!this->query().seek(item.row()) )
            return QVariant();
        return this->query().value(fieldName);
    }
    return QVariant();
}
int PacientePendienteViewModel::rowCount(const QModelIndex &parent) const
{
    return this->query().size();
}
void PacientePendienteViewModel::updateQuery(const QString ubicacion)
{
    QString query = "SELECT * FROM ";
    query.append(ubicacion);
    query.append("_paciente_pendiente");
    this->setQuery(query);
    qDebug () << "Last error: " << this->lastError().text();
}
void PacientePendienteViewModel::filterQueryByCellPhone(QString celular)
{
    QString celularForQuery = "'%" + celular + "%'";
    QString query = "SELECT * FROM ";
    //query.append();//clientes WHERE celular LIKE ";
    //QString query = "SELECT * FROM clientes WHERE celular LIKE ";
    query.append(celularForQuery);
    this->setQuery(query);
    qDebug () << "Last error: " << this->lastError().text();
}
QHash<int, QByteArray> PacientePendienteViewModel::roleNames() const
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
