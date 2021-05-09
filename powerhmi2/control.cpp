#include "control.h"
#include "ui_control.h"
#include <qmessagebox.h>
#include <QDebug>

Control::Control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Control)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

Control::~Control()
{
    delete ui;
}

void Control::EnterProcess(INT32S LogicAddr)
{
    mLogicAddr = LogicAddr;
    DisplayControlUI(LogicAddr);
}

void Control::changeEvent(QEvent *e)
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
void Control::DisplayControlUI(INT32S LogicAddr)
{
    ui->label_addr->setText(QString::number(pDeviceDataBase->SysCfgData.DevInfo[LogicAddr].phy_addr,10).append("#"));

    INT8U tTypeIndex = pDeviceDataBase->SysCfgData.DevInfo[LogicAddr].rtu_typeIndex;
    INT8S tVerIndex  = pDeviceDataBase->SysCfgData.DevInfo[LogicAddr].rtu_typeVer;

    QString tNameStr = QLatin1String(pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].ProtoName);
    ui->label_type->setText(tNameStr);
    ui->label_com->setText("COM"+QString::number(pDeviceDataBase->SysCfgData.DevInfo[LogicAddr].com_id));
    /**************************/

    mDevStatusIndex = 0;
    mDevStatus = 0;
    mErrorStatusIndex = 0;
    mErrorTotal = 0;
    mErrorStatus = 0;
//    mPowerStampStatus=0;
//    mPowerStampIndex=0;


    if(pDeviceDataBase->DeviceValue[LogicAddr].isIntern)
    {
        mDevStatusIndex = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].SwitchStatusParseInternSection.MapIndex;
        mDevStatus = pDeviceDataBase->DeviceValue[mLogicAddr].value[INFO_MEASURE_INTER_1].ValueData[mDevStatusIndex];
        mErrorStatusIndex = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].FaultParseInternSection.MapIndex[0];  // only one
        mErrorStatus = pDeviceDataBase->DeviceValue[mLogicAddr].value[INFO_MEASURE_INTER_1].ValueData[mErrorStatusIndex];
    }
    else
    {
        mDevStatusIndex = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].SwitchStatusParseSection.MapIndex;
        mDevStatus = pDeviceDataBase->DeviceValue[mLogicAddr].value[INFO_MEASURE_1].ValueData[mDevStatusIndex];
        mErrorTotal = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].FaultParseSection.Total;
        for(int i =0;i<mErrorTotal;i++)
        {
            mErrorStatusIndex = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].FaultParseSection.MapIndex[i];
            mErrorStatus += pDeviceDataBase->DeviceValue[mLogicAddr].value[INFO_SWITCH].ValueData[mErrorStatusIndex];
        }
    }
    qDebug()<<__FUNCTION__<<__LINE__<<pDeviceDataBase->DeviceValue[LogicAddr].isIntern<<mDevStatusIndex<<mDevStatus<<mErrorStatusIndex<<mErrorStatus;

    if(mErrorStatus)
    {
        ui->label_stat1->setText(tr("故障状态"));
    }
    else
    {
        if(mDevStatus == RELAY_STATUS_ON)
        {
            ui->label_stat1->setText(tr("合闸运行"));
            ui->label_stat1->setStyleSheet("background-color: rgb(255, 0, 0);border-radius:40px;border-color: rgb(0, 0, 0);border-width: 1px;"); //background-color: rgb(0, 255, 0);border-radius:40px;border-color: rgb(0, 0, 0);border-width: 1px;
        }
        else
        {
            ui->label_stat1->setText(tr("分闸待机"));
            ui->label_stat1->setStyleSheet("background-color: rgb(0, 255, 0);border-radius:40px;border-color: rgb(0, 0, 0);border-width: 1px;");
        }
    }

    mSelectCode = CONTROL_RELAY_ON;
    ui->relay_on->setStyleSheet("background-color: rgb(0, 255, 0);");
}
void Control::keyPressEvent(QKeyEvent *e)
{
    if(!e->isAutoRepeat())
    {
        switch(e->key())
        {
        case Qt::Key_F1:key_f1_press();break;
        case Qt::Key_Return:key_return_press();break;
        case Qt::Key_Escape:key_escape_press();break;
        }
    }
}
void Control::key_f1_press()
{
    mSelectCode++;
    if(mSelectCode >= CONTROL_MAX_SELECT)
        mSelectCode = CONTROL_RELAY_ON;
    switch(mSelectCode)
    {
    case CONTROL_RELAY_ON:
        ui->relay_on->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->relay_off->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->reset->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->test->setStyleSheet("background-color: rgb(255, 255, 255);");
        break;
    case CONTROL_RELAY_OFF:
        ui->relay_on->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->relay_off->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->reset->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->test->setStyleSheet("background-color: rgb(255, 255, 255);");
        break;
    case CONTROL_RESET:
        ui->relay_on->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->relay_off->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->reset->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->test->setStyleSheet("background-color: rgb(255, 255, 255);");
        break;
    case CONTROL_TEST:
        ui->relay_on->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->relay_off->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->reset->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->test->setStyleSheet("background-color: rgb(0, 255, 0);");
        break;
    default:
        ui->relay_on->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->relay_off->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->reset->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->test->setStyleSheet("background-color: rgb(255, 255, 255);");
        break;
    }
}
void Control::key_return_press()
{
    switch(mSelectCode)
    {
    case CONTROL_RELAY_ON:
        HandleRelayOn();
        break;
    case CONTROL_RELAY_OFF:
        HandleRelayOff();
        break;
    case CONTROL_RESET:
        HandleReset();
        break;
    case CONTROL_TEST:
        HandleTest();
        break;
    default:
        break;
    }
}
void Control::key_escape_press()
{
    switch(mSelectCode)
    {
    case CONTROL_RELAY_ON:
        ui->relay_on->setStyleSheet("background-color: rgb(255, 255, 255);");
        break;
    case CONTROL_RELAY_OFF:
        ui->relay_off->setStyleSheet("background-color: rgb(255, 255, 255);");
        break;
    case CONTROL_RESET:
        ui->reset->setStyleSheet("background-color: rgb(255, 255, 255);");
        break;
    case CONTROL_TEST:
        ui->test->setStyleSheet("background-color: rgb(255, 255, 255);");
        break;
    default:
        ui->relay_on->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->relay_off->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->reset->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->test->setStyleSheet("background-color: rgb(255, 255, 255);");
        break;

    }
    this->close();
}
void Control::HandleReset()
{
    if(QMessageBox::Yes == QMessageBox::information(this,tr("警告"),tr("是否要复归?"),QMessageBox::Yes,QMessageBox::No))
    {
        HandleControl(CONTROL_RESET);
    }
}
void Control::HandleRelayOn()
{
     if(QMessageBox::Yes == QMessageBox::information(this,tr("警告"),tr("是否合闸执行?"),QMessageBox::Yes,QMessageBox::No))
     {
         HandleControl(CONTROL_RELAY_ON);
     }

}
void Control::HandleRelayOff()
{
     if(QMessageBox::Yes == QMessageBox::information(this,tr("警告"),tr("是否分闸执行?"),QMessageBox::Yes,QMessageBox::No))
     {
        HandleControl(CONTROL_RELAY_OFF);
     }
}

