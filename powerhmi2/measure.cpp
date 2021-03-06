#include "measure.h"
#include "ui_measure.h"
#include <math.h>
#include <QDebug>

Measure::Measure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Measure)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    qDebug()<<"measure";
}

Measure::~Measure()
{
    delete ui;
}

void Measure::changeEvent(QEvent *e)
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

void Measure::EnterProcess(INT32S LogicAddr)
{
    DisplayMeasure(LogicAddr);
    ui->label_debug->setText(QString::number(pDeviceDataBase->DeviceValue[LogicAddr].isIntern));
    mEnterFlag = 1;
}

void Measure::DisplayMeasure(INT32S LogicAddr)
{
  //  qDebug()<<__FUNCTION__<<__LINE__<<value->isIntern<<logic_addr;
    mLogicAddr = LogicAddr;

    ui->label_addr->setText(QString::number(pDeviceDataBase->SysCfgData.DevInfo[mLogicAddr].phy_addr,10).append("#"));
    INT8U tTypeIndex = pDeviceDataBase->SysCfgData.DevInfo[mLogicAddr].rtu_typeIndex;
    INT8U tVerIndex  = pDeviceDataBase->SysCfgData.DevInfo[mLogicAddr].rtu_typeVer;
    QString str = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].ProtoName;

    ui->label_type->setText(str);
    ui->label_com->setText("COM"+QString::number(pDeviceDataBase->SysCfgData.DevInfo[mLogicAddr].com_id));
    /**************************/
    QStringList header;
    header<<tr("名称")<<tr("数值")<<tr("单位及说明");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    INT32S tRowCnt = 0;
    INT8U tIsIntern = pDeviceDataBase->DeviceValue[mLogicAddr].isIntern;
    INT8U tGroupTotalNum = 0;



    if(tIsIntern)
    {
        tRowCnt = 0;
        tGroupTotalNum = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureInternTotalNum;

        for(INT32S tGroupId = 0; tGroupId < tGroupTotalNum; tGroupId++)
            tRowCnt += pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureInternSection[tGroupId].DisplayTotal;

        ui->tableWidget->setRowCount(tRowCnt);

        INT32S tMax = 0;
        INT32S tRowStart = 0;

        for(INT32S tGroupId = 0; tGroupId < tGroupTotalNum; tGroupId++)
        {
            tMax = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureInternSection[tGroupId].DisplayTotal;
            for(INT32S i = 0; i < tMax; i++)
            {
                ui->tableWidget->setItem(tRowStart+i,0,new QTableWidgetItem(pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureInternSection[tGroupId].Point[i].name));
                ui->tableWidget->setItem(tRowStart+i,2,new QTableWidgetItem(pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureInternSection[tGroupId].Point[i].comment));
            }
            tRowStart += tMax;
        }
    }
    else
    {
        tGroupTotalNum = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeaureTotalNum;
        tRowCnt = 0;
        for(INT32S tGroupId = 0; tGroupId < tGroupTotalNum; tGroupId++)
            tRowCnt += pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureSection[tGroupId].DisplayTotal;
        tRowCnt += pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].TeleActionSection.DisplayTotal;

        ui->tableWidget->setRowCount(tRowCnt);

        INT32S tMax = 0;
        INT32S tRowStart = 0;

        for(INT32S tGroupId = 0; tGroupId < tGroupTotalNum; tGroupId++)
        {
            tMax = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureSection[tGroupId].DisplayTotal;
            for(INT32S i = 0; i < tMax; i++)
            {
                ui->tableWidget->setItem(tRowStart+i,0,new QTableWidgetItem(pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureSection[tGroupId].Point[i].name));
                ui->tableWidget->setItem(tRowStart+i,2,new QTableWidgetItem(pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureSection[tGroupId].Point[i].comment));
            }
            tRowStart += tMax;
        }

        for(INT32S i =0;i < pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].TeleActionSection.DisplayTotal; i++)
        {
            ui->tableWidget->setItem(tRowStart+i,0,new QTableWidgetItem(pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].TeleActionSection.Point[i].name));
            ui->tableWidget->setItem(tRowStart+i,2,new QTableWidgetItem(pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].TeleActionSection.Point[i].comment));
        }
    }

//    update.start(500);
//    connect(&update,SIGNAL(timeout()),this,SLOT(update_displayValueslot()));
}
//void Measure::update_display_row(int index,int dis)
//{
//    //ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(valid_value.value[INFO])));
//}
//void Measure::get_value()
//{
//    emit update_value(logic_code);
//}
void Measure::UpdateDevStatusSlot(INT8U LogicAddr,INT8U FrameType,INT8U GroupIndex)
{
//    qDebug()<<__FUNCTION__<<__LINE__;
    if((mEnterFlag)&&(LogicAddr == mLogicAddr))
    {
        UpdateDisplayValue();
    }
}

