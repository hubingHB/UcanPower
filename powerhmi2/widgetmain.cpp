#include "widgetmain.h"
#include "ui_widgetmain.h"
#include <QTime>
#include <QNetworkInterface>
#include <QDebug>
#include <qmessagebox.h>

#include <QMessageBox>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QIcon>
#include <QTimer>

#define max_fun 8
#define DEBUG 1


//static int logic_code = 1;
//static int total_dev = 0;
//static int startindex = 0;
//static CONFIGURE_FILE_CONTENT valid_cfg_info;
//sysStruct systemStruct;

//static ALL_TYPE_VALUE valid_all_value[MAX_RTU_NUM];
//static int ui_display = 1;

//devLocationInSt devLocationInStruct;//todo
//QString protostr[9] = {"8110","8120","8130","8210","8220","6110","6610","50Z","800II"};

WidgetMain::WidgetMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetMain)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    qDebug()<<"struct widgetmain: hmi init ok";

//    initIconArray();
    structinitflag = 0;
    ui_init();

    qDebug()<<"hello world";

#if 0
    //停电票操作
    //时间已授时
    connect(&commu,SIGNAL(rcv_server_info()),this,SLOT(ui_handle_server()));
#endif
    ui->treeWidget_commu->setFocus();
}
WidgetMain::~WidgetMain()
{
    delete ui;
}
void WidgetMain::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
/******************************************************************************/
void WidgetMain::keyPressEvent(QKeyEvent *e)
{
    if(!e->isAutoRepeat())
    {
        //qDebug()<<e->key();
        switch(e->key())
        {
        case Qt::Key_F1:key_f1_press();break;
      //  case Qt::Key_Up:key_up_press();break;
      //  case Qt::Key_Down:key_down_press();break;
      //  case Qt::Key_Left:key_left_press();break;
       // case Qt::Key_Right:key_right_press();break;
        case Qt::Key_Return:key_return_press();break;
        case Qt::Key_F2:key_f2_press();break;
        case Qt::Key_F3:key_f3_press();break;
            //testdebug();
      //  case Qt::Key_F4:
           // ui->treeWidget_commu->clear();
      //      if(testTimer.isActive())
      //          testTimer.stop();
      //      else
      //          testTimer.start(5000);
      //      break;
//        case Qt::Key_F5:
//            emit debugtestxmlsignal();
//            break;
        case Qt::Key_F6:
            testpic();
            break;
        }
    }
}

//void WidgetMain::testsndERRMSG()
//{
//    emit testsndERRMSGsignal();
//}

void WidgetMain::testpic()
{
    QPixmap pixmap_start(":/pic/START.png");
    int start_width = pixmap_start.width();
    int start_height = pixmap_start.height();

    QPixmap total_pixmap;

    QPainter painter(&total_pixmap);
    //
    painter.drawPixmap(QRect(0, 0, start_width, start_height), pixmap_start);

    QPixmap pixmap_CONGB0(":/pic/CONGB0.png");
    int CONGB_width = pixmap_start.width();
    int CONGB_height = pixmap_start.height();

    painter.drawPixmap(QRect(start_width, 0, CONGB_width, CONGB_height), pixmap_CONGB0);


    QPixmap pixmap_CONGB00(":/pic/CONGB0.png");
    int CONGB0_width = pixmap_start.width();
    int CONGB0_height = pixmap_start.height();

    painter.drawPixmap(QRect(start_width+CONGB_width, 0, CONGB0_width, CONGB0_height), pixmap_CONGB00);

}

//void WidgetMain::testdebug()
//{
//   // emit debugvaluesignal();
//    qDebug()<<"REAL TIME DATA DEBUG1"
//            <<pRealtimeData[64].commu.status<<pRealtimeData[64].commu.tx_byte
//            <<pRealtimeData[64].commu.rx_byte
//            <<pRealtimeData[64].commu.tx_frame<< pRealtimeData[64].commu.rx_frame
//            <<pRealtimeData[64].value[INFO_MEASURE_1].val_num<<INFO_MEASURE_1
//            <<pRealtimeData[64].value[INFO_MEASURE_INTER_1].val_num<<INFO_MEASURE_INTER_1
//            <<pvalid_cfg_info->info[64].logic_addr<<pvalid_cfg_info->info[64].phy_addr;
//}

void WidgetMain::key_f1_press()
{
    mFunCode++;
    if(mFunCode > max_fun)
        mFunCode = 1;
    switch(mFunCode)
    {
    case 1:
        ui->label_config->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_login->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 2:
        ui->label_login->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_mode->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 3:
        ui->label_mode->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_measure->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 4:
        ui->label_measure->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_constant->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 5:
        ui->label_constant->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_control->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 6:
        ui->label_control->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_soe->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 7:
        ui->label_soe->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_powerstamp->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 8:
    default:
        ui->label_powerstamp->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_config->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    }
}

void WidgetMain::key_f2_press()
{
    mFunCode--;
    if(mFunCode < 1)
        mFunCode = max_fun;
    switch(mFunCode)
    {
    case 1:
        ui->label_mode->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_login->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 2:
        ui->label_measure->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_mode->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 3:
        ui->label_constant->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_measure->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 4:
        ui->label_control->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_constant->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 5:
        ui->label_soe->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_control->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 6:
        ui->label_powerstamp->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_soe->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 7:
        ui->label_config->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_powerstamp->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    case 8:
    default:
        ui->label_login->setStyleSheet("background-color:rgb(255,255,255);");
        ui->label_config->setStyleSheet("background-color:rgb(0,255,0);");
        break;
    }
}

void WidgetMain::key_f3_press()
{
    if(mDisPlayFlag == FLAG_DISPLAY_COMMU)   // DISPLAY STRUCT
    {
       // if(structinitflag == 0)
       // {
        //    structinitflag = 1;
        //    ui_struct_show();
        //}
        ui->treeWidget_commu->hide();
        ui->treeWidget_struct->show();
     //   ui->treeWidget_struct->setColumnWidth(0,300);
        ui->treeWidget_struct->setFocus();
        ui->treeWidget_struct->expandAll();
        mDisPlayFlag = FLAG_DISPLAY_STRUCT;
        //qDebug()<<"mDisPlayFlag = "<<mDisPlayFlag<<structinitflag;
    }
    else
    {
        ui_display_info();
        ui->treeWidget_commu->setFocus();
        ui->treeWidget_commu->show();
        ui->treeWidget_commu->expandAll();
        ui->treeWidget_struct->hide();
        mDisPlayFlag = FLAG_DISPLAY_COMMU; //
        //qDebug()<<"mDisPlayFlag = "<<mDisPlayFlag<<structinitflag;
    }
}

