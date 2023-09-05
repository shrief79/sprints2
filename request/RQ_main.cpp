#include "request.h"



//check the path existance 
bool isPathExists(const std::string& path) {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}

int main(int argc, char* argv[]) {

    /*making a buffer that help me to pass the path of file or directory with the flag */
     char message1[1024];
    /*requester send order by pipe*/
     const char* pipeName;
     int fd;
     void* memptr; 
    sem_t* semptr;
    std :: string message="";
     
    Error_t ArgState = CheckArg (argc );
        if (ArgState == FAILED) {
            std::cerr << "Usage: " << argv[0] << " <-r or -l>" << std::endl;
        //LOG_ERROR << "Usage: <-r or -l>";
            LOG_ERROR << "the arguments not = 3";
            //report_and_exit("Not enough arguments"); 
            cout<<"ERROR-> the arguments not = 3"<<endl;
            return -1;
        }
        else{
        if(isPathExists(argv[2]))
        {
        
            strcpy(message1,argv[2]);
           
            message=message1;
         }
            else
            {
              cout<<"ERROR-> invaild path"<<endl;
              return -1;
            }

        }

    Error_t OrderState =  ReadOrder ( &message ,argv[1]);
    
        if(OrderState==READ_FILE)
        {
             LOG_DEBUG << "OrderType= -r";
             cout<<"request a read command"<<endl;
        }
       else if (OrderState==LIST) 
       {
             LOG_DEBUG << "OrderType= -l";
             cout<<"request a list command"<<endl;

       }
       else
       {
             LOG_ERROR << "Invalid argument. Please provide -r or -l.";
             //report_and_exit("Invalid arguments") ;
             cout<<"ERROR-> Invalid arguments"<<endl;
             return -1;
       }

    /*Named pipe*/ 
    CreatePipe (&pipeName);
    
    /* open as write-only */
    Error_t OpenState = OpenPipe (&pipeName , &fd);
        if(OpenState == FAILED )
        {

            LOG_ERROR << "Error opening the file";
            cout<<"ERROR-> opening the file"<<endl;
            return -1; // can't go on 
        }
        else 
        {
            /*using .c_str() to convert string to const char* */
            write(fd, message.c_str(), message.size() + 1);
            
            /* close pipe */
            close(fd); 
            unlink(pipeName); /* unlink from the implementing file */
            //std::cout << "Value " << value << " sent to the pipe." << std::endl;

            sleep(3);
        }


    /* shared memory */
    Error_t SHMOpenState = OpenSharedMemory(&fd);
        if(SHMOpenState == FAILED)
        {
            LOG_ERROR << "Can't get file descriptor...";
            //report_and_exit("Can't get file descriptor...");
            cout<<"ERROR-> Can't get file descriptor..."<<endl;
             return -1;
        }
        else
        {
            /* get a pointer to memory */
            Error_t MemPtrState = CreateMemoryPointer (&memptr,&fd) ;
                if(MemPtrState == FAILED)
                {
                    LOG_ERROR << "Can't access segment...";
                    //report_and_exit("Can't access segment...");  
                    cout<<"ERROR-> Can't access segment..."<<endl;
             return -1;                
                }
        }

   
    /* create a semaphore for mutual exclusion */
    Error_t SemState = CreateSem(&semptr);
    if(SemState == FAILED)
    {
        report_and_exit("sem_open");
        LOG_ERROR << "sem_open";
    } 

    /* use semaphore waiting for the writer to increment it */
    WaitSem(&semptr,&memptr);

    
    /* cleanup */
    munmap(memptr, ByteSize);
    close(fd);
    sem_close(semptr);
    unlink(BackingFile);
    return 0;
}
