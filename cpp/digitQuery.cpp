#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
void solve() {
    vector<ll> pref(1, 0);
    for (int i = 0; i < 18; i++) {
        pref.push_back((i + 1) * (9LL * (ll)pow(10, i)) + pref.back());
    }

    ll k;
    cin >> k;

    int digits = 0;
    for (int i = 0; i < (int)pref.size(); i++) {
        if (pref[i] >= k) {
            digits = i;
            k -= pref[i - 1];
            break;
        }
    }

    ll num = k / digits;
    ll digit = k % digits;

    if (digit == 0) {
        digit = digits;
    } else {
        num += 1;
    }

    ll number = (ll)pow(10, digits - 1) + num - 1;
    string s = to_string(number);
    cout << s[digit - 1] << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}