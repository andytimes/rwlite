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
#include <fstream>

enum {
	CHAR_EN_SIZE = 1,
	CHAR_CN_SIZE = 3,
};

extern const char SCRIPT_NAME[];

class Print {
public:
	Print(const std::string &name = SCRIPT_NAME) :
		script_name(name) {}
	~Print() { close(); }
	bool open(const std::string &name = SCRIPT_NAME);
	void close();
	void read();
	void command(const std::string &cmd);

	void view(const std::string &s, int del = RUN_AUTO,
			int char_del = NORMAL_DELAY);
	void title(const std::string &s);
	void sub(const std::string &s);
	void info(const std::string &s, int del = RUN_AUTO,
			int char_del = NORMAL_DELAY);
	void mono(const std::string &s, int del = RUN_AUTO,
			int char_del = NORMAL_DELAY);
private:
	static const int RUN_AUTO = -20;
	static const int MANUAL = -21;
	static const int NO_DELAY = 0;
	static const int FAST_DELAY = 10;
	static const int NORMAL_DELAY = 20;

	std::fstream::pos_type mark = 0;
	std::string script_name;
	std::fstream file;
	std::string line;

	bool get();

	int auto_sleep(const std::string &s);
	void delay(int del);
	void per_char_delay(int del);

	void rwsleep(const std::string &s);
	void rwmusic(const std::string &file);
};

#endif // __REWRITE_PRINT_H
