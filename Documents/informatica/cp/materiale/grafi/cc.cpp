#include <bits/stdc++.h>
using namespace std;

#define vec vector
#define pb push_back

int N, M;
vec<vec<int>> graph;
vec<int> ids;

void cc_dfs(int u, int counter) {
  ids[u] = counter;
  for (auto v: graph[u]) {
    if (ids[v] == -1) {
      cc_dfs(v, counter);
    }
  }
}

int cc() {
  int counter = 0;
  for (int i = 0; i < N; i++) {
    if (ids[i] == -1) {
      counter++;
      cc_dfs(i, counter);
    }
  }
  return counter;
}

int main() {  
  cin >> N >> M;
  graph.assign(N, vec<int>());
  ids.assign(N, -1);
  
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    graph[a].pb(b);
    graph[b].pb(a);
  }

  cout << cc() << endl;

  return 0;
}