#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

typedef int vertex;

struct Graph {
    int V; 
    vector<vector<vertex>> adj; // Listas de adyacencia
    Graph(int V) : V(V), adj(V) {}
};

static int cnt;
vector<int> pre;

static string indent;

static void dfsR(Graph* G, vertex v) {
    pre[v] = cnt++;
    
    cout << indent << v << " dfsR(G, " << v << ")" << endl;

    indent += "  ";

    for (vertex w : G->adj[v]) {

        cout << indent << v << "-" << w;
        if (pre[w] == -1) {
            cout << " dfsR(G, " << w << ")" << endl;
            dfsR(G, w);
        } else {
            cout << endl;
        }
    }
    
    indent = indent.substr(0, indent.length() - 2);
    cout << indent << v << endl;
}


void GRAPHdfs(Graph* G) {
    cnt = 0;
    pre.assign(G->V, -1);
    indent = "";

    for (vertex v = 0; v < G->V; ++v) {
        if (pre[v] == -1) { 
            dfsR(G, v);
        }
    }
}


Graph* loadGraph(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return nullptr;
    }

    int V;
    string line;
    getline(file, line);
    stringstream ss_v(line);
    ss_v >> V;
    
    if (V <= 0) {
        cerr << "Error: Número de vértices V debe ser > 0." << endl;
        return nullptr;
    }

    Graph* G = new Graph(V);

    while (getline(file, line)) {
        stringstream ss_line(line);
        vertex v;
        ss_line >> v; 

        if (v < 0 || v >= V) continue;

        vertex w;

        while (ss_line >> w) {
            if (w >= 0 && w < V) {
                G->adj[v].push_back(w);
            }
        }
    }

    file.close();
    return G;
}


int main() {
    
    const string filename = "grafo_ejemplo.txt";

    Graph* G = loadGraph(filename);

    if (G) {
        cout << "\n --- Rastreo ---" << endl;
        GRAPHdfs(G);
        cout << "--- Fin del Rastreo ---" << endl;

        cout << "\nVector pre[] final:" << endl;
        cout << "w \t|";
        for (int i = 0; i < G->V; ++i) cout << i << "\t";
        cout << endl;
        cout << "pre[w]\t|";
        for (int i = 0; i < G->V; ++i) cout << pre[i] << "\t";
        cout << endl;

        delete G;
    }

    return 0;
}