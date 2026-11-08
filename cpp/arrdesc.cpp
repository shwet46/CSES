#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
const ll INF = 1e18;

bool valid(int x, int m){
    return (x >= 0 && x <= m);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= m; i++){
        if(a[0] == i || a[0] == 0){
            dp[1][i] = 1;
        }
    }

    for(int i = 2; i <= n; i++){
        for(int k = 1; k <= m; k++){
            if(a[i-1] != 0 && a[i-1] != k){
                dp[i][k] = 0;
                continue;
            }
            for(int p = k-1; p <= k+1; p++){
                if(!valid(p, m)) continue;
                dp[i][k] = (dp[i][k] + dp[i-1][p]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans+ dp[n][i]) % MOD;
    }

    cout << ans <<"\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/