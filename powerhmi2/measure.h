#ifndef MEASURE_H
#define MEASURE_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include "DefineDb.h"

namespace Ui {
    class Measure;
}

class Measure : public QWidget {

    Q_OBJECT
public:
    Measure(QWidget *parent = 0);
    ~Measure();


    void EnterProcess(INT32S LogicAddr);
    void DisplayMeasure(INT32S LogicAddr);

    Deivce_DataBase *pDeviceDataBase;
    INT32S mLogicAddr;
    INT32S mEnterFlag;
    void UpdateDisplayValue();

public slots:
    //void update_display(ALL_TYPE_VALUE *value);

    void UpdateDevStatusSlot(INT8U LogicAddr,INT8U FrameType,INT8U GroupIndex);
signals:
    void update_value(int logicaddr);
protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *e);
private:
    Ui::Measure *ui;
    QTimer update;
//    void update_display_row(int index,int dis);
private slots:
//    void get_value();
};
#endif // MEASURE_H
