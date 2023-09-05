#include <gtest/gtest.h>
#include "../request/request.h" 

 
//makeing  test for the function CheckArg by several ways !
TEST(CheckArgTest1, CountNotEqualTo3) {
    int argc = 4;
    
    Error_t result = CheckArg(argc);
    
    EXPECT_EQ(result, FAILED);
}

TEST(CheckArgTest2, CountEqualTo3) {
    int argc = 3;
    
    
    Error_t result = CheckArg(argc);
    
    EXPECT_EQ(result, SUCCESS);
}

TEST(CheckArgTest3, CountNotEqualTo3) {
    int argc = 2;
    
    
    Error_t result = CheckArg(argc);
    
    EXPECT_EQ(result, FAILED);
}

//makeing  test for the function ReadOrder
TEST(ReadOrder, ReadOrderTypeR) {
    string order;
    char orderType[] = "-r";
    
    Error_t result = ReadOrder(&order, orderType);
    
    EXPECT_EQ(result, READ_FILE);
    EXPECT_EQ(order, "0");
}


int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
