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

    THIS SOFTWARE IS PROVIDED BY Emeric Verschuur ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL Emeric Verschuur BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * @brief Sample JSONBus echo plugin.
 * @file echo.h
 * @author Emeric VERSCHUUR <emericv@openihs.org>, (C) 2012
 */

#ifndef JSONBUS_SERVICES_ECHO_H
#define JSONBUS_SERVICES_ECHO_H

#include <jsonbus/core/exception.h>
#include <jsonbus/core/plugin.h>

using namespace JSONBus;

/**
 * @brief Sample JSONBus echo plugin.
 */
class Echo: public Plugin {
public:
	/**
	 * @brief Echo service constructor.
	 */
	Echo();

	/**
	 * @brief Echo service destructor.
	 */
	~Echo();
	
	/**
	 * @brief Function called on plugin init
	 */
	virtual void onInit (Settings &settings);
	
	/**
	 * @brief Function called on plugin load
	 */
	virtual void onLoad (Settings &settings);
	
	/**
	 * @brief Function called on plugin unload
	 */
	virtual void onUnload ();
	
	/**
	 * @brief Function called on plugin request
	 */
	virtual void onRequest(QVariant request);
private:
	QString m_fieldName;
	QString m_helloMsg;
};

#endif // JSONBUS_PLUGIN_ECHO_H
