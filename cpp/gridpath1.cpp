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
    vector<string> grid(n);
    rep(i, 0, n) cin >> grid[i];

    vector<vector<int>> paths(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            if(grid[i][j] == '*'){
                paths[i][j] = 0;
            }else{
                paths[i][j] = (i==0 & j==0);
                if(i) paths[i][j] += paths[i-1][j];
                if(j) paths[i][j] += paths[i][j-1];
                paths[i][j] %= MOD;
            }
        }
    }

    cout << paths[n-1][n-1] << "\n";
 
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/