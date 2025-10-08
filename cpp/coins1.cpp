#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int n, x;
   cin >> n >> x;

   vector<int> coins(n);
   for(int i = 0; i < n; i++) cin >> coins[i];

   vector<int> ways(x + 1);
   ways[0] = 1;

   for(int i = 1; i <= x; i++){
        ways[i] = 0;
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0){
                ways[i] = (ways[i] + ways[i-coins[j]]) % mod;
            }
        }
   }
    cout << ways[x] << "\n";
    
     return 0;
}