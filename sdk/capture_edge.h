/*
 * Copyright (c) 2022, Daniel Gorbea
 * All rights reserved.
 *
 * This source code is licensed under the MIT-style license found in the
 * LICENSE file in the root directory of this source tree. 
 *
 * Library for pin capture timer for RP2040
 */

#ifndef CAPTURE_EDGE
#define CAPTURE_EDGE

#ifdef __cplusplus
extern "C" {
#endif

#include "hardware/pio.h"
#include "hardware/irq.h"
#include "capture_edge.pio.h"

typedef enum edge_type_t
{
    EDGE_NONE,
    EDGE_FALLING,
    EDGE_RISING
} edge_type_t;

typedef void (*capture_handler_t)(uint counter, edge_type_t edge);

uint capture_edge_init(PIO pio, uint pin_base, float clk_div, uint irq);
void capture_edge_set_handler(uint pin, capture_handler_t handler);
void capture_edge_remove(void);

#ifdef __cplusplus
}
#endif

#endif
