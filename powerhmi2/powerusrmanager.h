#ifndef POWERUSRMANAGER_H
#define POWERUSRMANAGER_H

#include <QWidget>
#include "DefineDb.h"
#include <QKeyEvent>
#include "powerusraccountaddmodify.h"

namespace Ui {
class powerusrmanager;
}

class powerusrmanager : public QWidget
{
    Q_OBJECT

public:
    explicit powerusrmanager(QWidget *parent = 0);
    ~powerusrmanager();
//    usrlist *pusrlistdata;
//    usrlist ownpusrlistdata;
//    usrinfo singleusrinfo;

    Deivce_DataBase *pDeviceDataBase;

    int ismodified = 0;

//    void displayusrinfo();
//    void processReturnkeyPressed();

//    powerusrAccountAddModify addmodifyUsrIns;
//signals:
//    void confirmsaveusrinfosignal();
public slots:

    //void addmodifyUsrInfoslot(usrinfo singleusrinfo,int addormodify);
//protected:
//    void keyPressEvent(QKeyEvent *pkey);

private:
    Ui::powerusrmanager *ui;
};

#endif // POWERUSRMANAGER_H
