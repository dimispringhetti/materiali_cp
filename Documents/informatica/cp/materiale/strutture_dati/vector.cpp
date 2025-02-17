#include <bits/stdc++.h>
using namespace std;

int main() {
  // vettore vuoto
  vector<int> vettore;
  // vettore di 5 elementi inizializzati a 10
  vector<int> v2(5, 10);
  // clone di v2
  vector<int> v3(v2.begin(), v2.end());
  // vettore di 5 elementi
  vector<int> v4{1, 2, 3, 4, 5};

  // accesso agli elementi
  cout << v4[1] << endl;
  cout << v4.at(2) << endl;
  cout << v4.front() << endl;
  cout << v4.back() << endl;

  // info sul vettore
  cout << v4.size() << endl;
  cout << v4.capacity() << endl;
  cout << v4.max_size() << endl;

  // inserimento in coda
  vettore.push_back(6);
  // inserimento in testa
  vettore.insert(vettore.begin(), 0);
  // inserimento in posizione arbitraria
  vettore.insert(vettore.begin() + 3, 100);

  // for con iteratori
  for (auto it = vettore.begin(); it != vettore.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // rimozione in coda
  vettore.pop_back();
  // rimozione in testa
  vettore.erase(vettore.begin());
  // rimozione in posizione arbitraria
  vettore.erase(vettore.begin() + 1);
  // rimozione di tutti gli elementi
  vettore.clear();

  // for automatico
  for (auto it : vettore) {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}