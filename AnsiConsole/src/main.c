#include <stdint.h>
#include <stdio.h>
#include "calypsi/intrinsics65816.h"
#include "vera.h"
#include "ansi.h"

char vbl;
//	this is testing and messy 
//	boot into ROM 
int ROM_boot();

//	liddle trampoline to get going from system ram low 64kb
void main ()
{
	__disable_interrupts();
	ROM_boot();
}

//	IRQ called at end of frame currently 
__attribute__((interrupt(0xffee)))
void vblank()
{
	vbl++;
}

//	ROM code 
int ROM_boot()
{
  console_init();
  console_reset();

  char buf[128];
 
  for (int i = 0; i < 80; i++) {
    printf("This is line #%d\n", i);
  }

  console_clear();

  for (int i = 0; i < 30; i++) {
    printf("second go around -- This is line #%d\n", i);
  }

  // turn VERA back on
	VERA_DC_VIDEO=VERA_DC_LAYER0;

	__enable_interrupts();

	while(1)
	{
		vbl = 0;
		while(vbl==0) {};
	}
	return 0;	
}