void WidgetMain::key_return_press()
{
    int LogicAddr = -1;
    QString addrstr;
#if 0    // to Debug it will enable for release Version
    if(mFunCode != 1) //
    {
        if(psysStatus->islogin == LOGOUT)
        {
            QMessageBox::information(this,tr("提示"),tr("用户未登录，无法进行相关操作"),QMessageBox::Ok);
            return;
        }
    }
#endif
        if(mFunCode != max_fun)
        {
            if(mDisPlayFlag == FLAG_DISPLAY_COMMU)
            {
                if(ui->treeWidget_commu->currentItem())
                {
                    qDebug()<<__FUNCTION__<<__LINE__<<ui->treeWidget_commu->currentItem();
                    addrstr = ui->treeWidget_commu->currentItem()->text(0);
                    if(!addrstr.isEmpty())
                        LogicAddr = addrstr.toInt();
                }
                else
                {
                    QMessageBox::information(this,tr("提示"),tr("当前未选中设备,请按上下键选择设备"),QMessageBox::Ok);
                }
            }
            else
            {
                if(ui->treeWidget_struct->currentItem())
                {
                    qDebug()<<__FUNCTION__<<__LINE__;
                    addrstr = ui->treeWidget_struct->currentItem()->text(0);
                    if(!addrstr.isEmpty())
                        LogicAddr = addrstr.toInt();
                }
                else
                {
                    QMessageBox::information(this,tr("提示"),tr("当前未选中设备,请按上下键选择设备"),QMessageBox::Ok);
                }
            }

            qDebug()<<LogicAddr<<__FUNCTION__<<__LINE__;
            currentLogicaddr = LogicAddr;
            switch(mFunCode)
            {
                case 1:user_loginprocess();break;
                case 2:modeswitchprocess();break;
                case 3:ui_measure_show(LogicAddr);break;
                case 4:ui_constant_show(LogicAddr);break;
                case 5:ui_control_show(LogicAddr);break;
                case 6:ui_soe_show(LogicAddr);break;
                case 7:ui_operate_show(LogicAddr);break;
            }
         }
         else
         {
            if((pDeviceDataBase->UsrLoginInfo.usrlevel == LVLENGINEER)||(pDeviceDataBase->UsrLoginInfo.usrlevel == LVLMANAGE))
                ui_sys_config_show();
            else
            {
                QMessageBox::information(this,tr("提示"),tr("当前用户无设置权限"),QMessageBox::Ok);
            }
         }
}

/******************************************************************************/
void WidgetMain::DisplayTimeSlot() //
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->time->setText(str);
}
void WidgetMain::ui_init()
{
    ui->time_flag->setVisible(false);
    /*****************************/
  //ui->ip->setText(QNetworkInterface().allAddresses().at(2).toString());//ip地址显示
    /*****************************/
    mClockTimer.start(1000);
    connect(&mClockTimer,SIGNAL(timeout()),this,SLOT(DisplayTimeSlot()));
}
/******************************************************************************/

void WidgetMain::UpdateDevStatusSlot(INT8U LogicAddr,INT8U FrameType,INT8U GroupIndex)
{
//    qDebug()<<__FUNCTION__<<__LINE__;
    UIUpdateSingleDevStatus(LogicAddr,FrameType,GroupIndex);
}

void WidgetMain::UIUpdateSingleDevStatus(INT8U LogicAddr,INT8U FrameType,INT8U GroupIndex)
{
    //  qDebug()<<"HMI : "<<__FUNCTION__<<__LINE__<<logicaddr;
//    qDebug()<<__FUNCTION__<<__LINE__<<FrameType<<GroupIndex;

    INT32S tRowIndex1 = LogicAddr/16;
    INT32S tRowIndex2 = LogicAddr%16;

    INT32S tVoltage=0;
    FP32 tVoltageRatio = 0.0;
    FP32 tCurrentRatio = 0.0;
    INT32S tCurrent=0;
    INT8U tProtoIndex=0,tProtoVer=0,tVoltageIndex=0,tCurrentIndex=0;
    INT32S tDevStatus=0,tDevStatusIndex=0;
    INT32S tErrorStatus=0,tErrorStatusIndex=0;
    INT32S tPowerStampStatus=0,tPowerStampIndex=0;
    INT8U tCommuStatus = COMM_STATUS_OFF;
    INT8U tIsIntern = PROTO_PRIV_NO;

    //  qDebug()<<"####hbtest"<<__FUNCTION__<<__LINE__<<logicaddr<<pRealtimeData[logicaddr].isIntern<<pRealtimeData[logicaddr].value[INFO_MEASURE_INTER_1].val_num
    //         <<pvalid_cfg_info->info[logicaddr].phy_addr;
      tCommuStatus = pDeviceDataBase->DeviceValue[LogicAddr].commu.status;//pRealtimeData[logicaddr].commu.status;
      tIsIntern = pDeviceDataBase->DeviceValue[LogicAddr].isIntern;
      tProtoIndex = pDeviceDataBase->SysCfgData.DevInfo[LogicAddr].rtu_typeIndex;
      tProtoVer   = pDeviceDataBase->SysCfgData.DevInfo[LogicAddr].rtu_typeVer;

//      qDebug()<<__FUNCTION__<<__LINE__<<FrameType<<GroupIndex<<tIsIntern<<mDisPlayFlag;

      if(tIsIntern)
      {
           tVoltageIndex     = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].VoltageCurrentParseInternSection.vindex;
           tCurrentIndex     = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].VoltageCurrentParseInternSection.Iindex;
           tDevStatusIndex   = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].SwitchStatusParseInternSection.MapIndex;
           tErrorStatusIndex = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].FaultParseInternSection.MapIndex[0];
           tPowerStampIndex  = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].PowerDownStampParseSection.MapIndex;

           if(tVoltageIndex < MAX_VAL_NUM) //超过数组大小,禁止取值
           {
                tVoltage      = pDeviceDataBase->DeviceValue[LogicAddr].value[INFO_MEASURE_INTER_1].ValueData[tVoltageIndex];
                tVoltageRatio = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].MeasureInternSection[0].Point[tVoltageIndex].Ratio;
           }

           if(tCurrentIndex < MAX_VAL_NUM)
           {
               tCurrent = pDeviceDataBase->DeviceValue[LogicAddr].value[INFO_MEASURE_INTER_1].ValueData[tCurrentIndex];
               tCurrentRatio = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].MeasureInternSection[0].Point[tCurrentIndex].Ratio;
           }

           if(tDevStatusIndex < MAX_VAL_NUM)
                tDevStatus = pDeviceDataBase->DeviceValue[LogicAddr].value[INFO_MEASURE_INTER_1].ValueData[tDevStatusIndex];

           if(tErrorStatusIndex < MAX_VAL_NUM)
                tErrorStatus = pDeviceDataBase->DeviceValue[LogicAddr].value[INFO_MEASURE_INTER_1].ValueData[tErrorStatusIndex];

           if(tPowerStampIndex < MAX_VAL_NUM)
                tPowerStampStatus = pDeviceDataBase->DeviceValue[LogicAddr].value[INFO_MEASURE_INTER_1].ValueData[tPowerStampIndex];

          //qDebug()<<__FUNCTION__<<__LINE__<<voltage<<fac_voltage<<current<<fac_current;
           if(mDisPlayFlag == FLAG_DISPLAY_COMMU)
           {
                //qDebug()<<__FUNCTION__<<__LINE__<<rowindex1<<rowindex2;
                if(ui->treeWidget_commu->topLevelItem(tRowIndex1))
                {
                    if(ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2))
                    {
                       // qDebug()<<__FUNCTION__<<__LINE__<<tRowIndex1<<tRowIndex2;
                        ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setText(4,QString::number(tVoltage));
                        ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setText(5,QString::number(tCurrent));

                        ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setIcon(6,QIcon(QPixmap(":/pic/green2.png")));

                        if(tCommuStatus == COMM_STATUS_ON)
                        {
                            if(tErrorStatus > 0)//setIcon(1,QIcon(QPixmap(":/pic/green2.png")));
                            {
                                 ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setIcon(1,QIcon(QPixmap(":/pic/yellow2.png")));
                                 ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setText(1,QString::number(tErrorStatus));
                               //  qDebug()<<__FUNCTION__<<__LINE__<<"errorstatus"<<errorstatus;
                            }
                            else
                            {
                                 ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setText(1,"");
                                 if(tDevStatus == RELAY_STATUS_ON)
                                 {
                                      ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setIcon(1,QIcon(QPixmap(":/pic/red2.png")));
                                 }
                                 else
                                 {
                                     // qDebug()<<__FUNCTION__<<__LINE__<<"devstatus="<<devstatus;
                                      ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setIcon(1,QIcon(QPixmap(":/pic/green2.png")));
//                                      if(tPowerStampStatus == OPT_LOCK)//TODO
//                                      {
//                                          ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setIcon(1,QIcon(QPixmap(":/pic/blue2.png")));
//                                      }
                                 }
                            }
                         }
                         else
                         {
                              ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setIcon(1,QIcon(QPixmap(":/pic/grey2.png")));
                         }
                    }
                    else
                    {
                        qDebug()<<__FUNCTION__<<__LINE__<<tRowIndex1<<tRowIndex2;
                    }
                }
                else
                {
                    qDebug()<<__FUNCTION__<<__LINE__<<tRowIndex1<<tRowIndex2;
                }
           }
      }
      else // public protocol
      {
          tVoltageIndex     = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].VoltageCurrentParseSection.vindex;
          tCurrentIndex     = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].VoltageCurrentParseSection.Iindex;
          tDevStatusIndex   = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].SwitchStatusParseSection.MapIndex;

          if(tVoltageIndex < MAX_VAL_NUM) //超过数组大小,禁止取值
          {
              tVoltage = pDeviceDataBase->DeviceValue[LogicAddr].value[INFO_MEASURE_1].ValueData[tVoltageIndex];
              tVoltageRatio = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].MeasureSection[0].Point[tVoltageIndex].Ratio;
          }

          if(tCurrentIndex < MAX_VAL_NUM)
          {
              tCurrent = pDeviceDataBase->DeviceValue[LogicAddr].value[INFO_MEASURE_1].ValueData[tCurrentIndex];
              tCurrentRatio = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].MeasureSection[0].Point[tCurrentIndex].Ratio;
          }

          if(tDevStatusIndex < MAX_VAL_NUM)
               tDevStatus = pDeviceDataBase->DeviceValue[LogicAddr].value[INFO_MEASURE_1].ValueData[tDevStatusIndex];

          tErrorStatus = 0;
          for(INT8U i=0; i < pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].FaultParseSection.Total;i++)
          {
              tErrorStatusIndex = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].FaultParseSection.MapIndex[i];
              tErrorStatus |= (pDeviceDataBase->DeviceValue[LogicAddr].value[INFO_SWITCH].ValueData[tErrorStatusIndex] << i);
          }
          if(mDisPlayFlag == FLAG_DISPLAY_COMMU)
          {
               //qDebug()<<__FUNCTION__<<__LINE__<<tRowIndex1<<tRowIndex2;
               if(ui->treeWidget_commu->topLevelItem(tRowIndex1))
               {
                   if(ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2))
                   {
                      // qDebug()<<__FUNCTION__<<__LINE__<<rowindex1<<tRowIndex2;
                       ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setText(4,QString::number(tVoltage));
                       ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setText(5,QString::number(tCurrent));

                       if(tCommuStatus == COMM_STATUS_ON)
                       {
                           if(tErrorStatus > 0)//setIcon(1,QIcon(QPixmap(":/pic/green2.png")));
                           {
                                ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setIcon(1,QIcon(QPixmap(":/pic/yellow2.png")));
                              //  qDebug()<<__FUNCTION__<<__LINE__<<"errorstatus"<<errorstatus;
                                ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setText(1,QString::number(tErrorStatus));
                           }
                           else
                           {
                                ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setText(1,"");
                                if(tDevStatus == RELAY_STATUS_ON)
                                {
                                     ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setIcon(1,QIcon(QPixmap(":/pic/red2.png")));
                                }
                                else
                                {
                                    // qDebug()<<__FUNCTION__<<__LINE__<<"devstatus="<<devstatus;
                                     ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setIcon(1,QIcon(QPixmap(":/pic/green2.png")));
                                }
                           }
                        }
                        else
                        {
                             ui->treeWidget_commu->topLevelItem(tRowIndex1)->child(tRowIndex2)->setIcon(1,QIcon(QPixmap(":/pic/grey2.png")));
                        }
                   }
                   else
                   {
                       qDebug()<<__FUNCTION__<<__LINE__<<tRowIndex1<<tRowIndex2;
                   }
               }
               else
               {
                   qDebug()<<__FUNCTION__<<__LINE__<<tRowIndex1<<tRowIndex2;
               }
          }
     }
}

