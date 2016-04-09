/*
 * Copyright (c) 2016, Andy Deng <theandy.deng@gmail.com>
 *
 * Licensed under the FreeBSD as detailed in the accompanying
 * LICENSE file.
 */

#ifndef __REWRITE_CURSOR_H
#define __REWRITE_CURSOR_H

#include <stdio.h>
#include "rewrite.h"
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#define CLR_SCR		"\033[1H\033[2J"

#if !defined(_WIN32) && !defined(_WIN64)
#define CLR_LINE	"\033[2K\r"
#else
#define CLR_LINE	"\r                                        " \
			"                    \r"
#endif

#if !defined(_WIN32) && !defined(_WIN64)
#define CLR_UNDER	"\033[2K\033[B\033[2K\033[B\033[2K\033[B\033[2K\033[B" \
			"\033[2K\033[B\033[2K\033[B\033[2K\033[B\033[2K"
#else
#define CLR_UNDER	"\r                                        " \
			"                    \n" \
			"\r                                        " \
			"                    \n" \
			"\r                                        " \
			"                    \n" \
			"\r                                        " \
			"                    \n" \
			"\r                                        " \
			"                    \n" \
			"\r                                        " \
			"                    \n" \
			"\r                                        " \
			"                    \n" \
			"\r                                        " \
			"                    "
#endif

static inline void goto_xy(const unsigned int x, const unsigned int y)
{
#if defined(_WIN32) || defined(_WIN64)
	COORD cursorPosition;
	cursorPosition.X = x - 1;
	cursorPosition.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
				 cursorPosition);
#else
	printf("\033[%u;%dH", y, x);
#endif
}

static inline void clr_scr(void)
{
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	printf("%s", CLR_SCR);
#endif
}

static inline void clr_line(void)
{
	printf("%s", CLR_LINE);
}

static inline void clr_sub(void)
{
	goto_xy(1, 5);
	printf("%s", CLR_UNDER);
	goto_xy(1, 5);
}

static inline void clr_info(void)
{
	goto_xy(1, 7);
	printf("%s", CLR_UNDER);
	goto_xy(1, 7);
}

/*
 * Text output effect 1:
 *
 * Output 1 character per 24 ms (custom with change char_control to 1)
 *
 * delay：wait (delay) seconds once output finish.
 */
extern void txt_view(const char* str, const unsigned int delay);

/*
 * Text output effect 2:
 *
 * Same as Text output effect 1, but clean all characters after delay.
 */
static inline void one_line(const char *str, const unsigned int delay)
{
	txt_view(str, delay);
	clr_line();
}

static inline void prt_info(const char *str, const unsigned int delay)
{
	clr_info();
	goto_xy(1, 7);
	txt_view(str, delay);
}

// Output character monologue
static inline void prt_mono(const char *str, const unsigned int delay)
{
	clr_sub();
	prt_info(str, delay);
}

static inline void prt_sub(const char *str)
{
	clr_sub();
	goto_xy(1, 5);
	printf("%s", str);
}

static inline void prt_title(const char *str)
{
	clr_scr();
	goto_xy(1, 1);
	printf("%s", str);
}

#endif // __REWRITE_CURSOR_H
