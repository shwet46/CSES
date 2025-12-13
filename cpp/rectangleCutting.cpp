#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w,h;
    cin>>w>>h;
    int dp[w+1][h+1];

    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=INT_MAX;
                for(int k=1;k<i;k++){
                    dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
                }
                for(int k=1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
                }
            }
        }
    }
 
    cout << dp[w][h] << "\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/