void Control::HandleTest()
{
    if(QMessageBox::Yes == QMessageBox::information(this,tr("警告"),tr("是否测试?"),QMessageBox::Yes,QMessageBox::No))
    {
       HandleControl(CONTROL_TEST);
    }
}

void Control::HandleControl(INT8U Channel)
{
    INT32S tComPort    = mLogicAddr/16;
    INT32S tLogicIndex = mLogicAddr%16;

    QUEUE_MSG ControlMsg;
    memset(&ControlMsg,0x00,sizeof(QUEUE_MSG));
    if(tComPort >= 0 && tComPort <= 5) //
    {
        switch(Channel)
        {
        case CONTROL_RELAY_ON:
            ControlMsg.MsgType = FRAME_RELAYON;
            break;
        case CONTROL_RELAY_OFF:
            ControlMsg.MsgType = FRAME_RELAYOFF;
            break;
        case CONTROL_RESET:
            ControlMsg.MsgType = FRAME_RESET;
            break;
        case CONTROL_TEST:
            ControlMsg.MsgType = FRAME_TEST1;
            break;
        default:
            ControlMsg.MsgType = FRAME_COIL_OPERATION;
            break;
        }

        ControlMsg.Source     = SOURCE_HMI;
        ControlMsg.LogicAddr  = mLogicAddr;
        ControlMsg.PhyAddr    = pDeviceDataBase->SysCfgData.DevInfo[mLogicAddr].phy_addr;
        ControlMsg.ComPort    = tComPort;
        ControlMsg.LogicIndex = tLogicIndex;
        ControlMsg.GroupIndex = Channel; //

        pMsgQueueMutex[tComPort]->lock();
        pMsgQueue[tComPort]->enqueue(ControlMsg);
        pMsgQueueMutex[tComPort]->unlock();
    }
}

void Control::UpdateControlCoilSlot(INT8U LogicAddr,INT8U FrameType,INT8U Source,INT8U ChannelIndex)
{
    INT8U tTypeIndex = pDeviceDataBase->SysCfgData.DevInfo[LogicAddr].rtu_typeIndex;
    INT8S tVerIndex  = pDeviceDataBase->SysCfgData.DevInfo[LogicAddr].rtu_typeVer;
    QString tDisplayStr;

    if(ChannelIndex < MAX_CHANNEL_NUM)
    {
        if(Source == SOURCE_TCP)
        {
            tDisplayStr = tr("远程");
        }

        switch(FrameType)
        {
        case FRAME_COIL_OPERATION: //开关量控制
             tDisplayStr += tr("开关量操作命令:") + QString(pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].SwitchControlSection.Point[ChannelIndex].Desc);
             break;
        case FRAME_RELAYON:
             tDisplayStr += tr("合闸命令");
             break;
        case FRAME_RELAYOFF:
             tDisplayStr += tr("分闸命令");
             break;
        case FRAME_TEST1:
             tDisplayStr += tr("测试命令");
             break;
        case FRAME_RESET:
             tDisplayStr += tr("重置命令");
             break;
        }

        switch(pDeviceDataBase->DeviceValue[LogicAddr].Result)
        {
        case RESULT_SUCCESS:
             tDisplayStr += tr("成功");
             break;
        case RESULT_SEND_ERROR:
             tDisplayStr += tr("发送失败");
             break;
        case RESULT_RECV_TIMEOUT:
             tDisplayStr += tr("超时");
             break;
        case RESULT_CRC_ERROR:
             tDisplayStr += tr("CRC校验失败");
             break;
        case RESULT_FAILED:
             tDisplayStr += tr("失败");
             break;
        }

        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString(tr("提示")),QString(tDisplayStr));
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->exec();
    }
}
