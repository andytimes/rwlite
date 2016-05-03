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
using std::cout; using std::flush;

#include <string>
using std::string;

#include "print.h"
#include "cursor.h"
#include "time.h"

int Print::auto_sleep(const string &s)
{
	bool is_long_cn_str = s.size() > CHAR_CN_SIZE * 15;
	return is_long_cn_str ? 3 : 2;
}

void Print::delay(int del)
{
#ifndef RWDEBUG
	sleep(del);
#else
	msleep(10);
#endif
}

void Print::per_char_delay(int del)
{
#ifndef RWDEBUG
	msleep(del);
#else
	msleep(10);
#endif
}

void Print::title(const string &s)
{
	clscr();
	goto_xy(1, 1);
	cout << s;
}

void Print::sub(const string &s)
{
	clsub();
	goto_xy(1, 5);
	cout << s;
}

void Print::view(const string &s, int del, int char_del)
{
	for (auto i : s) {
		cout << i << flush;
		per_char_delay(char_del);
	}

	if (del == RUN_AUTO)
		delay(auto_sleep(s));
	else
		delay(del);
}

void Print::info(const string &s, int del, int char_del)
{
	clinfo();
	goto_xy(1, 7);
	view(s, del, char_del);
}

void Print::mono(const string &s, int del, int char_del)
{
	clsub();
	goto_xy(1, 7);
	view(s, del, char_del);
}
