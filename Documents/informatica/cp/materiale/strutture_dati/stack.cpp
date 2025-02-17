#include <bits/stdc++.h>
using namespace std;

int main() {
  stack<int> pila;
  pila.push(1);
  pila.push(2);

  while (!pila.empty()) {
    cout << pila.top() << endl;
    pila.pop();
  }
  return 0;
}