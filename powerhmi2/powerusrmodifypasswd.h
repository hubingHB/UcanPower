#ifndef POWERUSRMODIFYPASSWD_H
#define POWERUSRMODIFYPASSWD_H

#include <QWidget>
#include "DefineDb.h"
#include <QKeyEvent>




namespace Ui {
class powerusrmodifypasswd;
}

class powerusrmodifypasswd : public QWidget
{
    Q_OBJECT

public:
    explicit powerusrmodifypasswd(QWidget *parent = 0);
    ~powerusrmodifypasswd();

   // usrlist *pusrlistdata;

    Deivce_DataBase *pDeviceDataBase;

    int currentFocus;
    int keypressedflag[11];//

   // usrinfo singleusrinfo;
    QString usrstr;

    QString pwdoldstr;
    QString pwdoldstrshow;
    QString pwdstr;
    QString pwdstrshow;
    QString pwd2str;
    QString pwd2strshow;

    int currentAuth = 0;
    int currentname = 0;
    int rightpasswd = 0;

//    void updateDisplayUIoperate();

//    void checkusrexist(QString usrname);

//    void EnterProcess();

//    void enterkeypressprocess();
//signals:
//    void modifypasswdsignal();


//protected:
//    void keyPressEvent(QKeyEvent *e);
//    void keyReleaseEvent(QKeyEvent *e);

private:
    Ui::powerusrmodifypasswd *ui;
};

#endif // POWERUSRMODIFYPASSWD_H
