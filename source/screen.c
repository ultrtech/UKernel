#include "include/screen.h"
#include "include/charcolors.h"

char *vidmemptr = (char*)0xb8000;
unsigned int current_loc = 0;

void kprint(const char *str)
{
	unsigned int i = 0;
	while (str[i] != '\0') {
		vidmemptr[current_loc++] = str[i++];
		vidmemptr[current_loc++] = CHAR_FG_LIGHTGRAY; // light gray font
	}
}

void kprintcolored(const char *str, unsigned int color)
{
	unsigned int i = 0;
	while (str[i] != '\0') {
		vidmemptr[current_loc++] = str[i++];
		vidmemptr[current_loc++] = color; // light gray font
	}
}

void kprint_newline(void)
{
	unsigned int line_size = CHAR_BYTE_SIZE * COLUMNS_IN_LINE;
	current_loc = current_loc + (line_size - current_loc % (line_size));
}

void clear_screen(void)
{
	unsigned int i = 0;
	while (i < SCREENSIZE) {
		vidmemptr[i++] = ' ';
		vidmemptr[i++] = 0x07;
	}
}