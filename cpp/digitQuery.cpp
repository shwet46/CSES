#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
void solve() {
   ll k;
   cin>>k;
   k--;
   ll a = 1;
   ll b = 9;
   ll c = 1;
   while(k >= (b-a+1) * c){
        k -= (b-a+1) * c;
        a *= 10;
        b = b * 10 + 9;
        c++;
   }

   ll x = a+(k/c);
   cout << to_string(x)[k%c] - '0' << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/