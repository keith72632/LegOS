#pragma once 

#include <stdint.h>
#include <stddef.h>
enum
{
    // The offsets for reach register.
    GPIO_BASE = 0x200000,
 
    // Controls actuation of pull up/down to ALL GPIO pins.
    GPPUD = (GPIO_BASE + 0x94),
 
    // Controls actuation of pull up/down for specific GPIO pin.
    GPPUDCLK0 = (GPIO_BASE + 0x98),
 
    // The base address for UART.
    UART0_BASE = (GPIO_BASE + 0x1000), // for raspi4 0xFE201000, raspi2 & 3 0x3F201000, and 0x20201000 for raspi1
 
    // The offsets for reach register for the UART. Broadcom Manual page 178
    UART0_DR     = (UART0_BASE + 0x00), //Data reg. If FIFOs are enabled, data written here is pushed to tansmit FIFO
    UART0_RSRECR = (UART0_BASE + 0x04), //Recieve status/error clear register
    UART0_FR     = (UART0_BASE + 0x18), //Flag register
    UART0_ILPR   = (UART0_BASE + 0x20), //disabled
    UART0_IBRD   = (UART0_BASE + 0x24), //Integer part of the baud rate
    UART0_FBRD   = (UART0_BASE + 0x28), //Fractional part of baud rate.
    UART0_LCRH   = (UART0_BASE + 0x2C), //Line contol reg. LCRH, FBRD, and IBRD should not be changed while UART enabled
    UART0_CR     = (UART0_BASE + 0x30), //Control reg. 
    UART0_IFLS   = (UART0_BASE + 0x34), //Interrupt FIFO Level Selector. Basically shows how full FIFO is
    UART0_IMSC   = (UART0_BASE + 0x38), //Interrupt Mask set/clear reg. Read/write
    UART0_RIS    = (UART0_BASE + 0x3C), //Raw interrup status register. Read only. Return the current raw status value
    UART0_MIS    = (UART0_BASE + 0x40), //Masked Interrupt status register. Return masked status of corresponding interrupt
    UART0_ICR    = (UART0_BASE + 0x44), //Interrupt Clear register
    UART0_DMACR  = (UART0_BASE + 0x48), //Disabled
    UART0_ITCR   = (UART0_BASE + 0x80), //Test control register
    UART0_ITIP   = (UART0_BASE + 0x84),
    UART0_ITOP   = (UART0_BASE + 0x88),
    UART0_TDR    = (UART0_BASE + 0x8C), //Test data reg
 
    // The offsets for Mailbox registers
    MBOX_BASE    = 0xB880,
    MBOX_READ    = (MBOX_BASE + 0x00),
    MBOX_STATUS  = (MBOX_BASE + 0x18),
    MBOX_WRITE   = (MBOX_BASE + 0x20)
};

void uart_init(int raspi);
void uart_putc(unsigned char c);
unsigned char uart_getc();
void uart_puts(const char* str);