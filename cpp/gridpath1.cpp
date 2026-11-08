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
    
    int n;
    cin >> n;
    vector<string> g(n);
    rep(i, 0, n) cin >> g[i];

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == '*'){
                dp[i][j] = 0;
            }else{
                if(i == 0 && j == 0){
                    dp[i][j] = 1;

                }
                if(i) dp[i][j] += dp[i-1][j];
                if(j) dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n-1][n-1] <<"\n";
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/