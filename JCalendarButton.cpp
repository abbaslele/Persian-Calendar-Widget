#include "JCalendarButton.h"
#include "JCalendar.h"
#include <QDialog>
#include <QPushButton>


// کلاس دکمه های تاریخ از و تا
JCalendarButton::JCalendarButton(QWidget *parent) :
    QPushButton(parent)
{
    setText( JCalendar::today().toString() );
    connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}
// کدهای اجرا شونده در هنگام زدن دکمه تاریخ
void JCalendarButton::buttonClicked()
{
    QDialog dialog( this, Qt::FramelessWindowHint );

    JCalendar calendar( &dialog );
    dialog.setStyleSheet("QDialog{\n	background-color: #313131;\n	border-radius: 4px;\n}");
    dialog.setModal(true);

    //calendar.setDate( JCalendar::Date::fromString( text() ) );

    calendar.setDate( JCalendar::Date::fromString( mCurrentDateString ) );

    QPoint p = mapToGlobal( QPoint() );
    p.setY( p.y() + height() );
    dialog.move( p );
    dialog.exec();
    QString result;
    QString monthString;
    QString dayString;

    if(calendar.getCurrentDate().Month < 10)
    {
        monthString = "0" + QString::number(calendar.getCurrentDate().Month);
    }
    else
    {
        monthString = QString::number(calendar.getCurrentDate().Month);
    }
    if(calendar.getCurrentDate().Day < 10)
    {
        dayString = "0" + QString::number(calendar.getCurrentDate().Day);
    }
    else
    {
        dayString = QString::number(calendar.getCurrentDate().Day);
    }
    result = QString::number(calendar.getCurrentDate().Year)+ "-" + monthString  + "-" + dayString;

    QString azRtlText = QString::fromUtf8("از");
    QString taRtlText = QString::fromUtf8("تا");

    QString startCombined = QString(
                        "<table width='100%' cellspacing='0' cellpadding=0px >"
                        "<tr>"
                        "<td align='left' dir='ltr'>%1</td>"
                        "<td align='right' dir='rtl'>%2</td>"
                        "</tr></table>"
                        ).arg(toPersianNumbers(result), azRtlText);

    QString endCombined = QString(
                      "<table width='100%' cellspacing='0' cellpadding=0px>"
                      "<tr>"
                      "<td align='left' dir='ltr'>%1</td>"
                      "<td align='right' dir='rtl'>%2</td>"
                      "</tr></table>"
                      ).arg(toPersianNumbers(result), taRtlText);

    if(calendar.getAcceptButtonClicked())
    {
        // ارسال تاریخ و نام دکمه به ui
        if(objectName()=="uStartDatePushButton")
        {
            emit customButtonClickSignal(objectName(),result,startCombined);
        }
        else if(objectName()=="uEndDatePushButton")
        {

            emit customButtonClickSignal(objectName(),result,endCombined);
        }
        else
        {
            qDebug() << "Wrong Button Name.";
        }
    }
}

QString JCalendarButton::toPersianNumbers(const QString &input) // تبدیل اعداد به فارسی
{
    QString result;
    for (QChar c : input) {
        if (c.isDigit()) {
            ushort digit = c.digitValue();
            // یونیکد ارقام فارسی از ۰ (۰x06F0) شروع می‌شود
            result.append(QChar(0x06F0 + digit));
        } else {
            result.append(c); // بقیه کاراکترها (مثل ':' یا '-' و ' ') را بدون تغییر اضافه کن
        }
    }
    return result;
}


QString JCalendarButton::getCurrentDateString() const
{
    return mCurrentDateString;
}

void JCalendarButton::setCurrentDateString(const QString &CurrentDateStringInp)
{
    mCurrentDateString = CurrentDateStringInp;
}

