#include <stdint.h>
#include <stddef.h>
#include "calypsi/intrinsics65816.h"
#include "vera.h"
#include "ansi.h"
#include "ibm_vga.h"

/*
** console_init() - put VERA into 80x60 text mode and load the VGA font 
*/
void console_init() {
	VERA_CTRL=0;

  //	upload font to 0x01c000	
	VSET((uint32_t)(0x1c000 | AUTO_INC_1));
	for (uint16_t q=0;q<sizeof(font8x8_basic);q++)
		VERA_DATA0=font8x8_basic[q];

	//	set scale correctly 
	VERA_DC_HSCALE=0x80;
	VERA_DC_VSCALE=0x80;

	//	setup layers
	VERA_L0_CONFIG=VERA_L_BPP1|VERA_L_BITMAP|VERA_L_64H|VERA_L_128W;
	VERA_L0_MAPBASE=(0x8000>>9);
	VERA_L0_TILEBASE=VERA_TILEBASE(0x1c000,VERA_TILESIZE8x8);
	VERA_L0_HSCROLL=0x00;
	VERA_L0_VSCROLL=0x00;

  console_reset();

  // turn VERA back on
	VERA_DC_VIDEO=VERA_DC_LAYER0;
}

/*
** console_clear() - clear the screen
*/
void console_clear() {
  VSET(TEXT_CONSOLE_VRAM | AUTO_INC_1);
  for (int i = 0; i < (2 * TEXT_CONSOLE_COLS * TEXT_CONSOLE_ROWS); i++) {
    VERA_DATA0 = '\0';
    VERA_DATA0 = conControl.attribute;
  }

  conControl.x = 0;
  conControl.y = 0;
}

/*
** console_reset() - set some defaults for the console and clear the screen
*/
void console_reset() {
	conControl.attribute=0x0F;	
	conControl.width=TEXT_CONSOLE_COLS;
  conControl.height=TEXT_CONSOLE_ROWS; 
  console_clear();
}

/*
** console_set_cursor() - position the cursor to x,y
*/
void console_set_cursor(uint8_t x, uint8_t y) {
  conControl.x = x;
  conControl.y = y;
}

/*
** console_set_attribute() - set the current fg + bg color
*/
void console_set_attribute(uint8_t attrib) {
  conControl.attribute = attrib;
}

/*
** scrollWindowUp() - scroll the entire console window up a line.
** there's probably a faster way to do it than I've done here, but
** this will do for now.
*/
void scrollWindowUp() {
  char buf[2 * TEXT_CONSOLE_COLS];
  uint8_t row;
  
  for (row = 0; row < (TEXT_CONSOLE_ROWS - 1); row++) {
    VSET(TEXT_CONSOLE_VRAM + 0 + ((row + 1) <<8) | AUTO_INC_1);
    for (uint8_t col = 0; col < TEXT_CONSOLE_COLS * 2; col += 2) {
      buf[col] = VERA_DATA0;
      buf[col+1] = VERA_DATA0;
    }

    VSET(TEXT_CONSOLE_VRAM + 0 + ((row) <<8) | AUTO_INC_1);
    for (uint8_t col = 0; col < TEXT_CONSOLE_COLS * 2; col += 2) {
      VERA_DATA0 = buf[col];
      VERA_DATA0 = buf[col + 1];
    }
  }

  row = TEXT_CONSOLE_ROWS - 1;

  // now, add blank row at bottom
  VSET(TEXT_CONSOLE_VRAM + 0 + ((row) <<8) | AUTO_INC_1);  
  for (uint8_t col = 0; col < TEXT_CONSOLE_COLS * 2; col += 2) {
    VERA_DATA0 = '\0';
    VERA_DATA0 = conControl.attribute;
  }
}

/*
** console_raw_putc(c) - output 'c' to the screen without doing any ANSI interpretation.
** the only control character we currently deal with is '\n'.
*/
void console_raw_putc(unsigned char c)
{
  char skip = 0;

  if (c == '\n') {
    conControl.y++;
    conControl.x = 0;
    skip = 1;
  }

  if (conControl.y >= TEXT_CONSOLE_ROWS) {
    scrollWindowUp();
    conControl.y = TEXT_CONSOLE_ROWS - 1;
  }

  if (!skip) {
    VSET(TEXT_CONSOLE_VRAM + (conControl.x<<1) + (conControl.y<<8) | AUTO_INC_1);
    VERA_DATA0=c;
    VERA_DATA0=conControl.attribute;
    conControl.x++;
    if (conControl.x>conControl.width) {
      conControl.x=0;
      conControl.y++;
    }
  }
}

/*
** console_raw_puts(s) - print the string to the console without any ansi
** interpretation.  see console_raw_putc() for control characters we do deal with.
*/
void console_raw_puts(const char *s) {
  while (*s != 0) {
    console_raw_putc((unsigned char) *s);
    s++;
  }
}

/*
** TODO stub - currently just calls console_raw_putc()
** console_putc() - output a char to the console with ANSI interpretation.
*/
void console_putc(unsigned char c) {
  console_raw_putc(c);
}

/*
** TODO stub - currently just calls console_raw_puts()
** console_puts() - output a string to the console with ANSI interpretation.
*/
void console_puts(const char *s) {
  console_raw_puts(s);
}

// needed to satisfy requirements for Calypsi libc
size_t _Stub_write(int fd, const void *buf, size_t count)
{
  uint8_t *ptr = (uint8_t*)buf;
  if (fd==1)
  {
      for (int q=0;q<count;q++)
      {
          console_raw_putc(ptr[q]);
      }
  }
  return count;    
}

// needed to satisfy requirements for Calypsi libc
long _Stub_lseek(int fd, long offset, int whence) {
  return 0;
}

// needed to satisfy requirements for Calypsi libc
int _Stub_close(int fd) {
  return 0;
}