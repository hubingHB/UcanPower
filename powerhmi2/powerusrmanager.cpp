#include "powerusrmanager.h"
#include "ui_powerusrmanager.h"
#include <QTreeWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>
powerusrmanager::powerusrmanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::powerusrmanager)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

   // connect(&addmodifyUsrIns,SIGNAL(addmodifyUsrInfosignal(usrinfo,int)),this,SLOT(addmodifyUsrInfoslot(usrinfo,int)));
}

powerusrmanager::~powerusrmanager()
{
    delete ui;
}

#if 0
void powerusrmanager::keyPressEvent(QKeyEvent *pkey)
{
    if(pkey->key() == Qt::Key_Return)
    {
        processReturnkeyPressed();
    }
    else if(pkey->key() == Qt::Key_F1)
    {
        QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("是否保存信息?"));
        QPushButton * buttonyes= msgbox.addButton(tr("是"), QMessageBox::AcceptRole);
        QPushButton * buttonno = msgbox.addButton(tr("否"), QMessageBox::RejectRole);
        buttonno->setFocus();
        msgbox.exec();
        if(msgbox.clickedButton() == buttonyes)
        {
            ismodified = 0;
            memcpy(pusrlistdata,&ownpusrlistdata,sizeof(ownpusrlistdata));

//            qDebug()<<"pusrlistdata->engineerlvl.at(0).passwd"<<pusrlistdata->engineerlvl.at(0).passwd
//                     << ownpusrlistdata.engineerlvl.count()<<ownpusrlistdata.operaterlvl.count()
//                     << pusrlistdata->engineerlvl.count()<<pusrlistdata->operaterlvl.count();
            this->hide();
            emit confirmsaveusrinfosignal();
        }
    }
    else if(pkey->key() == Qt::Key_Escape)
    {
        if(ismodified)
        {
            QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("是否放弃修改并退出?"));
            QPushButton * buttonyes= msgbox.addButton(tr("是"), QMessageBox::AcceptRole);
            QPushButton * buttonno = msgbox.addButton(tr("否"), QMessageBox::RejectRole);
            buttonno->setFocus();
            msgbox.exec();
            if(msgbox.clickedButton() == buttonyes)
            {
                ismodified = 0;
                this->hide();
            }
        }
        else
        {
            ismodified = 0;
            this->hide();
        }
    }
}

void powerusrmanager::processReturnkeyPressed()
{
    if(ui->treeWidget->currentItem()) // exist no account.
    {
        if(ui->treeWidget->currentItem()->parent())
        {
            if(ui->treeWidget->currentItem()->parent() == ui->treeWidget->topLevelItem(0))
            {
                singleusrinfo.level = 2;// engineer
            }
            else
            {
                singleusrinfo.level = 3; // operator
            }

            QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("修改密码或删除账户"));
            QPushButton * buttonmodify = msgbox.addButton(tr("修改密码"), QMessageBox::AcceptRole);
            QPushButton * buttondel = msgbox.addButton(tr("删除账户"), QMessageBox::YesRole);
            QPushButton * buttoncancel = msgbox.addButton(tr("取消"), QMessageBox::RejectRole);
            buttoncancel->setFocus();
            msgbox.exec();
            if(msgbox.clickedButton() == buttonmodify)
            {
                singleusrinfo.name = ui->treeWidget->currentItem()->text(1).toInt();
                this->addmodifyUsrIns.entryprocess(&ownpusrlistdata,singleusrinfo,1);//0 add; 1 modify
                this->addmodifyUsrIns.show();
            }
            else if(msgbox.clickedButton() == buttondel)
            {
                int row = ui->treeWidget->currentItem()->text(0).toInt();
                ui->treeWidget->currentItem()->parent()->removeChild(ui->treeWidget->currentItem());
                ismodified = 1;

                if(singleusrinfo.level == 2)
                {
                    ownpusrlistdata.engineerlvl.removeAt(row);
                }
                else if(singleusrinfo.level == 3)
                {
                    ownpusrlistdata.operaterlvl.removeAt(row);
                }
                qDebug()<<"11check check"<<row;

                if(ui->treeWidget->currentItem())
                {
                    if(ui->treeWidget->currentItem()->parent())
                    {
                        int cnt = ui->treeWidget->currentItem()->parent()->childCount();
                        qDebug()<<"22check check"<<row<<cnt;
                        for(int i=row;i<cnt;i++)
                        {
                            int usrinfoIndex = ui->treeWidget->currentItem()->parent()->child(i)->text(0).toInt();
                            usrinfoIndex--;
                            ui->treeWidget->currentItem()->parent()->child(i)->setText(0,QString::number(usrinfoIndex));
                        }
                    }
                }
            }
        }
        else
        {
            if(ui->treeWidget->currentItem() == ui->treeWidget->topLevelItem(0))
            {
                 singleusrinfo.level = 2;
            }
            else
            {
                 singleusrinfo.level = 3;
            }
            QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("添加账户"));
            QPushButton * buttonadd = msgbox.addButton(tr("添加"), QMessageBox::AcceptRole);
            QPushButton * buttoncancel = msgbox.addButton(tr("取消"), QMessageBox::RejectRole);
            buttoncancel->setFocus();
            msgbox.exec();

            if(msgbox.clickedButton() == buttonadd)
            {
                this->addmodifyUsrIns.entryprocess(&ownpusrlistdata,singleusrinfo,0);//0 add; 1 modify

                this->addmodifyUsrIns.show();
            }
        }
    }
}

