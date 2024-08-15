/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "globalSetting.h"
#include "crabmodule.h"
void app_main(void)
{
    // xTaskCreatePinnedToCore(Lm75Task, "gda", 1024 * 5, NULL, 1, NULL, 1);
    // 硬件初始化
    // I2c_Init();
    // Wifi_STA_Init();
    // Ble_Init();
    // Uart1_Init();
    Uart2_Init();

    // helloworld();

    // 线程初始化

    // 看门狗初始化
    while (1)
    {
        LOG_INFO("Turning the LED %s!", "off");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
