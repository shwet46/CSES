#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int rounds = 1;
    for (int x = 1; x < n; x++) {
        if (pos[x + 1] < pos[x]) {
            rounds++;
        }
    }

    while (m--) {
        int i, j;
        cin >> i >> j;

        int u = arr[i];
        int v = arr[j];

        set<pair<int, int>> affected_pairs;
        if (u - 1 >= 1) affected_pairs.insert({u - 1, u});
        if (u + 1 <= n) affected_pairs.insert({u, u + 1});
        if (v - 1 >= 1) affected_pairs.insert({v - 1, v});
        if (v + 1 <= n) affected_pairs.insert({v, v + 1});

        for (auto p : affected_pairs) {
            if (pos[p.second] < pos[p.first]) {
                rounds--;
            }
        }

        swap(arr[i], arr[j]);
        pos[u] = j;
        pos[v] = i;

        for (auto p : affected_pairs) {
            if (pos[p.second] < pos[p.first]) {
                rounds++;
            }
        }

        cout << rounds << "\n";
    }

    return 0;
}