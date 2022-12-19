#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;


void addEdge(int x,int y){
	adj[x][y] = 1;
}

void bfs(int start){
	vector<bool> visited(adj.size(), false);
	vector<int> q;
	q.push_back(start);

	visited[start] = true;

	int vis;
	while (!q.empty()) {
		vis = q[0];

		cout << vis << " ";
		q.erase(q.begin());

		for (int i = 0; i < adj[vis].size(); i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {

				q.push_back(i);

				visited[i] = true;
			}
		}
	}
}

int main(){
	int v = 21;

	adj= vector<vector<int>>(v,vector<int>(v,0));

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
	
	bfs(12);
}

