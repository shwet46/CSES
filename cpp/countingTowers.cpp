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

ll tower[N][2];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    tower[1][1] = 1;
    tower[1][0] = 1;
    for(int i = 2; i < N; i++){
        tower[i][1] = (4 * tower[i-1][1] + tower[i-1][0]) % MOD;
        tower[i][0] = (tower[i-1][1] + 2 * tower[i-1][0]) % MOD;
    }
    
    ll t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout<<(tower[n][0] + tower[n][1]) % MOD <<"\n";
    }
 
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/