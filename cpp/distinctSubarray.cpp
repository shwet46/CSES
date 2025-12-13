#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin>>a[i];

    ll ans = 0;
    unordered_set<ll> window;
    int l = 0;
    for (int r = 0; r < n; r++) {
        while (window.count(a[r])) {
            window.erase(a[l]);
            l++;
        }
        window.insert(a[r]);
        ans += r - l + 1;
    }

    cout << ans << "\n";
    
    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/