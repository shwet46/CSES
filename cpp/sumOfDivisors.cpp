#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll sum = 0;
    ll i = 1;

    while (i <= n) {
        ll val = n / i;       
        ll last = n / val;       
        ll count = last - i + 1;
        ll range_sum = ((i + last) % mod) * ((count % mod) * ((mod + 1) / 2) % mod) % mod; 
        sum = (sum + (range_sum * (val % mod)) % mod) % mod;

        i = last + 1;
    }

    cout << sum % mod << "\n";
    return 0;
}