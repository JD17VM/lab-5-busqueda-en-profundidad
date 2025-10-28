#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1000;
vector<int> adj[MAXV];
int pre[MAXV];
int cnt = 0;
int indent = 0; 
void printIndent() {
    for(int i = 0; i < indent; i++) cout << "  ";
}

void dfsR(int v) {
    printIndent();
    cout << v << " dfsR(G," << v << ")" << endl;
    pre[v] = cnt++;
    indent++;
    for (int w : adj[v]) {
        printIndent();
        cout << v << "-" << w;
        if (pre[w] == -1) {
            cout << " dfsR(G," << w << ")" << endl;
            dfsR(w);
        } else {
            cout << endl;
        }
    }

    indent--;
    printIndent();
    cout << v << endl;
}

void GRAPHdfs(int V) {
    cnt = 0;
    for(int i = 0; i < V; i++) pre[i] = -1;

    for(int v = 0; v < V; v++) {
        if (pre[v] == -1) {
            dfsR(v);
        }
    }
}

int main() {
    int V = 10; 
    vector<pair<int,int>> edges = {
        {3,7}, {1,4}, {7,8}, {0,5}, {5,2},
        {3,8}, {2,9}, {0,6}, {4,9}, {2,6}, {6,4}
    };

    for (auto &e : edges) {
        int u = e.first;
        int v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    for (int i = 0; i < V; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    GRAPHdfs(V);

    cout << "\nTabla final del vector pre[]:\n";
    cout << "v:   ";
    for (int i = 0; i < V; i++) cout << i << " ";
    cout << "\npre: ";
    for (int i = 0; i < V; i++) cout << pre[i] << " ";
    cout << endl;
    return 0;
}
