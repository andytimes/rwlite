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

#ifndef __REWRITE_PRINT_H
#define __REWRITE_PRINT_H

#include <string>

#define RUN_AUTO	-20
#define RUN_MANUAL	-21

enum Char_Size {
	CHAR_EN_SIZE = 1,
	CHAR_CN_SIZE = 3,
};

enum Delay_Level {
	NO_DELAY = 0,
	FAST_DELAY = 10,
	NORMAL_DELAY = 20,
};

class Print {
public:
	/*
	 * Terminal's' print operation:
	 *
	 * @s:        the string that need to print;
	 * @del:      delay (del) seconds after print finish;
	 * @char_del: delay (char_del) milliseconds between each character.
	 *
	 * title() and sub() doesn't have @del and @char_del parameters.
	 */
	void title(const std::string &s);
	void sub(const std::string &s);
	void view(const std::string &s, int del = RUN_AUTO,
			int char_del = NORMAL_DELAY);
	void info(const std::string &s, int del = RUN_AUTO,
			int char_del = NORMAL_DELAY);
	void mono(const std::string &s, int del = RUN_AUTO,
			int char_del = NORMAL_DELAY);
private:

	int auto_sleep(const std::string &s);
	void delay(int del);
	void per_char_delay(int del);
};

#endif // __REWRITE_PRINT_H
