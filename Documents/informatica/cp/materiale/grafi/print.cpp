#include <bits/stdc++.h>
using namespace std;

void printGraph(const vector<vector<int>>& graph) {
    cout << "Grafo:\n";
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (int child : graph[i]) {
            cout << child << " ";
        }
        cout << "\n";
    }
}