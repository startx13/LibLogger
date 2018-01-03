//LibLogger header

//Status
// 0 = OK
// 1 = Error opening file
// 3 = App name not setted

//Filelog
// 0 = Disabled
// 1 = Enabled

int LogInit(const char* nomeapp, int filelog);

int LogString(const char* msg);

int LogWarning(const char* msg);

int LogError(const char* msg);

int LogFatalError(const char* msg);
