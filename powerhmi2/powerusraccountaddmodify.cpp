#include "powerusraccountaddmodify.h"
#include "ui_powerusraccountaddmodify.h"
#include <QMessageBox>
#include <QDebug>

powerusrAccountAddModify::powerusrAccountAddModify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::powerusrAccountAddModify)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    currentFocus = FOCUSONUSR;
    ui->label_usrtip->setText(QString(tr("用户名长度为6位")));
    ui->label_pwdtip->setText(QString(tr("密码长度在6位")));
//    updateDisplayUIoperate();

   // memset(&sUsrInfo,0x00,sizeof(usrinfo));
}

powerusrAccountAddModify::~powerusrAccountAddModify()
{
    delete ui;
}
#if 0
void powerusrAccountAddModify::entryprocess(usrlist *plist, usrinfo singleusrinfo, int addormodify)
{
    ui->label_info->clear();
    currentFocus = FOCUSONUSR;
    updateDisplayUIoperate();
    usrstr.clear();
    pwdstr.clear();
    pwdstrshow.clear();

    ui->label_user->clear();
    ui->label_passwd->clear();
    pusrlistdata = plist;
    memcpy(&sUsrInfo,&singleusrinfo,sizeof(usrinfo));

    memset(keypressedflag,0x00,sizeof(int)*11);
    addmodifyflag = addormodify;
    if(addmodifyflag == 1)//modify
    {
        if(sUsrInfo.level == 2)
            ui->label_title->setText("工程师账户密码修改");
        else
            ui->label_title->setText("操作员账户密码修改");
        ui->label_user->setText(QString::number(sUsrInfo.name));

        currentFocus = FOCUSONPWD;
        updateDisplayUIoperate();
    }
    else
    {
        if(sUsrInfo.level == 2)
            ui->label_title->setText("添加工程师账户");
        else
            ui->label_title->setText("添加操作员账户");
    }
}

