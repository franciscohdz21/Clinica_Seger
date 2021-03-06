#include <ctime>
#include <QDebug>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "datemanipulation.h"
#include "clinicacore.h"

#define FIRST_YEAR_OF_DATA 2013

DateManipulation &DateManipulation::Instance()
{
    static DateManipulation instance; //Guaranteed to be destroyed
    return instance;
}
void DateManipulation::init()
{
    buildYearRange();
    buildLowerBoundDate(0);
    buildUpperBoundDate(0);

    ClinicaCore::Instance().consoleOut("DateManipulation::init - Current date: " + m_lowerBoundDate.toString("yyyy-MM-dd"));
    ClinicaCore::Instance().consoleOut("DateManipulation::init - Upper bound date: " + m_upperBoundDate.toString("yyyy-MM-dd"));
}
QDate DateManipulation::lowerBoundDate() const
{
    return m_lowerBoundDate;
}
void DateManipulation::setLowerBoundDate(QDate date)
{
    if (date != m_lowerBoundDate)
    {
        m_lowerBoundDate = date;
        emit lowerBoundDateChanged();
    }

    ClinicaCore::Instance().consoleOut("DateManipulation::setLowerBoundDate - Current date is: " + m_lowerBoundDate.toString("yyyy-MM-dd"));
}
void DateManipulation::buildLowerBoundDate(int year)
{
    if (year == 0)
    {
        //build date
        // current date/time based on current system
        time_t now = time(0);

        // convert now to string form
        char* dt = ctime(&now);
        QString currentDateAndTime = dt;

        ClinicaCore::Instance().consoleOut("DateManipulation::buildLowerBoundDate - The local date and time is: " + currentDateAndTime);

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

        //set date
        QDate date;
        date.setDate(yearInt, monthInt, dayInt);
        setLowerBoundDate(date);
    }
    else
    {
        QDate date;
        date.setDate(year, 01, 01);
        setLowerBoundDate(date);
    }
}
QDate DateManipulation::upperBoundDate() const
{
    return m_upperBoundDate;
}
void DateManipulation::setUpperBoundDate(QDate date)
{
    if (date != m_upperBoundDate)
    {
        m_upperBoundDate = date;
        emit upperBoundDateChanged();
    }

    ClinicaCore::Instance().consoleOut("DateManipulation::setUpperBoundDate - Upper bound date is: " + m_upperBoundDate.toString("yyyy-MM-dd"));
}
void DateManipulation::buildUpperBoundDate(int year)
{
    if (year == 0)
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

        //set date
        QDate date;
        date.setDate(yearInt, monthInt, dayInt);
        setUpperBoundDate(date);
    }
    else
    {
        QDate date;
        date.setDate(year, 12, 31);
        setUpperBoundDate(date);
    }
}
void DateManipulation::buildDateBounds(int year)
{
    buildLowerBoundDate(year);
    buildUpperBoundDate(year);
}
int DateManipulation::daysToSelection(QDate date)
{
    return m_lowerBoundDate.daysTo(date);
}
void DateManipulation::generateID(QDate date, QString horaInicio)
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

    ClinicaCore::Instance().consoleOut("DateManipulation::generateID - Final ID: " + ID);
}
long long int DateManipulation::getCurrentID() const
{
    return m_currentID;
}
void DateManipulation::setCurrentID(long long int ID)
{
    m_currentID = ID;
}
QDate DateManipulation::getCurrentDate() const
{
    return m_currentDate;
}
void DateManipulation::setCurrentDate(QDate date)
{
    m_currentDate = date;
}
QString DateManipulation::getCurrentInitialTime() const
{
    return m_currentInitialTime;
}
void DateManipulation::setCurrentInitialTime(QString time)
{
    m_currentInitialTime = time;
}
QVector<long long> DateManipulation::getIDsQueued() const
{
    return m_IDsQueued;
}
void DateManipulation::clearIDsQueued()
{
    m_IDsQueued.clear();
}
void DateManipulation::addCurrentIDToIDsQueued()
{
    m_IDsQueued.push_back(m_currentID);
}
QStringList DateManipulation::getYearRange() const
{
    return m_yearRange;
}
void DateManipulation::buildYearRange()
{
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);
    QString currentDateAndTime = dt;

    ClinicaCore::Instance().consoleOut("DateManipulation::buildYearRange - The local date and time is: " + currentDateAndTime);

    QStringList currentDateAndTimeSplit = currentDateAndTime.split(" ");
    QString year = currentDateAndTimeSplit.at(4);
    year.chop(1);
    int yearInt;
    yearInt = year.toInt();
    m_yearRange.clear();
    for (int i = FIRST_YEAR_OF_DATA; i <= yearInt; i++)
    {
        m_yearRange.push_back(QString::number(i));
    }
    m_yearRange.push_back("Presente");
}
DateManipulation::DateManipulation()
{
    init();
}
