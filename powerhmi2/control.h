#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include "DefineDb.h"
#include <QMutex>
#include <QQueue>
namespace Ui {
    class Control;
}

class Control : public QWidget {
    Q_OBJECT
public:
    Control(QWidget *parent = 0);
    ~Control();
    void EnterProcess(INT32S LogicAddr);
    void DisplayControlUI(INT32S LogicAddr);

    void key_f1_press();
    void key_return_press();
    void key_escape_press();

    void HandleReset();
    void HandleRelayOn();
    void HandleRelayOff();
    void HandleTest();

    void HandleControl(INT8U Channel);

    Deivce_DataBase *pDeviceDataBase;
    QQueue<QUEUE_MSG> *pMsgQueue[MAX_COM_NUM];
    QMutex *pMsgQueueMutex[MAX_COM_NUM];

public slots:
    void UpdateControlCoilSlot(INT8U LogicAddr,INT8U FrameType,INT8U Source,INT8U ChannelIndex);



protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *e);
private:
    Ui::Control *ui;
    INT32S mLogicAddr;
    INT8U mSelectCode;
    INT8S mDevStatusIndex;
    INT8S mProtocolIndex;
    INT8S mDevStatus;
    INT8S mErrorStatusIndex;
    INT8S mErrorTotal;
    INT8S mErrorStatus;
};

#endif // CONTROL_H
