#include <bits/stdc++.h>
using namespace std;

void solve(int start, int helper, int end, int count) {
    if (count == 1) {
        cout << start << " " << end << endl;
        return;
    }
    solve(start, end, helper, count - 1);
    cout << start << " " << end << endl;
    solve(helper, start, end, count - 1);
}

int main () {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << endl;
    solve(1, 2, 3, n);
}
