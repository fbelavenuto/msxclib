
#include "bios.h"

#define RDSLT  0x000C
#define WRSLT  0x0014
#define CALSLT 0x001C
#define ENASLT 0x0024
#define RESET  0x0000
#define KILBUF 0x0156
#define RAMAD0 0xF341		// slotid DOS ram page 0
#define RAMAD1 0xF342		// slotid DOS ram page 1
#define RAMAD2 0xF343		// slotid DOS ram page 2
#define RAMAD3 0xF344		// slotid DOS ram page 3
#define EXPTBL 0xFCC1		// slotids
#define DSKSLT 0xF348		// slotid DOS diskrom

/* clearKeyBuf: Clear the keyboard buffer
 * Input: none
 * Output: none
 */
void clearKeyBuf(void) __naked {
    __asm
        ld	ix, #KILBUF
        ld	iy, (EXPTBL-1)
        jp	CALSLT
    __endasm;
}

/* readSlot: Read one byte from addr in the other slot
 * Input: slot number in format E...SSPP, addr absolute
 * Output: byte read
 */
unsigned char readSlot(unsigned char slot, unsigned int addr) __naked {
    __asm
        ; A = slot
        ; DE = addr
        ex	    de, hl
        call	RDSLT
        ret		; A = return value
    __endasm;
}

/* writeSlot: Write one byte to addr in the other slot
 * Input: byte to wrtie, slot number in format E...SSPP, addr absolute
 * Output: none
 */
void writeSlot(unsigned char slot, unsigned int addr, unsigned char byte) __naked {
    __asm
        ; A = slot
        ; DE = addr
        ; stack = byte
        ex	de, hl
        ld	iy, #0
        add	iy, sp
        ld	e, 2(iy)	; byte
        jp	WRSLT
    __endasm;
}

/* putRamFrame1: Put RAM in Frame 1
 * Input: none
 * Output: none
 */
void putRamFrame1(void) __naked {
    __asm
        ld	a, (RAMAD1)
        ld	h, #0x40
        jp	ENASLT
    __endasm;
}

/* putRamFrame2: Put RAM in Frame 2
 * Input: none
 * Output: none
 */
void putRamFrame2(void) __naked {
    __asm
        ld	a, (RAMAD2)
        ld	h, #0x80
        jp	ENASLT
    __endasm;
}

/* putRamFrame1: Put Slot in Frame 1
 * Input: slot number in format E...SSPP
 * Output: none
 */
void putSlotFrame1(unsigned char slot) __naked {
    __asm
        ; A = slot
        ld	h, #0x40
        jp	ENASLT
    __endasm;
}

/* putRamFrame1: Put Slot in Frame 2
 * Input: slot number in format E...SSPP
 * Output: none
 */
void putSlotFrame2(unsigned char slot) __naked {
    __asm
        ; A = slot
        ld	h, #0x80
        jp	ENASLT
    __endasm;
}

/* resetSystem: Reset the MSX
 * Input: none
 * Output: none
 */
void resetSystem(void) __naked {
    __asm
        ld	ix, #RESET
        ld	iy, (EXPTBL-1)
        jp	CALSLT
    __endasm;
}
