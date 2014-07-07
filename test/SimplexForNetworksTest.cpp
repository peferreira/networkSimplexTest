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
	ASSERT_VECTOR(r, T.getParent(), T.getNumV());
	ASSERT_VECTOR(a, T.getAlturaArray(), T.getNumV());

}

TEST_F(SimplexForNetworksTest, checkIfFeaseableSolution) {
	Graph *G;
	Graph T;
	list<Arc>::iterator it;
	int i;
	int b, bexpected;
	b = bexpected = 0;
	G = new Graph();

	inputReader.loadFile(G);
	G->graphDFS();
	T = simplex.addArtificialArcs(*G);
	for (i = 0; i < T.getNumV(); i++) {
		if (i == T.getInitialVertex()) {
			bexpected = -1 * T.getProdEscoado();
		} else if (i == T.getFinishVertex()) {
			bexpected = T.getProdEscoado();
		} else
			bexpected = 0;
		b=0;
		for (it = T.getBegin(i); it != T.getEnd(i); it++) {
			if (!(it->isFake())) {
				/*cout << "v:" << it->getV() << " w:" << it->getW()
						<< " Arc Fake:" << it->isFake() << " Arc Artificial:"
						<< it->isArtificial() << '\n';*/
				b = b - it->getValue();
			} else
				b = b + it->getValue();

		}
		ASSERT_EQ(b ,bexpected);

	}
}

TEST_F(SimplexForNetworksTest, findCorrectJoin) {
	Graph *G;
	Graph T;
	G = new Graph();
	inputReader.loadFile(G);
	G->graphDFS();

	T = simplex.addArtificialArcs(*G);
	ASSERT_EQ(1,simplex.findCycle(1,4,*G));
	ASSERT_EQ(1,simplex.findCycle(4,1,*G));
	ASSERT_EQ(1,simplex.findCycle(1,1,*G));
	ASSERT_EQ(4,simplex.findCycle(3,4,*G));
	ASSERT_EQ(4,simplex.findCycle(4,3,*G));



	ASSERT_EQ(0,simplex.findCycle(4,3,T));
	ASSERT_EQ(0,simplex.findCycle(2,1,T));
	ASSERT_EQ(0,simplex.findCycle(1,3,T));
}

TEST_F(SimplexForNetworksTest, testFindingJoinTree2) {
	int i;
	int V;
	int *t;
	Graph G;
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
	ASSERT_EQ(1,simplex.findCycle(7,3,G));
	ASSERT_EQ(4,simplex.findCycle(5,6,G));
	ASSERT_EQ(0,simplex.findCycle(6,7,G));
	ASSERT_EQ(0,simplex.findCycle(7,6,G));
	ASSERT_EQ(4,simplex.findCycle(4,4,G));
}


