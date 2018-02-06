#ifndef CALENDARFUNCTIONS_H
#define CALENDARFUNCTIONS_H

#include <QObject>
#include <QDate>
#include <QVector>

class CalendarFunctions : public QObject
{
    Q_OBJECT
public:
    ~CalendarFunctions()=default;
    static CalendarFunctions &Instance();

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

    //SQL
    Q_INVOKABLE bool rowIsEmpty()const;

signals:

private:
    CalendarFunctions()=default;
    CalendarFunctions(CalendarFunctions const&)=delete;
    void operator = (CalendarFunctions const&)=delete;

    QDate m_todaysDate;
    QDate m_upperBoundDate;
    long long int m_currentID;
    QDate m_currentDate;
    QString m_currentInitialTime;
    QVector <long long int> m_IDsQueued;

};

#endif // CALENDARFUNCTIONS_H
