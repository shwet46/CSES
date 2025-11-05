#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int &w : p) cin >> w;

    sort(p.begin(), p.end());
    int i = 0, j = n - 1, ans = 0;

    while (i <= j) {
        if (p[i] + p[j] <= x) i++;
        j--;
        ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}