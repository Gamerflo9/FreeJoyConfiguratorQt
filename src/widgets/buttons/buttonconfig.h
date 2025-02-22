#ifndef BUTTONCONFIG_H
#define BUTTONCONFIG_H

#include <QWidget>

#include "buttonlogical.h"
#include "buttonphysical.h"

#include "common_defines.h"
#include "common_types.h"

#include "deviceconfig.h"
#include "global.h"

//#define DYNAMIC_CREATION
#ifdef DYNAMIC_CREATION
    //#define DYNAMIC_CREATION_ALL
#endif
namespace Ui {
class ButtonConfig;
}

class ButtonConfig : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonConfig(QWidget *parent = nullptr);
    ~ButtonConfig();

    void readFromConfig();
    void writeToConfig();
    void buttonStateChanged();

    void retranslateUi();

signals:
    void encoderInputChanged(int ecoder_A, int ecoder_B);
    void logicalButtonsCreated();

public slots:
    void setUiOnOff(int value);

private slots:
    void functionTypeChanged(int index, int functionPreviousIndex, int buttonIndex);
    void setPhysicButton(int buttonIndex);

#ifdef DYNAMIC_CREATION
private slots:
    void logScrollValueChanged(int value);
    void createLogButtons(int count);
protected:
    void resizeEvent(QResizeEvent *event) override;
#endif

    void on_checkBox_AutoPhysBut_toggled(bool checked);

private:
    Ui::ButtonConfig *ui;
    void physButtonsCreator(int count);
    QString m_defaultShiftStyle;

    int m_logicButtonInFocus;
    bool m_autoPhysButEnabled;

    bool m_isShifts_act;
    bool m_shift1_act;
    bool m_shift2_act;
    bool m_shift3_act;
    bool m_shift4_act;
    bool m_shift5_act;

    void logicaButtonsCreator();

    QList<ButtonLogical *> m_logicButtonPtrList;
    QList<ButtonPhysical *> m_PhysButtonPtrList;
};

#endif // BUTTONCONFIG_H
