#include "stdint.h"
#include "uart.h"
#include "halUart.h"

extern volatile PL011_t* Uart;

void Hal_uart_init(void)
{
	Uart->uartcr.bits.UARTEN = 0;
	Uart->uartcr.bits.TXE = 1;
	Uart->uartcr.bits.RXE = 1;
	Uart->uartcr.bits.UARTEN = 1;
}

void Hal_put_char(void)
{
	while(Uart->uartfr.bits.TXFF);
	Uart->uartdr.all = (ch & 0xFF);
}