void WidgetMain::ui_display_info()
{ 
    qDebug()<<"StationName="<<pDeviceDataBase->SysCfgData.StationName;

    ui->treeWidget_commu->clear();

    QPixmap com0 = QPixmap(":/pic/COM_0.png");
    QPixmap com1 = QPixmap(":/pic/COM_1.png");
    QPixmap com2 = QPixmap(":/pic/COM_2.png");
    QPixmap com3 = QPixmap(":/pic/COM_3.png");
    QPixmap com4 = QPixmap(":/pic/COM_4.png");
    QPixmap com5 = QPixmap(":/pic/COM_5.png");

    QPixmap GB = QPixmap(":/pic/GB.png");
    QPixmap YB = QPixmap(":/pic/YB.png");
    QPixmap ZM = QPixmap(":/pic/ZM.png");
    QPixmap KD = QPixmap(":/pic/KD.png");

    for(int i = 0;i < MAX_COM_NUM; i++)
    {
        QTreeWidgetItem * addDevItem1 = new QTreeWidgetItem(1);
        switch(i)
        {
        case 0:
            addDevItem1->setIcon(0,QIcon(com0));
            break;
        case 1:
            addDevItem1->setIcon(0,QIcon(com1));
            break;
        case 2:
            addDevItem1->setIcon(0,QIcon(com2));
            break;
        case 3:
            addDevItem1->setIcon(0,QIcon(com3));
            break;
        case 4:
            addDevItem1->setIcon(0,QIcon(com4));
            break;
        case 5:
            addDevItem1->setIcon(0,QIcon(com5));
            break;
        }
        ui->treeWidget_commu->addTopLevelItem(addDevItem1);

        for(int j=0;j < pDeviceDataBase->SysCfgData.OneComDevTotal[i];j++)
        {
            QTreeWidgetItem * addDevItem2 = new QTreeWidgetItem(1);

            QString str=QString(QLatin1String(pDeviceDataBase->SysCfgData.DevInfo[16*i+j].devcode));
          //  qDebug()<<"type = "<<str;

            addDevItem2->setText(3,str);
            addDevItem2->setText(0,QString::number(16*i + j));
            addDevItem2->setText(2,QString::number(pDeviceDataBase->SysCfgData.DevInfo[16*i+j].phy_addr));

            int typeindex = pDeviceDataBase->SysCfgData.DevInfo[16*i+j].rtu_typeIndex;
            addDevItem2->setText(6,QString(QLatin1String(pDeviceDataBase->SysCfgData.ProtoList.ProtoArray[typeindex].Name)));

          //  qDebug()<<"protocol = " <<QLatin1String(pProtocollistIns->ProtoName[typeindex]);

            addDevItem2->setTextAlignment(0,Qt::AlignCenter);
            addDevItem2->setTextAlignment(1,Qt::AlignCenter);
            addDevItem2->setTextAlignment(2,Qt::AlignCenter);
            addDevItem2->setTextAlignment(3,Qt::AlignCenter);
            addDevItem2->setTextAlignment(4,Qt::AlignCenter);
            addDevItem2->setTextAlignment(5,Qt::AlignCenter);
            addDevItem2->setTextAlignment(6,Qt::AlignCenter);
#if 1
            int Iconflag = getdevicestatus(pDeviceDataBase->SysCfgData.DevInfo[16*i+j].logic_addr);
#endif
            switch(Iconflag)
            {
            case BLUEICON:
                addDevItem2->setIcon(1,QIcon(QPixmap(":/pic/blue2.png")));
                break;
            case YELLOWICON:
                addDevItem2->setIcon(1,QIcon(QPixmap(":/pic/yellow2.png")));
                break;
            case GREENICON:
                addDevItem2->setIcon(1,QIcon(QPixmap(":/pic/green2.png")));
                break;
            case REDICON:
                addDevItem2->setIcon(1,QIcon(QPixmap(":/pic/red2.png")));
                break;
            case GREYICON:
            default:
                addDevItem2->setIcon(1,QIcon(QPixmap(":/pic/grey2.png")));
                break;
            }

        //     qDebug()<<"code = "<<str<<pvalid_cfg_info->info[16*i+j].phy_addr;

            if(strcmp(pDeviceDataBase->SysCfgData.ProtoList.ProtoArray[typeindex].Icon,"GB") == 0)
            {
                addDevItem2->setIcon(0,QIcon(GB));
            }
            else if(strcmp(pDeviceDataBase->SysCfgData.ProtoList.ProtoArray[typeindex].Icon,"YB") == 0)
            {
                addDevItem2->setIcon(0,QIcon(YB));
            }
            else if(strcmp(pDeviceDataBase->SysCfgData.ProtoList.ProtoArray[typeindex].Icon,"ZM") == 0)
            {
                addDevItem2->setIcon(0,QIcon(ZM));
            }
            else
            {
                addDevItem2->setIcon(0,QIcon(KD));
            }
            ui->treeWidget_commu->topLevelItem(i)->addChild(addDevItem2);
        }
    }
    ui->treeWidget_commu->expandAll();
    ui->treeWidget_commu->setStyleSheet("QTreeView::item{height:13px;}");

    ui->treeWidget_commu->setColumnWidth(0,240);
    ui->treeWidget_commu->setColumnWidth(1,50);
    ui->treeWidget_commu->setColumnWidth(2,50);
    ui->treeWidget_commu->setColumnWidth(3,40);
    ui->treeWidget_commu->setColumnWidth(4,60);
    ui->treeWidget_commu->setColumnWidth(5,60);
    ui->treeWidget_commu->setColumnWidth(6,50);

  //  ui->treeWidget_commu->headerItem()->setTextAlignment(1,Qt::AlignCenter);
    ui->treeWidget_commu->headerItem()->setTextAlignment(2,Qt::AlignCenter);
    ui->treeWidget_commu->headerItem()->setTextAlignment(3,Qt::AlignCenter);
    ui->treeWidget_commu->headerItem()->setTextAlignment(4,Qt::AlignCenter);
    ui->treeWidget_commu->headerItem()->setTextAlignment(5,Qt::AlignCenter);
    ui->treeWidget_commu->headerItem()->setTextAlignment(6,Qt::AlignCenter);

    ui->treeWidget_struct->hide();
    ui->treeWidget_commu->show();
    ui->treeWidget_commu->setFocus();
    ui->treeWidget_commu->expandAll();
    mDisPlayFlag = FLAG_DISPLAY_COMMU;
}
/******************************************************************************/
int WidgetMain::handle_value_adjust(float value)// 大于多少转换为k为单位
{
    int num = value / 1000;
    if(num == 0)
        return 0;
    else if(num < 100)
        return 1;
    return 2;
}

