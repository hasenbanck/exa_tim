#pragma once

#include <stdint.h>

static uint8_t const BTN1_BIT = 1U << 0;
static uint8_t const BTN2_BIT = 1U << 1;
static uint8_t const BTN3_BIT = 1U << 2;
static uint8_t const BTN4_BIT = 1U << 3;

typedef uint8_t btnBitField;

/* Returns a copy of a bitfield of pressed button events */
btnBitField getPressedButtonEvent();
