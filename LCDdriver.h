#define VERTICAL 0
#define HORIZONTAL 1
#define LCD_ALIGNMENT VERTICAL
//#define LCD_ALIGNMENT HORIZONTAL

#ifdef PIMORONI_PICOSYSTEM
	#define X_RES 240 // 横方向解像度
	#define Y_RES 240 // 縦方向解像度
#elif LCD_ALIGNMENT == VERTICAL
	#define X_RES 240 // 横方向解像度
	#define Y_RES 320 // 縦方向解像度
#else
	#define X_RES 320 // 横方向解像度
	#define Y_RES 240 // 縦方向解像度
#endif

#ifdef PIMORONI_PICOSYSTEM
#define LCD_SCK 6
#define LCD_TX 7
#define LCD_CS 5
#define LCD_DC 9
#define LCD_RESET 4
#define LCD_BACKLIGHT 12
#define LCD_VSYNC 8
#define LCD_SPI_FREQ 62500 * 1000
#else
#define LCD_SCK PICO_DEFAULT_SPI_SCK_PIN
#define LCD_TX PICO_DEFAULT_SPI_TX_PIN
#define LCD_CS 11 //GPIO11
#define LCD_DC 12 //GPIO12
#define LCD_RESET 13 //GPIO13
#define LCD_SPI_FREQ 40000 * 1000
#endif

#define SPICH spi0

void LCD_WriteComm(unsigned char comm);
void LCD_WriteData(unsigned char data);
void LCD_WriteData2(unsigned short data);
void LCD_WriteDataN(unsigned char *b,int n);
void LCD_Init(void);
void LCD_SetCursor(unsigned short x, unsigned short y);
void LCD_Clear(unsigned short color);
void drawPixel(unsigned short x, unsigned short y, unsigned short color);
unsigned short getColor(unsigned short x, unsigned short y);
