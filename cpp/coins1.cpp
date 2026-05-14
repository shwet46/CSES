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

    int n, x;
    cin >> n >> x;
    vi c(n);
    rep(i , 0, n) cin >> c[i];

    vi ways(x+1);
    ways[0] = 1;

    rep(i , 1, x+1){
        ways[i] = 0;
        rep(j, 0, n){
            if(i-c[j] >= 0) ways[i] = (ways[i] + ways[i-c[j]]) % MOD;
        }
    }

    cout << ways[x] << "\n";
     
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/