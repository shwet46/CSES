#include<bits/stdc++.h>
using namespace std;
 
set<string> solve(string s) {
   sort(s.begin(), s.end());
   set<string> uniq;
   do{
    uniq.insert(s);
   }while(next_permutation(s.begin(), s.end()));
   return uniq;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    cin >> s;
    set<string> ans = solve(s);
    cout<<ans.size()<<"\n";
    for(auto x: ans) cout<<x<<"\n";
 
    return 0;
}