void powerusrmanager::displayusrinfo()
{
    memcpy(&ownpusrlistdata,pusrlistdata,sizeof(usrlist));
    ui->treeWidget->clear();

     QTreeWidgetItem * addDevItem1 = new QTreeWidgetItem(1);

     addDevItem1->setText(0,tr("工程师账户"));
     addDevItem1->setText(1,tr("用户名"));
     addDevItem1->setText(2,tr("密码"));
     ui->treeWidget->addTopLevelItem(addDevItem1);

     addDevItem1 = new QTreeWidgetItem(1);

     addDevItem1->setText(0,tr("操作员账户"));
     addDevItem1->setText(1,tr("用户名"));
     addDevItem1->setText(2,tr("密码"));
     ui->treeWidget->addTopLevelItem(addDevItem1);

     for(int i=0;i<pusrlistdata->engineerlvl.count();i++)
     {
         QTreeWidgetItem * addDevItem2 = new QTreeWidgetItem(1);
         addDevItem2->setText(0,QString::number(i));
         addDevItem2->setText(1,QString::number(pusrlistdata->engineerlvl.at(i).name));
         addDevItem2->setText(2,QString::number(pusrlistdata->engineerlvl.at(i).passwd));
         ui->treeWidget->topLevelItem(0)->addChild(addDevItem2);
     }

     for(int i=0;i<pusrlistdata->operaterlvl.count();i++)
     {
         QTreeWidgetItem * addDevItem2 = new QTreeWidgetItem(1);
         addDevItem2->setText(0,QString::number(i));
         addDevItem2->setText(1,QString::number(pusrlistdata->operaterlvl.at(i).name));
         addDevItem2->setText(2,QString::number(pusrlistdata->operaterlvl.at(i).passwd));
         ui->treeWidget->topLevelItem(1)->addChild(addDevItem2);
     }
     ui->treeWidget->expandAll();
}
void powerusrmanager::addmodifyUsrInfoslot(usrinfo singleusrinfo, int addormodify)
{
    if(addormodify == 0)//add
    {
        QTreeWidgetItem * addDevItem = new QTreeWidgetItem(1);

        addDevItem->setText(1,QString::number(singleusrinfo.name));
        addDevItem->setText(2,QString::number(singleusrinfo.passwd));
        if(singleusrinfo.level == 2)
        {
            addDevItem->setText(0,QString::number(ownpusrlistdata.engineerlvl.count()));
            ui->treeWidget->topLevelItem(0)->addChild(addDevItem);
            ownpusrlistdata.engineerlvl.append(singleusrinfo);
            ismodified = 1;
        }
        else
        {
            addDevItem->setText(0,QString::number(ownpusrlistdata.operaterlvl.count()));
            ui->treeWidget->topLevelItem(1)->addChild(addDevItem);
            ownpusrlistdata.operaterlvl.append(singleusrinfo);
            ismodified = 1;
        }
    }
    else//modify
    {
        ui->treeWidget->currentItem()->setText(2,QString::number(singleusrinfo.passwd));

        if(singleusrinfo.level == 2)
        {
             //qDebug()<<"singleusrinfo.passwd"<<singleusrinfo.name<<singleusrinfo.passwd<<ownpusrlistdata.engineerlvl.count();
             for(int i=0;i<ownpusrlistdata.engineerlvl.count();i++)
             {
                // qDebug()<<"ownpusrlistdata.engineerlvl.at(i).name"<<ownpusrlistdata.engineerlvl.at(i).name;
                 if(singleusrinfo.name == ownpusrlistdata.engineerlvl.at(i).name)
                 {
                     ownpusrlistdata.engineerlvl.removeAt(i);

                     ownpusrlistdata.engineerlvl.insert(i,singleusrinfo);
                   //  qDebug()<<"ownpusrlistdata"<<ownpusrlistdata.engineerlvl.at(0).name<<ownpusrlistdata.engineerlvl.at(0).passwd;
                     ismodified = 1;
                 }
             }
        }
        else
        {
            for(int i=0;i<ownpusrlistdata.operaterlvl.count();i++)
            {
                if(singleusrinfo.name == ownpusrlistdata.operaterlvl.at(i).name)
                {
                    ownpusrlistdata.operaterlvl.removeAt(i);
                    ownpusrlistdata.operaterlvl.insert(i,singleusrinfo);
                     ismodified = 1;
                }
            }
        }
    }
}
#endif
