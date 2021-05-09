#ifndef POWERUSRACCOUNTADDMODIFY_H
#define POWERUSRACCOUNTADDMODIFY_H

#include <QWidget>
#include "DefineDb.h"

#include <QKeyEvent>
namespace Ui {
class powerusrAccountAddModify;
}

class powerusrAccountAddModify : public QWidget
{
    Q_OBJECT

public:
    explicit powerusrAccountAddModify(QWidget *parent = 0);
    ~powerusrAccountAddModify();

//    usrlist *pusrlistdata;

//    usrinfo sUsrInfo;
    Deivce_DataBase *pDeviceDataBase;

    int addmodifyflag=0;

    int currentFocus;
    int keypressedflag[11];//

    QString usrstr;
    QString pwdstr;
    QString pwdstrshow;

//    void updateDisplayUIoperate();

    //void entryprocess(usrlist *plist,usrinfo singleusrinfo,int addormodify);

//    void enterkeypressprocess();

//    int checkdupusr();
//signals:
    //void addmodifyUsrInfosignal(usrinfo singleusrinfo,int addormodify);
//protected:
//    void keyPressEvent(QKeyEvent *e);
//    void keyReleaseEvent(QKeyEvent *e);

private:
    Ui::powerusrAccountAddModify *ui;
};

#endif // POWERUSRACCOUNTADDMODIFY_H
