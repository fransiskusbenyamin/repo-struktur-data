#include <iostream>
using namespace std;

class Graph {
   private:
  bool** adjMatrix;
  int V;

   public:
  Graph(int V) {
    this->V = V;
    adjMatrix = new bool*[V];
    for (int i = 0; i < V; i++) {
      adjMatrix[i] = new bool[V];
      for (int j = 0; j < V; j++)
        adjMatrix[i][j] = false;
    }
  }

  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
  }

  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
  }

  void toString() {
    for (int i = 0; i < V; i++) {
      cout << i << "\t: ";
      for (int j = 0; j < V; j++)
        cout << adjMatrix[i][j] << "  ";
      cout << "\n";
    }
  }

};

int main() {
	
	cout << "    ke->  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 \n \n";
    Graph g(21);
    g.addEdge(1, 0);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 8);
    g.addEdge(3, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.addEdge(4, 8);
    g.addEdge(5, 7);
    g.addEdge(5, 11);
    g.addEdge(6, 8);
    g.addEdge(7, 9);
    g.addEdge(8, 12);
    g.addEdge(9, 3);
    g.addEdge(10, 4);
    g.addEdge(10, 5);
    g.addEdge(11, 7);
    g.addEdge(12, 13);
    g.addEdge(12, 14);
    g.addEdge(13, 10);
    g.addEdge(13, 14);
    g.addEdge(14, 15);
    g.addEdge(15, 16);
    g.addEdge(15, 17);
    g.addEdge(17, 18);
    g.addEdge(18, 6);
    g.addEdge(19, 10);
	g.addEdge(20, 19);
	
	g.toString();
	cout << "^ dari";
}
