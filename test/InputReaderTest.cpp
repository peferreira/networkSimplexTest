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
	ASSERT_EQ(14,G->numArc());
	//G->printMatrixADJ();
}

TEST_F(InputReaderTest, checkInputReadsCorrectArcs){
	Graph *G;
	G = new Graph();
	inputReader.loadFile(G);
	ASSERT_EQ(G->existArc(0,1)->getW(),1);
	ASSERT_EQ(G->existArc(1,2)->getW(),2);
	ASSERT_EQ(G->existArc(1,3)->getW(),3);
	ASSERT_EQ(G->existArc(1,4)->getW(),4);
	ASSERT_EQ(G->existArc(2,4)->getW(),4);
	ASSERT_EQ(G->existArc(3,1)->getW(),1);
	ASSERT_EQ(G->existArc(3,4)->getW(),4);
}

