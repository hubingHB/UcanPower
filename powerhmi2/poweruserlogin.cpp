#include "poweruserlogin.h"
#include "ui_poweruserlogin.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
poweruserlogin::poweruserlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::poweruserlogin)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    currentFocus = FOCUSONUSR;

    ui->label_usrtip->setText(QString("用户名长度为6位"));
    ui->label_pwdtip->setText(QString("密码长度为6位"));

   // memset(&singleusrinfo,0x00,sizeof(usrinfo));
   // connect(&loginvalidtimer,SIGNAL(timeout()),this,SLOT(validtimertimeoutslot()));
}

poweruserlogin::~poweruserlogin()
{
    delete ui;
}
#if 0
void poweruserlogin::keyPressEvent(QKeyEvent *e)
{
#if 1
    if(e->key() == Qt::Key_Down)
    {
        currentFocus++;
        if(currentFocus > FOCUSONPWD)
            currentFocus = FOCUSONUSR;
        updateDisplayUIoperate();

    }
    else if(e->key() == Qt::Key_Up)
    {
        currentFocus--;
        if(currentFocus < FOCUSONUSR)
            currentFocus = FOCUSONPWD;
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
    else if(e->key() == Qt::Key_F2)
    {
        qDebug()<<"F2 pressed";
        this->hide();
        emit usrpasswdmodifyDisplaysignal();
    }
    else if(e->key() == Qt::Key_F1)
    {
        if(psysStatus->islogin == LOGIN)
        {
            QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("是否退出"));
            QPushButton *buttonY = msgbox.addButton(tr("是"), QMessageBox::RejectRole);
            QPushButton *buttonN = msgbox.addButton(tr("否"), QMessageBox::AcceptRole);
            buttonN->setFocus();
            msgbox.exec();

            if (msgbox.clickedButton() == buttonY)
            {
                usrlogoutprocess();
                this->hide();
                emit usrlogoutsignal();
            }
        }
    }
    else if(e->key() == Qt::Key_0)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE0] = KEYPRESSED;
        }
        else
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE0] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_1)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
             {
                 keypressedflag[KEYVALUE1] = KEYPRESSED;
             }
        }
        else
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE1] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_2)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE2] = KEYPRESSED;
        }
        else
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE2] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_3)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE3] = KEYPRESSED;
        }
        else
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE3] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_4)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE4] = KEYPRESSED;
        }
        else
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE4] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_5)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE5] = KEYPRESSED;
        }
        else
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE5] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_6)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE6] = KEYPRESSED;
        }
        else
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE6] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_7)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE7] = KEYPRESSED;
        }
        else
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE7] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_8)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE8] = KEYPRESSED;
        }
        else
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE8] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_9)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < MAX_BITS_USR)
                 keypressedflag[KEYVALUE9] = KEYPRESSED;
        }
        else
        {
            if(pwdstr.length() < MAX_BITS_PWD)
            {
                keypressedflag[KEYVALUE9] = KEYPRESSED;
            }
        }
    }

#endif
}

