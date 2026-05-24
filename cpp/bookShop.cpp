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
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,x;
    cin >> n >> x;
    vi h(n), s(n);
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, n) cin >> s[i];
    
    vi total(x+1);
    rep(i, 0, n){
        for(int j = x; j >= h[i]; j--){
            total[j] = max(total[j], s[i] + total[j-h[i]]);
        }
    }
    
    cout << total[x] << "\n";
 
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/