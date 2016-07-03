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

#include <iostream>
using std::cout;

#include "cursor.h"

#ifdef _WIN32
#include <windows.h>
#endif

void goto_xy(int x, int y)
{
#ifdef _WIN32
	COORD cursorPosition;
	cursorPosition.X = x - 1;
	cursorPosition.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
				 cursorPosition);
#else
	cout << "\033[" << y << ";" << x << "H";
#endif
}

void clscr()
{
#ifdef _WIN32
	system("cls");
#else
	cout << CLR_SCR;
#endif
}

void clline()
{
	cout << CLR_LINE;
}

void clsub()
{
	goto_xy(1, 5);
	cout << CLR_UNDER;
	goto_xy(1, 5);
}

void clinfo()
{
	goto_xy(1, 7);
	cout << CLR_UNDER;
	goto_xy(1, 7);
}
