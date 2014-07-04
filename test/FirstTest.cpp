#include "gtest/gtest.h"
#include "MyClass.h"
class FirstTest: public ::testing::Test {

protected:
	MyClass m;

};


TEST_F(FirstTest, passingTest) {
	ASSERT_TRUE(true);
}

TEST_F(FirstTest, myClassReturnZero){
	ASSERT_EQ(0,m.getZero());
}
