
#include "types.h"
#include "conio.h"

#define BDOS 5

void putchar(const char c) __naked {
	__asm
		;A = c
		ld		e, a
		ld		c, #2
		call	BDOS
		ret
	__endasm;
}

char getchar(void) {
	__asm
		ld		c, #8
		call	BDOS
		ld		a, l
		ret		; A = return value
	__endasm;
}

void puts(const char *s) {
	while (*s != 0) {
		putchar(*s++);
	}
}

void puthex(int8_t nibbles, uint16_t v) {
	int8_t i = nibbles - 1;
	while (i >= 0) {
		uint16_t aux = (v >> (i << 2)) & 0x000F;
		uint8_t n = aux & 0x000F;
		if (n > 9)
			putchar('A' + (n - 10));
		else
			putchar('0' + n);
		i--;
	}
}

void puthex8(uint8_t v) {
	puthex(2, (uint16_t) v);
}

void puthex16(uint16_t v) {
	puthex(4, v);
}

void putdec(int16_t digits, uint16_t v) {
	uint8_t fz = 0;
	while (digits > 0) {
		uint16_t aux = v / digits;
		uint8_t n = aux % 10;
		if (n != 0 || fz != 0) {
			putchar('0' + n);
			fz = 1;
		}
		digits /= 10;
		if (digits == 1) {
			fz = 1;
		}
	}
}


void putdec8(uint8_t v) {
	putdec(100, (uint16_t) v);
}


void putdec16(uint16_t v) {
	putdec(10000, v);
}


