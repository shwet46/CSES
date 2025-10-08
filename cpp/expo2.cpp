#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll power(ll base, ll exp, ll modulus) {
    ll res = 1;
    base %= modulus;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % modulus;
        base = (base * base) % modulus;
        exp /= 2;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        ll exp = power(b, c, MOD - 1);
        
        ll ans = power(a, exp, MOD);
        
        cout << ans << "\n";
    }
 
    return 0;
}