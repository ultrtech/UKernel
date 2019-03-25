#include "include/screen.h"
#include "include/charcolors.h"

char *vidmemptr = (char *)0xb8000; // pointer to video memory
unsigned int current_loc = 0;	  // current char location

/*
Writes chars to video memory
*/
void kprint(const char *str)
{
	unsigned int i = 0;
	while (str[i] != '\0')
	{												  // print until null-byte is present
		vidmemptr[current_loc++] = str[i++];		  // print char
		vidmemptr[current_loc++] = CHAR_FG_LIGHTGRAY; // light gray font
	}
}

/*
kprint() variant with colored text
*/
void kprintcolored(const char *str, unsigned int color)
{
	unsigned int i = 0;
	while (str[i] != '\0')
	{										 // print until null-byte is present
		vidmemptr[current_loc++] = str[i++]; // print char
		vidmemptr[current_loc++] = color;	// set attrib-byte to user-defined color
	}
}

/*
Print empty chars until the end of current line
*/
void kprint_newline(void)
{
	unsigned int line_size = CHAR_BYTE_SIZE * COLUMNS_IN_LINE;
	current_loc = current_loc + (line_size - current_loc % (line_size));
}

/*
Loop over the entire screen, filling video memory with empty chars
*/
void clear_screen(void)
{
	unsigned int i = 0;
	while (i < SCREENSIZE)
	{
		vidmemptr[i++] = ' ';
		vidmemptr[i++] = 0x07;
	}
}