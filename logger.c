#include <stdio.h>
#include "logger.h"

const char* app = "not setted yet!";
int init = 0;

void LogInit(const char* nomeapp){
	init = 1;
	app = nomeapp;
}

void LogString(const char* msg){
	if(init == 1){
		printf("[%s]%s\n",app,msg);
	}else{
		printf("[LibLogger] ERROR:App name not setted\n");
	}
}

void LogWarning(const char* msg){
	
	if(init == 1){
                printf("[%s]WARNING:%s\n",app,msg);
        }else{
                printf("[LibLogger] ERROR:App name not setted\n");
        }
}

void LogError(const char* msg){
	if(init == 1){
                printf("[%s]ERROR:%s\n",app,msg);
        }else{
                printf("[LibLogger] ERROR:App name not setted\n");
        }

}

void LogFatalError(const char* msg){
	if(init == 1){
                printf("[%s]FATAL ERROR:%s\n",app,msg);
        }else{
                printf("[LibLogger] ERROR:App name not setted\n");
        }
}
