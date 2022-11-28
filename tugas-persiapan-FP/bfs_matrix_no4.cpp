#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
   private:
  bool** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void toString() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  ~Graph() {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
  
  void bfs(int s, int d) {
        vector<bool> visited(numVertices, false);
        vector<int> q;
        q.push_back(s);
        
        visited[s] = true;
        
        while (!q.empty()) {
            s = q[0];
            cout << "(V" << s << ")\n";
            if(s == d) return;
            q.erase(q.begin());
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[s][i] == 1 && (!visited[i])) {
                    q.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }
  
};


int main() {
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

  g.bfs(1, 20);
}
