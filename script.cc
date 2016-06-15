/*
 * Copyright (c) 2016, Andy Deng <theandy.deng@gmail.com>
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

#include <fstream>
using std::fstream; using std::getline;

#include <iostream>
using std::cerr; using std::endl;

#include <string>
using std::string; using std::stoi;

#include <SDL_mixer.h>

#include "script.h"
#include "common.h"
#include "print.h"
#include "time.h"
#include "music.h"
#include "rewrite.h"

static const string &rwscript_name("script.txt");

static const string cmd_sleep("$sleep ");
static const string cmd_music("$music ");
static const string cmd_save("$save ");
static const string cmd_load("$load ");
static const auto cmd_nofound(std::string::npos);

bool Script::open()
{
	rwscript.open(rwscript_name, fstream::in);

	if (!rwscript) {
		cerr << "Unable to open " << rwscript_name << "!" << endl;
		return false;
	}

	if (rw_continue)
		load();

	return true;
}

void Script::close()
{
	if (rwscript.is_open())
		rwscript.close();
}

bool Script::get()
{
	if (getline(rwscript, line)) {
		++line_num;
		script_mark = rwscript.tellg();
	} else {
		return false;
	}

	if (line_num % 51 == 0)
		save();

	return true;
}

void Script::read()
{
	open();

	while (rwscript && get()) {
		if (line.empty())
			continue;

		const string &prefix = line.substr(0, 2);

		if (prefix == ";;")
			continue;

		if (line.front() == '$') {
			command(line);
			continue;
		} else if (line.front() == '[' && line.back() == ']') {
			sub(line);
			continue;
		}

		if (line.back() == '\\') {
			line.pop_back();
			line += '\n';
		}

		if (prefix == "--") {
			const string &s = line.substr(2);

			if (s.back() == '\n') {
				multiline += s;
			} else if (!multiline.empty()) {
				multiline += s;
				mono(multiline);
				multiline.clear();
			} else {
				mono(s);
			}
			continue;
		} else if (prefix == "=T") {
			title(line.substr(2));
			continue;
		} else {
			if (line.back() == '\n') {
				multiline += line;
			} else if (!multiline.empty()) {
				multiline += line;
				info(multiline);
				multiline.clear();
			} else {
				info(line);
			}
		}
	}

	close();
}

void Script::command(const std::string &s)
{

	if (s.find(cmd_sleep) != cmd_nofound) {
		const string &cmd = s.substr(cmd_sleep.size());
		rwsleep(cmd);
	} else if (s.find(cmd_music) != cmd_nofound) {
		const string &cmd = s.substr(cmd_music.size());
		rwmusic(cmd);
	} else if (s.find(cmd_save) != cmd_nofound) {
		const string &cmd = s.substr(cmd_save.size());
		rwsave(cmd);
	} else if (s.find(cmd_load) != cmd_nofound) {
		const string &cmd = s.substr(cmd_load.size());
		rwload(cmd);
	}
}

void Script::rwsleep(const string &s)
{
#ifndef RWDEBUG
	sleep(stoi(s));
#else
	msleep(500);
#endif
}

void Script::rwmusic(const string &s)
{
	play_bgm(s);
}

void Script::rwsave(const string &s)
{
	if (s != "auto")
		save(stoi(s));
	else
		save();
}

void Script::rwload(const string &s)
{
	if (s != "auto")
		load(stoi(s));
	else
		load();
}
