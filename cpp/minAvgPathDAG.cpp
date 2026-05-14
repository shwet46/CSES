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
const int N = 1e5 + 5;

struct E{
    int to;
    int w;
};
 
vector<E> adj[N];
double d[N];
int pr[N];

bool check(double mid, int n){
    fill(d, d+n+1, INF);
    d[1] = 0;
    rep(u, 1, n+1){
        if(d[u] >= INF) continue;
        for(auto &e: adj[u]){
            double new_d = d[u] + (e.w - mid);
            if(new_d < d[e.to]){
                d[e.to] = new_d;
                pr[e.to] = u;
            }
        }
    }
    return d[n] <= 0;
}


 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    rep(i, 0, m){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    
    double L = 0, R = 100;
    rep(i, 0, 60){
        double mid = (L+R) / 2.0;
        if(check(mid, n)){
            R = mid;
        }else{
            L = mid;
        }
    }
    
    check(R, n);
    
    vi path;
    for(int v = n; v != 0; v = pr[v]){
        path.push_back(v);
        if(v == 1) break;
    }
    
    reverse(all(path));
    
    cout << (int)path.size()-1 << "\n";
    rep(i, 0, (int)path.size()){
        cout << path[i] << (i == (int)path.size() - 1 ? "" : " ");
    }
    
    cout<<"\n";
    
 
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/