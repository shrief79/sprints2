/** Compilation: g++ -o fh fh.c -lrt -lpthread **/
#include <iostream>
#include <fstream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <cstring>
#include <sys/epoll.h>
#include "../logger/simpleLogger.h"


#define BackingFile "/my_shared_memory_file"
#define AccessPerms 0644
#define ByteSize 1024
#define SemaphoreName "/my_semaphore"

void report_and_exit(const char* msg) {
  perror(msg);
  exit(-1);
}

int main() {
    int fd;
     void* memptr;
     sem_t* semptr;
    
    const char* file = "../fifoChannel";
     fd = open(file, O_RDONLY);
    if (fd < 0) return -1; /* no point in continuing */
    /*here we are parsing the string */
    char buffer[1024];
    /*read the pipe*/
    ssize_t count = read(fd, buffer, sizeof(buffer));
    /*parsing the first element of the buffer to know thae command is "r" or "l"*/
    int value=buffer[0]-'0';
    if (count >= sizeof(buffer)) {
    std ::cout<<count<<std::endl;
        std::cerr << "Error reading from the pipe." << std::endl;
         LOG_ERROR << "reading from the pipe.";
        close(fd);
        return -1;
    }
 	 std::string receivedMessage(buffer+1, count);

    close(fd); /* close pipe from read end */
    unlink(file); /* unlink from the underlying file */
    std::cout << "Received value: " << value << std::endl;

    /*shared memory*/
    fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
    if (fd < 0) {report_and_exit("Can't open shared mem segment...");
     LOG_ERROR << "Can't open shared mem segment...";}

    ftruncate(fd, ByteSize);

    memptr = mmap(NULL, ByteSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if ((void*) -1 == memptr) {report_and_exit("Can't get segment...");
	 LOG_ERROR << "Can't get segment...";}
    std::cerr << "shared mem address: " << memptr << " [0.." << ByteSize - 1 << "]" << std::endl;
    LOG_TRACE << "shared mem address:";
    std::cerr << "backing file:       /dev/shm" << BackingFile << std::endl;
    LOG_TRACE << "backing file:       /dev/shm";

     semptr = sem_open(SemaphoreName, O_CREAT, AccessPerms, 0);
    if (semptr == (void*) -1) report_and_exit("sem_open");
    

if (value == 0) {

    // Open the file for reading
    FILE* file = fopen(receivedMessage.c_str(), "r");
    if (file == nullptr) {
        report_and_exit("fopen");
    }

    // Read the content of the file
    size_t read_size = fread(memptr, 1, ByteSize, file);
    if (read_size > 0) {
        // Null-terminate the content if needed
        if (read_size < ByteSize) {
            static_cast<char*>(memptr)[read_size] = '\0';
        }
    }

    sleep(12);
    // Close the file and post the semaphore
    
    fclose(file);
    sem_post(semptr);
}
     else if (value == 1) {
        // Execute "ls" command and capture its output
        FILE* ls_output = popen(("ls "+receivedMessage).c_str(), "r");
        if (ls_output == nullptr) {report_and_exit("popen");
	LOG_DEBUG << "popen";}
        // Read the output and write to shared memory
        char buffer[ByteSize];
        size_t read_size = fread(buffer, sizeof(char), ByteSize, ls_output);
        if (read_size > 0) {
            strncpy(static_cast<char*>(memptr), buffer, ByteSize);
        }

        sleep(12);
        // Close the popen stream and the semaphore
        pclose(ls_output);
        sem_post(semptr);
    }

    // Cleanup
    munmap(memptr, ByteSize);
    close(fd);
    sem_close(semptr);
    shm_unlink(BackingFile);
    return 0;
}
