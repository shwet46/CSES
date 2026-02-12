#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    ll d1 = 0;
    ll d2 = 1;

    for (int i = 3; i <= n; i++) {
        ll d = (i - 1) * (d1 + d2) % MOD;
        d1 = d2;
        d2 = d;
    }

    cout << d2 << '\n';

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/