#if 0
void WidgetMain::ui_handle_soe(int addr,DETAIL_VALUE *info)
{
    //realtimefaultIns;


    int errorcode = 0;
    int logicaddr = -1;
    int phyaddr = addr;
    for(int i = 0;i < MAX_RTU_NUM; i++)
    {
        if(phyaddr == pvalid_cfg_info->info[i].phy_addr)
        {
            logicaddr = i;
        }
    }

   // if(logic != -1)
    {
        //errorcode = info->code;
        //if(code > 0)
        {
            //int type = pvalid_cfg_info->info[logic].rtu_typeIndex;
            //int total = valid_cfg_info.data[type].basic[INFO_CODE].num;

            for(int i = 0;i < total;i++)
            {
                //if(code == valid_cfg_info.data[type].basic[INFO_CODE].info[i].type)
                {

                    QString str = QString("%1号地址发生故障为%2，保护器型号为%3，时间为%4年%5月%6日%7时%8分%9秒%10毫秒。")
                                     .arg(addr)
                                     .arg(valid_cfg_info.data[type].basic[INFO_CODE].info[i].name)
                                     .arg(valid_cfg_info.data[type].type_name)
                                     .arg(info->year)
                                     .arg(info->month)
                                     .arg(info->day)
                                     .arg(info->hour)
                                     .arg(info->min)
                                     .arg(info->sec)
                                     .arg(info->msec);
                    //ui->info->append(str);

                    ui_soe.handle_fault_insert(logic,str);
                    playaudio.play_music(addr,valid_cfg_info.data[type].basic[INFO_CODE].info[i].fac,code,valid_cfg_info.data[type].type_name);
                    i = total;
                }
            }
#endif
//        }
//       // else
//       // {
//        //  ;//  playaudio.stop_music();
//       // }
//    }
//}
/******************************************************************************/
void WidgetMain::user_loginprocess() //
{
    emit powerusrloginDisplaysignal();
}

void WidgetMain::modeswitchprocess()
{
        QString operatemode;
        if(pDeviceDataBase->StationRLMode == REMOTE_MODE)
        {
            operatemode = QString(tr("就地模式"));
        }
        else
        {
            operatemode = QString(tr("远控模式"));
        }

        QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("是否切换为")+operatemode);
        QPushButton *buttonY = msgbox.addButton(tr("是"), QMessageBox::YesRole);
        QPushButton *buttonN = msgbox.addButton(tr("否"), QMessageBox::NoRole);

        buttonN->setFocus();
        msgbox.exec();

        if(msgbox.clickedButton() == buttonY)
        {
            if(pDeviceDataBase->StationRLMode == REMOTE_MODE)
            {
                pDeviceDataBase->StationRLMode = LOCAL_MODE;//locate
                ui->label_modelocate->setStyleSheet("background-color: rgb(0, 255, 0);");
                ui->label_moderemote->setStyleSheet("background-color: rgb(255, 255, 255);");
            }
            else
            {
               pDeviceDataBase->StationRLMode = REMOTE_MODE;//remote
               ui->label_modelocate->setStyleSheet("background-color: rgb(255, 255, 255);");
               ui->label_moderemote->setStyleSheet("background-color: rgb(0, 255, 0);");
            }
        }
}

void WidgetMain::ui_measure_show(int LogicAddr) //display 对应协议的内容
{
    if(LogicAddr != -1)
    {
        //if(valid_all_value[LogicAddr].commu.status)
        if(1)//Debug
            emit MeasureInsDisplaysignal(LogicAddr);
        else
            QMessageBox::information(this,tr("提示"),tr("设备处于离线状态！"),QMessageBox::Ok);
    }
}

void WidgetMain::ui_constant_show(int LogicAddr)
{
    if(LogicAddr != -1)
    {
        //if(valid_all_value[LogicAddr].commu.status)
        if(1)//Debug
            emit ConstantInsDisplaysignal(LogicAddr);
        else
            QMessageBox::information(this,tr("提示"),tr("设备处于离线状态!"),QMessageBox::Ok);
    }
}
void WidgetMain::ui_control_show(int LogicAddr)
{
    if(pDeviceDataBase->StationRLMode == REMOTE_MODE)//remote mode
    {
        QMessageBox::information(this,tr("提示"),tr("设备处于远控模式，无法进行就地控制!"),QMessageBox::Ok);
    }
    else
    {
        if(LogicAddr != -1)
        {
            //if(valid_all_value[LogicAddr].commu.status)
            if(1)//Debug
                emit controlInsDisplaysignal(LogicAddr);
            else
                QMessageBox::information(this,tr("提示"),tr("设备处于离线状态!"),QMessageBox::Ok);
        }
    }
}
void WidgetMain::ui_soe_show(int LogicAddr)
{
   // if(LogicAddr != -1)
    int laddr = LogicAddr;
    {
        QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("显示历史或者当前故障信息"));
        QPushButton *buttonhistory = msgbox.addButton(tr("历史故障"), QMessageBox::AcceptRole);
        QPushButton *buttonrealtime = msgbox.addButton(tr("当前故障"), QMessageBox::RejectRole);
        QPushButton *buttoncancel = msgbox.addButton(tr("取消"), QMessageBox::NoRole);

        msgbox.setStyleSheet(
                             "QPushButton{background-color:white; border-style:outset; font:10px; min-width:5em; min-height:2em;}"
                             "QPushButton:focus{background-color:green; border-style:outset; font:10px; min-width:5em; min-height:2em;}"
                             "QLabel{font:10px;}"
                            );

        buttoncancel->setFocus();
        msgbox.exec();

        if(msgbox.clickedButton() == buttonhistory)
        {
            emit faulthistoryDisplaysignal();
        }
        else if(msgbox.clickedButton() == buttonrealtime)
        {
            emit faultrealtimeDisplaysignal();
        }

    //    ui_soe.display_fault(LogicAddr,pvalid_cfg_info);
       // ui_soe.move((800-600)/2,0);
    //    ui_soe.show();
    }
}
void WidgetMain::ui_commu_show(int LogicAddr)
{
    if(LogicAddr != -1)
    {

    //    ui_commu.display_commu(LogicAddr,pvalid_cfg_info,&valid_all_value[LogicAddr].commu);
    //    ui_commu.move((800-400)/2,(480-250)/2);
    //    ui_commu.show();
    }
}
void WidgetMain::ui_commu_update()
{
    //int logic_addr = logic_code - 1;
 //   ui_commu.update_display(&valid_all_value[currentLogicaddr].commu);
}
void WidgetMain::ui_operate_show(int LogicAddr)
{

    if(pDeviceDataBase->StationRLMode == REMOTE_MODE)//remote mode
    {
        QMessageBox::information(this,tr("提示"),tr("设备处于远控模式，无法进行就地控制!"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("设置停电票或查询所有停电票状态"));
        QPushButton *buttonsetup = msgbox.addButton(tr("设置"), QMessageBox::AcceptRole);
        QPushButton *buttoncheck = msgbox.addButton(tr("查询"), QMessageBox::RejectRole);
        QPushButton *buttoncancel = msgbox.addButton(tr("取消"), QMessageBox::NoRole);
        buttoncancel->setFocus();
        msgbox.setStyleSheet(
                             "QPushButton{background-color:white; border-style:outset; font:10px; min-width:5em; min-height:2em;}"
                             "QPushButton:focus{background-color:green; border-style:outset; font:10px; min-width:5em; min-height:2em;}"
                             "QLabel{font:10px;}"
                            );
        msgbox.exec();

        if (msgbox.clickedButton() == buttonsetup)
        {
            if(LogicAddr == -1)
            {
                QMessageBox infobox(QMessageBox::Information, tr("提示"), tr("请按上下键选中所需设置的设备"));
                QPushButton *buttonOK = msgbox.addButton(tr("设置"), QMessageBox::AcceptRole);
                buttonOK->setFocus();
                infobox.exec();
            }
            else
            {
                emit PowerDownStampSetupsignal();
            }
        }
        else if(msgbox.clickedButton() == buttoncheck)
        {
            emit PowerDownStampDisplaysignal();
        }
    }
}

void WidgetMain::ui_sys_config_show()
{
    if(pDeviceDataBase->StationRLMode == REMOTE_MODE)//remote mode
    {
        QMessageBox::information(this,tr("提示"),tr("设备处于远控模式，无法进行就地控制!"),QMessageBox::Ok);
    }
    else
    {
        emit sysconfigDisplaysignal();
    }
}

//////////////////////////////////
void WidgetMain::ui_handle_server()
{
     ui->time_flag->setVisible(true);
}

int WidgetMain::getdevicestatus(int logicaddr)
{ //to do
    INT8U tProtoIndex=0,tProtoVer=0;
    INT8U tDevStatus=0,tDevStatusIndex=0;
    INT8U tErrorStatus=0,tErrorStatusIndex=0;
    INT8U tPowerStampStatus=0,tPowerStampIndex=0;
    INT8U tCommuStatus = COMM_STATUS_OFF;

    INT8U tIsIntern   = pDeviceDataBase->DeviceValue[logicaddr].isIntern;
    tCommuStatus = pDeviceDataBase->DeviceValue[logicaddr].commu.status;

    if(tCommuStatus == COMM_STATUS_OFF)
    {
        return GREYICON;
    }
    else
    {
        if(tIsIntern)
        {
            // qDebug()<<__FUNCTION__<<__LINE__;
             tProtoIndex = pDeviceDataBase->SysCfgData.DevInfo[logicaddr].rtu_typeIndex;
             tProtoVer   = pDeviceDataBase->SysCfgData.DevInfo[logicaddr].rtu_typeVer;

             tDevStatusIndex   = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].SwitchStatusParseInternSection.MapIndex;
             tErrorStatusIndex = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].FaultParseInternSection.MapIndex[0];
             tPowerStampIndex  = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].PowerDownStampParseSection.MapIndex;

             tDevStatus = pDeviceDataBase->DeviceValue[logicaddr].value[INFO_MEASURE_INTER_1].ValueData[tDevStatusIndex];

             tErrorStatus = pDeviceDataBase->DeviceValue[logicaddr].value[INFO_MEASURE_INTER_1].ValueData[tErrorStatusIndex];
             tPowerStampStatus = pDeviceDataBase->DeviceValue[logicaddr].value[INFO_MEASURE_INTER_1].ValueData[tPowerStampIndex];

                 if(tErrorStatus > 0)//setIcon(1,QIcon(QPixmap(":/pic/green2.png")));
                 {
                     return YELLOWICON;
                 }
                 else
                 {
                      if(tErrorStatus == RELAY_STATUS_ON)
                      {
                           return REDICON;
                      }
                      else
                      {
//                           if(powerstampstatus == OPT_LOCK)
//                           {
//                               return BLUEICON;
//                           }
//                           else
//                           {
                                return GREENICON;
//                           }
                      }
                 }
        }
        else
        {
            tProtoIndex = pDeviceDataBase->SysCfgData.DevInfo[logicaddr].rtu_typeIndex;
            tProtoVer   = pDeviceDataBase->SysCfgData.DevInfo[logicaddr].rtu_typeVer;

            tDevStatusIndex   = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].SwitchStatusParseSection.MapIndex;
            tErrorStatusIndex = pDeviceDataBase->SysCfgData.ProtoCfgData[tProtoIndex][tProtoVer].FaultParseSection.MapIndex[0];

            tDevStatus = pDeviceDataBase->DeviceValue[logicaddr].value[INFO_SWITCH].ValueData[tDevStatusIndex]; // 暂时默认在Coil区

            tErrorStatus = pDeviceDataBase->DeviceValue[logicaddr].value[INFO_MEASURE_1].ValueData[tErrorStatusIndex];
            tPowerStampStatus = pDeviceDataBase->DeviceValue[logicaddr].value[INFO_MEASURE_1].ValueData[tPowerStampIndex];

                if(tErrorStatus > 0)//setIcon(1,QIcon(QPixmap(":/pic/green2.png")));
                {
                    return YELLOWICON;
                }
                else
                {
                     if(tErrorStatus == RELAY_STATUS_ON)
                          return REDICON;
                     else
                          return GREENICON;
                }
        }
    }
}

