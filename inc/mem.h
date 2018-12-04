

#ifndef  __MEM_H__
#define  __MEM_H__


#include "types.h"

#define peek(A) (*(volatile unsigned char*)(A))
#define poke(A,V) *(volatile unsigned char*)(A)=(V)
#define peek16(A) (*(volatile unsigned int*)(A))
#define poke16(A,V) *(volatile unsigned int*)(A)=(V)

extern void memcpy(uint8_t *dest, uint8_t *src, uint16_t n);
extern void memset(uint8_t *s, uint8_t c, uint16_t n);
extern unsigned char memcmp(uint8_t *dest, uint8_t *src, uint16_t n);

#endif  // __MEM_H__
