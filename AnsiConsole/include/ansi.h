#include <stdint.h>

#ifndef _ANSI_H
#define _ANSI_H

#define TEXT_CONSOLE_VRAM 0x8000
#define TEXT_CONSOLE_COLS 80
#define TEXT_CONSOLE_ROWS 60

typedef struct ConControl_Struct {
  uint8_t x;
  uint8_t y;
  uint8_t width;
  uint8_t height;
  uint8_t attribute;
} ConControl_Struct;

static ConControl_Struct conControl;

extern void console_init();
extern void console_reset();
extern void console_clear();
extern void console_set_cursor(uint8_t x, uint8_t y);
extern void console_set_attribute(uint8_t attrib);
extern void console_putc(unsigned char c);
extern void console_puts(const char *s);
extern void console_raw_putc(unsigned char c);
extern void console_raw_puts(const char *s);

#endif