void WidgetMain::usrloginslot()
{
    ui->label_usrname->setText(QString(tr("工号")) + QString::number(pDeviceDataBase->UsrLoginInfo.usrname));

    QString UsrName;
    if(pDeviceDataBase->UsrLoginInfo.usrlevel == LVLMANAGE)
    {
        UsrName = QString(tr("管理员"));
    }
    else if(pDeviceDataBase->UsrLoginInfo.usrlevel == LVLENGINEER)
    {
        UsrName = QString(tr("工程师"));
    }
    else
    {
        UsrName = QString(tr("操作员"));
    }

    ui->label_loginstatus->setText(UsrName + QString(tr("已登录")));

}
void WidgetMain::usrlogoutslot()
{
    ui->label_usrname->clear();
    ui->label_loginstatus->setText(tr("未登录"));
}

//void WidgetMain::initIconArray()
//{
//    GBiconI[0][0] = QIcon(QPixmap(":/pic/deviceicon/I/GB/1_GB_0.png"));
//    GBiconI[0][1] = QIcon(QPixmap(":/pic/deviceicon/I/GB/1_GB_1.png"));
//    GBiconI[1][0] = QIcon(QPixmap(":/pic/deviceicon/I/GB/2_GB_0.png"));
//    GBiconI[1][1] = QIcon(QPixmap(":/pic/deviceicon/I/GB/2_GB_1.png"));
//    GBiconI[2][0] = QIcon(QPixmap(":/pic/deviceicon/I/GB/3_GB_0.png"));
//    GBiconI[2][1] = QIcon(QPixmap(":/pic/deviceicon/I/GB/3_GB_1.png"));
//    GBiconI[3][0] = QIcon(QPixmap(":/pic/deviceicon/I/GB/4_GB_0.png"));
//    GBiconI[3][1] = QIcon(QPixmap(":/pic/deviceicon/I/GB/4_GB_1.png"));
//    GBiconI[4][0] = QIcon(QPixmap(":/pic/deviceicon/I/GB/5_GB_0.png"));
//    GBiconI[4][1] = QIcon(QPixmap(":/pic/deviceicon/I/GB/5_GB_1.png"));
//    GBiconI[5][0] = QIcon(QPixmap(":/pic/deviceicon/I/GB/6_GB_0.png"));
//    GBiconI[5][1] = QIcon(QPixmap(":/pic/deviceicon/I/GB/6_GB_1.png"));
//    GBiconI[6][0] = QIcon(QPixmap(":/pic/deviceicon/I/GB/7_GB_0.png"));
//    GBiconI[6][1] = QIcon(QPixmap(":/pic/deviceicon/I/GB/7_GB_1.png"));
//    GBiconI[7][0] = QIcon(QPixmap(":/pic/deviceicon/I/GB/8_GB_0.png"));
// //   GBicon[7][1] = QIcon(QPixmap(":/pic/GB/8_GB_1.png"));

