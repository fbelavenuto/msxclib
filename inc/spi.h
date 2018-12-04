/*
TBBlue / ZX Spectrum Next project

Copyright (c) 2015 Fabio Belavenuto & Victor Trucco

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
  TBBlue / ZX Spectrum Next project
  Copyright (c) 2015 Fabio Belavenuto & Victor Trucco
*/

#ifndef SPI_H
#define SPI_H

// Flash SPI commands
const unsigned char cmd_write_enable	= 0x06;
const unsigned char cmd_write_disable	= 0x04;
const unsigned char cmd_read_status		= 0x05;
const unsigned char cmd_read_bytes		= 0x03;
const unsigned char cmd_read_id			= 0xAB;
const unsigned char cmd_jedec_id		= 0x9F;
const unsigned char cmd_fast_read		= 0x0B;
const unsigned char cmd_write_status	= 0x01;
const unsigned char cmd_write_bytes		= 0x02;
const unsigned char cmd_erase_bulk		= 0xC7;
const unsigned char cmd_erase_block64	= 0xD8;		// Block Erase 64K

// Send 1 byte to flash
void SPI_sendcmd(unsigned char cmd);

// Send 3 bytes to flash
void SPI_send3bytes(unsigned char *buffer);

// Send 4 bytes to flash
void SPI_send4bytes(unsigned char *buffer);

// Send 1 byte to flash and receive answer
unsigned char SPI_sendcmd_recv(unsigned char cmd);

// Send 4 bytes to flash and receive answer
unsigned char SPI_send4bytes_recv(unsigned char *buffer);

// Send command to flash and receive 3 bytes
void SPI_sendcmd_recv3bytes(unsigned char cmd, unsigned char *buffer);

// Writing data in flash (260 bytes)
void SPI_writebytes(unsigned char *buffer);

#endif

