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

    int n;
    cin >> n;
    vll ways(n+1);
    ways[0] = 1;

    rep(i, 1, n+1){
        ways[i] = 0;
        rep(v, 1, 6+1){
            if(i-v >= 0) ways[i] += ways[i-v];
        }
        ways[i] %= MOD;
    }
 
    cout << ways[n] << "\n";
     
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/