//    YBiconI[0][0] = QIcon(QPixmap(":/pic/deviceicon/I/YB/1_YB_0.png"));
//    YBiconI[0][1] = QIcon(QPixmap(":/pic/deviceicon/I/YB/1_YB_1.png"));
//    YBiconI[1][0] = QIcon(QPixmap(":/pic/deviceicon/I/YB/2_YB_0.png"));
//    YBiconI[1][1] = QIcon(QPixmap(":/pic/deviceicon/I/YB/2_YB_1.png"));
//    YBiconI[2][0] = QIcon(QPixmap(":/pic/deviceicon/I/YB/3_YB_0.png"));
//    YBiconI[2][1] = QIcon(QPixmap(":/pic/deviceicon/I/YB/3_YB_1.png"));
//    YBiconI[3][0] = QIcon(QPixmap(":/pic/deviceicon/I/YB/4_YB_0.png"));
//    YBiconI[3][1] = QIcon(QPixmap(":/pic/deviceicon/I/YB/4_YB_1.png"));
//    YBiconI[4][0] = QIcon(QPixmap(":/pic/deviceicon/I/YB/5_YB_0.png"));
//    YBiconI[4][1] = QIcon(QPixmap(":/pic/deviceicon/I/YB/5_YB_1.png"));
//    YBiconI[5][0] = QIcon(QPixmap(":/pic/deviceicon/I/YB/6_YB_0.png"));
//    YBiconI[5][1] = QIcon(QPixmap(":/pic/deviceicon/I/YB/6_YB_1.png"));
//    YBiconI[6][0] = QIcon(QPixmap(":/pic/deviceicon/I/YB/7_YB_0.png"));
//    YBiconI[6][1] = QIcon(QPixmap(":/pic/deviceicon/I/YB/7_YB_1.png"));
//    YBiconI[7][0] = QIcon(QPixmap(":/pic/deviceicon/I/YB/8_YB_0.png"));
// //   YBiconI[7][1] = QIcon(QPixmap(":/pic/YB/8_YB_1.png"));

//    ZMiconI[0][0] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/1_ZM_0.png"));
//    ZMiconI[0][1] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/1_ZM_1.png"));
//    ZMiconI[1][0] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/2_ZM_0.png"));
//    ZMiconI[1][1] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/2_ZM_1.png"));
//    ZMiconI[2][0] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/3_ZM_0.png"));
//    ZMiconI[2][1] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/3_ZM_1.png"));
//    ZMiconI[3][0] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/4_ZM_0.png"));
//    ZMiconI[3][1] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/4_ZM_1.png"));
//    ZMiconI[4][0] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/5_ZM_0.png"));
//    ZMiconI[4][1] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/5_ZM_1.png"));
//    ZMiconI[5][0] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/6_ZM_0.png"));
//    ZMiconI[5][1] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/6_ZM_1.png"));
//    ZMiconI[6][0] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/7_ZM_0.png"));
//    ZMiconI[6][1] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/7_ZM_1.png"));
//    ZMiconI[7][0] = QIcon(QPixmap(":/pic/deviceicon/I/ZM/8_ZM_0.png"));
// //   ZMiconI[7][1] = QIcon(QPixmap(":/pic/ZM/8_ZM_1.png"));

//    KDiconI[0][0] = QIcon(QPixmap(":/pic/deviceicon/I/KD/1_KD_0.png"));
//    KDiconI[0][1] = QIcon(QPixmap(":/pic/deviceicon/I/KD/1_KD_1.png"));
//    KDiconI[1][0] = QIcon(QPixmap(":/pic/deviceicon/I/KD/2_KD_0.png"));
//    KDiconI[1][1] = QIcon(QPixmap(":/pic/deviceicon/I/KD/2_KD_1.png"));
//    KDiconI[2][0] = QIcon(QPixmap(":/pic/deviceicon/I/KD/3_KD_0.png"));
//    KDiconI[2][1] = QIcon(QPixmap(":/pic/deviceicon/I/KD/3_KD_1.png"));
//    KDiconI[3][0] = QIcon(QPixmap(":/pic/deviceicon/I/KD/4_KD_0.png"));
//    KDiconI[3][1] = QIcon(QPixmap(":/pic/deviceicon/I/KD/4_KD_1.png"));
//    KDiconI[4][0] = QIcon(QPixmap(":/pic/deviceicon/I/KD/5_KD_0.png"));
//    KDiconI[4][1] = QIcon(QPixmap(":/pic/deviceicon/I/KD/5_KD_1.png"));
//    KDiconI[5][0] = QIcon(QPixmap(":/pic/deviceicon/I/KD/6_KD_0.png"));
//    KDiconI[5][1] = QIcon(QPixmap(":/pic/deviceicon/I/KD/6_KD_1.png"));
//    KDiconI[6][0] = QIcon(QPixmap(":/pic/deviceicon/I/KD/7_KD_0.png"));
//    KDiconI[6][1] = QIcon(QPixmap(":/pic/deviceicon/I/KD/7_KD_1.png"));
//    KDiconI[7][0] = QIcon(QPixmap(":/pic/deviceicon/I/KD/8_KD_0.png"));
//  //  KDiconII[7][1] = QIcon(QPixmap(":/pic/KD/8_KD_1.png"));

