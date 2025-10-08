#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int& coin : coins) {
        cin >> coin;
    }

    vector<int> dp(x+1, x+1);
    dp[0] = 0;

    for(auto coin : coins){
        for(int i = coin; i <= x; i++){
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    cout << (dp[x] > x ? -1 : dp[x]) << "\n";

    return 0;
}