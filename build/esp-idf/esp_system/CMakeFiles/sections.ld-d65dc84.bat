@echo off
cd /D F:\project\crab-robot\software\esp32\CrabRN\build\esp-idf\esp_system || (set FAIL_LINE=2& goto :ABORT)
f:\project\crab-robot\sdk\esp32IDE\tool\python_env\idf5.2_py3.11_env\Scripts\python.exe F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/tools/ldgen/ldgen.py --config F:/project/crab-robot/software/esp32/CrabRN/sdkconfig --fragments-list F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/xtensa/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_ringbuf/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_mm/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/driver/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/driver/gpio/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/driver/gptimer/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/driver/i2c/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/driver/ledc/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/driver/mcpwm/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/driver/rmt/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/driver/twai/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/driver/uart/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_pm/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/spi_flash/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_system/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_system/app.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_rom/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/hal/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/log/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/heap/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/soc/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_hw_support/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_hw_support/dma/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/freertos/linker_common.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/freertos/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/newlib/newlib.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/newlib/system_libs.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_common/common.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_common/soc.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/app_trace/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_event/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_phy/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/vfs/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/lwip/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_netif/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/wpa_supplicant/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_coex/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_wifi/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/bt/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_adc/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_eth/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_gdbstub/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_psram/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_lcd/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/espcoredump/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/ieee802154/linker.lf;F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/openthread/linker.lf --input F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/components/esp_system/ld/esp32s3/sections.ld.in --output F:/project/crab-robot/software/esp32/CrabRN/build/esp-idf/esp_system/ld/sections.ld --kconfig F:/project/crab-robot/sdk/esp32IDE/v5.2.1/esp-idf/Kconfig --env-file F:/project/crab-robot/software/esp32/CrabRN/build/config.env --libraries-file F:/project/crab-robot/software/esp32/CrabRN/build/ldgen_libraries --objdump F:/project/crab-robot/sdk/esp32IDE/tool/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32s3-elf-objdump.exe || (set FAIL_LINE=3& goto :ABORT)
goto :EOF

:ABORT
set ERROR_CODE=%ERRORLEVEL%
echo Batch file failed at line %FAIL_LINE% with errorcode %ERRORLEVEL%
exit /b %ERROR_CODE%