//    GBiconII[0][0] = QIcon(QPixmap(":/pic/deviceicon/II/GB/1_GB_0.png"));
//    GBiconII[0][1] = QIcon(QPixmap(":/pic/deviceicon/II/GB/1_GB_1.png"));
//    GBiconII[1][0] = QIcon(QPixmap(":/pic/deviceicon/II/GB/2_GB_0.png"));
//    GBiconII[1][1] = QIcon(QPixmap(":/pic/deviceicon/II/GB/2_GB_1.png"));
//    GBiconII[2][0] = QIcon(QPixmap(":/pic/deviceicon/II/GB/3_GB_0.png"));
//    GBiconII[2][1] = QIcon(QPixmap(":/pic/deviceicon/II/GB/3_GB_1.png"));
//    GBiconII[3][0] = QIcon(QPixmap(":/pic/deviceicon/II/GB/4_GB_0.png"));
//    GBiconII[3][1] = QIcon(QPixmap(":/pic/deviceicon/II/GB/4_GB_1.png"));
//    GBiconII[4][0] = QIcon(QPixmap(":/pic/deviceicon/II/GB/5_GB_0.png"));
//    GBiconII[4][1] = QIcon(QPixmap(":/pic/deviceicon/II/GB/5_GB_1.png"));
//    GBiconII[5][0] = QIcon(QPixmap(":/pic/deviceicon/II/GB/6_GB_0.png"));
//    GBiconII[5][1] = QIcon(QPixmap(":/pic/deviceicon/II/GB/6_GB_1.png"));
//    GBiconII[6][0] = QIcon(QPixmap(":/pic/deviceicon/II/GB/7_GB_0.png"));
//    GBiconII[6][1] = QIcon(QPixmap(":/pic/deviceicon/II/GB/7_GB_1.png"));
//    GBiconII[7][0] = QIcon(QPixmap(":/pic/deviceicon/II/GB/8_GB_0.png"));
// //   GBicon[7][1] = QIcon(QPixmap(":/pic/GB/8_GB_1.png"));

//    YBiconII[0][0] = QIcon(QPixmap(":/pic/deviceicon/II/YB/1_YB_0.png"));
//    YBiconII[0][1] = QIcon(QPixmap(":/pic/deviceicon/II/YB/1_YB_1.png"));
//    YBiconII[1][0] = QIcon(QPixmap(":/pic/deviceicon/II/YB/2_YB_0.png"));
//    YBiconII[1][1] = QIcon(QPixmap(":/pic/deviceicon/II/YB/2_YB_1.png"));
//    YBiconII[2][0] = QIcon(QPixmap(":/pic/deviceicon/II/YB/3_YB_0.png"));
//    YBiconII[2][1] = QIcon(QPixmap(":/pic/deviceicon/II/YB/3_YB_1.png"));
//    YBiconII[3][0] = QIcon(QPixmap(":/pic/deviceicon/II/YB/4_YB_0.png"));
//    YBiconII[3][1] = QIcon(QPixmap(":/pic/deviceicon/II/YB/4_YB_1.png"));
//    YBiconII[4][0] = QIcon(QPixmap(":/pic/deviceicon/II/YB/5_YB_0.png"));
//    YBiconII[4][1] = QIcon(QPixmap(":/pic/deviceicon/II/YB/5_YB_1.png"));
//    YBiconII[5][0] = QIcon(QPixmap(":/pic/deviceicon/II/YB/6_YB_0.png"));
//    YBiconII[5][1] = QIcon(QPixmap(":/pic/deviceicon/II/YB/6_YB_1.png"));
//    YBiconII[6][0] = QIcon(QPixmap(":/pic/deviceicon/II/YB/7_YB_0.png"));
//    YBiconII[6][1] = QIcon(QPixmap(":/pic/deviceicon/II/YB/7_YB_1.png"));
//    YBiconII[7][0] = QIcon(QPixmap(":/pic/deviceicon/II/YB/8_YB_0.png"));
// //   YBiconI[7][1] = QIcon(QPixmap(":/pic/YB/8_YB_1.png"));

//    ZMiconII[0][0] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/1_ZM_0.png"));
//    ZMiconII[0][1] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/1_ZM_1.png"));
//    ZMiconII[1][0] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/2_ZM_0.png"));
//    ZMiconII[1][1] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/2_ZM_1.png"));
//    ZMiconII[2][0] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/3_ZM_0.png"));
//    ZMiconII[2][1] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/3_ZM_1.png"));
//    ZMiconII[3][0] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/4_ZM_0.png"));
//    ZMiconII[3][1] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/4_ZM_1.png"));
//    ZMiconII[4][0] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/5_ZM_0.png"));
//    ZMiconII[4][1] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/5_ZM_1.png"));
//    ZMiconII[5][0] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/6_ZM_0.png"));
//    ZMiconII[5][1] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/6_ZM_1.png"));
//    ZMiconII[6][0] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/7_ZM_0.png"));
//    ZMiconII[6][1] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/7_ZM_1.png"));
//    ZMiconII[7][0] = QIcon(QPixmap(":/pic/deviceicon/II/ZM/8_ZM_0.png"));
// //   ZMiconI[7][1] = QIcon(QPixmap(":/pic/ZM/8_ZM_1.png"));

//    KDiconII[0][0] = QIcon(QPixmap(":/pic/deviceicon/II/KD/1_KD_0.png"));
//    KDiconII[0][1] = QIcon(QPixmap(":/pic/deviceicon/II/KD/1_KD_1.png"));
//    KDiconII[1][0] = QIcon(QPixmap(":/pic/deviceicon/II/KD/2_KD_0.png"));
//    KDiconII[1][1] = QIcon(QPixmap(":/pic/deviceicon/II/KD/2_KD_1.png"));
//    KDiconII[2][0] = QIcon(QPixmap(":/pic/deviceicon/II/KD/3_KD_0.png"));
//    KDiconII[2][1] = QIcon(QPixmap(":/pic/deviceicon/II/KD/3_KD_1.png"));
//    KDiconII[3][0] = QIcon(QPixmap(":/pic/deviceicon/II/KD/4_KD_0.png"));
//    KDiconII[3][1] = QIcon(QPixmap(":/pic/deviceicon/II/KD/4_KD_1.png"));
//    KDiconII[4][0] = QIcon(QPixmap(":/pic/deviceicon/II/KD/5_KD_0.png"));
//    KDiconII[4][1] = QIcon(QPixmap(":/pic/deviceicon/II/KD/5_KD_1.png"));
//    KDiconII[5][0] = QIcon(QPixmap(":/pic/deviceicon/II/KD/6_KD_0.png"));
//    KDiconII[5][1] = QIcon(QPixmap(":/pic/deviceicon/II/KD/6_KD_1.png"));
//    KDiconII[6][0] = QIcon(QPixmap(":/pic/deviceicon/II/KD/7_KD_0.png"));
//    KDiconII[6][1] = QIcon(QPixmap(":/pic/deviceicon/II/KD/7_KD_1.png"));
//    KDiconII[7][0] = QIcon(QPixmap(":/pic/deviceicon/II/KD/8_KD_0.png"));
//  //  KDiconII[7][1] = QIcon(QPixmap(":/pic/KD/8_KD_1.png"));

