#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;
    vector<string> g(n);
    pair<int,int> s, e;

    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') s = {i, j};
            if (g[i][j] == 'B') e = {i, j};
        }
    }

    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    char mv[4] = {'R','D','L','U'};

    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<pair<int,int>>> par(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> step(n, vector<char>(m));

    queue<pair<int,int>> q;
    q.push(s);
    vis[s.first][s.second] = true;

    while (!q.empty()) {
        auto [r,c] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r+dr[k], nc = c+dc[k];
            if (nr<0||nr>=n||nc<0||nc>=m) continue;
            if (g[nr][nc]=='#' || vis[nr][nc]) continue;
            vis[nr][nc] = true;
            par[nr][nc] = {r,c};
            step[nr][nc] = mv[k];
            q.push({nr,nc});
        }
    }

    if (!vis[e.first][e.second]) {
        cout << "NO\n";
        return 0;
    }

    string path;
    for (auto cur = e; cur != s; cur = par[cur.first][cur.second]) {
        path.push_back(step[cur.first][cur.second]);
    }
    reverse(path.begin(), path.end());

    cout << "YES\n" << path.size() << "\n" << path << "\n";
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/