/*
 ************************************************************************
 * 作者:  IntoRobot Team
 * 版本:  V1.0.0
 * 日期:  03-30-15
 ************************************************************************
 功能描述：
 酒精含量检测器：检测酒精含量

 所需器件:
 1.MQ-3酒精乙醇传感器模块

 接线说明:
 MQ-3                         核心板
 1.VIN                        +5V
 2.GND                        GND
 3.AO                         A0
 4.DO                         悬空

 说明：带有“D”的为数字管脚，带有“A”的为模拟管脚，接线时请确认核心板引脚，避免接线错误。
 */

#include <WidgetAlcoholDetect.h>

#define beerPinAO  A0 //连接传感器模拟输出管脚
int soberReading;  //没有监测到酒精的阈值，实际中监测获取

WidgetAlcoholDetect alcohol = WidgetAlcoholDetect();

void setup()
{
    pinMode(beerPinAO, AN_INPUT);	//设置管脚为输入模式
    soberReading = analogRead(beerPinAO); //没有监测到酒精的阈值，实际中监测获取
}
float getAlcoholValue()
{
    // 电压每升高0.1V,实际被测气体的浓度增加约20ppm
    float ppm = (analogRead(beerPinAO) - soberReading)* (3.3/4095) * 10 * 20;
    ppm = ppm > 0 ?  ppm : 0;
    return ppm;
}
void loop()
{
    // 把获得的酒精浓度上传到云平台
    alcohol.displayConcentration(getAlcoholValue());
    delay(3000);
}
