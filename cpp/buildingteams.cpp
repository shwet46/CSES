#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
vector<int> graph[N];
int teams[N];

bool dfs(int x, int team){
    if(teams[x] != 0) return teams[x] == team;
    teams[x] = team;
    for(int y : graph[x]){
        if(!dfs(y, 3 - team)) return false;
    }
    return true;
}

bool bfs(int x, int team){
    queue<int> q;
    q.push(x);
    teams[x] = team;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(teams[v] == 0){
                teams[v] = 3 - teams[u];
                q.push(v);
            } else if(teams[v] == teams[u]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        if(teams[i] != 0) continue;
        if(!bfs(i,1)){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << teams[i] << ' ';
    }
    cout << '\n';
}