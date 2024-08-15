#ifndef _CRABI2C_H_
#define _CRABI2C_H_
#include "driver/i2c.h"
int I2c_Init();
void Lm75Task(void *arg);
void DspTask(void *arg);
#endif