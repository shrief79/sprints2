#ifndef FH_H_
#define FH_H_

#include <iostream>
#include <fstream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <cstring>
#include <sys/epoll.h>
#include "../logger/simpleLogger.h"

// using namespace std;
#define BackingFile "/my_shared_memory_file"
#define AccessPerms 0644
#define ByteSize 1024
#define SemaphoreName "/my_semaphore"

//enum for errors
typedef enum{
	SUCCESS=0,
	FAILED,
    READ_FILE,
    LIST

}Error_t;


void report_and_exit(const char *msg);
Error_t ls_command(std::string message, void *memptr);
Error_t read_command(std::string message, void *memptr);



#endif
