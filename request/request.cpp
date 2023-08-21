/** Compilation: g++ -o request request.c -lrt -lpthread **/
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


#define BackingFile "/my_shared_memory_file"  // Define the shared memory file name
#define AccessPerms 0644                      // Define the access permissions
#define ByteSize 1024                         // Define the size of the shared memory segment
#define SemaphoreName "/my_semaphore"          // Define the name of the semaphore
#define MemContents "Hello, Shared Memory!"   // Define the content to write to shared memory

void report_and_exit(const char* msg) {
  perror(msg);
  exit(-1);
}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <-r or -l>" << std::endl;
        return -1;
    }
    /*creating a buffer for the command*/
    char m_buffer[1024];
    /*copying command to argv*/
    strcpy(m_buffer,argv[2]);
    /*there we had a problem that we cant use array of char cause i use the + on "1" and "0"*/
    std :: string message="";
    /* so i used message to prevent me from adding explicit declaration for the whole code */
    message=m_buffer;
    /*checking the command is r or l*/
    if (strcmp(argv[1], "-r") == 0) {
        message = "0"+message;//we are adding 0 to the string then we parse in the hundler file (0 refers to that the message is -r )
        LOG_DEBUG << "argv= -r";
        
    } else if (strcmp(argv[1], "-l") == 0) {
        message = "1"+message;//we are adding 1 to the string then we parse in the hundler file (0 refers to that the message is -l )
        LOG_DEBUG << "argv= -l";
    } else {
        std::cerr << "Invalid argument. Please provide -r or -l." << std::endl;
         LOG_ERROR << "Invalid argument. Please provide -r or -l.";
        return -1;
    }

    const char* pipeName = "../fifoChannel";
    mkfifo(pipeName, 0666); /* read/write for user/group/others */
    int fd = open(pipeName, O_CREAT | O_WRONLY); /* open as write-only */
    if (fd < 0) return -1; /* can't go on */

    
    write(fd, message.c_str(), message.size() + 1); 
    close(fd); /* close pipe */
    unlink(pipeName); /* unlink from the implementing file */
    //std::cout << "Value " << value << " sent to the pipe." << std::endl;

    sleep(3);

    /* shared memory */
    fd = shm_open(BackingFile, O_RDWR, AccessPerms);  /* empty to begin */
    if (fd < 0) {report_and_exit("Can't get file descriptor...");
	LOG_ERROR << "Can't get file descriptor...";}
    /* get a pointer to memory */
    void* memptr = mmap(NULL,       /* let system pick where to put segment */
                        ByteSize,   /* how many bytes */
                        PROT_READ | PROT_WRITE, /* access protections */
                        MAP_SHARED, /* mapping visible to other processes */
                        fd,         /* file descriptor */
                        0);         /* offset: start at 1st byte */
    if ((void*) -1 == memptr) {report_and_exit("Can't access segment...");
	LOG_ERROR << "Can't access segment...";}
    /* create a semaphore for mutual exclusion */
    sem_t* semptr = sem_open(SemaphoreName, /* name */
                            O_CREAT,       /* create the semaphore */
                            AccessPerms,   /* protection perms */
                            0);            /* initial value */
    if (semptr == (void*) -1){ report_and_exit("sem_open");
    LOG_ERROR << "sem_open";}

    /* use semaphore as a mutex (lock) by waiting for writer to increment it */
    if (!sem_wait(semptr)) { /* wait until semaphore != 0 */
        for (int i = 0; i < strlen(MemContents); i++)
            write(STDOUT_FILENO, static_cast<char*>(memptr) + i, 1); /* one byte at a time */
        sem_post(semptr);
    }

    /* cleanup */
    munmap(memptr, ByteSize);
    close(fd);
    sem_close(semptr);
    unlink(BackingFile);
    return 0;
}
