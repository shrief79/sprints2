#ifndef    REQUEST_H
#define    REQUEST_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <string>
#include <sys/shm.h>
#include "../logger/simpleLogger.h"

using namespace std;


/* Define the shared memory file name*/
#define BackingFile "/my_shared_memory_file" 

/*Define the access permissions*/ 
#define AccessPerms 0644 

/*Define the access pipe permissions*/ 
#define AccessPipePerms 0666 


/* Define the size of the shared memory segment*/                     
#define ByteSize 1024    

/* Define the name of the semaphore*/    
#define SemaphoreName "/my_semaphore"       

/*Define the content to write to shared memory*/
#define MemContents 4096  /*you can upgrade as you want to read or list */


typedef enum{
	SUCCESS=0,
	FAILED,
    READ_FILE,
    LIST

}Error_t;

void report_and_exit(const char* msg);

Error_t CheckArg (int Count);

Error_t ReadOrder (string *Order ,char *OrderType);

void CreatePipe (const char **pipeName);

Error_t OpenPipe (const char **pipeName , int *copy_fd);

Error_t OpenSharedMemory(int* copy_fd);

Error_t CreateMemoryPointer (void **MemoryPtr, int *copy_fd);

Error_t CreateSem(sem_t** copyp_semptr);

void WaitSem(sem_t** copyp_semptr, void **copy_mmptr);









#endif
