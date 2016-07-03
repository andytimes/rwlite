/*
 * Copyright (c) 2015-2016, Andy Deng <theandy.deng@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __REWRITE_CURSOR_H
#define __REWRITE_CURSOR_H

#define CLR_SCR		"\033c"

#ifndef _WIN32
#define CLR_LINE	"\033[2K\r"
#else
#define CLR_LINE	"\r                              " \
			"                              \r"
#endif

#ifndef _WIN32
#define CLR_UNDER	"\033[2K\033[B\033[2K\033[B\033[2K\033[B\033[2K\033[B" \
			"\033[2K\033[B\033[2K\033[B\033[2K\033[B\033[2K"
#else
#define CLR_UNDER	"\r                              " \
			"                              \n" \
			"\r                              " \
			"                              \n" \
			"\r                              " \
			"                              \n" \
			"\r                              " \
			"                              \n" \
			"\r                              " \
			"                              \n" \
			"\r                              " \
			"                              \n" \
			"\r                              " \
			"                              \n" \
			"\r                              " \
			"                              "
#endif

void goto_xy(int x, int y);

void clscr();
void clline();
void clsub();
void clinfo();

#endif // __REWRITE_CURSOR_H
