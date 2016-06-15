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

#include <iostream>
using std::cerr; using std::endl;

#include <fstream>
using std::fstream;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <iomanip>
using std::setfill; using std::setw;

#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"
using namespace rapidjson;

#include "savedata.h"

const string &SavedataName = string("rwsave.json");
const string &DefaultSavedata = string("{\"save001\":0}");

void Savedata::create()
{
	sav_file.open(SavedataName, fstream::out | fstream::trunc);
	sav_file << DefaultSavedata;
	sav_file.close();
}

void Savedata::save(unsigned ix)
{
	const string s = index_name(ix);

	sav_file.open(SavedataName, fstream::in);

	if (!sav_file.is_open()) {
		create();
		sav_file.open(SavedataName, fstream::in);
	}

	stringstream ss;
	ss << sav_file.rdbuf();
	sav_file.close();

	Document d;
	d.Parse(ss.str().c_str());

	if (d.HasMember(s.c_str())) {
		Value &cur = d[s.c_str()];
		cur.SetUint(script_mark);
	} else {
		Value &new_sav = Value(script_mark).Move();
		d.AddMember(StringRef(s.c_str()), new_sav, d.GetAllocator());
	}

	StringBuffer buffer;
	PrettyWriter<StringBuffer> writer(buffer);
	d.Accept(writer);

	sav_file.open(SavedataName, fstream::out | fstream::trunc);
	sav_file << buffer.GetString();
	sav_file.close();
}

void Savedata::load(unsigned ix)
{
	const string s = index_name(ix);

	sav_file.open(SavedataName, fstream::in);

	if (!sav_file.is_open()) {
		create();
		sav_file.open(SavedataName, fstream::in);
	}

	stringstream ss;
	ss << sav_file.rdbuf();
	sav_file.close();

	Document d;
	d.Parse(ss.str().c_str());

	Value::ConstMemberIterator it = d.FindMember(s.c_str());

	if (it == d.MemberEnd()) {
		cerr << "No such " << s << " found!" << endl;
		return;
	}

	rwscript.seekg(it->value.GetUint());
}

string Savedata::index_name(unsigned ix)
{
	stringstream ss;
	ss << "save" << setfill('0') << setw(3) << ix;

	return ss.str();
}

bool Savedata::pretty()
{
	sav_file.open(SavedataName, fstream::in);

	if (!sav_file.is_open()) {
		cerr << "Unable to open " << SavedataName << endl;
		return false;
	}

	stringstream ss;
	ss << sav_file.rdbuf();
	sav_file.close();

	Document d;
	d.Parse(ss.str().c_str());

	StringBuffer buffer;
	PrettyWriter<StringBuffer> writer(buffer);
	d.Accept(writer);

	sav_file.open(SavedataName, fstream::out | fstream::trunc);
	sav_file << buffer.GetString();
	sav_file.close();

	return true;
}
