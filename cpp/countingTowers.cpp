#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

const int N = 1000001;
vector<vector<ll>> dp(N, vector<ll>(2, 0));

void precompute() {
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i < N; i++) {
        dp[i][1] = (4 * dp[i - 1][1] + dp[i - 1][0]) % mod;
        dp[i][0] = (dp[i - 1][1] + 2 * dp[i - 1][0]) % mod;
    }
}

void solve() {
    ll n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % mod << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/