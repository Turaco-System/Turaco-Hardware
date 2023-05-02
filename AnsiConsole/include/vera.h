#define VERA_BASE 0xDF00

#define AUTO_NONE		0x000000
#define AUTO_INC_1  0x100000
#define AUTO_INC_2  0x200000
#define AUTO_INC_4  0x300000
#define AUTO_INC_8  0x400000
#define AUTO_INC_16 0x500000
#define AUTO_INC_32 0x600000
#define AUTO_INC_64 0x700000
#define AUTO_INC_128 0x800000
#define AUTO_INC_256 0x900000
#define AUTO_INC_512 0xA00000
#define AUTO_INC_40  0xB00000
#define AUTO_INC_80  0xC00000
#define AUTO_INC_160 0xD00000
#define AUTO_INC_320 0xE00000
#define AUTO_INC_640 0xF00000

#define IO_HASKEY 				(*(volatile __far uint16_t *)(0xd000))
#define IO_KEY 						(*(volatile __far uint16_t *)(0xd001))


#define VERA_ADDR_L   	  (*(volatile __far uint8_t *)VERA_BASE)
#define VERA_ADDR_M   	  (*(volatile __far uint8_t *)(VERA_BASE + 0x01))
#define VERA_ADDR_H   	  (*(volatile __far uint8_t *)(VERA_BASE + 0x02))
#define VERA_DATA0        (*(volatile __far uint8_t *)(VERA_BASE + 0x03))
#define VERA_DATAW        (*(volatile __far uint16_t *)(VERA_BASE + 0x03))
#define VERA_DATA1        (*(volatile __far uint8_t *)(VERA_BASE + 0x04))

#define VERA_CTRL         (*(volatile __far uint8_t *)(VERA_BASE + 0x05))
#define VERA_CTRL_ADDR_SEL0 	0b00000000
#define VERA_CTRL_ADDR_SEL1 	0b00000001
#define VERA_CTRL_ADDR_DCSEL0	0b00000000
#define VERA_CTRL_ADDR_DCSEL1	0b00000010
#define VERA_IEN          (*(volatile __far uint8_t *)(VERA_BASE + 0x06))
#define VERA_IEN_VSYNC 		0b00000001
#define VERA_IEN_LINE 		0b00000010
#define VERA_IEN_SPRCOL		0b00000100
#define VERA_IEN_AFLOW		0b00001000
#define VERA_IEN_IRQ			0b10000000
#define VERA_ISR          (*(volatile __far uint8_t *)(VERA_BASE + 0x07))
#define VERA_ISR_VSYNC 		0b00000001
#define VERA_ISR_LINE 		0b00000010
#define VERA_ISR_SPRCOL		0b00000100
#define VERA_IRQ_LINE_L   (*(volatile __far uint8_t *)(VERA_BASE + 0x08))
#define VERA_DC_VIDEO     (*(volatile __far uint8_t *)(VERA_BASE + 0x09))
#define VERA_DC_LAYER0		0b00010000
#define VERA_DC_LAYER1		0b00100000
#define VERA_DC_SPRITE		0b01000000
#define VERA_DC_HSCALE    (*(volatile __far uint8_t *)(VERA_BASE + 0x0A))
#define VERA_DC_VSCALE    (*(volatile __far uint8_t *)(VERA_BASE + 0x0B))
#define VERA_DC_BORDER    (*(volatile __far uint8_t *)(VERA_BASE + 0x0C))
#define VERA_DC_HSTART    (*(volatile __far uint8_t *)(VERA_BASE + 0x09))
#define VERA_DC_HSTOP     (*(volatile __far uint8_t *)(VERA_BASE + 0x0A))
#define VERA_DC_VSTART    (*(volatile __far uint8_t *)(VERA_BASE + 0x0B))
#define VERA_DC_VSTOP     (*(volatile __far uint8_t *)(VERA_BASE + 0x0C))
#define VERA_L0_CONFIG    (*(volatile __far uint8_t *)(VERA_BASE + 0x0D))
#define VERA_L0_MAPBASE   (*(volatile __far uint8_t *)(VERA_BASE + 0x0E))
#define VERA_L0_TILEBASE  (*(volatile __far uint8_t *)(VERA_BASE + 0x0F))
#define VERA_L0_HSCROLL 	(*(volatile __far uint16_t *)(VERA_BASE + 0x10))
#define VERA_L0_VSCROLL 	(*(volatile __far uint16_t *)(VERA_BASE + 0x12))
#define VERA_L1_CONFIG    (*(volatile __far uint8_t *)(VERA_BASE + 0x14))
#define VERA_L1_MAPBASE   (*(volatile __far uint8_t *)(VERA_BASE + 0x15))
#define VERA_L1_TILEBASE  (*(volatile __far uint8_t *)(VERA_BASE + 0x16))
#define VERA_L1_HSCROLL 	(*(volatile __far uint16_t *)(VERA_BASE + 0x17))
#define VERA_L1_VSCROLL 	(*(volatile __far uint16_t *)(VERA_BASE + 0x19))

#define VERA_L_BPP1 	 	  0b00000000
#define VERA_L_BPP2 	 	  0b00000001
#define VERA_L_BPP4 	 	  0b00000010
#define VERA_L_BPP8 	 	  0b00000011
#define VERA_L_BITMAP 	  0b00000100
#define VERA_L_T256C	 	  0b00001000
#define VERA_L_32W	 	   	0b00000000
#define VERA_L_64W	 	   	0b00010000
#define VERA_L_128W	 	   	0b00100000
#define VERA_L_256W	 	   	0b00110000
#define VERA_L_32H	 	   	0b00000000
#define VERA_L_64H	 	   	0b01000000
#define VERA_L_128H	 	   	0b10000000
#define VERA_L_256H	 	   	0b11000000


#define VERA_AUDIO_CTRL   (*(volatile __far uint8_t *)(VERA_BASE + 0x1B))
#define VERA_AUDIO_RATE   (*(volatile __far uint8_t *)(VERA_BASE + 0x1C))
#define VERA_AUDIO_DATA   (*(volatile __far uint8_t *)(VERA_BASE + 0x1D))
#define VERA_SPI_DATA     (*(volatile __far uint8_t *)(VERA_BASE + 0x1E))
#define VERA_SPI_CTRL     (*(volatile __far uint8_t *)(VERA_BASE + 0x1F))

#define VERA_PSG_BASE 0x1F9C0
#define VERA_PALETTE_BASE 0x1FA00
#define VERA_SPRITES_BASE 0x1FC00

#define VERA_TILESIZE8x8 0b00000000
#define VERA_TILESIZE16x8 0b00000001
#define VERA_TILESIZE8x16 0b00000010
#define VERA_TILESIZE16x16 0b00000011
#define VERA_TILEBASE(x,size) 	(((x >> 9)&0b11111100) | size)

#define VSET(x) {\
									VERA_ADDR_L=((uint32_t)x&0xff);\
									VERA_ADDR_M=(((uint32_t)(x)>>8)&0xff);\
									VERA_ADDR_H=(((uint32_t)(x)>>16)&0xff);\
								}
