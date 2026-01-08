#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    ll t= 0;
    ll l = 0;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        t += x;
        l = max(l, x);
    }

    cout << max(t, 2 * l) << "\n";
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/