/*
 * Copyright 2026 gooseFoundation and the HARK kernel contibutors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <drivers/kUART.h>
#include <arch/asm/ports.h>
#include <stdint.h>
#include <util/config.h>

#define COM1 0x3F8 // todo: scan COM ports to find correct one

// gets kUART ready to print to UART
void kUART_init() {
    #if CONFIG_USE_UART == 1

    outb(COM1 + 1, 0x00);    // Disable all interrupts
    outb(COM1 + 3, 0x80);    // Enable DLAB (set baud rate divisor)
    outb(COM1 + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
    outb(COM1 + 1, 0x00);    //                  (hi byte)
    outb(COM1 + 3, 0x03);    // 8 bits, no parity, one stop bit
    outb(COM1 + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    outb(COM1 + 4, 0x0B);    // IRQs enabled, RTS/DSR set
    outb(COM1 + 4, 0x0F);    // Now that we have confirmed its fine, lets set it back to normal mode

    #endif    
}

// checks if the OS can safely write to UART
int is_transmit_empty() {
   return inb(COM1 + 5) & 0x20;
}

// prints a single character to UART
void kUART_putc(char c) {
    #if CONFIG_USE_UART == 1

    while (is_transmit_empty() == 0); // waste CPU cycles to wait on this, maybe do this more efficeintly?

    outb(COM1, c); // write the character to UART

    #endif
}

// prints a single string to UART
void kUART_puts(char* str) {
    #if CONFIG_USE_UART == 1

    // stop when 0 is encountered(NULL terminator)
    while (*str) {
        kUART_putc(*str);
        str++;
    }

    #endif
}