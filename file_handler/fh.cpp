#include "fh.hpp"


void report_and_exit(const char *msg)
{
    perror(msg);
    exit(-1);
}

Error_t ls_command(std::string message, void *memptr)
{
    /* Execute "ls" command and capture its output */
    FILE *ls_output = popen(("ls " + message).c_str(), "r");
    if (ls_output == nullptr)
    {

        report_and_exit("popen");
        LOG_DEBUG << "popen";
        return FAILED ;
    }

    /* Read the output and write to shared memory */
    char buffer[ByteSize];
    size_t read_size = fread(buffer, sizeof(char), ByteSize, ls_output);
    if (read_size > 0)
    {
        std::cout << "size returned from list command = " << read_size << std::endl;
        strncpy(static_cast<char *>(memptr), buffer, ByteSize);
        
    }
    else 
    {
        std::cout<<"read_size not > 0 "<<std::endl;
        return FAILED ;
    }
    /* Close the popen stream and the semaphore */
    pclose(ls_output);
    return SUCCESS ;
}

Error_t read_command(std::string message, void *memptr)
{
    struct stat fileStat;
    if (stat(message.c_str(), &fileStat) != 0)
    { 
        std::cout << "Failed to get the file size." << std::endl;
        return FAILED ;
    }
    std::cout << "File size: " << fileStat.st_size << " bytes." << std::endl;

    /* Open the file for reading */
    FILE *file = fopen(message.c_str(), "r");
    if (file == nullptr)
    {
        report_and_exit("fopen");
        LOG_DEBUG << "fopen";
        return FAILED ;
    }

    /* Read the content of the file */
    size_t read_size = fread(memptr, 1,  fileStat.st_size , file);
    if (read_size > 0)
    {
        // Null-terminate the content if needed
            std::cout << "size returned from read command = " << read_size << std::endl;
            static_cast<char *>(memptr)[read_size] = '\0';
    }
    else 
    {
         std::cout<<"read_size not > 0 "<<std::endl;
        return FAILED ;
    }

    /* Close the file and post the semaphore */
    fclose(file);
    return SUCCESS ;
}
