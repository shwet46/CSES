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
const int N = 1000001;
 
ll towers[N][2];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    towers[1][1] = 1;
    towers[1][0] = 1;

    for (int i = 2; i < N; ++i) {
        towers[i][1] = (4 * towers[i - 1][1] + towers[i - 1][0]) % MOD;
        towers[i][0] = (towers[i - 1][1] + 2 * towers[i - 1][0]) % MOD;
    }
 
    ll t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << (towers[n][0] + towers[n][1]) % MOD << "\n";
    }
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/