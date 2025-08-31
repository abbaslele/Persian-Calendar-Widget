#ifndef JCALENDAR_H
#define JCALENDAR_H

#include <QWidget>
#include <QDialog>

namespace Ui { class JCalendar; }
class QPushButton;
class QLabel;
class QRadioButton;

class JCalendar : public QWidget
{
    Q_OBJECT

public:
    explicit JCalendar(QWidget *i_parent = 0);
    ~JCalendar();

    struct Date
    {
        int Year;
        int Month;
        int Day;
        QString toString();
        QString toStringFull();
        QDate toQDate();
        bool operator ==( Date &i_other );

        static Date fromQDate( const QDate &i_qDate );
        static Date fromString( const QString &i_date );
        static Date fromString( const QString &i_date, const QString &i_format );
    };

    QDialog *dialog=nullptr;

    // Static methods (unchanged)
    static bool isLeap(int i_year);
    static bool isValid(Date &i_date );
    static bool isValid(const QString &i_date);
    static Date toJalali( Date &i_date );
    static Date toGregorian( Date &i_date );
    static int getDayCount( int i_year );
    static int getDayCount( int i_year, int i_moon );
    static int sumOfDaysJalali(Date &i_date);
    static int sumOfDaysGregorian( Date &i_date );
    static Date today();
    static int getDayOfWeek( Date &i_date );
    static QString getDayOfWeekName( Date &i_date );
    static QString getDayOfWeekNameSmall( Date &i_date );
    static int getDiffInDay( Date &i_from, Date &i_to );

    Date &getCurrentDate();
    Date &getStartDate();
    Date &getEndDate();
    bool getAcceptButtonClicked() const;
    void setAcceptButtonClicked(bool AcceptButtonClickedInp);
    bool getCancelButtonClicked() const;
    void setCancelButtonClicked(bool CancelButtonClickedInp);

    QString toPersianNumbers(const QString &input);

signals:
    void dateChanged( QString date );
    void dateRangeChanged( QString startDate, QString endDate );

public slots:
    void setDate(Date i_date );

private slots:
    void on_moon_currentIndexChanged(int i_index);
    void on_year_valueChanged(int i_value);
    void on_today_clicked();
    void bClicked( bool i_checked );
    void on_TextDate_editingFinished();
    void on_uCancel_PushButton_clicked();
    void on_uAccept_PushButton_clicked();
    void on_uSelectDay_RadioButton_toggled(bool checked);
    void on_uSelectRange_RadioButton_toggled(bool checked);

private:
    void reDecorate();
    void clearSelection();
    bool isInRange(int buttonIndex);

    int m_currentB;
    Ui::JCalendar *m_ui;
    QPushButton *m_b[ 42 ];
    int m_day[ 42 ];
    QLabel *m_w[ 6 ];
    Date m_currentDate;
    Date m_startDate;
    Date m_endDate;
    int mSetCounter=0;
    bool mAcceptButtonClicked=false;
    bool mCancelButtonClicked=false;
    bool mRangeSelectionMode=false;
    bool mFirstDateSelected=false;
    int mStartButtonIndex=-1;
    int mEndButtonIndex=-1;
};

#endif
