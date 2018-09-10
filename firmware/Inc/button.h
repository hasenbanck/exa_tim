#pragma once

typedef enum {no_button_pressed, btn1_pressed, btn2_pressed, btn3_pressed, btn4_pressed } btn_pressed_event;

btn_pressed_event getPressedButtonEvent();
