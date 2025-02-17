#include <bits/stdc++.h>
using namespace std;

#define vec vector
#define pb push_back

vec<vec<int>> graph;
vec<bool> visited;

void dfs(int r) {
  // entro in un nodo
  // cout << u << endl;
  // segno visited
  visited[r] = true;
  // visito i nodi adiacenti
  for (auto v: graph[r]) {
    // controllo se e stato gia visitato
    if (visited[v] == false) {
      // chiamo la dfs su v
      dfs(v);
    }
  }
}

void dfs_esplicita(int r) {
  stack<int> s;
  s.push(r);
  visited[r] = true;

  while(!s.empty()) {
    auto u = s.top();
    s.pop();
    
    for (auto v: graph[u]) {
      if (visited[v] == false) {
        s.push(v);
        visited[v] = true;
      }
    }
  }
}

void dfs_esplicita_con_post_visita(int r) {
  // false -> pre visita, true -> post visita
  stack<pair<int, bool>> s;
  s.push({r, false});
  visited[r] = true;

  while(!s.empty()) {
    auto t = s.top();
    s.pop();
    auto u = t.first;
    auto vis = t.second;
    // pre visita
    if (vis == false) {
      s.push({u, true});
    }
    // post visita
    else {
      cout << u << endl;
    }
    
    for (auto v: graph[u]) {
      if (visited[v] == false) {
        s.push({v, false});
        visited[v] = true;
      }
    }
  }
}

void bfs(int r) {
  queue<int> q;
  q.push(r);
  visited[r] = true;

  while (q.empty() == false) {
    auto u = q.front();
    q.pop();

    cout << u << endl;

    for (auto v: graph[u]) {
      if (visited[v] == false) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
  int N = 5;
  graph.assign(N, vec<int>());
  
  graph[0].pb(3);
  graph[0].pb(2);
  graph[1].pb(4);
  graph[3].pb(2);
  graph[3].pb(4);

  visited.assign(N, false);
  // dfs(0);
  // dfs_esplicita(0);
  bfs(0);

  return 0;
}