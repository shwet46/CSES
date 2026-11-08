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

 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x;
    cin >> n >> x;
    vi c(n+1);
    rep(i, 0, n) cin >> c[i];
    
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    
    for(int i = n-1; i >= 0; i--){
        for(int s = 1; s <= x; s++){
            int skip = dp[i+1][s];
            int pick = 0;
            if(c[i] <= s){
                pick = dp[i][s - c[i]];
            }
            dp[i][s] = (skip + pick) % MOD;
        }
    }
    
    cout << dp[0][x] <<"\n";
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/