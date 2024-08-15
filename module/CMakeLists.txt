file(GLOB SOURCES *.c)

# 
idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS .
                       REQUIRES res driver soc esp_wifi esp_hid nvs_flash
                       PRIV_REQUIRES bt)