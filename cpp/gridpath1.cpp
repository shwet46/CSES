#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int M = 1000000007;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = (grid[0][0] == '.');

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '*') continue;
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % M;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % M;
        }
    }

    cout << dp[n-1][n-1] << "\n";
    
    return 0;
}