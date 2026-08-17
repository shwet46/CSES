#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
   int n;
   cin>>n;
   string s;
   cin>>s;
   int l = 0;
   for(auto ch : s){
       if(ch == '#') l++;
   }
   
   int ans = (l+1)/2;
   cout<<ans<<"\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}