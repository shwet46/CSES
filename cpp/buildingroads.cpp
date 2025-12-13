#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mod 1000000007

const int N = 1e5 + 1;
vector < int > adj[N], vis(N, false), ans;

void dfs(int node) {
    vis[node] = true;
    for (auto & v: adj[node])
        if (!vis[v]) dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }

    cout << ans.size() - 1 << endl;

    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i - 1] << " " << ans[i] << endl;
    }

    return 0;
}