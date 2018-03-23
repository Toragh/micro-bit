#ifndef UART_H
#define UART_H
#include <stdint.h>
#define UART ((NRF_UART_REG*)0x40002000)

void uart_init();
void uart_send(char letter);
char uart_read();

#endif
