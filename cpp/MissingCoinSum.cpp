#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin>>n;
    vector<ll>coins(n);
    for(int i = 0;i<n;i++){
        cin>>coins[i];
    }

    sort(coins.begin(),coins.end());

    ll ans = 0;

    for(int i = 0;i<n;i++){
        if(coins[i]>ans+1){
            break;
        }
        ans+=coins[i];
    }

    cout<<ans+1<<"\n";
 
    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/