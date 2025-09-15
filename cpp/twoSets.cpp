#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(ll n) {
    ll temp = (n * (n + 1) / 2);
    if (temp % 2 == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    ll target = temp / 2;
    ll sum = 0;
    ll i = n;
    unordered_set < ll > s;
    s.reserve(n);
    while (sum < target) {
        s.insert(i);
        sum += i;
        i--;
    }
    if (sum > target) {
        sum -= (i + 1);
        assert(sum < target);
        s.erase(s.find(i + 1));

        s.insert(target - sum);
    }
    cout << s.size() << "\n";
    for (auto element: s) {
        cout << element << " ";
    }
    cout << "\n";
    cout << n - s.size() << "\n";
    for (int j = 1; j <= n; j++) {
        if (s.find(j) == s.end()) {
            cout << j << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    solve(n);

    return 0;
}