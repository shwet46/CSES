#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll pow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
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

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/