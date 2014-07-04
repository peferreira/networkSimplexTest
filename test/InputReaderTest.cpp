#include "gtest/gtest.h"
#include "InputReader.h"
class InputReaderTest: public ::testing::Test {

protected:
	InputReader inputReader;

};


TEST_F(InputReaderTest, inputReaderOpenFile){
	ASSERT_EQ(1,inputReader.loadFile());
}
