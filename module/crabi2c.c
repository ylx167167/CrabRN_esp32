#include "crabi2c.h"
#include "freertos/portmacro.h"
#include "globalSetting.h"
#include "driver/i2c.h"

/*! @brief I2C基础配置*/
#define I2C_MASTER_NUM I2C_NUM_1    // 选用i2c1
#define I2C_MASTER_TX_BUF_DISABLE 0 /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE 0 /*!< I2C master doesn't need buffer */
#define I2C_WRITE_WAIT_TIME 1000 / portTICK_PERIOD_MS
#define I2C_READ_WAIT_TIME 1000 / portTICK_PERIOD_MS
#define I2C_ACK_CHECK_EN 0x1 // 是否进行ack检查
#define I2C_ACK_CHECK_DIS 0x0

/*! @brief LM75温湿度传感器*/
#define LM75_ADDRESS 0x48
#define LM75_CONF_REG (0x1)
#define LM75_TEMP_REG (0x0)
#define LM75_THYST_REG (0x2)
#define LM75_TOS_REG (0x3)

/*! @brief DSP从设备地址*/

/*! @brief  程序相关变量初始化*/
SemaphoreHandle_t print_mux = NULL;

/**
 *  @brief I2C驱动初始化
 *  @param
 *  @return
 */

int I2c_Init(void)
{
    // 第一步初始化结构体
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER; // 主机模式
    conf.sda_io_num = I2C_MASTER_SDA_IO;
    conf.scl_io_num = I2C_MASTER_SCL_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;    // sda为上拉状态
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;    // scl为上拉状态
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ; // 设置i2c的频率
    i2c_param_config(I2C_MASTER_NUM, &conf);
    return i2c_driver_install(I2C_MASTER_NUM, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

/**
 *  @brief I2C写数据函数
 *  @param slaveAddr 从设备地址
 *  @param regAddr 寄存器地址
 *  @param pData 写入数据
 *  @param dataLen 数据长度
 *  @return 错误码
 */

int I2C_WriteData(uint8_t slaveAddr, uint8_t regAddr, uint8_t *pData, uint16_t dataLen)
{
    int ret;
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();                                    // 创建命令链接
    i2c_master_start(cmd);                                                           // 启动命令
    i2c_master_write_byte(cmd, slaveAddr << 1 | I2C_MASTER_WRITE, I2C_ACK_CHECK_EN); // 1step: 写入从机地址 7位地址+读写位
    if (NULL != regAddr)
    {
        i2c_master_write_byte(cmd, regAddr, I2C_ACK_CHECK_EN); // 2step:写入寄存器地址
    }
    i2c_master_write(cmd, pData, dataLen, I2C_ACK_CHECK_EN);              // 3step:写入数据
    i2c_master_stop(cmd);                                                 // 4step:命令完善完成
    ret = i2c_master_cmd_begin(I2C_MASTER_NUM, cmd, I2C_WRITE_WAIT_TIME); // 5step:等待i2c控制器进行发送
    i2c_cmd_link_delete(cmd);                                             // 6step::结束i2c write
    return ret;
}
/**
 *  @brief I2C读数据函数
 *  @param slaveAddr 从设备地址
 *  @param regAddr 寄存器地址
 *  @param pData 读数据缓存
 *  @param dataLen 数据长度
 *  @return 错误码
 */
int I2C_ReadData(uint8_t slaveAddr, uint8_t regAddr, uint8_t *pData, uint16_t dataLen)
{
    int ret;
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, slaveAddr << 1 | I2C_MASTER_WRITE, I2C_ACK_CHECK_EN); // 1step: 写入从机地址 7位地址+读写位
    if (NULL != regAddr)
    {
        i2c_master_write_byte(cmd, regAddr, I2C_ACK_CHECK_EN); // 2step:写入寄存器地址
    }
    i2c_master_read(cmd, pData, dataLen, I2C_ACK_CHECK_EN);               // 3step:读取数据
    i2c_master_stop(cmd);                                                 // 4step:命令完善完成
    ret = i2c_master_cmd_begin(I2C_MASTER_NUM, cmd, I2C_WRITE_WAIT_TIME); // 5step:等待i2c控制器进行发送
    i2c_cmd_link_delete(cmd);                                             // 6step::结束i2c write
    return ret;
}

#ifdef LM75

/**
 *  @brief LM75读取线程
 *  @param
 *  @return
 */
void Lm75Task(void *arg)
{
    while (1)
    {
        LOG_INFO("lm75up");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
#endif
/**
 *  @brief Dsp数据读写线程
 *  @param
 *  @return
 */

#ifdef Dsp28335
void DspTask(void *arg)
{
    while (1)
    {
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
#endif
