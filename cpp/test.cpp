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
   string s;
   cin >> s;
   int f = n/k;
   int ans = 0;
   rep(i, 0, f){
        bool o = true;
        rep(j, 0, k){
            if (s[i*k + j] == '0') {
                o = false;
                break;
            }
        }
        if (o) ans++;
   }

   cout << ans << "\n";
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