void powerusrAccountAddModify::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Down)
    {
        ui->label_info->clear();
        currentFocus++;
        if(currentFocus > FOCUSONPWD)
            currentFocus = FOCUSONUSR;
        updateDisplayUIoperate();

    }
    else if(e->key() == Qt::Key_Up)
    {
        ui->label_info->clear();
        currentFocus--;
        if(currentFocus < FOCUSONUSR)
            currentFocus = FOCUSONPWD;
        updateDisplayUIoperate();
    }
    else if(e->key() == Qt::Key_Left)
    {

        ui->label_info->clear();
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
    else if(e->key() == Qt::Key_0)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < 6)
                 keypressedflag[KEYVALUE0] = KEYPRESSED;
        }
        else
        {
            if(pwdstr.length() < 6)
            {
                keypressedflag[KEYVALUE0] = KEYPRESSED;
            }
        }
    }
    else if(e->key() == Qt::Key_1)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < 6)
                 keypressedflag[1] = 1;
        }
        else
        {
            if(pwdstr.length() < 6)
            {
                keypressedflag[1] = 1;
            }
        }
    }
    else if(e->key() == Qt::Key_2)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < 6)
                 keypressedflag[2] = 1;
        }
        else
        {
            if(pwdstr.length() < 6)
            {
                keypressedflag[2] = 1;
            }
        }
    }
    else if(e->key() == Qt::Key_3)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < 6)
                 keypressedflag[3] = 1;
        }
        else
        {
            if(pwdstr.length() < 6)
            {
                keypressedflag[3] = 1;
            }
        }
    }
    else if(e->key() == Qt::Key_4)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < 6)
                 keypressedflag[4] = 1;
        }
        else
        {
            if(pwdstr.length() < 6)
            {
                keypressedflag[4] = 1;
            }
        }
    }
    else if(e->key() == Qt::Key_5)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < 6)
                keypressedflag[5] = 1;
        }
        else
        {
            if(pwdstr.length() < 6)
            {
                keypressedflag[5] = 1;
            }
        }
    }
    else if(e->key() == Qt::Key_6)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < 6)
                 keypressedflag[6] = 1;
        }
        else
        {
            if(pwdstr.length() < 6)
            {
                keypressedflag[6] = 1;
            }
        }
    }
    else if(e->key() == Qt::Key_7)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < 6)
                 keypressedflag[7] = 1;
        }
        else
        {
            if(pwdstr.length() < 6)
            {
                keypressedflag[7] = 1;
            }
        }
    }
    else if(e->key() == Qt::Key_8)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < 6)
                 keypressedflag[8] = 1;
        }
        else
        {
            if(pwdstr.length() < 6)
            {
                keypressedflag[8] = 1;
            }
        }
    }
    else if(e->key() == Qt::Key_9)
    {
        if(currentFocus == FOCUSONUSR)
        {
             if(usrstr.length() < 6)
                 keypressedflag[9] = 1;
        }
        else
        {
            if(pwdstr.length() < 6)
            {
                keypressedflag[9] = 1;
            }
        }
    }
}
void powerusrAccountAddModify::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Left)
    {
         if(keypressedflag[10] == 1)
         {
             keypressedflag[10] = 0;
             if(currentFocus == 0)
             {
                  if(usrstr.length() > 0)
                  {
                       usrstr.chop(1);
                       ui->label_user->setText(usrstr);
                       if(usrstr.length() == 6)
                           ui->label_usrtip->setStyleSheet("color: rgb(255, 255, 255);");
                       else
                           ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
                  }
             }
             else
             {
                 if(pwdstr.length() > 0)
                 {
                        pwdstr.chop(1);
                        pwdstrshow.chop(1);
                        ui->label_passwd->setText(pwdstr);

                        if(pwdstr.length() == 6)
                            ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                        else
                            ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
                 }
             }
         }
    }
    if(e->key() == Qt::Key_0)
    {
        if(keypressedflag[0] == 1)
        {
            keypressedflag[0] = 0;
            if(currentFocus == 0)
            {
                usrstr.append("0");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == 6)
                    ui->label_usrtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("0");
                pwdstrshow.append('*');
                ui->label_passwd->setText(pwdstr);
                if(pwdstr.length() == 6)
                    ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
        }
    }
    else if(e->key() == Qt::Key_1)
    {
        if(keypressedflag[1] == 1)
        {
            keypressedflag[1] = 0;
            if(currentFocus == 0)
            {
                usrstr.append("1");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == 6)
                    ui->label_usrtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("1");
                pwdstrshow.append('*');
                ui->label_passwd->setText(pwdstr);
                if(pwdstr.length() == 6)
                    ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
        }
    }
    else if(e->key() == Qt::Key_2)
    {
        if(keypressedflag[2] == 1)
        {
            keypressedflag[2] = 0;
            if(currentFocus == 0)
            {
                usrstr.append("2");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == 6)
                    ui->label_usrtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("2");
                pwdstrshow.append("*");
                ui->label_passwd->setText(pwdstr);
                if(pwdstr.length() == 6)
                    ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
        }
    }
    else if(e->key() == Qt::Key_3)
    {
        if(keypressedflag[3] == 1)
        {
            keypressedflag[3] = 0;
            if(currentFocus == 0)
            {
                usrstr.append("3");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == 6)
                    ui->label_usrtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("3");
                pwdstrshow.append("*");
                ui->label_passwd->setText(pwdstr);
                if(pwdstr.length() == 6)
                    ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
        }
    }
    else if(e->key() == Qt::Key_4)
    {
        if(keypressedflag[4] == 1)
        {
            keypressedflag[4] = 0;
            if(currentFocus == 0)
            {
                usrstr.append("4");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == 6)
                    ui->label_usrtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("4");
                pwdstrshow.append("*");
                ui->label_passwd->setText(pwdstr);
                if(pwdstr.length() == 6)
                    ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
        }
    }
    else if(e->key() == Qt::Key_5)
    {
        if(keypressedflag[5] == 1)
        {
            keypressedflag[5] = 0;
            if(currentFocus == 0)
            {
                usrstr.append("5");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == 6)
                    ui->label_usrtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("5");
                pwdstrshow.append("*");
                ui->label_passwd->setText(pwdstr);
                if(pwdstr.length() == 6)
                    ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
        }
    }
    else if(e->key() == Qt::Key_6)
    {
        if(keypressedflag[6] == 1)
        {
            keypressedflag[6] = 0;
            if(currentFocus == 0)
            {
                usrstr.append("6");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == 6)
                    ui->label_usrtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("6");
                pwdstrshow.append("*");
                ui->label_passwd->setText(pwdstr);
                if(pwdstr.length() == 6)
                    ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
        }
    }
    else if(e->key() == Qt::Key_7)
    {
        if(keypressedflag[7] == 1)
        {
            keypressedflag[7] = 0;
            if(currentFocus == 0)
            {
                usrstr.append("7");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == 6)
                    ui->label_usrtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("7");
                pwdstrshow.append("*");
                ui->label_passwd->setText(pwdstr);
                if(pwdstr.length() == 6)
                    ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
        }
    }
    else if(e->key() == Qt::Key_8)
    {
        if(keypressedflag[8] == 1)
        {
            keypressedflag[8] = 0;
            if(currentFocus == 0)
            {
                usrstr.append("8");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == 6)
                    ui->label_usrtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("8");
                pwdstrshow.append("*");
                ui->label_passwd->setText(pwdstr);
                if(pwdstr.length() == 6)
                    ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
        }
    }
    else if(e->key() == Qt::Key_9)
    {
        if(keypressedflag[9] == 1)
        {
            keypressedflag[9] = 0;
            if(currentFocus == 0)
            {
                usrstr.append("9");
                ui->label_user->setText(usrstr);
                if(usrstr.length() == 6)
                    ui->label_usrtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_usrtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
            else
            {
                pwdstr.append("9");
                pwdstrshow.append("*");
                ui->label_passwd->setText(pwdstr);
                if(pwdstr.length() == 6)
                    ui->label_pwdtip->setStyleSheet("color: rgb(255,255,255);");
                else
                    ui->label_pwdtip->setStyleSheet("color: rgb(255, 0, 0);");
            }
        }
    }
}
void powerusrAccountAddModify::updateDisplayUIoperate()
{
    switch(currentFocus)
    {
    case FOCUSONUSR:
         ui->label_user->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(170, 255, 255);");
         ui->label_passwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
         break;
    case FOCUSONPWD:
         ui->label_user->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
         ui->label_passwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(170, 255, 255);");
         break;
    default:
         ui->label_user->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(170, 255, 255);");
         ui->label_passwd->setStyleSheet("border:2px groove light blue;padding:2px 4px;background-color: rgb(255, 255, 255);");
         break;
    }
}
void powerusrAccountAddModify::enterkeypressprocess()
{
    int ret =0;
    if(addmodifyflag == 0)// add
    {
        ret = checkdupusr();
        if(ret)
        {
            ui->label_info->setText(tr("已经有此用户名,请重新添加"));
            QMessageBox::information(this, "提示", tr("已经有此用户名,添加无效"),QMessageBox::Yes);
        }
        else
        {
            usrstr = ui->label_user->text();
            pwdstr = ui->label_passwd->text();

            sUsrInfo.name = usrstr.toInt();
            sUsrInfo.passwd = pwdstr.toInt();

            if((usrstr.length() == 6)&&(pwdstr.length() == 6))
            {
                this->hide();
                emit addmodifyUsrInfosignal(sUsrInfo,0);
            }
        }
    }
    else  //modify
    {
        usrstr = ui->label_user->text();
        pwdstr = ui->label_passwd->text();

        sUsrInfo.name = usrstr.toInt();
        sUsrInfo.passwd = pwdstr.toInt();

        if((usrstr.length() == 6)&&(pwdstr.length() == 6))
        {
            this->hide();
            emit addmodifyUsrInfosignal(sUsrInfo,1);
        }

    }
}
int powerusrAccountAddModify::checkdupusr()
{
    if(usrstr.toInt() == 999999)
    {
        return 1;
    }

        for(int i=0;i<pusrlistdata->engineerlvl.count();i++)
        {
            if(usrstr.toInt() == pusrlistdata->engineerlvl.at(i).name)
            {
                return 1;
            }
        }

        for(int i=0;i<pusrlistdata->operaterlvl.count();i++)
        {
            if(usrstr.toInt() == pusrlistdata->operaterlvl.at(i).name)
            {
                return 1;
            }
        }
    return 0;
}
#endif
