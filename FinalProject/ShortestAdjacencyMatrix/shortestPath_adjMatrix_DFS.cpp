#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;

void addEdge(int x, int y){
	adj[x][y] = 1;
}

void dfs(int start, vector<bool>& visited){

	cout << start << " ";
	visited[start] = true;

	for (int i = 0; i < adj[start].size(); i++) {

		if (adj[start][i] == 1 && (!visited[i])) {
			dfs(i, visited);
		}
	}
}

int main(){
	int v = 21;
	int e = 30;

	adj = vector<vector<int> >(v, vector<int>(v, 0));

    addEdge(1, 0);
    addEdge(1, 3);
    addEdge(2, 1);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(3, 6);
    addEdge(3, 7);
    addEdge(4, 2);
    addEdge(4, 5);
    addEdge(4, 8);
    addEdge(5, 7);
    addEdge(5, 11);
    addEdge(6, 8);
    addEdge(7, 9);
    addEdge(8, 12);
    addEdge(9, 3);
    addEdge(10, 4);
    addEdge(10, 5);
    addEdge(11, 7);
    addEdge(12, 13);
    addEdge(12, 14);
    addEdge(13, 10);
    addEdge(13, 14);
    addEdge(14, 15);
    addEdge(15, 16);
    addEdge(15, 17);
    addEdge(17, 18);
    addEdge(18, 6);
    addEdge(19, 10);
    addEdge(20, 19);

	vector<bool> visited(v, false);

	dfs(12, visited);
}