////#define GREENICON 0
////#define REDICON 1
////#define GREYICON 2
////#define BLUEICON 3
////#define YELLOWICON 4

//    pix_CONGB[REDICON][0] = tr(":/pic/CONGBred0.png");//
//    pix_CONGB[REDICON][1] = tr(":/pic/CONGBred1.png");//

//    pix_CONGB[GREENICON][0] = tr(":/pic/CONGBgreen0.png");//
//    pix_CONGB[GREENICON][1] = tr(":/pic/CONGBgreen1.png");//

//    pix_CONGB[YELLOWICON][0] = tr(":/pic/CONGByellow0.png");//
//    pix_CONGB[YELLOWICON][1] = tr(":/pic/CONGByellow1.png");//

//    pix_CONGB[GREYICON][0] = tr(":/pic/CONGBgrey0.png");//
//    pix_CONGB[GREYICON][1] = tr(":/pic/CONGBgrey1.png");//

//    pix_CONKD[REDICON][0] = tr(":/pic/CONKDred0.png");//
//    pix_CONKD[REDICON][1] = tr(":/pic/CONKDred1.png");//

//    pix_CONKD[GREENICON][0] = tr(":/pic/CONKDgreen0.png");//
//    pix_CONKD[GREENICON][1] = tr(":/pic/CONKDgreen1.png");//

//    pix_CONKD[YELLOWICON][0] = tr(":/pic/CONKDyellow0.png");//
//    pix_CONKD[YELLOWICON][1] = tr(":/pic/CONKDyellow1.png");//

//    pix_CONKD[GREYICON][0] = tr(":/pic/CONKDgrey0.png");//
//    pix_CONKD[GREYICON][1] = tr(":/pic/CONKDgrey1.png");//

//    pix_start = tr(":/pic/START.png");
//    pix_end   = tr(":/pic/END.png");
//    pix_empty = tr(":/pic/EMPTY.png");

//}

void WidgetMain::remotesnd_result_slot(int logicaddr,int type,int subtype, int rs)
{
//    u8 phyaddr = pvalid_cfg_info->info[logicaddr].phy_addr;
//    u8 comPort = pvalid_cfg_info->info[logicaddr].com_id;

//    QString DevInfostr;
//    QString CMDstr;
//    QString ResltStr;

//    DevInfostr = QString(tr("%1串口%2号设备下发")).arg(comPort).arg(phyaddr);

//    if(rs == RESULT_SUCCESS)
//    {
//        ResltStr = QString(tr("成功!"));
//    }
//    else
//    {
//        ResltStr = QString(tr("失败!"));
//    }

//    if(type == INFO_SETTING)
//    {
//        if(subtype == INFO_SETTING_READ)
//        {
//             CMDstr = QString(tr("远程定值读取"));
//        }
//        else if(type == INFO_SETTING_WRITE)
//        {
//             CMDstr = QString(tr("远程定值设置"));
//        }
//        else
//        {
//             CMDstr = QString(tr("未知命令"));
//        }
//    }
//    else if(type == INFO_CONTROL)
//    {
//        switch(subtype)
//        {
//        case ID_RESET:
//            CMDstr = QString(tr("远程重置"));
//            break;
//        case ID_RELAYON:
//            CMDstr = QString(tr("远程合闸"));
//            break;
//        case ID_RELAYOFF:
//            CMDstr = QString(tr("远程分闸"));
//            break;
//        case ID_TEST1:
//            CMDstr = QString(tr("漏电闭锁测试"));
//        }
//    }
//    else
//    {
//        qDebug()<<"warning unknow type"<<type;
//    }
//    QString displaystr = CMDstr  + DevInfostr + ResltStr;
//    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString(tr("提示")),displaystr);
//    QTimer::singleShot(2000,m_box,SLOT(accept()));
//    m_box->exec();
}

void WidgetMain::remotercv_result_slot(int logicaddr, int type, int subtype, int rs)
{
//    u8 phyaddr = pvalid_cfg_info->info[logicaddr].phy_addr;
//    u8 comPort = pvalid_cfg_info->info[logicaddr].com_id;

//    //QString DevInfostr;
//    QString CMDstr;
//    QString ResltStr;

//   // DevInfostr = QString(tr("%1串口%2号设备")).arg(comPort).arg(phyaddr);


//    if(rs == RESULT_TIMEOUT)
//    {
//        ResltStr = QString(tr("超时!"));
//    }
//    else if(rs == RESULT_SUCCESS)
//    {
//        ResltStr = QString(tr("成功!"));
//    }
//    else
//    {
//        ResltStr = QString(tr("失败!"));
//    }

//    if(type == INFO_SETTING)
//    {
//        if(subtype == INFO_SETTING_READ)
//        {
//             CMDstr = QString(tr("远程定值读取"));
//        }
//        else if(type == INFO_SETTING_WRITE)
//        {
//             CMDstr = QString(tr("远程定值设置"));
//        }
//        else
//        {
//             CMDstr = QString(tr("未知命令"));
//        }
//    }
//    else if(type == INFO_CONTROL)
//    {
//        switch(subtype)
//        {
//        case ID_RESET:
//            CMDstr = QString(tr("远程重置"));
//            break;
//        case ID_RELAYON:
//            CMDstr = QString(tr("远程合闸"));
//            break;
//        case ID_RELAYOFF:
//            CMDstr = QString(tr("远程分闸"));
//            break;
//        case ID_TEST1:
//            CMDstr = QString(tr("远程测试"));
//        }
//    }
//    else
//    {
//        qDebug()<<"warning unknow type"<<type;
//    }
//    QString displaystr = CMDstr   + ResltStr;
//    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString(tr("提示")),displaystr);
//    QTimer::singleShot(2000,m_box,SLOT(accept()));
//    m_box->exec();
}

void WidgetMain::remoteSETTINGrcvResultSlot(int logicaddr, int result, u8 num, u32 *data)
{
//    u8 phyaddr = pvalid_cfg_info->info[logicaddr].phy_addr;
//    u8 comPort = pvalid_cfg_info->info[logicaddr].com_id;

//  //  QString DevInfostr;
//    QString CMDstr;
//    QString ResltStr;

//  //  DevInfostr = QString(tr("%1串口%2号设备")).arg(comPort).arg(phyaddr);

//    if(result == RESULT_SUCCESS)
//    {
//        ResltStr = QString(tr("成功!"));
//    }
//    else
//    {
//        ResltStr = QString(tr("失败!"));
//    }

//    if(num > 0) // constant write
//    {
//        CMDstr = QString(tr("远程写定值"));
//    }
//    else
//    {
//        CMDstr = QString(tr("远程读定值"));
//    }

//    QString displaystr = CMDstr  + ResltStr;
//    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString(tr("提示")),displaystr);
//    QTimer::singleShot(2000,m_box,SLOT(accept()));
//    m_box->exec();
}

void WidgetMain::remoteswitch_local_remote_slot(INT8U currentmode)
{
    if(currentmode == LOCAL_MODE)
    {
        ui->label_modelocate->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->label_moderemote->setStyleSheet("background-color: rgb(255, 255, 255);");
    }
    else
    {
       ui->label_modelocate->setStyleSheet("background-color: rgb(255, 255, 255);");
       ui->label_moderemote->setStyleSheet("background-color: rgb(0, 255, 0);");
    }
}
