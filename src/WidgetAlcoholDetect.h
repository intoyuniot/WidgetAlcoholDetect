#ifndef WIDGET_ALCOHO_DETECT_H_
#define WIDGET_ALCOHO_DETECT_H_

#include "application.h"


class WidgetAlcoholDetect
{
    public:
        WidgetAlcoholDetect(uint8_t ucItem = 0);
        ~WidgetAlcoholDetect();
        void begin(void (*UserCallBack)(void) = NULL);
        void displayConcentration(int concentration);

    private:
        char pDataConcentrationTopic[64];
        uint8_t _Item=0;
};

#endif
