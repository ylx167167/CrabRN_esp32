#include "string.h"
#include "crabwifi.h"
#include "globalSetting.h"
#include "esp_mac.h"
#include "esp_event.h"
#include "nvs_flash.h"
/**
 *  @brief  function called when an event is posted to the queue
 *  @param
 *  @return
 */
static void wifi_handle_event(void *event_handler_arg,
                              esp_event_base_t event_base,
                              int32_t event_id,
                              void *event_data)
{
    if (event_id == WIFI_EVENT_AP_STACONNECTED) // 判断有设备链接上
    {
        wifi_event_ap_staconnected_t *event = (wifi_event_ap_staconnected_t *)event_data;
        LOG_INFO("station " MACSTR " join, AID=%d",
                 MAC2STR(event->mac), event->aid);
    }
    else if (event_id == WIFI_EVENT_AP_STADISCONNECTED) // 判断有设锻炼
    {
        wifi_event_ap_stadisconnected_t *event = (wifi_event_ap_stadisconnected_t *)event_data;
        LOG_INFO("station " MACSTR " leave, AID=%d",
                 MAC2STR(event->mac), event->aid);
    }
    else if (event_id == WIFI_EVENT_STA_CONNECTED)
    {
        LOG_INFO("hdagdafdafdsafd");
    }
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        LOG_INFO("STA成功接入热点\n");
        ip_event_got_ip_t *info = (ip_event_got_ip_t *)event_data;
        LOG_INFO("STA的IP是" IPSTR "\n", IP2STR(&info->ip_info.ip));
    }
}

/**
 *  @brief 将Wifi配置成softap模式
 *  @param
 *  @return
 */
void Wifi_SoftAP_Init(void)
{
    nvs_flash_init();                                 // esp32 flash-nvs键值对
    ESP_ERROR_CHECK(esp_netif_init());                // 启动WIP协议栈
    ESP_ERROR_CHECK(esp_event_loop_create_default()); // 创建vent task
    wifi_init_config_t conf = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&conf));                                                                              // 1stepwifi初始化
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_handle_event, NULL, NULL)); // 2step注册链接断开事件回调
    wifi_config_t ap_conf = {
        .ap = {
            .ssid = WIFI_AP_SSID,               // SSID
            .ssid_len = strlen(WIFI_AP_SSID),   // SSID 长度
            .channel = WIFI_AP_CHANNEL,         // AP 信道
            .password = WIFI_AP_PASSWD,         // AP密码
            .max_connection = WIFI_AP_MAX_CONN, // 最大连接数
            .authmode = WIFI_AUTH_WPA_WPA2_PSK, // wifi加密方式
            .pmf_cfg = {
                .required = false,
            },
        },
    }; // 3step:配置wifi信息
    if (strlen(WIFI_AP_PASSWD) == 0)
    {
        ap_conf.ap.authmode = WIFI_AUTH_OPEN; // 如果密码长度为0则将AP设置为open wifi
    }
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP)); // 4step:设置wifi模式
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &ap_conf));
    ESP_ERROR_CHECK(esp_wifi_start()); // 5step:启动driver
}

/**
 *  @brief 将Wifi配置成sta模式
 *  @param
 *  @return
 */
void Wifi_STA_Init()
{
    nvs_flash_init();                // esp32 flash-nvs键值对
    esp_event_loop_create_default(); // 创建默认事件循环
    //
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_handle_event, NULL, NULL)); // 2step注册链接断开事件回调
    ESP_ERROR_CHECK(esp_netif_init());                                                                                  // 启动WIP协议栈
    ESP_ERROR_CHECK(esp_netif_create_default_wifi_sta());                                                               // 3step创建一个STA类型的网卡

    wifi_init_config_t conf = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&conf));
    esp_wifi_set_mode(WIFI_MODE_STA); // 4step:设置wifi模式为STA
    wifi_config_t sta_cfg =
        {
            .sta =
                {
                    .ssid = "Wayneyao",
                    .password = "ylxznb111"}};
    esp_wifi_set_config(ESP_IF_WIFI_STA, &sta_cfg);
    ESP_ERROR_CHECK(esp_wifi_start());              // 5step:启动drivercft
    ESP_ERROR_CHECK(esp_wifi_connect());            // 6step:链接该wifi
    ESP_ERROR_CHECK(esp_wifi_set_ps(WIFI_PS_NONE)); // 不需要省电！
}

/**
 *  @brief Wifi任务线程
 *  @param
 *  @return
 */
void WifiTask(void *arg) {}