#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int N = n + m - 1;

    vector<ll> fact(N + 1), invfact(N + 1);

    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i > 0; i--)
        invfact[i - 1] = invfact[i] * i % MOD;

    ll ans = fact[n + m - 1];
    ans = ans * invfact[m] % MOD;
    ans = ans * invfact[n - 1] % MOD;

    cout << ans << '\n';

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/