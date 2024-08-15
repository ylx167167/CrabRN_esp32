# crabRN(crab relay node)
  本项目取名为螃蟹中继节点,主要负责DSP上报的电机数据，以及通过短距某块或者I2C与crabHeart进行通信。也借此机会对Esp32与FreeRtos进行一次那个完整的学习
本项目将进行以下4部分工作：
* 1.目录重构
  ├── moudle 硬件模块驱动
  ├── package 第三方包
  ├── res 资源文件
  └── main  主函数
  ESP32 Cmake教程：
  https://blog.csdn.net/weixin_51954217/article/details/130463971

* 2. Esp32学习
  FreeRtos学习教程：https://blog.csdn.net/qq_45355603/article/details/130650193
  Esp32 menuconfig: https://blog.csdn.net/dingyc_ee/article/details/128691330

* 3.各模块bring up
 * i2c bring up
  官方教程：https://docs.espressif.com/projects/esp-idf/zh_CN/v4.3-beta1/esp32/api-reference/peripherals/i2c.html
  个人教程：https://blog.csdn.net/qq_63922192/article/details/133430640 https://blog.csdn.net/HandBAI/article/details/131350331 https://blog.csdn.net/qq_36347513/article/details/116762846
  流程：
 * spi bring up 

 * uart bring up
  个人教程：https://www.elecfans.com/d/2106881.html
           接收：https://www.jianshu.com/p/cf65c087ca4a
 * wifi bring up
  AP个人教程：https://blog.csdn.net/qq_45803449/article/details/134255011
  STA个人教程：
 * ble bring up


* 4.各模块功能完善
  速率spi>i2c>uart
 * i2c func
   i2c主机模式 读取LM75数据以及Dsp28335数据(通过TLV格式数据包进行传输)
 * spi func 
   负责oled显示
 * uart func
   uart1负责串口调试 uart2 负责与Dsp28335进行通信(传输配置参数，进阶可进行程序更新(若可行)) 通过TLV格式数据包进行传输
 * wifi func
   支持AP STA两种模式，支持通过蓝牙的方式更改wifi密码，AP模式下创立TCP服务器，STA模式下创建MQTT客户端或者HTTP客户端
 * ble func
   手机通过蓝牙配网app，检索到esp蓝牙信号，连接，蓝牙配网：通过蓝牙将wifi配置信息传给esp32。
 * 掉电存储模块
    https://blog.csdn.net/tsliuch/article/details/125498379
* 5.组件

 * aes加密组件
 * 线程池组件
 * lvgl组件
# CrabRN_esp32
