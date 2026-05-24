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

const int M = 1000000007;
const int N = 100001;

int dp[N][105]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    
    rep(j, 1, m + 1){
        if(a[1] == 0 || a[1] == j){
            dp[1][j] = 1;
        }
    }
    
    rep(i, 2, n + 1){
        rep(j, 1, m + 1){
            if(a[i] == 0 || a[i] == j){
                rep(k, -1, 2){
                    if (j + k >= 1 && j + k <= m) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j + k]) % MOD;
                    }
                }
            }
        }
    }
    
    int ans = 0;
    rep(j, 1, m + 1){
        ans = (ans + dp[n][j]) % MOD;
    }
    
    cout << ans << "\n";
   
    return 0;
}

/* 
          /\_/\        
         (='.'=)    
         (")_(")        
*/