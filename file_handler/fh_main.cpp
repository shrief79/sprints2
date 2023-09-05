#include "fh.hpp"

int main()
{
    int fd;
    void *memptr;
    sem_t *semptr;
    int value;
    ssize_t count;
    const char *file;


    while (1)
    {
        /*Named pipe*/
        char buffer[1024];
        file = "../request/fifoChannel";
        fd = open(file, O_RDONLY);
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(fd, &readSet);

        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        int ready = select(fd + 1, &readSet, NULL, NULL, &timeout);

        if (ready > 0 && FD_ISSET(fd, &readSet))
        {
        	// Read data from the named pipe
            count = read(fd, buffer, sizeof(buffer));
            value = buffer[0] - '0';
            if (count > 0)
            {
                if (count >= sizeof(buffer))
                {
                    std ::cout << count << std::endl;
                    std::cerr << "Error reading from the pipe." << std::endl;
                    LOG_ERROR << "Error reading from the pipe.";
                    close(fd);
                    return -1;
                }
                else
                {
                    std::string receivedMessage(buffer + 1, count);

                    if (value == 0)
                    {
                        std::cout << "read request from the requester" << std::endl;
                    }
                    else
                    {
                        std::cout << "list request from the requester" << std::endl;
                    }
                    std::cout << "Received value: " << value << std::endl;

                    /* Shared memory */

                    // Create or open the shared memory segment

                    fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
                    if (fd < 0)
                    {
                        report_and_exit("Can't open shared mem segment...");
                        LOG_ERROR << "Can't open shared mem segment...";
                    }
		    // Set the size of the shared memory segment
                    ftruncate(fd, ByteSize);

                    memptr = mmap(NULL, ByteSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
                    if ((void *)-1 == memptr)
                    {
                        report_and_exit("Can't get segment...");
                        LOG_ERROR << "Can't get segment...";
                    }
                    std::cerr << "shared mem address: " << memptr << " [0.." << ByteSize - 1 << "]" << std::endl;
                    LOG_TRACE << "shared mem address:";
                    std::cerr << "backing file:       /dev/shm" << BackingFile << std::endl;
                    LOG_TRACE << "backing file:       /dev/shm";
		    
		    // Open or create a semaphore
                    semptr = sem_open(SemaphoreName, O_CREAT, AccessPerms, 0);
                    if (semptr == (void *)-1)
                        report_and_exit("sem_open");

                    if (value == 0)
                    {
                      // Handle read command
                      Error_t state=read_command(receivedMessage, memptr);
                        sem_post(semptr);// Release the semaphore
                    }
                    else if (value == 1)
                    {
                      // Handle list command
                      Error_t state =ls_command(receivedMessage, memptr);
                        sem_post(semptr);// Release the semaphore
                    }
                   
                }
            }

        }
        
    }
    return 0;
}