void poweruserlogin::keyReleaseEvent(QKeyEvent *e)
{
#if 1
    if(e->key() == Qt::Key_Left)
    {
         if(keypressedflag[KEYVALUELEFT] == KEYPRESSED)
         {
             keypressedflag[KEYVALUELEFT] = KEYRELEASED;
             if(currentFocus == FOCUSONUSR) //FOCUSONUSR = 0
             {
                  if(usrstr.length() > 0)
                  {
                       usrstr.chop(1);
                       ui->label_user->setText(usrstr);
                       if(usrstr.length() == MAX_BITS_USR)
                           ui->label_usrtip->setStyleSheet("color: rgb(0, 255, 0);");
                       else
                           ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                       getaccountauthority(usrstr);
                  }
             }
             else
             {
                 ui->label_tip2->clear();
                 if(pwdstr.length() > 0)
                 {
                        pwdstr.chop(1);
                        pwdstrshow.chop(1);

                        if(pwdstr.length() == MAX_BITS_PWD)
                            ui->label_pwdtip->setStyleSheet("color: rgb(0, 255, 0);");
                        else
                            ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");

                        ui->label_passwd->setText(pwdstrshow);
                 }
             }
         }
    }
    if(e->key() == Qt::Key_0)
    {
        if(keypressedflag[KEYVALUE0] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE0] = KEYRELEASED;
            if(currentFocus == FOCUSONUSR)
            {
                usrstr.append("0");
                ui->label_user->setText(usrstr);
                getaccountauthority(usrstr);

                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("0");
                pwdstrshow.append('*');

                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_passwd->setText(pwdstrshow);
            }
        }
    }
    else if(e->key() == Qt::Key_1)
    {
        if(keypressedflag[KEYVALUE1] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE1] = KEYRELEASED;
            if(currentFocus == FOCUSONUSR)
            {
                usrstr.append("1");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                getaccountauthority(usrstr);
            }
            else
            {
                pwdstr.append("1");
                pwdstrshow.append('*');
                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_passwd->setText(pwdstrshow);
            }
        }
    }
    else if(e->key() == Qt::Key_2)
    {
        if(keypressedflag[KEYVALUE2] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE2] = KEYRELEASED;
            if(currentFocus == FOCUSONUSR)
            {
                usrstr.append("2");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                getaccountauthority(usrstr);
            }
            else
            {
                pwdstr.append("2");
                pwdstrshow.append("*");
                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_passwd->setText(pwdstrshow);
            }
        }
    }
    else if(e->key() == Qt::Key_3)
    {
        if(keypressedflag[KEYVALUE3] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE3] = KEYRELEASED;
            if(currentFocus == FOCUSONUSR)
            {
                usrstr.append("3");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                getaccountauthority(usrstr);
            }
            else
            {
                pwdstr.append("3");
                pwdstrshow.append("*");
                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_passwd->setText(pwdstrshow);
            }
        }
    }
    else if(e->key() == Qt::Key_4)
    {
        if(keypressedflag[KEYVALUE4] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE4] = KEYRELEASED;
            if(currentFocus == FOCUSONUSR)
            {
                usrstr.append("4");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                getaccountauthority(usrstr);
            }
            else
            {
                pwdstr.append("4");
                pwdstrshow.append("*");
                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_passwd->setText(pwdstrshow);
            }
        }
    }
    else if(e->key() == Qt::Key_5)
    {
        if(keypressedflag[KEYVALUE5] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE5] = KEYRELEASED;
            if(currentFocus == FOCUSONUSR)
            {
                usrstr.append("5");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                getaccountauthority(usrstr);
            }
            else
            {
                pwdstr.append("5");
                pwdstrshow.append("*");
                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_passwd->setText(pwdstrshow);
            }
        }
    }
    else if(e->key() == Qt::Key_6)
    {
        if(keypressedflag[KEYVALUE6] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE6] = KEYRELEASED;
            if(currentFocus == FOCUSONUSR)
            {
                usrstr.append("6");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                getaccountauthority(usrstr);
            }
            else
            {
                pwdstr.append("6");
                pwdstrshow.append("*");
                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_passwd->setText(pwdstrshow);
            }
        }
    }
    else if(e->key() == Qt::Key_7)
    {
        if(keypressedflag[KEYVALUE7] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE7] = KEYRELEASED;
            if(currentFocus == FOCUSONUSR)
            {
                usrstr.append("7");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                getaccountauthority(usrstr);
            }
            else
            {
                pwdstr.append("7");
                pwdstrshow.append("*");
                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_passwd->setText(pwdstrshow);
            }
        }
    }
    else if(e->key() == Qt::Key_8)
    {
        if(keypressedflag[KEYVALUE8] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE8] = KEYRELEASED;
            if(currentFocus == FOCUSONUSR)
            {
                usrstr.append("8");
                ui->label_user->setText(usrstr);

                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                getaccountauthority(usrstr);
            }
            else
            {
                pwdstr.append("8");
                pwdstrshow.append("*");
                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_passwd->setText(pwdstrshow);
            }
        }
    }
    else if(e->key() == Qt::Key_9)
    {
        if(keypressedflag[KEYVALUE9] == KEYPRESSED)
        {
            keypressedflag[KEYVALUE9] = KEYRELEASED;
            if(currentFocus == FOCUSONUSR)
            {
                usrstr.append("9");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == MAX_BITS_USR)
                    ui->label_usrtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                getaccountauthority(usrstr);
            }
            else
            {
                pwdstr.append("9");
                pwdstrshow.append("*");
                if(pwdstr.length() == MAX_BITS_PWD)
                    ui->label_pwdtip->setStyleSheet("color: rgb(0, 0, 0);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                ui->label_passwd->setText(pwdstrshow);
            }
        }
    }
 //   qDebug()<<usrstr<<pwdstr;
