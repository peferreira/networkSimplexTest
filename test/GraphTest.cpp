#include "gtest/gtest.h"
#include "Graph.h"
class GraphTest: public ::testing::Test {

protected:


};


TEST_F(GraphTest, numberOfArcsIsCorret) {
	Graph G(4);
	ASSERT_EQ(0,G.numArc());
	G.insertA(1,3);
	G.insertA(2,0);
	ASSERT_EQ(2,G.numArc());
	G.removeA(2,0);
	ASSERT_EQ(1,G.numArc());
}

TEST_F(GraphTest, removeInsertAndExistArcs) {
	Graph G(4);
	ASSERT_FALSE(G.existArc(1,3));
	G.insertA(1,3);
	ASSERT_TRUE(G.existArc(1,3));
	G.removeA(1,3);
	ASSERT_FALSE(G.existArc(1,3));

}

TEST_F(GraphTest, doesNotInsertTwiceSameArc) {
	Graph G(4);
	G.insertA(1,3);
	G.insertA(1,3);
	G.insertA(1,3);
	ASSERT_EQ(1,G.numArc());
	G.removeA(1,3);
	ASSERT_EQ(0,G.numArc());
}

TEST_F(GraphTest, numArcsCorrectAfterRemoveArcThatDoesNotExist) {
	Graph G(4);
	G.insertA(1,3);
	G.removeA(1,4);
	ASSERT_EQ(1,G.numArc());
}
