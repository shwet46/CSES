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
 
void solve() {
   int n, k;
   cin >> n >> k;
   vi a(n), b(n);
   rep(i, 0, n) cin >> a[i];
   rep(i, 0, n) cin >> b[i];


   int ca = 0, cb = 0;
   rep(i, 0, n){
    if((a[i] & 1) == 0) ca++;
    if((b[i] & 1) == 0) cb++;
   }

   if((k & 1) == 0){
    if(ca <= cb){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
   }else{
    if(ca >= cb){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
   }
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