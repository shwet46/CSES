#include <iostream>
#include <string>
using namespace std;

const int N = 9; 
const int PATH_LEN = 48;
string path;
int dr[4] = {-1, 0, 1, 0}; // U, R, D, L
int dc[4] = {0, 1, 0, -1};
bool visited[N][N];

int dfs(int r, int c, int idx) {
    if (r == 7 && c == 1) return idx == PATH_LEN ? 1 : 0;
    if (idx == PATH_LEN) return 0;

    if ((visited[r][c - 1] && visited[r][c + 1] && !visited[r - 1][c] && !visited[r + 1][c]) ||
        (visited[r - 1][c] && visited[r + 1][c] && !visited[r][c - 1] && !visited[r][c + 1]))
        return 0;

    visited[r][c] = true;
    int totalPaths = 0;

    if (path[idx] != '?') {
        int dir = string("URDL").find(path[idx]);
        int nr = r + dr[dir], nc = c + dc[dir];
        if (!visited[nr][nc])
            totalPaths += dfs(nr, nc, idx + 1);
    } else {
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (!visited[nr][nc])
                totalPaths += dfs(nr, nc, idx + 1);
        }
    }

    visited[r][c] = false; // backtrack
    return totalPaths;
}

int main() {
    cin >> path;

    for (int i = 0; i < N; ++i) {
        visited[0][i] = visited[8][i] = true;
        visited[i][0] = visited[i][8] = true;
    }

    cout << dfs(1, 1, 0) << '\n';
    return 0;
}