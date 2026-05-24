#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll v_lcm(vi a){
    if(a.empty()) return 0;
    
    return accumulate(a.begin(), a.end(), 1LL, [](ll acc, ll ele){
        if(ele == 0 || acc == 0) return 0LL;
        return (acc / __gcd(acc, ele)) * ele;
    });
}


ll v_gcd(vi a){
    if(a.empty()) return 0;
    
    return accumulate(a.begin()+1, a.end(), a[0], [](ll acc, ll ele){
        return __gcd(acc, ele);
    });
}
 
void solve() {
   int n;
   cin >> n;
   vi a(n);
   rep(i, 0, n) cin >> a[i];
   cout << "lcm: " <<  v_lcm(a) <<"\n";
   cout << "gcd: " << v_gcd(a) << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/