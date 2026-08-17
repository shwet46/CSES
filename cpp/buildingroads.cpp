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
 
const int N = 1e5+1;
vi adj[N], vis(N, false), ans;

void dfs(int node){
    vis[node] = true;
    for(auto v : adj[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ans.pb(i);
            dfs(i);
        }
    }

    cout << sz(ans)-1 << "\n";
    for(int i = 1; i < sz(ans); i++){
        cout << ans[i-1] << " " << ans[i] << "\n";
    }
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/