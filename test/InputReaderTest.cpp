#include "gtest/gtest.h"
#include "InputReader.h"
#include "Graph.h"

class InputReaderTest: public ::testing::Test {

protected:
	InputReader inputReader;

};


TEST_F(InputReaderTest, inputReaderOpenFile){
	Graph *G;
	G = new Graph();
	ASSERT_EQ(1,inputReader.loadFile(G));
}

TEST_F(InputReaderTest, checkInputReadsCorrectNumArcs){
	Graph *G;
	G = new Graph();
	inputReader.loadFile(G);
	ASSERT_EQ(8,G->numArc());
}

TEST_F(InputReaderTest, checkInputReadsCorrectArcs){
	Graph *G;
	G = new Graph();
	inputReader.loadFile(G);
	ASSERT_TRUE(G->existArc(0,1));
	ASSERT_TRUE(G->existArc(0,3));
	ASSERT_TRUE(G->existArc(1,2));
	ASSERT_TRUE(G->existArc(1,3));
	ASSERT_TRUE(G->existArc(1,4));
	ASSERT_TRUE(G->existArc(2,4));
	ASSERT_TRUE(G->existArc(3,1));
	ASSERT_TRUE(G->existArc(3,4));
}
