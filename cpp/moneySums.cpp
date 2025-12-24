#include <bits/stdc++.h>
using namespace std;

int main() {
    const int X = 100000;
    int n;
    cin >> n;

    vector<bool> possible(X + 1, false);

    possible[0] = true;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int s = X; s >= x; --s) {
            possible[s] = possible[s] || possible[s - x];
        }
    }

    int k = 0;
    for (int s = 1; s <= X; ++s) {
        if (possible[s]) k++;
    }

    cout << k << "\n";
    for (int s = 1; s <= X; ++s) {
        if (possible[s]) cout << s << " ";
    }
    cout << "\n";
}