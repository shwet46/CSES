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
    rep(i, 1, n+1) cin >> c[i];
    
    vi dp(x+1, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= n; j++){
            if(c[j] <= i){
                dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
            }
        }
    }
    
    cout << dp[x] <<"\n";
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/