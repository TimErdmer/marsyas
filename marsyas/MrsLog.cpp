/*
** Copyright (C) 1998-2006 George Tzanetakis <gtzan@cs.uvic.ca>
**  
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software 
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/**
\class MrsLog
\brief Logging Class

Logging class for diagnostic, warning, error, debug, etc messages. Can output
messages to a log file or std output (i.e. screen).
*/

#include <iostream>
#include <fstream>

#include "MrsLog.h"
#include "common.h"

using namespace std;
using namespace Marsyas;

string MrsLog::fname_ = "marsyas.log";

void 
MrsLog::setLogFile(string fname)
{
	fname_ = fname;
}

void 
MrsLog::mrsErr(const ostringstream& oss)
{
#ifdef MARSYAS_LOG2STDOUT
	cout << oss.str() << endl;
#endif

#ifdef MARSYAS_LOG2FILE
	ofstream ofs(fname_.c_str(), ios::out | ios::app);
	if (ofs.fail())
		return;
	if (!(ofs << "[MRSERR] " << oss.str() << endl))
	{
		ofs.close();
		return;
	}
	ofs.close();
	return;
#endif 
}

void 
MrsLog::mrsWarning(const ostringstream& oss)
{
#ifdef MARSYAS_LOG2STDOUT
	cout << oss.str() << endl;
#endif

#ifdef MARSYAS_LOG2FILE
	ofstream ofs(fname_.c_str(), ios::out | ios::app);
	if (ofs.fail())
		return;
	if (!(ofs << "[MRS_WARNING] " <<  oss.str() << endl))
	{
		ofs.close();
		return;
	}
	ofs.close();
	return;
#endif
}

void 
MrsLog::mrsDiagnostic(const ostringstream& oss)
{
#ifdef MARSYAS_LOG2STDOUT
	cout << oss.str() << endl;
#endif

#ifdef MARSYAS_LOG2FILE
	ofstream ofs(fname_.c_str(), ios::out | ios::app);
	if (ofs.fail())
		return;
	if (!(ofs << "[MRS_DIAG] " <<  oss.str() << endl))
	{
		ofs.close();
		return;
	}
	ofs.close();
	return;
#endif
}

void 
MrsLog::mrsDebug(const ostringstream& oss)
{
#ifdef MARSYAS_LOG2STDOUT
	cout << oss.str() << endl;
#endif

#ifdef MARSYAS_LOG2FILE
	ofstream ofs(fname_.c_str(), ios::out | ios::app);
	if (ofs.fail())
		return;
	if (!(ofs << "[MRS_DEBUG] " <<  oss.str() << endl))
	{
		ofs.close();
		return;
	}
	ofs.close();
	return;
#endif
}

void 
MrsLog::mrsAssert(char *strFile, unsigned uLine) 
{
	fflush(NULL);
	fprintf(stderr, "\nMARSYAS Assertion failed: %s, line %u\n", 
		strFile, uLine);
	fflush(stderr);
	abort();
}

