#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll pow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % mod;
    ll x = pow(a, b/2);
    if(b % 2 == 0){
        return (x * x) % mod;
    } else {
        return (((x * x) % mod) * a) % mod;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << pow(a,b) << "\n";
    }
 
    return 0;
}