#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    
    multiset<int> t;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        auto it = t.upper_bound(x);
        if (it == t.end()) {
            t.insert(x);
        } else {
            t.erase(it);
            t.insert(x);
        }
    }
    cout << t.size() << "\n";
 
    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/