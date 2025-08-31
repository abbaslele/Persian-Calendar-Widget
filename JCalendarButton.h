#ifndef JCALENDARBUTTON_H
#define JCALENDARBUTTON_H

#include <QPushButton>
#include <QTableWidget>
#include <QDialog>
#include <QtCore>
#include <QDate>
#include <QScrollBar>
#include <QTextBlock>

class JCalendarButton : public QPushButton
{
    Q_OBJECT

public:
    JCalendarButton(QWidget *parent = 0);

    QString getCurrentDateString() const;
    void setCurrentDateString(const QString &CurrentDateStringInp);

signals:
    void customButtonClickSignal(QString name, QString dateString, QString textString);


private slots:
    void buttonClicked();

private:
    QString mCurrentDateString;


    QString toPersianNumbers(const QString &input);
};

#endif
