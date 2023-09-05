#include <gtest/gtest.h>
#include "../file_handler/fh.hpp"

// Test ls_command with a successful scenario
TEST(CommandsTest, LSCommandSuccess)
{

    int fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
     void *memptr = mmap(NULL, ByteSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    
    std::string message = "/home/shrief/Desktop/main";
    Error_t result = ls_command(message, memptr);
    EXPECT_EQ(result, SUCCESS);

   
}

// Test ls_command with a failure scenario (popen fails)
TEST(CommandsTest, LSCommandFailurePopen)
{
    int fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
     void *memptr = mmap(NULL, ByteSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    std::string message = "/home/shrief/Desktop/mai";
    Error_t result = ls_command("invalid_command", memptr);
    EXPECT_EQ(result, FAILED);

}

// Test read_command with a successful scenario
TEST(CommandsTest, ReadCommandSuccess)
{
    int fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
     void *memptr = mmap(NULL, ByteSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    std::string message = "/home/shrief/Desktop/main/test.txt"; 
    Error_t result = read_command(message, memptr);
    EXPECT_EQ(result, SUCCESS);

}

// Test read_command with a failure scenario (fopen fails)
TEST(CommandsTest, ReadCommandFailureFopen)
{
     int fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
     void *memptr = mmap(NULL, ByteSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    std::string message = "/home/shrief/Desktop/main/tt.txt"; 
    Error_t result = read_command(message, memptr);
    EXPECT_EQ(result, FAILED);
  
}

// Test read_command with a failure scenario (stat fails)
TEST(CommandsTest, ReadCommandFailureStat)
{
    int fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
     void *memptr = mmap(NULL, ByteSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    std::string message = "/home/shrief/Desktop/main/tt.txt"; 
    Error_t result = read_command(message, memptr);
    EXPECT_EQ(result, FAILED);
    
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}