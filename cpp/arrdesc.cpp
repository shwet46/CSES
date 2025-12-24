#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    if (a[0] == 0) {
        for (int v = 1; v <= m; v++) dp[0][v] = 1;
    } else {
      
        dp[0][a[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int v = 1; v <= m; v++) {
                for (int prev = v - 1; prev <= v + 1; prev++) {
                    if (prev >= 1 && prev <= m) {
                        dp[i][v] = (dp[i][v] + dp[i - 1][prev]) % MOD;
                    }
                }
            }
        } else {
            int v = a[i];
            for (int prev = v - 1; prev <= v + 1; prev++) {
                if (prev >= 1 && prev <= m) {
                    dp[i][v] = (dp[i][v] + dp[i - 1][prev]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int v = 1; v <= m; v++) {
        ans = (ans + dp[n - 1][v]) % MOD;
    }

    cout << ans << "\n";

    return 0;
}