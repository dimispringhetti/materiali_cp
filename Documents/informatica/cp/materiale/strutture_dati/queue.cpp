#include <bits/stdc++.h>
using namespace std;

int main() {
  queue<int> coda;

  coda.push(1);
  coda.push(2);

  while (!coda.empty()) {
    int x = coda.front();
    cout << x << endl;
    coda.pop();
  }
  
  return 0;
}