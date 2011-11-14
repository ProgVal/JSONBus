/*
    Copyright (c) 2011, Emeric Verschuur <emericv@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
        * Neither the name of the <organization> nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY Emeric Verschuur <emericv@gmail.com> ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL Emeric Verschuur <emericv@gmail.com> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * @brief JSONBus : Commuon
 * @file common.h
 * @author Emeric VERSCHUUR <contact@mr-ti.com>, (C) 2012
 */

#ifndef JSONBUS_COMMON_H
#define JSONBUS_COMMON_H

#ifndef JSONBUS_EXPORT
#define JSONBUS_EXPORT
#endif

#include <iostream>
#include <QString>

#define outLog cout
#define outErr cerr
#define outCri cerr
#define outSysErr cerr << 

using namespace std;

namespace jsonbus {

inline JSONBUS_EXPORT std::ostream &operator << (std::ostream &stream, const QString &string) {
    return (stream << string.toStdString());
}

#ifdef WIN32
inline JSONBUS_EXPORT QString getMessageError(DWORD no) {
    LPVOID lpMsgBuf;
    QString buf;
    if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),0,(LPTSTR) &lpMsgBuf,0,NULL)) {
        buf=string((char*)lpMsgBuf);
        LocalFree(lpMsgBuf);
    } else {
        buf="error no "+TOSTDSTR(no);
    }
    return buf;
}
#endif

}

#endif