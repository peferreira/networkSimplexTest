#include <gtest/gtest.h>
#include <Graph.h>
#include <InputReader.h>
#include <SimplexForNetworks.h>
class SimplexForNetworksTest: public ::testing::Test {

protected:
	InputReader inputReader;
	SimplexForNetworks simplex;
};

void ASSERT_VECTOR(int *a, int *b, int n) {
	int i;
	for (i = 0; i < n; i++) {
		ASSERT_EQ(a[i], b[i]);
	}
}

TEST_F(SimplexForNetworksTest, initialTreeIsCorrect) {
	Graph *G;
	Graph T;
	G = new Graph();
	inputReader.loadFile(G);
	G->graphDFS();
	G->printMatrixADJ();

	T = simplex.addArtificialArcs(*G);

	assert(T.existArc(0, 1) != T.getEnd(0));
	assert(T.existArc(0, 2) != T.getEnd(0));
	assert(T.existArc(0, 3) != T.getEnd(0));
	assert(T.existArc(0, 4) != T.getEnd(0));
}

TEST_F(SimplexForNetworksTest, artificialArcsAreCorrect) {
	Graph *G;
	Graph T;
	G = new Graph();
	inputReader.loadFile(G);
	G->graphDFS();
	G->printMatrixADJ();

	T = simplex.addArtificialArcs(*G);
	ASSERT_TRUE((T.existArc(0, 2))->isArtificial());
	ASSERT_TRUE((T.existArc(0, 4))->isArtificial());
	ASSERT_FALSE((T.existArc(0, 1))->isArtificial());
	ASSERT_FALSE((T.existArc(0, 3))->isArtificial());
}

TEST_F(SimplexForNetworksTest, parentAndAlturaAreCorrect) {
	Graph *G;
	Graph T;
	int i;
	G = new Graph();
	int r[] = { 0, 0, 0, 0, 0 };
	int a[] = { 0, 1, 1, 1, 1 };
	inputReader.loadFile(G);
	G->graphDFS();

	T = simplex.addArtificialArcs(*G);
	ASSERT_VECTOR(r,T.getParent(),T.getNumV());
	ASSERT_VECTOR(a,T.getAlturaArray(),T.getNumV());

}


