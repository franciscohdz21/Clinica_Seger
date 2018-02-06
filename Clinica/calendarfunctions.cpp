#include <iostream>
#include <ctime>
#include <QDebug>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "calendarfunctions.h"
#include "cabinaviewmodel.h"

#define MAX_MESES_CITA 4

CalendarFunctions &CalendarFunctions::Instance()
{
    static CalendarFunctions instance; //Guaranteed to be destroyed
    return instance;
}
void CalendarFunctions::init()
{
    setTodaysDate();
    setUpperBoundDate();
    qDebug () << "Current date: " << m_todaysDate.toString("yyyy-MM-dd");
    qDebug () << "Upper bound date: " << m_upperBoundDate.toString("yyyy-MM-dd");
}
QDate CalendarFunctions::getTodaysDate() const
{
    return m_todaysDate;
}
void CalendarFunctions::setTodaysDate()
{
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);
    QString currentDateAndTime = dt;
    qDebug () << "The local date and time is: " << currentDateAndTime;
    QStringList currentDateAndTimeSplit = currentDateAndTime.split(" ");
    QString day = currentDateAndTimeSplit.at(2);
    QString month = currentDateAndTimeSplit.at(1);
    if (month.compare("Jan", Qt::CaseInsensitive) == 0)
        month = "01";
    else if (month.compare("Feb", Qt::CaseInsensitive) == 0)
            month = "02";
    else if (month.compare("Mar", Qt::CaseInsensitive) == 0)
            month = "03";
    else if (month.compare("Apr", Qt::CaseInsensitive) == 0)
            month = "04";
    else if (month.compare("May", Qt::CaseInsensitive) == 0)
            month = "05";
    else if (month.compare("Jun", Qt::CaseInsensitive) == 0)
            month = "06";
    else if (month.compare("Jul", Qt::CaseInsensitive) == 0)
            month = "07";
    else if (month.compare("Aug", Qt::CaseInsensitive) == 0)
            month = "08";
    else if (month.compare("Sep", Qt::CaseInsensitive) == 0)
            month = "09";
    else if (month.compare("Oct", Qt::CaseInsensitive) == 0)
            month = "10";
    else if (month.compare("Nov", Qt::CaseInsensitive) == 0)
            month = "11";
    else if (month.compare("Dec", Qt::CaseInsensitive) == 0)
            month = "12";
    QString year = currentDateAndTimeSplit.at(4);
    year.chop(1);

    int dayInt, monthInt, yearInt;
    dayInt = day.toInt();
    monthInt = month.toInt();
    yearInt = year.toInt();

    QDate date(yearInt, monthInt, dayInt);
    m_todaysDate = date;
//    qDebug () << "Current date is: " << m_todaysDate;
}
QDate CalendarFunctions::getUpperBoundDate() const
{
    return m_upperBoundDate;
}
void CalendarFunctions::setUpperBoundDate()
{
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);
    QString currentDateAndTime = dt;
    QStringList currentDateAndTimeSplit = currentDateAndTime.split(" ");
    QString day = currentDateAndTimeSplit.at(2);
    QString month = currentDateAndTimeSplit.at(1);

    if (month.compare("Jan", Qt::CaseInsensitive) == 0)
        month = "01";
    else if (month.compare("Feb", Qt::CaseInsensitive) == 0)
            month = "02";
    else if (month.compare("Mar", Qt::CaseInsensitive) == 0)
            month = "03";
    else if (month.compare("Apr", Qt::CaseInsensitive) == 0)
            month = "04";
    else if (month.compare("May", Qt::CaseInsensitive) == 0)
            month = "05";
    else if (month.compare("Jun", Qt::CaseInsensitive) == 0)
            month = "06";
    else if (month.compare("Jul", Qt::CaseInsensitive) == 0)
            month = "07";
    else if (month.compare("Aug", Qt::CaseInsensitive) == 0)
            month = "08";
    else if (month.compare("Sep", Qt::CaseInsensitive) == 0)
            month = "09";
    else if (month.compare("Oct", Qt::CaseInsensitive) == 0)
            month = "10";
    else if (month.compare("Nov", Qt::CaseInsensitive) == 0)
            month = "11";
    else if (month.compare("Dec", Qt::CaseInsensitive) == 0)
            month = "12";

    QString year = currentDateAndTimeSplit.at(4);
    year.chop(1);

    int tmpMonth = month.toInt();
    tmpMonth = tmpMonth + MAX_MESES_CITA;
    qDebug () << tmpMonth;
    if (tmpMonth > 12)
    {
        tmpMonth = tmpMonth - 12;
        month = QString::number(tmpMonth);
        int tmpYear = year.toInt();
        tmpYear++;
        year = QString::number(tmpYear);
    }

    int dayInt, monthInt, yearInt;
    dayInt = day.toInt();
    monthInt = tmpMonth;
    yearInt = year.toInt();

    QDate date(yearInt, monthInt, dayInt);
    m_upperBoundDate = date;
    //    qDebug () << "Upper bound date is: " << m_todaysDate;
}
int CalendarFunctions::daysToSelection(QDate date)
{
    return m_todaysDate.daysTo(date);
}
void CalendarFunctions::generateID(QDate date, QString horaInicio)
{
    QString ID;
    ID.append(QString::number(date.year()));
    if (date.month() < 10)
    {
        ID.append("0");
    }
    ID.append(QString::number(date.month()));
    if (date.day() < 10)
    {
        ID.append("0");
    }
    ID.append(QString::number(date.day()));
    ID.append(horaInicio);
    //set current parameters
    setCurrentID(ID.toLongLong());
    setCurrentDate(date);;
    setCurrentInitialTime(horaInicio);
    qDebug () << "Final ID: " << ID.toLongLong();
}
long long int CalendarFunctions::getCurrentID() const
{
    return m_currentID;
}
void CalendarFunctions::setCurrentID(long long int ID)
{
    m_currentID = ID;
}
QDate CalendarFunctions::getCurrentDate() const
{
    return m_currentDate;
}
void CalendarFunctions::setCurrentDate(QDate date)
{
    m_currentDate = date;
}
QString CalendarFunctions::getCurrentInitialTime() const
{
    return m_currentInitialTime;
}
void CalendarFunctions::setCurrentInitialTime(QString time)
{
    m_currentInitialTime = time;
}
QVector<long long> CalendarFunctions::getIDsQueued() const
{
    return m_IDsQueued;
}
void CalendarFunctions::clearIDsQueued()
{
    m_IDsQueued.clear();
}
void CalendarFunctions::addCurrentIDToIDsQueued()
{
    m_IDsQueued.push_back(m_currentID);
}
bool CalendarFunctions::rowIsEmpty() const
{
    QSqlQuery query;
    QString selectString = "SELECT Nombre FROM " + CabinaViewModel::Instance().getNombreDeTabla();
    query.prepare(selectString +
                  " WHERE ID = :id;");

    query.bindValue(":id", QString::number(CalendarFunctions::Instance().getCurrentID()));
    query.exec();

    while (query.next())
    {
        bool nombreEsNull = query.value(0).isNull();
        QString nombre = query.value(0).toString();
        nombre = nombre.simplified();
        nombre.replace( " ", "" );
        if (nombreEsNull == true || nombre.compare("", Qt::CaseInsensitive) == 0)
            return true;
        else
            return false;
    }
    return true;
}
