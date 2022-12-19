#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class Graph{
    int V;
    list< pair<int, int> > *adj;
 
public:
	
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s, int W);
};
 
Graph::Graph(int V){
    this->V = V;
    adj = new list< pair<int, int> >[V];
}
 
void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
}
 

void Graph::shortestPath(int src, int W){

    vector<pair<int, list<int>::iterator> > dist(V);
 
    for (int i = 0; i < V; i++)
        dist[i].first = INF;

    list<int> B[W * V + 1];
 
    B[0].push_back(src);
    dist[src].first = 0;
 
    int idx = 0;
    while (1){

        while (B[idx].size() == 0 && idx < W*V)
            idx++;
 
        if (idx == W * V)
            break;
 
        int u = B[idx].front();
        B[idx].pop_front();

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i){
            int v = (*i).first;
            int weight = (*i).second;
 
            int du = dist[u].first;
            int dv = dist[v].first;
 
            if (dv > du + weight){

                if (dv != INF)
                    B[dv].erase(dist[v].second);
 
                dist[v].first = du + weight;
                dv = dist[v].first;
 
                B[dv].push_front(v);
 
                dist[v].second = B[dv].begin();
            }
        }
    }
 
    cout << "Node\tBobot dari Node " << src << "\n";
    for (int i = 0; i < V; ++i){
    	if(dist[i].first > 1000){
    		dist[i].first = 0;
		}
        cout << i << "\t"<< dist[i].first<< "\n";
    }
}
 
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
 
    g.shortestPath(12, 13);
    cout << "\nJika value = 0 maka path tidak memungkinkan";
    
    return 0;
}
