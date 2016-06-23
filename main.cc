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

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout;

#include <SDL.h>
#include <SDL_mixer.h>
#include "cursor.h"
#include "print.h"
#include "music.h"
#include "script.h"

int aurora;
bool rw_continue = false;

static bool music_switch()
{
	string s;

	cout << "是否开启音乐？\n\n1.开启  2.关闭\n\n请选择 (默认关闭): ";

	return (cin >> s && s[0] == '1');
}

static void quit()
{
	clscr();
	Mix_Quit();
	SDL_Quit();
}

static void main_line()
{
	Script script;
	script.read();
	quit();
}

static void start_menu()
{
	string s;
	Print prt;

	clscr();
	music_on = music_switch();
	mix_init();
	play_bgm(RW_Tabi);

	clscr();
	cout << "Rewrite Lite (Terminal)\n\n  1.开始 Rewrite"
		"\n  2.继续 Rewrite\n  3.退出\n\n请选择(默认退出): ";

	while (cin >> s) {
		switch (s[0]) {
		case '1':
			goto start;
		case '2':
			goto read;
		case '3':
		default:
			goto end;
		}
	}

start:
	clscr();
	prt.view("\n将一切，全部改写 ...\n", 5);
	clscr();
	main_line();
	return;

read:
	rw_continue = true;
	clscr();
	prt.view("\n延续 ...", 5);
	clscr();
	main_line();
	return;

end:
	clscr();
	prt.view("\n结束 ...", 3);
	clscr();
	return;
}

int main(int, char *[])
{
	start_menu();
}
