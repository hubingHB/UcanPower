#ifndef POWERUSERLOGIN_H
#define POWERUSERLOGIN_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>

#include "DefineDb.h"



namespace Ui {
class poweruserlogin;
}

class poweruserlogin : public QWidget
{
    Q_OBJECT

public:
    explicit poweruserlogin(QWidget *parent = 0);
    ~poweruserlogin();

//    usrlist *pusrlistdata;

//    STsyscurStatus *psysStatus;

    Deivce_DataBase *pDeviceDataBase;

    int currentFocus;
    int keypressedflag[11];//

 //   usrinfo singleusrinfo;
    QString usrstr;
    QString pwdstr;
    QString pwdstrshow;
    int currentAuth = 0;
    int currentname = 0;
    int rightpasswd = 0;

    int isLogin = 0;

//    void validtimestart();
//    void validtimestop();

//    void updateDisplayUIoperate();
//    void enterkeypressprocess();

//    void getaccountauthority(QString name);

//    void displayusrlogin();

//    void usrlogoutprocess();

//    void loginInit();
//signals:
//    void usrloginsignal();
//    void usrlogoutsignal();

//    void managerloginsignal();

//    void usrpasswdmodifyDisplaysignal();

//public slots:
//    void validtimertimeoutslot();

//protected:
//    void keyPressEvent(QKeyEvent *pkey);
//    void keyReleaseEvent(QKeyEvent *pkey);

private:
    Ui::poweruserlogin *ui;
    QTimer loginvalidtimer;
};

#endif // POWERUSERLOGIN_H
