// algoritmo Kruskal per minimum spanning tree

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<array<ll, 2>>> graph;

vector<ll> A;

ll Find(ll x){
    if(A[x] == x) return x;
    ll p = Find(A[x]);
    A[x] = p;
    return p;
}

void Union(ll x, ll y){
    ll cx = Find(x);
    ll cy = Find(y);
    A[cx] = cy;
}

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    // N nodi e M archi
    ll N, M;
    cin >> N >> M;

    graph.assign(N, vector<array<ll,2>>());

    ll u, v, w;
    for(ll i = 0; i < M; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // IMPLEMENTAZIONE

    // init A
    for(ll i = 0; i < N; i++){
        A.push_back(i);
    }
    // init lista archi
    vector<array<ll,3>> edges; // peso, sorgente, arrivo
    for(ll u = 0; u < N; u++){
        for(auto [v, w] : graph[u]){
            edges.push_back({w, u, v});
        }
    }

    // algoritmo
    sort(edges.begin(), edges.end());
    ll peso_totale = 0;
    vector<array<ll, 2>> ans;
    for(auto [w, u, v] : edges){
        if(Find(u) != Find(v)){
            ans.push_back({u, v}); // output
            peso_totale += w;// output
            Union(u, v);
        }
    }
    
    // output
    cout << peso_totale << endl;
    for(auto [u, v] : ans) cout << u <<" " << v <<endl;

    return 0;
}