#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int& coin : coins) {
        cin >> coin;
    }

    vector<int> dp(x + 1, x + 1); 
    dp[0] = 0;

    for (int coin : coins) {
        for (int amount = coin; amount <= x; amount++) {
            dp[amount] = min(dp[amount], dp[amount - coin] + 1);
        }
    }

    cout << (dp[x] > x ? -1 : dp[x]) << endl;

    return 0;
}