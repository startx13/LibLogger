#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

const char* app = "not setted yet!";
int init = 0;
int tofile = 0;

int LogInit(const char* nomeapp, int filelog){
	init = 1;
	app = nomeapp;
    if(filelog == 1){
        FILE *f = fopen("log.txt", "a");
        if (f == NULL)
        {
	    LogError("Error opening log file");
            return 1;
        }else{
            fprintf(f,"[LibLogger] Init\n");
            tofile = filelog;
            return 0;
        }
        
    }
    return 0;
}

int LogString(const char* msg){
	if(init == 1){
		printf("[%s]%s\n",app,msg);
        if(tofile == 1){
            FILE *f = fopen("log.txt", "a");
            if (f == NULL)
            {
                LogError("Error opening log file");
                return 1;
            }else{
                fprintf(f,"[%s]%s\n",app,msg);
                return 0;
            }
            
        }
	}else{
		printf("[LibLogger] ERROR:App name not setted\n");
        return 3;
    }
    
}

int LogWarning(const char* msg){
	
	if(init == 1){
        printf("[%s]WARNING:%s\n",app,msg);
        if(tofile == 1){
            FILE *f = fopen("log.txt", "a");
            if (f == NULL)
            {
                LogError("Error opening log file");
                return 1;
            }else{
                fprintf(f,"[%s]WARNING:%s\n",app,msg);
                return 0;
            }
        }
        
    }else{
        printf("[LibLogger] ERROR:App name not setted\n");
        return 3;
    }
    
}

int LogError(const char* msg){
	if(init == 1){
        printf("[%s]ERROR:%s\n",app,msg);
        if(tofile == 1){
            FILE *f = fopen("log.txt", "a");
            if (f == NULL)
            {
                LogError("Error opening log file");
                return 1;
            }else{
                fprintf(f,"[%s]ERROR:%s\n",app,msg);
                return 0;
            }
            
        }
    }else{
            printf("[LibLogger] ERROR:App name not setted\n");
            return 3;
    }

}

int LogFatalError(const char* msg){
	if(init == 1){
        printf("[%s]FATAL ERROR:%s\n",app,msg);
        if(tofile == 1){
            FILE *f = fopen("log.txt", "a");
            if (f == NULL)
            {
                LogError("Error opening log file");
                return 1;
            }else{
                fprintf(f,"[%s]FATAL ERROR:%s\n",app,msg);
                return 0;
            }
        }
    }else{
        printf("[LibLogger] ERROR:App name not setted\n");
        return 3;
    }
}
