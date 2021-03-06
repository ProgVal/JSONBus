/*
    Copyright (c) 2012, Emeric Verschuur <emericv@openihs.org>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
        * Neither the name of the OpenIHS.org nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY Emeric Verschuur <emericv@openihs.org> ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL Emeric Verschuur <emericv@openihs.org> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef JSONPARSER_STDSTREAMBUF_H
#define JSONPARSER_STDSTREAMBUF_H

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <QIODevice>
#include "abstractstreambuf.h"

/**
 * @namespace
 */
namespace jsonparser {

class StdStreamBuf : public AbstractStreamBuf {
public:
	inline StdStreamBuf(std::istream &stream): m_streambuf(*stream.rdbuf()) {};
	inline virtual ~StdStreamBuf() {};
protected:
	inline virtual bool waitReadyToRead(int timeout) { 
		if (!m_streambuf.in_avail()) {
			usleep(timeout);
			return false;
		} else {
			return true;
		}
	};
	inline virtual int getNextChar() { return m_streambuf.sbumpc(); };
	
private:
	std::streambuf &m_streambuf;
};

}

#endif // JSONPARSER_STDSTREAMBUF_H
