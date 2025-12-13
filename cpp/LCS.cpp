#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin>>n>>m;
    vector<int> a(n+1), b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=m;j++) cin>>b[j];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << "\n";

    vector<int> lcs;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(a[i] == b[j]) {
            lcs.push_back(a[i]);
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    for(int x : lcs) cout << x << " ";
 
    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/