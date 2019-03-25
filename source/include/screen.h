#pragma once
#define LINES 25
#define COLUMNS_IN_LINE 80
#define CHAR_BYTE_SIZE 2
#define SCREENSIZE CHAR_BYTE_SIZE * COLUMNS_IN_LINE * LINES

extern unsigned int current_loc;
extern char *vidmemptr;

void kprint(const char *str);
void kprintcolored(const char *str, unsigned int color);
void kprint_newline(void);
void clear_screen(void);
