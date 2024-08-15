#ifndef _GLBAL_SETTINGH_
#define _GLBAL_SETTINGH_
#include "esp_log.h"
#include "soc/gpio_num.h"

// 重定义答应log
#define LOGTAG "WayneCrabd"
#ifdef LOGTAG
#define LOG_ERROR(format, ...) ESP_LOGE(LOGTAG, format, ##__VA_ARGS__)
#define LOG_WARN(format, ...) ESP_LOGW(LOGTAG, format, ##__VA_ARGS__)
#define LOG_INFO(format, ...) ESP_LOGI(LOGTAG, format, ##__VA_ARGS__)
#define LOG_DEBUG(format, ...) ESP_LOGD(LOGTAG, format, ##__VA_ARGS__)
#define LOG_V(format, ...) ESP_LOGV(LOGTAG, format, ##__VA_ARGS__)
#else
#define LOG_ERROR(format, ...) ESP_LOGE("", format, ##__VA_ARGS__)
#define LOG_WARN(format, ...) ESP_LOGW("", format, ##__VA_ARGS__)
#define LOG_INFO(format, ...) ESP_LOGI("", format, ##__VA_ARGS__)
#define LOG_DEBUG(format, ...) ESP_LOGD("", format, ##__VA_ARGS__)
#define LOGV(format, ...) ESP_LOGV("", format, ##__VA_ARGS__)
#endif

// 功能开关
#define LM75

// 配置I2C GPIO引脚
#define I2C_MASTER_SCL_IO 1
#define I2C_MASTER_SDA_IO 2
#define I2C_MASTER_FREQ_HZ 100000
#define I2C_SLAVE_ADDR 0x66

// 配置WIFI
#define WIFI_AP_SSID "WayneyaoEsp32"
#define WIFI_AP_PASSWD "12345678"
#define WIFI_AP_CHANNEL 1
#define WIFI_AP_MAX_CONN 4

// 配置Uart uart1 和pc 相连 uart2和dsp相连
#define UART1_BAUD_RATE 115200
#define UART1PC_PORT UART_NUM_1
#define UART1_RX_IO GPIO_NUM_17
#define UART1_TX_IO GPIO_NUM_18
#define RX_BUFF_SIZE 1024

#define UART2_BAUD_RATE 115200
#define UART2DSP_PORT UART_NUM_2
#define UART2_RX_IO GPIO_NUM_19
#define UART2_TX_IO GPIO_NUM_20
#define RX_BUFF_SIZE 1024
#define UART2_ECHO_LOOP 1 // 回环测试标志位

#endif