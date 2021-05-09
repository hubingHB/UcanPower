#ifndef WIDGETMAIN_H
#define WIDGETMAIN_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include "DefineDb.h"
//#include "basiccommu.h"
//#include "communication.h"
//#include "measure.h"
//#include "constant.h"
//#include "control.h"
//#include "operate.h"
//#include "fault.h"
//#include "audioplay.h"
//#include "sysconfig.h"
#include <QFrame>
#include <QLabel>
#include <QIcon>

#define FLAG_DISPLAY_COMMU    0
#define FLAG_DISPLAY_STRUCT   1

namespace Ui {
    class WidgetMain;
}

class WidgetMain : public QWidget {
    Q_OBJECT
public:
    WidgetMain(QWidget *parent = 0);
    ~WidgetMain();

//    CONFIGURE_FILE_CONTENT * pvalid_cfg_info;
//    sysStruct              * psystemStruct;
//    ProtocolList           * pProtocollistIns;

//    ALL_TYPE_VALUE         * pRealtimeData;

    Deivce_DataBase *pDeviceDataBase;
    int mFunCode = 1;

//     void initIconArray();

     QIcon GBiconI[8][2]; // 0 without tail ; 1 without tail;
     QIcon YBiconI[8][2];
     QIcon KDiconI[8][2];
     QIcon ZMiconI[8][2];

     QIcon GBiconII[8][2]; // 0 without tail ; 1 without tail;
     QIcon YBiconII[8][2];
     QIcon KDiconII[8][2];
     QIcon ZMiconII[8][2];

     QIcon DisplayIcon;

     void testpic();

     QPixmap total_pixmap0;
     QPixmap total_pixmap1;
     QPixmap total_pixmap2;
     QPixmap total_pixmap3;

     QString pix_CONGB[5][2];
     QString pix_CONKD[5][2];
     QString pix_start;
     QString pix_end;
     QString pix_empty;

     QString displaystr;
     QPixmap DisplayPix0;
     QPixmap DisplayPix1;
     QPixmap DisplayPix2;
     QPixmap DisplayPix3;


protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *e);

signals:
    void MeasureInsDisplaysignal(int LogicAddr);
    void ConstantInsDisplaysignal(int LogicAddr);
    void controlInsDisplaysignal(int LogicAddr);
    void sysconfigDisplaysignal();

    void faulthistoryDisplaysignal();
    void faultrealtimeDisplaysignal();

    void PowerDownStampSetupsignal();
    void PowerDownStampDisplaysignal();

    void powerusrloginDisplaysignal();

public:
    Ui::WidgetMain *ui;

    int checktimes;
    int checkindex = 0;
    int *psysMode;


    u8 deviceprotoisIntern[MAX_RTU_NUM]; // proto is intern or not.

    INT32S mDisPlayFlag = FLAG_DISPLAY_COMMU;

    int structinitflag = 0;

    int currentLogicaddr=0;


    int getdevicestatus(int logicaddr);
    int pointerinit();

    void ui_init();
    void ui_display_info();

    QTimer mClockTimer;

    void key_f1_press();
    void key_f2_press();
    void key_f3_press();
    void key_up_press();
    void key_down_press();
    void key_left_press();
    void key_right_press();
    void key_return_press();
    void select_dev(int last,int now);
    int handle_value_adjust(float value);

    // 9 mainfunction
    void user_loginprocess();
    void modeswitchprocess();
    void sysviewswitchprocess();
    void ui_measure_show(int LogicAddr);
    void ui_constant_show(int LogicAddr);
    void ui_control_show(int LogicAddr);
    void ui_soe_show(int LogicAddr);
    void ui_commu_show(int LogicAddr);
    void ui_operate_show(int LogicAddr);
    void ui_sys_config_show();


    void UIUpdateSingleDevStatus(INT8U LogicAddr,INT8U FrameType,INT8U GroupIndex);

private slots:
    void DisplayTimeSlot();

    void ui_commu_update();

    void ui_handle_server();

    void usrloginslot();
    void usrlogoutslot();
public slots:
    void remotesnd_result_slot(int logicaddr, int type, int subtype, int rs);
    void remotercv_result_slot(int logicaddr, int type, int subtype, int rs);
    void remoteSETTINGrcvResultSlot(int logicaddr,int result,u8 num,u32 *data);

    void remoteswitch_local_remote_slot(INT8U currentmode);


    //数据更新刷新界面
    void UpdateDevStatusSlot(INT8U LogicAddr,INT8U FrameType,INT8U GroupIndex);

};

#endif // WIDGETMAIN_H
