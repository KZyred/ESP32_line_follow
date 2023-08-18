#ifndef _MAIN_H_
#define _MAIN_H_

#include <Arduino.h>
#include <esp32_motor.h>
#include <PIDcontroller.h>
#include <line_status.h>

#define BASE_PWM 300    // xung PWM cơ sở
#define KP 35           // hệ số tỉ lệ
#define KI 0            // độ lợi tích phân
#define KD 15           // độ lợi vi phân

#endif