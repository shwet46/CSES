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
const int N = 500 * 501 / 4;
const int M = 1000000007;

int sets[N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int total = n*(n+1)/2;
    if(total % 2 != 0){
        cout << 0 <<"\n";
        return 0;
    }

    int half = total / 2;
    sets[0] = 1;
    rep(x, 1, n){
        for(int s = half; s - x >= 0; --s){
            sets[s] = (sets[s] + sets[s - x]) % M;
        }
    }

    cout << sets[half] <<"\n";
 
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/