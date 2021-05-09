#include "powerusrmodifypasswd.h"
#include "ui_powerusrmodifypasswd.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

powerusrmodifypasswd::powerusrmodifypasswd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::powerusrmodifypasswd)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

powerusrmodifypasswd::~powerusrmodifypasswd()
{
    delete ui;
}
#if 0
void powerusrmodifypasswd::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Down)
    {
        currentFocus++;
        if(currentFocus > MODIFYFOCUSONPWDAGAIN)
            currentFocus = MODIFYFOCUSONUSR;
        updateDisplayUIoperate();

    }
    else if(e->key() == Qt::Key_Up)
    {
        currentFocus--;
        if(currentFocus < MODIFYFOCUSONUSR)
            currentFocus = MODIFYFOCUSONPWDAGAIN;
        updateDisplayUIoperate();

    }
    else if(e->key() == Qt::Key_Left)
    {
        keypressedflag[KEYVALUELEFT] = KEYPRESSED;
    }
    else if(e->key() == Qt::Key_Return)
    {
        enterkeypressprocess();
    }
    else if(e->key() == Qt::Key_Escape)
    {
        this->hide();
    }
//    else if(e->key() == Qt::Key_F2)
//    {
//        qDebug()<<"F2 pressed";
//        this->hide();
//      //  emit usrpasswdmodifysignal();
//    }
 //   else if(e->key() == Qt::Key_F1)
 //   {
//        QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("是否退出"));
//        QPushButton *buttonY = msgbox.addButton(tr("是"), QMessageBox::RejectRole);
//        QPushButton *buttonN = msgbox.addButton(tr("否"), QMessageBox::AcceptRole);
//        buttonN->setFocus();
//        msgbox.exec();

//        if (msgbox.clickedButton() == buttonY)
//        {
//            usrlogoutprocess();
//            this->hide();
//            emit usrlogoutsignal();
//        }
 //   }
    else if(e->key() == Qt::Key_0)
    {
        if(currentFocus == MODIFYFOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE0] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONOLDPWD)
        {
          //  qDebug()<<"old pwd 0";
            if(pwdoldstr.length() < MAX_BITS_PWD)
                keypressedflag[KEYVALUE0] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONPWD)
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE0] = KEYPRESSED;
            }
        }
        else
        {
            if(pwd2str.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE0] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_1)
    {
        if(currentFocus == MODIFYFOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE1] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONOLDPWD)
        {
            if(pwdoldstr.length() < MAX_BITS_PWD)
                keypressedflag[KEYVALUE1] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONPWD)
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE1] = KEYPRESSED;
            }
        }
        else
        {
            if(pwd2str.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE1] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_2)
    {
        if(currentFocus == MODIFYFOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE2] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONOLDPWD)
        {
            if(pwdoldstr.length() < MAX_BITS_PWD)
                keypressedflag[KEYVALUE2] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONPWD)
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE2] = KEYPRESSED;
            }
        }
        else
        {
            if(pwd2str.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE2] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_3)
    {
        if(currentFocus == MODIFYFOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE3] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONOLDPWD)
        {
            if(pwdoldstr.length() < MAX_BITS_PWD)
                keypressedflag[KEYVALUE3] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONPWD)
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE3] = KEYPRESSED;
            }
        }
        else
        {
            if(pwd2str.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE3] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_4)
    {
        if(currentFocus == MODIFYFOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE4] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONOLDPWD)
        {
            if(pwdoldstr.length() < MAX_BITS_PWD)
                keypressedflag[KEYVALUE4] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONPWD)
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE4] = KEYPRESSED;
            }
        }
        else
        {
            if(pwd2str.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE4] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_5)
    {
        if(currentFocus == MODIFYFOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE5] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONOLDPWD)
        {
            if(pwdoldstr.length() < MAX_BITS_PWD)
                keypressedflag[KEYVALUE5] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONPWD)
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE5] = KEYPRESSED;
            }
        }
        else
        {
            if(pwd2str.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE5] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_6)
    {
        if(currentFocus == MODIFYFOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE6] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONOLDPWD)
        {
            if(pwdoldstr.length() < MAX_BITS_PWD)
                keypressedflag[KEYVALUE6] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONPWD)
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE6] = KEYPRESSED;
            }
        }
        else
        {
            if(pwd2str.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE6] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_7)
    {
        if(currentFocus == MODIFYFOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE7] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONOLDPWD)
        {
            if(pwdoldstr.length() < MAX_BITS_PWD)
                keypressedflag[KEYVALUE7] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONPWD)
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE7] = KEYPRESSED;
            }
        }
        else
        {
            if(pwd2str.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE7] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_8)
    {
        if(currentFocus == MODIFYFOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE8] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONOLDPWD)
        {
            if(pwdoldstr.length() < MAX_BITS_PWD)
                keypressedflag[KEYVALUE8] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONPWD)
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE8] = KEYPRESSED;
            }
        }
        else
        {
            if(pwd2str.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE8] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_9)
    {
        if(currentFocus == MODIFYFOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE9] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONOLDPWD)
        {
            if(pwdoldstr.length() < MAX_BITS_PWD)
                keypressedflag[KEYVALUE9] = KEYPRESSED;
        }
        else if(currentFocus == MODIFYFOCUSONPWD)
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE9] = KEYPRESSED;
            }
        }
        else
        {
            if(pwd2str.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE9] = KEYPRESSED;
            }
        }
    }
}


