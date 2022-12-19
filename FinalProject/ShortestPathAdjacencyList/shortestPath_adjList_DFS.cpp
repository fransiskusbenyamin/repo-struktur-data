#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
        int v;
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
    public:
        Graph(int v) {
            this->v = v;
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }
        void addEdge(int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
        }

        void findShortestPathDFS(int start, int end){
        	int awal = start;
        	int akhir = end;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );
            cout<<"Jalur terpendek dari " << awal << " ke " << akhir << " adalah: ";  
            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i];
                if(i+1 < dfsResult.size())
                	cout << " -> ";
            }

            cout << endl << "Dengan total bobot = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
            }
            
            visited[start] = true;
            path.push_back(start);
            list<int>::iterator it;
            for ( it = adj[start].begin(); it != adj[start].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
        }

};

int main(){
    Graph g(21);
    
    g.addEdge(1, 0, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 8, 6);
    g.addEdge(3, 6, 5);
    g.addEdge(3, 7, 8);
    g.addEdge(4, 2, 5);
    g.addEdge(4, 5, 5);
    g.addEdge(4, 8, 3);
    g.addEdge(5, 7, 7);
    g.addEdge(5, 11, 6);
    g.addEdge(6, 8, 1);
    g.addEdge(7, 9, 11);
    g.addEdge(8, 12, 2);
    g.addEdge(9, 3, 5);
    g.addEdge(10, 4, 4);
    g.addEdge(10, 5, 5);
    g.addEdge(11, 7, 6);
    g.addEdge(12, 13, 2);
    g.addEdge(12, 14, 7);
    g.addEdge(13, 10, 3);
    g.addEdge(13, 14, 5);
    g.addEdge(14, 15, 2);
    g.addEdge(15, 16, 4);
    g.addEdge(15, 17, 5);
    g.addEdge(17, 18, 4);
    g.addEdge(18, 6, 13);
    g.addEdge(19, 10, 7);
    g.addEdge(20, 19, 5);

    g.findShortestPathDFS(12, 0);

    return 0;    
}
