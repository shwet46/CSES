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

    vector<pii> curr; 
    curr.pb({0, 0});

    string ans = "";
    ans += grid[0][0];

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vis[0][0] = true;

    for (int step = 1; step < 2 * n - 1; step++) {

        char mn = 'Z';
        vector<pii> next;

        for (auto [i, j] : curr) {
            if (i + 1 < n)
                mn = min(mn, grid[i + 1][j]);
            if (j + 1 < n)
                mn = min(mn, grid[i][j + 1]);
        }

        for (auto [i, j] : curr) {
            if (i + 1 < n && grid[i + 1][j] == mn && !vis[i + 1][j]) {
                vis[i + 1][j] = true;
                next.pb({i + 1, j});
            }
            if (j + 1 < n && grid[i][j + 1] == mn && !vis[i][j + 1]) {
                vis[i][j + 1] = true;
                next.pb({i, j + 1});
            }
        }

        ans += mn;
        curr = next;
    }

    cout << ans << "\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/