#include <iostream>
using namespace std;
using ll = long long;

ll fast_exp(ll base, ll exp, ll mod){
    ll ans = 1;

    base %= mod;

    if(!base) return 0;
    while(exp > 0){
        if(exp & 1){ // se dispari (ultima cifra del binario)
            ans *= base;
            ans %= mod;
        }
        exp = exp >> 1; // shift (binario(guardalo))
        base = base*base % mod;
    }
    return ans;
}
