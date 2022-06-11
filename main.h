#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>



/**
 *struct handler - struct to choose the right function dependin on format specifier
 *@handler: format specifier
 *@printer: function to print
 */

typedef struct handler
{
	char *identifier;
	int (*printer)(va_list);
} handler;


//function prototypes
int _write(char c);
int _printf(char *,...);
int print_char(va_list arg);
int printidentifier(char next, va_list arg);
int print_char(va_list arg);
int print_int(va_list arg);
int print_str(va_list arg);
#endif
