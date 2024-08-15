#include "crabuartPc.h"
#include "globalSetting.h"
#include "freertos/FreeRTOS.h"

QueueHandle_t uart1_queue = NULL;
QueueHandle_t uart2_queue = NULL;
uint8_t uart1_buff[RX_BUFF_SIZE];
uint8_t uart2_buff[RX_BUFF_SIZE];

void Uart2EventHandle(void *param)
{
    uart_event_t event;

    while (pdTRUE)
    {
        if (xQueueReceive(uart1_queue, (void *)&event, portMAX_DELAY))
        {
            switch (event.type)
            {
            case UART_DATA:
                break;
            case UART_FIFO_OVF:
            case UART_BUFFER_FULL:

                break;
            default:
                break;
            }
        }
    }
}

void Uart1EventHandle(void *param) {}
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
    xTaskCreate(Uart2EventHandle, "uart_event_hanle", 1024, NULL, 5, NULL);
}

void Uart1_Init(void)
{
    uart_config_t uartConf = {
        .baud_rate = UART1_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .stop_bits = UART_STOP_BITS_1,
        .parity = UART_PARITY_DISABLE,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    uart_param_config(UART1PC_PORT, &uartConf);
    uart_set_pin(UART1PC_PORT, UART1_TX_IO, UART1_RX_IO, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    uart1_queue = xQueueCreate(8, 512);
    uart_driver_install(UART1PC_PORT, RX_BUFF_SIZE, RX_BUFF_SIZE, 8, &uart1_queue, 0);
    xTaskCreate(Uart1EventHandle, "uart_event_hanle", 1024, NULL, 5, NULL);
}