void Measure::UpdateDisplayValue()
{
//    INT32S tTypeIndex = pDeviceDataBase->SysCfgData.DevInfo[mLogicAddr].rtu_typeIndex;
//    INT32S tVerIndex  = pDeviceDataBase->SysCfgData.DevInfo[mLogicAddr].rtu_typeVer;
    INT8U tIsIntern   = pDeviceDataBase->DeviceValue[mLogicAddr].isIntern;

    INT8U tTypeIndex = pDeviceDataBase->SysCfgData.DevInfo[mLogicAddr].rtu_typeIndex;
    INT8U tVerIndex  = pDeviceDataBase->SysCfgData.DevInfo[mLogicAddr].rtu_typeVer;

    QString tShowStr;
    INT32S tMax = 0;
    INT32S tRowStart = 0;
    INT32S tValueIndex = 0;

    FP32 tRatio = 0.0;

    INT8U tGroupTotalNum = 0;
    if(tIsIntern)
    {
         tMax = 0;
         tRowStart = 0;
         tValueIndex = INFO_MEASURE_INTER_1;
         tGroupTotalNum = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureInternTotalNum;

//         FP32 tRatio = 1;
//         for(INT32S i = 0; i < tTotal; i++)
//         {
//             tRatio = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].ConstantSection[tSectionIndex].Point[i].Ratio;

//
//             if(tRatio == 1)
//             {
//                 ui->tableWidget->setItem(i,tRatio,new QTableWidgetItem(QString::number(pDeviceDataBase->DeviceValue[LogicAddr].value[tValueIndex].ValueData[i])));
//             }
//             else
//             {
//                 float tDisplayValue = (float)pDeviceDataBase->DeviceValue[LogicAddr].value[tValueIndex].ValueData[i]/tRatio;
//                 ui->tableWidget->setItem(i,tCol,new QTableWidgetItem(QString::number(tDisplayValue ,'f',2)));
//             }
//         }

        for(INT32S tGroupId = 0; tGroupId < tGroupTotalNum; tGroupId++)
        {
            if(tGroupId==0)
                tValueIndex = INFO_MEASURE_INTER_1;
            else
                tValueIndex = INFO_MEASURE_INTER_2;

            tMax =pDeviceDataBase->DeviceValue[mLogicAddr].value[tValueIndex].ValueNum;

//            qDebug()<<__FUNCTION__<<__LINE__<<tMax;
            for(INT32S i = 0; i < tMax; i++)
            {
                tRatio = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureInternSection[tGroupId].Point[i].Ratio;

                tRatio = tRatio != 0 ? tRatio : 1;
                FP32 tDisplayValue = (float)pDeviceDataBase->DeviceValue[mLogicAddr].value[tValueIndex].ValueData[i]/tRatio;
                ui->tableWidget->setItem(tRowStart+i,1,new QTableWidgetItem(QString::number(tDisplayValue,'f',2)));
            }
            tRowStart += tMax;
        }
    }
    else
    {
        tMax = 0;
        tRowStart = 0;
        INT8U tValueIndexArray[7] = {INFO_MEASURE_1,INFO_MEASURE_2,INFO_MEASURE_3,INFO_MEASURE_4,INFO_MEASURE_5,INFO_MEASURE_6,INFO_SWITCH};
        tValueIndex = INFO_MEASURE_1;

        for(INT32S tGroupId = 0; tGroupId < 7; tGroupId++)
        {
            tValueIndex = tValueIndexArray[tGroupId];
            tMax = pDeviceDataBase->DeviceValue[mLogicAddr].value[tValueIndex].ValueNum;
            for(INT32S i = 0; i < tMax; i++)
            {
                if(tGroupId < 6) // Measure
                    tRatio = pDeviceDataBase->SysCfgData.ProtoCfgData[tTypeIndex][tVerIndex].MeasureSection[tGroupId].Point[i].Ratio;
                else // teleAction
                    tRatio = 1;
                tRatio = tRatio != 0 ? tRatio : 1;

                FP32 tDisplayValue = (float)pDeviceDataBase->DeviceValue[mLogicAddr].value[tValueIndex].ValueData[i]/tRatio;
                ui->tableWidget->setItem(tRowStart+i,1,new QTableWidgetItem(QString::number(tDisplayValue,'f',2)));
            }
            tRowStart += tMax;
        }
    }

    ui->label_send->setText(QString::number(pDeviceDataBase->DeviceValue[mLogicAddr].commu.tx_frame));
    ui->label_rec->setText(QString::number(pDeviceDataBase->DeviceValue[mLogicAddr].commu.rx_frame));
    ui->label_sbyte->setText(QString::number(pDeviceDataBase->DeviceValue[mLogicAddr].commu.tx_byte));
    ui->label_rbyte->setText(QString::number(pDeviceDataBase->DeviceValue[mLogicAddr].commu.rx_byte));

    if(pDeviceDataBase->DeviceValue[mLogicAddr].commu.status == COMM_STATUS_ON)
    {
        ui->label_stat->setText(tr("正常"));
    }
    else
    {
        ui->label_stat->setText(tr("异常"));
    }
}
void Measure::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape)
    {
        mEnterFlag = 0;
        update.stop();
        ui->tableWidget->clear();
        ui->label_type->clear();
        this->close();
    }
}
