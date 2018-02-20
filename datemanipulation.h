#ifndef DATEMANIPULATION_H
#define DATEMANIPULATION_H

#include <QObject>
#include <QDate>
#include <QVector>

#define MAX_MESES_CITA 4

class DateManipulation : public QObject
{
    Q_OBJECT
public:
    ~DateManipulation()=default;
    static DateManipulation &Instance();

    Q_INVOKABLE void init();
    Q_INVOKABLE QDate getTodaysDate()const;
    Q_INVOKABLE void setTodaysDate();
    Q_INVOKABLE QDate getUpperBoundDate()const;
    void setUpperBoundDate();
    Q_INVOKABLE int daysToSelection(QDate date);
    Q_INVOKABLE void generateID(QDate date, QString horaInicio);
    Q_INVOKABLE long long int getCurrentID()const;
    void setCurrentID(long long int ID);
    QDate getCurrentDate()const;
    void setCurrentDate(QDate date);
    QString getCurrentInitialTime()const;
    void setCurrentInitialTime(QString time);
    QVector <long long int> getIDsQueued()const;
    Q_INVOKABLE void clearIDsQueued();
    Q_INVOKABLE void addCurrentIDToIDsQueued();
    Q_INVOKABLE QStringList getYearRange()const;
    Q_INVOKABLE void buildYearRange();

private:
    DateManipulation();
    DateManipulation(DateManipulation const&)=delete;
    void operator = (DateManipulation const&)=delete;

    QDate m_todaysDate;
    QDate m_upperBoundDate;
    long long int m_currentID;
    QDate m_currentDate;
    QString m_currentInitialTime;
    QVector <long long int> m_IDsQueued;
    QStringList m_yearRange;
};

#endif // DATEMANIPULATION_H