void powerusrmodifypasswd::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Left)
    {
         if(keypressedflag[KEYVALUELEFT] == KEYPRESSED)
         {
             keypressedflag[KEYVALUELEFT] = KEYRELEASED;
             if(currentFocus == MODIFYFOCUSONUSR) //FOCUSONUSR = 0
             {
                  if(usrstr.length() > 0)
                  {
                       usrstr.chop(1);
                       ui->label_usr->setText(usrstr);
                       if(usrstr.length() == MAX_BITS_USR)
                           ui->label_usrtip->setStyleSheet("color: rgb(0, 255, 0);");
                       else
                           ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                      // getaccountauthority(usrstr);
                       checkusrexist(usrstr);
                  }
             }
             else if(currentFocus == MODIFYFOCUSONOLDPWD)
             {
                 if(pwdoldstr.length() > 0)
                 {
                        pwdoldstr.chop(1);
                        pwdoldstrshow.chop(1);

                        if(pwdoldstr.length() == MAX_BITS_PWD)
                            ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 255, 0);");
                        else
                            ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");

                        ui->label_oldpwd->setText(pwdoldstrshow);
                 }
             }
             else if(currentFocus == MODIFYFOCUSONPWD)
             {
                // ui->label_tip2->clear();
                 if(pwdstr.length() > 0)
                 {
                        pwdstr.chop(1);
                        pwdstrshow.chop(1);

                        if(pwdstr.length() == MAX_BITS_PWD)
                            ui->label_pwdtip->setStyleSheet("color: rgb(0, 255, 0);");
                        else
                            ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");

                        ui->label_pwd->setText(pwdstrshow);

                        if(QString::compare(pwdstr,pwd2str) != 0)
                        {
                            ui->label_tip->setText(QString(tr("两次密码输入不同")));
                            ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                        }
                        else
                            ui->label_tip->clear();
                 }
             }
             else
             {
                 if(pwd2str.length() > 0)
                 {
                        pwd2str.chop(1);
                        pwd2strshow.chop(1);

                        if(pwd2str.length() == MAX_BITS_PWD)
                            ui->label_pwd2tip->setStyleSheet("color: rgb(0, 255, 0);");
                        else
                            ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");

                        ui->label_pwd2->setText(pwd2strshow);

                        if(QString::compare(pwdstr,pwd2str) != 0)
                        {
                            ui->label_tip->setText(QString(tr("两次密码输入不同")));
                            ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                        }
                        else
                            ui->label_tip->clear();
                 }
             }
         }
    }
    if(e->key() == Qt::Key_0)
    {
        if(keypressedflag[KEYVALUE0] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE0] = KEYRELEASED;
            if(currentFocus == MODIFYFOCUSONUSR)
            {
                usrstr.append("0");
                ui->label_usr->setText(usrstr);
               // getaccountauthority(usrstr);
                checkusrexist(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else if(currentFocus == MODIFYFOCUSONOLDPWD)
            {

              //  qDebug()<<"MODIFYFOCUSONOLDPWD=======";
                    pwdoldstr.append("0");
                    pwdoldstrshow.append('*');

                    if(pwdoldstr.length() == MAX_BITS_PWD)
                        ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                    else
                        ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                    ui->label_oldpwd->setText(pwdoldstrshow);

            }
            else if(currentFocus == MODIFYFOCUSONPWD)
            {
                pwdstr.append("0");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd->setText(pwdstrshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
            else
            {
                pwd2str.append("0");
                pwd2strshow.append('*');

                if(pwd2str.length() == MAX_BITS_PWD)
                    ui->label_pwd2tip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd2->setText(pwd2strshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
        }
    }
    else if(e->key() == Qt::Key_1)
    {
        if(keypressedflag[KEYVALUE1] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE1] = KEYRELEASED;
            if(currentFocus == MODIFYFOCUSONUSR)
            {
                usrstr.append("1");
                ui->label_usr->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
              //  getaccountauthority(usrstr);
                checkusrexist(usrstr);
            }
            else if(currentFocus == MODIFYFOCUSONOLDPWD)
            {
                pwdoldstr.append("1");
                pwdoldstrshow.append('*');

                if(pwdoldstr.length() == MAX_BITS_PWD)
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_oldpwd->setText(pwdoldstrshow);
            }
            else if(currentFocus == MODIFYFOCUSONPWD)
            {
                pwdstr.append("1");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd->setText(pwdstrshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
            else
            {
                pwd2str.append("1");
                pwd2strshow.append('*');

                if(pwd2str.length() == MAX_BITS_PWD)
                    ui->label_pwd2tip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd2->setText(pwd2strshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
        }
    }
    else if(e->key() == Qt::Key_2)
    {
        if(keypressedflag[KEYVALUE2] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE2] = KEYRELEASED;
            if(currentFocus == MODIFYFOCUSONUSR)
            {
                usrstr.append("2");
                ui->label_usr->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
              //  getaccountauthority(usrstr);
                checkusrexist(usrstr);
            }
            else if(currentFocus == MODIFYFOCUSONOLDPWD)
            {
                pwdoldstr.append("2");
                pwdoldstrshow.append('*');

                if(pwdoldstr.length() == MAX_BITS_PWD)
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_oldpwd->setText(pwdoldstrshow);
            }
            else if(currentFocus == MODIFYFOCUSONPWD)
            {
                pwdstr.append("2");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd->setText(pwdstrshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
            else
            {
                pwd2str.append("2");
                pwd2strshow.append('*');

                if(pwd2str.length() == MAX_BITS_PWD)
                    ui->label_pwd2tip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd2->setText(pwd2strshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
        }
    }
    else if(e->key() == Qt::Key_3)
    {
        if(keypressedflag[KEYVALUE3] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE3] = KEYRELEASED;
            if(currentFocus == MODIFYFOCUSONUSR)
            {
                usrstr.append("3");
                ui->label_usr->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
              //  getaccountauthority(usrstr);
                checkusrexist(usrstr);
            }
            else if(currentFocus == MODIFYFOCUSONOLDPWD)
            {
                pwdoldstr.append("3");
                pwdoldstrshow.append('*');

                if(pwdoldstr.length() == MAX_BITS_PWD)
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_oldpwd->setText(pwdoldstrshow);
            }
            else if(currentFocus == MODIFYFOCUSONPWD)
            {
                pwdstr.append("3");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd->setText(pwdstrshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
            else
            {
                pwd2str.append("3");
                pwd2strshow.append('*');

                if(pwd2str.length() == MAX_BITS_PWD)
                    ui->label_pwd2tip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd2->setText(pwd2strshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
        }
    }
    else if(e->key() == Qt::Key_4)
    {
        if(keypressedflag[KEYVALUE4] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE4] = KEYRELEASED;
            if(currentFocus == MODIFYFOCUSONUSR)
            {
                usrstr.append("4");
                ui->label_usr->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
             //   getaccountauthority(usrstr);
                checkusrexist(usrstr);
            }
            else if(currentFocus == MODIFYFOCUSONOLDPWD)
            {
                pwdoldstr.append("4");
                pwdoldstrshow.append('*');

                if(pwdoldstr.length() == MAX_BITS_PWD)
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_oldpwd->setText(pwdoldstrshow);
            }
            else if(currentFocus == MODIFYFOCUSONPWD)
            {
                pwdstr.append("4");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd->setText(pwdstrshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
            else
            {
                pwd2str.append("4");
                pwd2strshow.append('*');

                if(pwd2str.length() == MAX_BITS_PWD)
                    ui->label_pwd2tip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd2->setText(pwd2strshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
        }
    }
    else if(e->key() == Qt::Key_5)
    {
        if(keypressedflag[KEYVALUE5] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE5] = KEYRELEASED;
            if(currentFocus == MODIFYFOCUSONUSR)
            {
                usrstr.append("5");
                ui->label_usr->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
               // getaccountauthority(usrstr);
                checkusrexist(usrstr);
            }
            else if(currentFocus == MODIFYFOCUSONOLDPWD)
            {
                pwdoldstr.append("5");
                pwdoldstrshow.append('*');

                if(pwdoldstr.length() == MAX_BITS_PWD)
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_oldpwd->setText(pwdoldstrshow);
            }
            else if(currentFocus == MODIFYFOCUSONPWD)
            {
                pwdstr.append("5");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd->setText(pwdstrshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
            else
            {
                pwd2str.append("5");
                pwd2strshow.append('*');

                if(pwd2str.length() == MAX_BITS_PWD)
                    ui->label_pwd2tip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd2->setText(pwd2strshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
        }
    }
    else if(e->key() == Qt::Key_6)
    {
        if(keypressedflag[KEYVALUE6] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE6] = KEYRELEASED;
            if(currentFocus == MODIFYFOCUSONUSR)
            {
                usrstr.append("6");
                ui->label_usr->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
              //  getaccountauthority(usrstr);
                checkusrexist(usrstr);
            }
            else if(currentFocus == MODIFYFOCUSONOLDPWD)
            {
                pwdoldstr.append("6");
                pwdoldstrshow.append('*');

                if(pwdoldstr.length() == MAX_BITS_PWD)
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_oldpwd->setText(pwdoldstrshow);
            }
            else if(currentFocus == MODIFYFOCUSONPWD)
            {
                pwdstr.append("6");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd->setText(pwdstrshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
            else
            {
                pwd2str.append("6");
                pwd2strshow.append('*');

                if(pwd2str.length() == MAX_BITS_PWD)
                    ui->label_pwd2tip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd2->setText(pwd2strshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
        }
    }
    else if(e->key() == Qt::Key_7)
    {
        if(keypressedflag[KEYVALUE7] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE7] = KEYRELEASED;
            if(currentFocus == MODIFYFOCUSONUSR)
            {
                usrstr.append("7");
                ui->label_usr->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
               // getaccountauthority(usrstr);
                checkusrexist(usrstr);
            }
            else if(currentFocus == MODIFYFOCUSONOLDPWD)
            {
                pwdoldstr.append("7");
                pwdoldstrshow.append('*');

                if(pwdoldstr.length() == MAX_BITS_PWD)
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_oldpwd->setText(pwdoldstrshow);
            }
            else if(currentFocus == MODIFYFOCUSONPWD)
            {
                pwdstr.append("7");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd->setText(pwdstrshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
            else
            {
                pwd2str.append("7");
                pwd2strshow.append('*');

                if(pwd2str.length() == MAX_BITS_PWD)
                    ui->label_pwd2tip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd2->setText(pwd2strshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
        }
    }
    else if(e->key() == Qt::Key_8)
    {
        if(keypressedflag[KEYVALUE8] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE8] = KEYRELEASED;
            if(currentFocus == MODIFYFOCUSONUSR)
            {
                usrstr.append("8");
                ui->label_usr->setText(usrstr);

                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
              //  getaccountauthority(usrstr);
                checkusrexist(usrstr);
            }
            else if(currentFocus == MODIFYFOCUSONOLDPWD)
            {
                pwdoldstr.append("8");
                pwdoldstrshow.append('*');

                if(pwdoldstr.length() == MAX_BITS_PWD)
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_oldpwd->setText(pwdoldstrshow);
            }
            else if(currentFocus == MODIFYFOCUSONPWD)
            {
                pwdstr.append("8");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd->setText(pwdstrshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
            else
            {
                pwd2str.append("8");
                pwd2strshow.append('*');

                if(pwd2str.length() == MAX_BITS_PWD)
                    ui->label_pwd2tip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd2->setText(pwd2strshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
        }
    }
    else if(e->key() == Qt::Key_9)
    {
        if(keypressedflag[KEYVALUE9] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE9] = KEYRELEASED;
            if(currentFocus == MODIFYFOCUSONUSR)
            {
                usrstr.append("9");
                ui->label_usr->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
             //   getaccountauthority(usrstr);
                checkusrexist(usrstr);
            }
            else if(currentFocus == MODIFYFOCUSONOLDPWD)
            {
                pwdoldstr.append("9");
                pwdoldstrshow.append('*');

                if(pwdoldstr.length() == MAX_BITS_PWD)
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_oldpwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_oldpwd->setText(pwdoldstrshow);
            }
            else if(currentFocus == MODIFYFOCUSONPWD)
            {
                pwdstr.append("9");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd->setText(pwdstrshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
            else
            {
                pwd2str.append("9");
                pwd2strshow.append('*');

                if(pwd2str.length() == MAX_BITS_PWD)
                    ui->label_pwd2tip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwd2tip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_pwd2->setText(pwd2strshow);

                if(QString::compare(pwdstr,pwd2str) != 0)
                {
                    ui->label_tip->setText(QString(tr("两次密码输入不同")));
                    ui->label_tip->setStyleSheet("color: rgb(255, 0, 0);");
                }
                else
                    ui->label_tip->clear();
            }
        }
    }
}
void powerusrmodifypasswd::updateDisplayUIoperate()
{
    switch(currentFocus)
    {
        case MODIFYFOCUSONUSR:
             ui->label_usr->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(100, 150, 255);");
             ui->label_oldpwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             ui->label_pwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             ui->label_pwd2->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             break;
        case MODIFYFOCUSONOLDPWD:
             ui->label_usr->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             ui->label_oldpwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(100, 150, 255);");
             ui->label_pwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             ui->label_pwd2->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             break;
        case MODIFYFOCUSONPWD:
             ui->label_usr->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             ui->label_oldpwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             ui->label_pwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(100, 150, 255);");
             ui->label_pwd2->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             break;
        case MODIFYFOCUSONPWDAGAIN:
        default:
             ui->label_usr->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             ui->label_oldpwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             ui->label_pwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
             ui->label_pwd2->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(100, 150, 255);");
             break;
    }
}
void powerusrmodifypasswd::checkusrexist(QString usrname)
{
    currentAuth = 0;
    if(usrname.length() < MAX_BITS_USR)
    {
         ui->label_nametip->setText(tr("用户名无效长度"));
    }
    else
    {
        int namenum = usrname.toInt();
        if(namenum == pusrlistdata->adminlvl.name)
        {
            ui->label_nametip->setText(tr("管理员")); // modify admin
            currentAuth = LVLMANAGE;
            currentname = namenum;
        }
        else
        {
            for(int i=0;i<pusrlistdata->engineerlvl.count();i++) // modify engineer
            {
                if(pusrlistdata->engineerlvl.at(i).name == namenum)
                {
                    ui->label_nametip->setText(tr("工程师"));
                    currentAuth =LVLENGINEER;
                    currentname = namenum;
                }
            }

            for(int i=0;i<pusrlistdata->operaterlvl.count();i++)   //modify operater
            {
                if(pusrlistdata->operaterlvl.at(i).name == namenum)
                {
                    currentname = namenum;
                    ui->label_nametip->setText(tr("操作员"));
                    currentAuth = LVLOPERATOR;
                }
            }
        }
        if(currentAuth == 0)
            ui->label_nametip->setText(tr("用户名不存在"));
    }
}

void powerusrmodifypasswd::EnterProcess()
{
    currentFocus = FOCUSONUSR;
    updateDisplayUIoperate();

    memset(keypressedflag,0x00,sizeof(int)*11);

   // usrinfo singleusrinfo;
    usrstr.clear();
    pwdstr.clear();
    pwdstrshow.clear();
    pwd2str.clear();
    pwd2strshow.clear();

    pwdoldstr.clear();
    pwdoldstrshow.clear();

    currentAuth = 0;
    currentname = 0;

    ui->label_usr->clear();
    ui->label_oldpwd->clear();
    ui->label_pwd->clear();
    ui->label_pwd2->clear();
}

void powerusrmodifypasswd::enterkeypressprocess()
{
    int usrNum = -1;
    qDebug()<<"pwdoldstr = "<<pwdoldstr;

    if(currentAuth == 0)
    {
        QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("用户名不存在"));
        QPushButton *buttonY = msgbox.addButton(tr("是"), QMessageBox::YesRole);
        buttonY->setFocus();
        msgbox.exec();
    }
    else
    {
        usrNum = usrstr.toInt();

        if(pwdoldstr.length() < MAX_BITS_PWD)
        {
            QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("原密码不正确1"));
            QPushButton *buttonY = msgbox.addButton(tr("是"), QMessageBox::YesRole);
            buttonY->setFocus();
            msgbox.exec();
            return;
        }
        else
        {
            rightpasswd = -1;
            if(currentAuth == LVLMANAGE)
            {
                qDebug()<<"rightpwd="<<rightpasswd;
                rightpasswd = pusrlistdata->adminlvl.passwd;
            }
            else if(currentAuth == LVLENGINEER)
            {
                for(int i=0;i<pusrlistdata->engineerlvl.count();i++) //
                {
                    if(pusrlistdata->engineerlvl.at(i).name == usrNum)
                    {
                        rightpasswd = pusrlistdata->engineerlvl.at(i).passwd;
                    }
                }
            }
            else
            {
                for(int i=0;i<pusrlistdata->operaterlvl.count();i++)   //modify operater
                {
                    if(pusrlistdata->operaterlvl.at(i).name == usrNum)
                    {
                       rightpasswd = pusrlistdata->operaterlvl.at(i).passwd;
                    }
                }
            }

            if(rightpasswd != -1)
            {
                 if(rightpasswd != pwdoldstr.toInt())
                 {
                     QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("原密码不正确"));
                     QPushButton *buttonY = msgbox.addButton(tr("是"), QMessageBox::YesRole);
                     buttonY->setFocus();
                     msgbox.exec();
                     return;
                 }
                 else
                 {
                     if((QString::compare(pwdstr,pwd2str) == 0)&&(pwdstr.length() == MAX_BITS_PWD))
                     {
                         int passwdNum = pwdstr.toInt();
                         if(currentAuth == LVLMANAGE)
                         {
                             pusrlistdata->adminlvl.passwd = passwdNum;
                             emit modifypasswdsignal();
                         }
                         else if(currentAuth == LVLENGINEER)
                         {
                             for(int i=0;i<pusrlistdata->engineerlvl.count();i++) // modify engineer
                             {
                                 if(pusrlistdata->engineerlvl.at(i).name == usrNum)
                                 {
                                     singleusrinfo.name = usrNum;
                                     singleusrinfo.level = pusrlistdata->engineerlvl.at(i).level;
                                     singleusrinfo.passwd = pusrlistdata->engineerlvl.at(i).passwd;

                                     pusrlistdata->engineerlvl.removeAt(i);

                                     singleusrinfo.passwd = pwdstr.toInt();
                                     pusrlistdata->engineerlvl.insert(i,singleusrinfo);

                                     emit modifypasswdsignal();
                                 }
                             }

                         }
                         else
                         {
                             for(int i=0;i<pusrlistdata->operaterlvl.count();i++)   //modify operater
                             {
                                 if(pusrlistdata->operaterlvl.at(i).name == usrNum)
                                 {
                                     singleusrinfo.name = usrNum;
                                     singleusrinfo.level = pusrlistdata->operaterlvl.at(i).level;
                                     singleusrinfo.passwd = pusrlistdata->operaterlvl.at(i).passwd;

                                     pusrlistdata->operaterlvl.removeAt(i);

                                     singleusrinfo.passwd = pwdstr.toInt();
                                     pusrlistdata->operaterlvl.insert(i,singleusrinfo);

                                     emit modifypasswdsignal();
                                 }
                             }
                         }
                         QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("密码修改成功"));
                         QPushButton *buttonY = msgbox.addButton(tr("是"), QMessageBox::YesRole);
                         buttonY->setFocus();
                         msgbox.exec();


                         this->hide();
                     }
                 }
            }
        }


//        if((QString::compare(pwdstr,pwd2str) == 0)&&(pwdstr.length() == MAX_BITS_PWD))
//        {
//            int passwdNum = pwdstr.toInt();
//            if(currentAuth == LVLMANAGE)
//            {
//                pusrlistdata->adminlvl.passwd = passwdNum;
//            }
//            else if(currentAuth == LVLENGINEER)
//            {
//                for(int i=0;i<pusrlistdata->engineerlvl.count();i++) // modify engineer
//                {
//                    if(pusrlistdata->engineerlvl.at(i).name == passwdNum)
//                    {
//                       // ownpusrlistdata.engineerlvl.removeAt(i);

//                       // ownpusrlistdata.engineerlvl.insert(i,singleusrinfo);
//                       // qDebug()<<"ownpusrlistdata"<<ownpusrlistdata.engineerlvl.at(0).name<<ownpusrlistdata.engineerlvl.at(0).passwd;
//                       // ismodified = 1;

//                    }
//                }

//            }
//            else
//            {
//                for(int i=0;i<pusrlistdata->operaterlvl.count();i++)   //modify operater
//                {
//                    if(pusrlistdata->operaterlvl.at(i).name == passwdNum)
//                    {
//                        currentname = passwdNum;
//                        ui->label_nametip->setText(tr("操作员"));
//                        currentAuth = LVLOPERATOR;
//                    }
//                }
//            }
//        }
    }
}
#endif
