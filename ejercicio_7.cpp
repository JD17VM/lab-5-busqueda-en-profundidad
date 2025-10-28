#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef int vertex;

struct Graph {
    int V;
    vector<vector<vertex>> adj;

    Graph(int V) : V(V), adj(V) {}
};

static int cnt;
vector<int> pre;


static void dfsR_iterative(Graph* G, vertex v) {
    stack<vertex> s;
    s.push(v);

    while (!s.empty()) {
        vertex curr = s.top();
        s.pop();

        if (pre[curr] != -1) {
            continue;
        }

        pre[curr] = cnt++;

        vector<vertex> neighbors = G->adj[curr];
        reverse(neighbors.begin(), neighbors.end());

        for (vertex w : neighbors) {
            if (pre[w] == -1) {
                s.push(w);
            }
        }
    }
}

void GRAPHdfs_iterative(Graph* G) {
    cnt = 0;
    pre.assign(G->V, -1);
 
    for (vertex v = 0; v < G->V; ++v) {
        if (pre[v] == -1) {
            dfsR_iterative(G, v);
        }
    }
}

int main() {

    int V = 6;
    Graph* G = new Graph(V);
    G->adj[0] = {1};
    G->adj[1] = {2, 3};
    G->adj[2] = {4, 5};
    
    cout << "Grafo del Ejemplo A creado." << endl;
    cout << "Arcos: 0-1, 1-2, 1-3, 2-4, 2-5" << endl;

    GRAPHdfs_iterative(G);

    cout << "\nVector pre[] final (version iterativa):" << endl;
    cout << "w \t|";
    for (int i = 0; i < G->V; ++i) cout << i << " ";
    cout << endl;
    cout << "pre[w] |";
    for (int i = 0; i < G->V; ++i) cout << pre[i] << " ";
    cout << endl;

    cout << "\nResultado esperado:" << endl;
    cout << "w  |0 1 2 3 4 5 " << endl;
    cout << "pre[w] |0 1 2 5 3 4 " << endl;

    delete G;

    return 0;
}