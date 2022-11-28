#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    vector<list<int>> adj;  
public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    void BFS(int s, int d){
        vector<bool> visited;
        visited.resize(V,false);

        list<int> queue;
     
        visited[s] = true;
        queue.push_back(s);
     
        while(!queue.empty()){
            s = queue.front();
            cout << "(V" << s << ")\n";
            if (s == d) return;
            queue.pop_front();
            for (auto adjecent: adj[s]){
                if (!visited[adjecent]){
                    visited[adjecent] = true;
                    queue.push_back(adjecent);
                }
            }
        }
    }
};


 
int main()
{

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
    
    g.BFS(1, 20);
 
    return 0;
}
