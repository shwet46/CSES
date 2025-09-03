#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll solve(ll n, ll x, vector<ll>& coins) {
    ll dp[x+1] = {};
    dp[0] = 1; 

    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(coins[j] > i) {
                continue; // Skip if coin is larger than current amount
            }
            dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }

    return dp[x]; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << solve(n, x, coins) << endl;

    return 0;
}