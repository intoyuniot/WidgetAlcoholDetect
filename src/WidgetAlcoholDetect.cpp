#include "WidgetAlcoholDetect.h"


WidgetAlcoholDetect::WidgetAlcoholDetect(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pDataConcentrationTopic,0,sizeof(pDataConcentrationTopic));
    sprintf(pDataConcentrationTopic,"channel/alcoholDetect_%d/data/concentration",_Item);
}

WidgetAlcoholDetect::~WidgetAlcoholDetect()
{

}

void WidgetAlcoholDetect::begin(void (*UserCallBack)(void))
{

}

void WidgetAlcoholDetect::displayConcentration(int concentration)
{
    IntoRobot.publish(pDataConcentrationTopic,concentration);
}









