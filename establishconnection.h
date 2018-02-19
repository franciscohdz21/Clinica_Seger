#ifndef ESTABLISHCONNECTION_H
#define ESTABLISHCONNECTION_H

#include <QObject>

class EstablishConnection : public QObject
{
    Q_OBJECT
public:
    ~EstablishConnection()=default;
    static EstablishConnection &Instance();

    Q_INVOKABLE bool establecerConexion(const QString IP, const int puerto, const QString contrasena);
    Q_INVOKABLE int loginAPrograma(const QString usuario, const QString contrasena);

signals:

private:
    EstablishConnection()=default;
    EstablishConnection(EstablishConnection const&)=delete;
    void operator = (EstablishConnection const&)=delete;
};

#endif // ESTABLISHCONNECTION_H
