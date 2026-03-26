#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int a, b;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }

    vector<ll> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int x = -1;
    for (int i = 1; i <= n; i++) {
        x = -1;
        for (auto &e : edges) {
            if (dist[e.a] + e.w < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.w;
                parent[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        x = parent[x];
    }
    vector<int> cycle;
    int cur = x;
    do {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != x);
    cycle.push_back(x);

    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int v : cycle) cout << v << " ";
    cout << "\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/