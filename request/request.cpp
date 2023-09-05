#include "request.h"


void report_and_exit(const char* msg) {
  perror(msg);
  exit(-1);
}

//checking the num of arguments
Error_t CheckArg (int Count)
{

    if ( Count != 3) {
        
            return FAILED  ;
        }
        else{
            return SUCCESS ;
        }
}

//reading the order
Error_t ReadOrder (string *Order ,char *OrderType)
{

    if (strcmp(OrderType, "-r") == 0) {
            *Order = "0"+ *Order;
           return READ_FILE ;

        } else if (strcmp(OrderType, "-l") == 0) {
             *Order = "1"+ *Order;
           return LIST;

        } 
        else {
           
           return FAILED;
    }

}

//create a named pipe
void CreatePipe (const char **pipeName)
{

 *pipeName = "./fifoChannel";
    
    /* read/write for user/group/others */
    mkfifo(*pipeName, AccessPipePerms);

}
//open the named pipe, open as write-only 
Error_t OpenPipe (const char **pipeName , int *copy_fd)
{
    *copy_fd = open(*pipeName, O_CREAT | O_WRONLY); 
    if (*copy_fd < 0) 
    {
        return FAILED;
    }
    else
    {
        return SUCCESS;
    }
}
//create a shared memory
Error_t OpenSharedMemory(int* copy_fd)
{
    *copy_fd = shm_open(BackingFile, O_RDWR, AccessPerms);  /* empty to begin */
    if(*copy_fd < 0)
    {
         return FAILED;
    }
    else
    {
         return SUCCESS;
    }
}

Error_t CreateMemoryPointer (void **MemoryPtr, int *copy_fd)
{
    *MemoryPtr = mmap(NULL,       /* let system pick where to put segment */
                        ByteSize,   /* how many bytes */
                        PROT_READ | PROT_WRITE, /* access protections */
                        MAP_SHARED, /* mapping visible to other processes */
                        *copy_fd,         /* file descriptor */
                        0);         /* offset: start at 1st byte */

    if ((void*) -1 == *MemoryPtr)
    {
        return FAILED;
    }
    else
    {
        return SUCCESS;
    }
}
/* create a semaphore for mutual exclusion */
Error_t CreateSem(sem_t** copyp_semptr)
{
    * copyp_semptr = sem_open(SemaphoreName, /* name */
                            O_CREAT,       /* create the semaphore */
                            AccessPerms,   /* protection perms */
                            0);            /* initial value */
    if(* copyp_semptr == (void*) -1)
    {
        return FAILED;
    }
    else
    {
        return SUCCESS;
    }
}

/* use semaphore waiting for the writer to increment it */
void WaitSem(sem_t** copyp_semptr, void **copy_mmptr)
{
    if (!sem_wait(*copyp_semptr)) { /* wait until semaphore != 0 */
        for (int i = 0; i < MemContents ; i++)
            write(STDOUT_FILENO, static_cast<char*>(*copy_mmptr) + i, 1); /* one byte at a time */
        sem_post(*copyp_semptr);
    }
}
