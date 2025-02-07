#ifndef __NEOPIXEL_H__2_H
#define __NEOPIXEL_H__2_H

#include <stdio.h>
#include "pico/stdlib.h"

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws28122.pio.h"

#define MATRIX_LEN 5

void initNeoPixel();
uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b);
void renderMatrix(bool letra[MATRIX_LEN][MATRIX_LEN]);
void renderRGBMatrix(uint32_t matrix[MATRIX_LEN][MATRIX_LEN]);

#define NEOPIXEL_PIN 7

#endif