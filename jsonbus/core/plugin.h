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
 * @brief JSONBus : Plugin service management.
 * @file service.h
 * @author Emeric VERSCHUUR <emericv@openihs.org>, (C) 2012
 */

#ifndef JSONBUS_SERVICE_H
#define JSONBUS_SERVICE_H

#include <jsonbus/core/exception.h>
#include <jsonbus/core/settings.h>

#define jsonbus_declare_plugin(class_name) \
extern "C" {\
	JSONBus::Plugin *getSingleton () {\
		return new class_name();\
	}\
}

#ifndef JSONBUS_EXPORT
#define JSONBUS_EXPORT
#endif

#include <QString>

namespace JSONBus {

jsonbus_declare_exception(PluginException, Exception);

/**
 * @brief Plugin management.
 */
class JSONBUS_EXPORT Plugin: public QObject {
	Q_OBJECT
public:
	/**
	 * @brief Plugin constructor.
	 */
	Plugin();

	/**
	 * @brief Plugin destructor.
	 */
	virtual ~Plugin() = 0;
	
	/**
	 * @brief Function called on plugin init
	 */
	inline virtual void onInit (Settings &settings) {};
	
	/**
	 * @brief Function called on plugin load
	 */
	inline virtual void onLoad (Settings &settings) {m_loaded = true;};
	
	/**
	 * @brief Function called on plugin unload
	 */
	inline virtual void onUnload () {m_loaded = false;};
	
	/**
	 * @brief Return true if the plugin is loaded
	 */
	inline bool isLoaded() {return m_loaded;};
	
	/**
	 * @brief Function called on plugin request
	 */
	virtual void onRequest(QVariant request) = 0;
	
signals:
	void resultAvailable(QVariant result);
	
private:
	
	bool m_loaded;
};

}

#endif