#endif
}

void poweruserlogin::usrlogoutprocess()
{
    usrstr.clear();
    pwdstr.clear();
    pwdstrshow.clear();

    currentFocus = FOCUSONUSR;
    memset(&singleusrinfo,0x00,sizeof(usrinfo));

    ui->label_user->clear();
    ui->label_passwd->clear();

    ui->label_loginflag->setStyleSheet("border-image: url(:/pic/loginout.png);");
    ui->label_nametip->setText(tr("无效用户名"));

    currentAuth = 0;
    currentname = 0;
    rightpasswd = 0;
    psysStatus->usrlevel = 0;
    psysStatus->usrname = 0;
    psysStatus->islogin = LOGOUT;


    ui->label_user->show();
    ui->label_passwd->show();
    ui->label_usroption->show();
    ui->label_pwdoption->show();

    ui->label_usrtip->show();
    ui->label_pwdtip->show();

    ui->label_logintip->hide();
    ui->label_logintip2->hide();
    ui->label_loginname->hide();
}

void poweruserlogin::getaccountauthority(QString name)
{

    if(name.length() < 6)
    {
        ui->label_nametip->setText(tr("无效用户名"));
        currentAuth = 0;
        psysStatus->usrlevel = 0;
    }
    else
    {
        int namenum = name.toInt();
        if(namenum == pusrlistdata->adminlvl.name)
        {
            ui->label_nametip->setText(tr("管理员"));
            currentAuth =1;
            psysStatus->usrlevel = LVLMANAGE;
            currentname = namenum;
            psysStatus->usrname = namenum;
            rightpasswd = pusrlistdata->adminlvl.passwd;
        }
        else
        {
            for(int i=0;i<pusrlistdata->engineerlvl.count();i++)
            {
                if(pusrlistdata->engineerlvl.at(i).name == namenum)
                {
                    ui->label_nametip->setText(tr("工程师"));
                    currentAuth =2;
                    psysStatus->usrlevel = LVLENGINEER;
                    currentname = namenum;
                    psysStatus->usrname = namenum;
                    rightpasswd = pusrlistdata->engineerlvl.at(i).passwd;
                }
            }

            for(int i=0;i<pusrlistdata->operaterlvl.count();i++)
            {
                if(pusrlistdata->operaterlvl.at(i).name == namenum)
                {
                    currentname = namenum;
                    psysStatus->usrname = namenum;
                    ui->label_nametip->setText(tr("操作员"));
                    psysStatus->usrlevel = LVLOPERATOR;
                    currentAuth = 3;
                    rightpasswd = pusrlistdata->operaterlvl.at(i).passwd;
                }
            }
        }
        if(currentAuth == 0)
            ui->label_nametip->setText(tr("无权限用户名"));
    }
}


void poweruserlogin::updateDisplayUIoperate()
{
    switch(currentFocus)
    {
    case FOCUSONUSR:
         ui->label_user->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(100, 150, 255);");
         ui->label_passwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
         break;
    case FOCUSONPWD:
         ui->label_user->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
         ui->label_passwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(100, 150, 255);");
         break;
    default:
         ui->label_user->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(100, 150, 255);");
         ui->label_passwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
         break;
    }
}

