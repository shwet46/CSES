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
    cin>>n>>x;
    vi a(n+1);
    rep(i,1,n+1) cin>>a[i];

    set<tuple<int,int,int>> s;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            s.emplace(a[i]+a[j], i, j);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            s.erase(make_tuple(a[i]+a[j], i, j));
        }
        for (int j = i - 1; j >= 1; j--) {
            int diff = x - a[i] - a[j];
            auto it = s.lower_bound({diff, 0, 0});
            if (it == s.end()) continue;
            auto [s, a, b] = *it;
            if (s != diff) continue;
            cout << i << " " << j << " " << a << " " << b << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/