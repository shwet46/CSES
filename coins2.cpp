#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll solveDistinctOrdered(ll n, ll x, vector<ll>& coins) {
    ll dp[x+1] = {};
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			if (j - coins[i - 1] >= 0) {  // prevent out of bounds cases
				dp[j] += dp[j - coins[i - 1]];
				dp[j] %= mod;
			}
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

    cout << solveDistinctOrdered(n, x, coins) << endl;

    return 0;
}