#include <gtest/gtest.h>
#include <Graph.h>

class GraphTest: public ::testing::Test {

protected:

};

TEST_F(GraphTest, numberOfArcsIsCorret) {
	Graph G;
	G.init(4,0,3,10);
	ASSERT_EQ(0, G.numArc());
	G.insertArc(false,1, 3,1);
	G.insertArc(false,2, 0,1);
	ASSERT_EQ(4, G.numArc());
	G.removeArc(2, 0);
	ASSERT_EQ(2, G.numArc());
}

TEST_F(GraphTest, removeInsertAndExistArcs) {
	Graph G;
	G.init(4,0,3,10);
	assert(G.existArc(1, 3) == G.getEnd(1));
	G.insertArc(false,1, 3,1);
	assert(G.existArc(1, 3) != G.getEnd(1));
	G.removeArc(1, 3);
	assert(G.existArc(1, 3) == G.getEnd(1));

}

TEST_F(GraphTest, doesNotInsertTwiceSameArc) {
	Graph G;
	G.init(4,0,3,10);
	G.insertArc(false,1, 3,1);
	G.insertArc(false,1, 3,1);
	G.insertArc(false,1, 3,1);
	ASSERT_EQ(2, G.numArc());
	G.removeArc(1, 3);
	ASSERT_EQ(0, G.numArc());
}

TEST_F(GraphTest, numArcsCorrectAfterRemoveArcThatDoesNotExist) {
	Graph G;
	G.init(4,0,3,10);
	G.insertArc(false, 1, 2, 1);
	G.removeArc(1, 3);
	ASSERT_EQ(2, G.numArc());
}

TEST_F(GraphTest, testParentAlturaArrays) {
	int i;
	int V;
	int *t;
	Graph G;
	int r[] = { 0, 0, 1, 1, 0, 4, 4, 2 };
	int a[] = { 0, 1, 2, 2, 1, 2, 2, 3 };

	i = 0;
	V = 8;
	bool fake = false;
	int p = 5;
	G.init(V,0,3,10);
	G.insertArc(fake, 0, 1, p);
	G.insertArc(fake, 1, 3, p);
	G.insertArc(fake, 1, 2, p);
	G.insertArc(fake, 2, 7, p);
	G.insertArc(fake, 0, 4, p);
	G.insertArc(fake, 4, 6, p);
	G.insertArc(fake, 4, 5, p);

	G.graphDFS();
	t = G.getParent();
	for (i = 0; i < V; i++) {
		ASSERT_EQ(r[i], t[i]);
		ASSERT_EQ(a[i], G.getAltura(i));
	}
}
