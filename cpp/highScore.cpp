#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mod 1000000007

const int N = 2505;

struct Edge {
    int a, b;
    ll w;
};

vector<int> adj[N];
vector<Edge> edges;
vector<bool> vis(N, false);
vector<bool> bad(N, false);

void dfs(int node) {
    vis[node] = true;
    for (auto &v : adj[node])
        if (!vis[v]) dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;

        edges.push_back({a, b, -x});   // negate weight
        adj[a].push_back(b);
    }

    vector<ll> dist(n + 1, 1e18);
    dist[1] = 0;

    // Bellman-Ford
    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.a] < 1e18)
                dist[e.b] = min(dist[e.b], dist[e.a] + e.w);
        }
    }

    // Detect negative cycle
    for (auto &e : edges) {
        if (dist[e.a] < 1e18 && dist[e.b] > dist[e.a] + e.w) {
            bad[e.b] = true;
        }
    }

    // Check if bad nodes can reach n
    for (int i = 1; i <= n; i++) {
        if (bad[i]) {
            fill(vis.begin(), vis.end(), false);
            dfs(i);
            if (vis[n]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << -dist[n] << endl;

    return 0;
}