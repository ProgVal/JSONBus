
#include <sharedlib.h>
#include <common.h>

namespace jsonbus {

#ifdef WIN32
const int SharedLib::DefaultFlags = 0;
#else
const int SharedLib::DefaultFlags = RTLD_LAZY|RTLD_GLOBAL;
#endif

SharedLib::SharedLib(const QString &path)
        : path(path),
        handle(0) {
}

SharedLib::~SharedLib() {
    if(handle != 0)
        unload();
}

void SharedLib::load(int flags) {
    QString lastError;
    if(handle!=0){
        lastError = "Dynamic library already loaded.";
        outErr << lastError << "\n" << endl;
        throw new SharedLibException("Fail to load the plugin : " + lastError);
    }
#ifdef WIN32
    //Chargement de la lib
    handle = LoadLibrary (path.c_str());
    if (!handle) {
        lastError="LoadLibrary() >> " + getMessageError(GetLastError());
        outErr << lastError << "\n" << endl;
        throw new SharedLibException("Fail to load the dynamic library : " + lastError);
    }
#else
    char *dl_error;
    //Chargement de la lib
    handle = dlopen (path.toAscii(), flags);
    if (!handle) {
        dl_error=dlerror();
        lastError="dlopen() >> "+QString(dl_error);
        outErr << lastError << "\n" << endl;
        throw new SharedLibException("Fail to load the dynamic library : " + lastError);
    }
#endif
}

void *SharedLib::getSymbol(const char *symbol) {
    QString lastError;
    if(handle==0){
        lastError = "Dynamic library not loaded.";
        outErr << lastError << "\n" << endl;
        throw new SharedLibException("Fail to get a symbol : " + lastError);
    }
    void *ptr;
#ifdef WIN32
    ptr = GetProcAddress(handle, symbol);
    if (ptr == NULL)  {
        lastError="GetProcAddress(\""+QString(symbol)+"\") >> " + getMessageError(GetLastError());
        outErr << lastError << "\n" << endl;
        throw new SharedLibException("Fail to get the symbol : " + lastError);
    }
#else
    char *dl_error;
    ptr = dlsym(handle, symbol);
    if ((dl_error = dlerror()) != NULL)  {
        lastError="dlsym() >> "+QString(dl_error);
        outErr << lastError << "\n" << endl;
        throw new SharedLibException("Fail to load the plugin : " + lastError);
    }
#endif
    return ptr;
}

void SharedLib::unload() {
    QString lastError;
    if(handle==0){
        lastError = "Dynamic library not loaded.";
        outErr << lastError << "\n" << endl;
        throw new SharedLibException("Fail to unload the plugin : " + lastError);
    }
#ifdef WIN32
    FreeLibrary(handle);
#else
    dlclose(handle);
#endif
    handle = 0;
}

}