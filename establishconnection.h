#ifndef ESTABLISHCONNECTION_H
#define ESTABLISHCONNECTION_H

#include <QObject>
#include <QThread>
#include <QSqlDatabase>

class EstablishConnection : public QThread
{
    Q_OBJECT
    Q_PROPERTY(bool connectionErrorMessageVisible READ connectionErrorMessageVisible WRITE setConnectionErrorMessageVisible NOTIFY connectionErrorMessageVisibleChanged)
public:
    ~EstablishConnection()=default;
    static EstablishConnection &Instance();

    //Q_PROPERTES
    bool connectionErrorMessageVisible()const;
    void setConnectionErrorMessageVisible(bool trueOrFalse);

    //Other
    Q_INVOKABLE bool establecerConexion(const QString IP, const int puerto, const QString contrasena);
    Q_INVOKABLE int loginAPrograma(const QString usuario, const QString contrasena);
    void run();
    Q_INVOKABLE void terminateThread();

signals:
    void connectionErrorMessageVisibleChanged();

private:
    EstablishConnection();
    EstablishConnection(EstablishConnection const&)=delete;
    void operator = (EstablishConnection const&)=delete;

    QSqlDatabase m_sqlDatabse;
    bool m_connected;
    bool m_connectionErrorMessageVisible;

};

#endif // ESTABLISHCONNECTION_H
