#ifndef __UART_H__
#define __UART_H__

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uart_init (void);
unsigned char uart_recieve (void);
void uart_transmit (char data);
void uart_string_transmit (char *str);
void uart_print (char *name, long val);
void uart_print_string (char *str);
int usart_tx_char (char ch, FILE *fp);
void uart_print_8bit_num (uint8_t);

#endif // __UART_H__