void poweruserlogin::enterkeypressprocess()
{
#if 1
   // if(islogin == 0)
    {
         if(usrstr.length() != 6)
         {
             ui->label_usrtip->setText(QString("用户名长度为6位"));
             return;
         }

         if(pwdstr.length() != 6)
         {
             ui->label_pwdtip->setText(QString("密码长度为6位"));
             return;
         }

         if((currentname == usrstr.toInt())&&(rightpasswd == pwdstr.toInt()))
         {
              psysStatus->islogin = LOGIN;
              emit usrloginsignal();

              if(currentname == 999999)//admin account
              {
                  this->hide();
                  emit managerloginsignal();
              }
              this->hide();
              displayusrlogin();
              ui->label_tip2->clear();
              QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("登录成功"));
              QPushButton *buttonY = msgbox.addButton(tr("确定"), QMessageBox::RejectRole);
              buttonY->setFocus();
              msgbox.exec();
         }
         else if(currentname != usrstr.toInt())
         {
              ui->label_tip2->setText(QString("用户名不匹配"));
         }
         else
         {
             ui->label_tip2->setText(QString("密码不正确"));
         }
     }
//     else
//     {
//          this->hide();
//          emit MsgSendSwitchOperationSignal(usrdeviceLogicAddr,usrActOperateType,usrOperateDevice);
//          validtimestart();//重新开始计时
//     }
#endif
}

void poweruserlogin::validtimestart()
{
     if(loginvalidtimer.isActive())
         loginvalidtimer.stop();
     loginvalidtimer.start(600000);//10分钟
}
void poweruserlogin::validtimestop()
{
    if(loginvalidtimer.isActive())
        loginvalidtimer.stop();
}

void poweruserlogin::validtimertimeoutslot()
{
#if 0
    islogin = 0;
    validtimestop();

    ui->label_loginflag->setStyleSheet("border-image: url(:/new/picture/resource/loginout.png);");

    user_info.level = 0;
    usrstr.clear();
    pwdstr.clear();
    pwdstrshow.clear();

    ui->label_user->clear();
    ui->label_passwd->clear();
    ui->label_tip->clear();

    ui->label_user->show();
    ui->label_passwd->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_info->hide();
#endif
}

void poweruserlogin::displayusrlogin()
{
   ui->label_loginflag->setStyleSheet("border-image: url(:/pic/loginin.png);");

   ui->label_user->hide();
   ui->label_passwd->hide();
   ui->label_usroption->hide();
   ui->label_pwdoption->hide();

   ui->label_usrtip->hide();
   ui->label_pwdtip->hide();

   ui->label_logintip->show();
   ui->label_loginname->show();

   ui->label_loginname->setText(QString(tr("工号"))+QString::number(psysStatus->usrname)+QString(tr("已登录")));
   if(psysStatus->usrlevel == LVLMANAGE)
       ui->label_logintip2->show();
   else
       ui->label_logintip2->hide();
}
void poweruserlogin::loginInit()
{
    if(psysStatus->islogin == LOGOUT)
    {
        usrstr.clear();
        pwdstr.clear();
        pwdstrshow.clear();

        currentFocus = FOCUSONUSR;
        updateDisplayUIoperate();
        memset(&singleusrinfo,0x00,sizeof(usrinfo));

        ui->label_user->clear();
        ui->label_passwd->clear();

        ui->label_loginflag->setStyleSheet("border-image: url(:/pic/loginout.png);");
        ui->label_nametip->setText(tr("无效用户名"));

        currentAuth = 0;
        currentname = 0;
        rightpasswd = 0;
        psysStatus->usrlevel = 0;
        psysStatus->usrname = 0;

        ui->label_user->show();
        ui->label_passwd->show();
        ui->label_usroption->show();
        ui->label_pwdoption->show();

        ui->label_usrtip->show();
        ui->label_pwdtip->show();

        ui->label_logintip->hide();
        ui->label_logintip2->hide();
        ui->label_loginname->hide();
     }
     else
     {
        ui->label_user->hide();
        ui->label_passwd->hide();
        ui->label_usroption->hide();
        ui->label_pwdoption->hide();

        ui->label_usrtip->hide();
        ui->label_pwdtip->hide();

        ui->label_logintip->show();
        ui->label_loginname->show();
        if(psysStatus->usrlevel == LVLMANAGE)
            ui->label_logintip2->show();
        else
            ui->label_logintip2->hide();

     }
}
#endif
