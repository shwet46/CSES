#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll fact[MAXN], invfact[MAXN];

ll modpow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[MAXN-1] = modpow(fact[MAXN-1], MOD-2);
    for (int i = MAXN-2; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % MOD;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    ll ans = fact[n];
    for (int f : freq) {
        if (f > 0) ans = ans * invfact[f] % MOD;
    }

    cout << ans << "\n";
    return 0;
}

/*  
          /\_/\        
         (='.'=)    
         (")_(")    
*/