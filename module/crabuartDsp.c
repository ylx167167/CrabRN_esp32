#include "crabuartDsp.h"
#include "globalSetting.h"
#include "freertos/FreeRTOS.h"

QueueHandle_t uart2_queue = NULL;
enum Uart2HandleEvent
{
    UART2_ECHO_LOOP_HANDLE,

    UART2_HANDLE_SUCCESS = 200,
    UART2_HANDLE_ERROR,
};
// uint8_t uart2_buff[RX_BUFF_SIZE]; 全局缓冲区改成局部初始化

/**
 *  @brief 接收处理函数
 *  @param dataBuf 接收到的数据
 *  @param size    接收到的数据长度
 *  @return UART2_HANDLE_SUCCESS 成功 UART2_HANDLE_ERROR失败
 */
int handleReceivePacket(uint8_t *dataBuf, uint32_t size)
{
    int event;
    if (UART2_ECHO_LOOP == 1)
        event = UART2_ECHO_LOOP_HANDLE;
    switch (event)
    {
    case UART2_ECHO_LOOP_HANDLE:
        uart_write_bytes(UART2DSP_PORT, "haha", 5); // 回传一个haha
        break;
    default:
        break;
    }
    return UART2_HANDLE_SUCCESS;
}
/**
 *  @brief 接收数据线程
 *  @param
 *  @return
 */
void Uart2ReciveEventHandle(void *param)
{
    uart_event_t event;
    uint8_t *puartBuf = (uint8_t *)malloc(RX_BUFF_SIZE);

    while (pdTRUE)
    {
        // 等待uart事件
        if (xQueueReceive(uart2_queue, (void *)&event, portMAX_DELAY))
            switch (event.type)
            {
            case UART_DATA:
                uart_read_bytes(UART2DSP_PORT, puartBuf, event.size, portMAX_DELAY);
                LOG_INFO("recevie buf.size:%d , buf:%s", event.size, puartBuf);
                if (UART2_ECHO_LOOP == 1)
                    handleReceivePacket(puartBuf, event.size);
                break;
            case UART_FIFO_OVF:
            case UART_BUFFER_FULL:
                LOG_ERROR("hardware fifo overflow"); // 硬件缓存溢出
                uart_flush_input(UART2DSP_PORT);     // 清空uart2缓存
                xQueueReset(uart2_queue);            // 重置队列
                break;
            case UART_PARITY_ERR:
                LOG_ERROR("uart parity error");
                break;
            case UART_FRAME_ERR:
                LOG_ERROR("uart frame error");
                break;
            default:
                break;
            }
    }
    vTaskDelete(NULL); // 一般不会执行到这
}

/**
 *  @brief uart可以同时进行发送和接收数据 发送线程 但uart2主要用于发送相关配置参数
 *         通过接收和发送线程来配合发送进度 当dsp接收到相关配置参数时返回 TLV数据包
 *         该线程负责参数修改等相关配置
 *  @param
 *  @return
 */
void Uart2SendEventHandle(void *param)
{
    uart_event_t event;
    while (1)
    {
        // uart2 负责发送相关配置参数
        vTaskDelay(pdMS_TO_TICKS(200)); // 延迟200ms
    }

    vTaskDelete(NULL); // 一般不会执行到这
}

void Uart2_Init(void)
{
    uart_config_t uartConf = {

        .baud_rate = UART2_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .stop_bits = UART_STOP_BITS_1,
        .parity = UART_PARITY_DISABLE,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    uart_param_config(UART2DSP_PORT, &uartConf);
    uart_set_pin(UART2DSP_PORT, UART2_TX_IO, UART2_RX_IO, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    uart2_queue = xQueueCreate(8, 512);
    uart_driver_install(UART2DSP_PORT, RX_BUFF_SIZE, RX_BUFF_SIZE, 8, &uart2_queue, 0);
    xTaskCreate(Uart2ReciveEventHandle, "uart_recive_event_hanle", 1024, NULL, 5, NULL); // 接受线程 优先级5
    xTaskCreate(Uart2SendEventHandle, "uart_recive_event_hanle", 1024, NULL, 5, NULL);   // 发送线程 优先级5
}
