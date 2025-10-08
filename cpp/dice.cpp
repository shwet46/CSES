#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    
    vector<ll> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        dp[i] = 0;
        for(int v = 1; v <= 6; ++v){
            if(i-v >= 0){
                dp[i] += dp[i-v];
            }
        }
        dp[i] %= mod;
    }
    
    cout<<dp[n]<<"\n";
 
    return 0;
}