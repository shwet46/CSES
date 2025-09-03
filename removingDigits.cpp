#include<bits/stdc++.h>
using namespace std;    
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll> dp(n+1,1e9);
    dp[0]=0;

    for(int i = 1; i <= n; i++){
        ll temp = i;
        while(temp){
            ll d = temp % 10;
            dp[i] = min(dp[i], 1 + dp[i - d]);
            temp /= 10;
        }
    }

    cout << dp[n] << endl;
  
    return 0;
}