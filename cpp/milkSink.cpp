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
    vi od(n+1, 0);
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        od[u]++;
    }
    
    int sink = -1;
    for(int i = 1; i <= n; i++){
        if(od[i] == 0){
            if(sink != -1){
                cout << -1 <<"\n";
                return 0;
            }
            sink = i;
        }
    }
    
    cout << sink <<"\n";
 
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/