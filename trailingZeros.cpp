#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    int count = 0;
    for (long long i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while (t--) {
        solve();
    }

    return 0;
}