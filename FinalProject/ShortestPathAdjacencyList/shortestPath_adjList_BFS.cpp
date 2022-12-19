#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V; 
    vector<int> *adj;
    Graph(int V){
        this->V = V;
        this->adj = new vector<int>[V];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    void BFS(int src, int dest, vector<int> &dist, vector<int> &parent){
        vector<bool> vis(V, 0);
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int q_size = q.size();
            while(q_size--){
                int node = q.front();
                q.pop();
                vis[node] = 1;
                for(int adjNode : this->adj[node]){
                    if(!vis[adjNode]){
                        vis[adjNode] = 1; 
                        dist[adjNode] = dist[node] + 1;
                        parent[adjNode] = node;
                        q.push(adjNode);
                    }
                }
            }
        }
    }
    void findShortestPath(int src, int dest){
        vector<int> dist(V, 0);
        vector<int> parent(V);
        int awal = src;
        int akhir = dest;
        for(int i=0;i<V;++i){
           parent[i] = i;
        }
        BFS(src, dest, dist, parent);
        stack<int> st;
        while(parent[dest]!=dest){
            st.push(dest);
            dest = parent[dest];
        }
        st.push(dest);
        int Path_length = st.size();
        cout<<"Jalur terpendek dari " << awal << " ke " << akhir << " adalah: ";  
        while(st.size()>1){
            cout<<st.top()<<" -> ";
            st.pop();
        }
        cout<<st.top()<<"\n";
        cout<<"Dengan bobot(banyak langkah) = "<<Path_length-1;
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
    
	g.findShortestPath(12, 0);
	return 0;
}
