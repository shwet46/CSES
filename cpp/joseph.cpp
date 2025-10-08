#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


ll josephus(ll n, ll k)
{
    if (n == 1) return 1;
    if (k <= (n + 1) / 2)
    {
        if (2 * k > n) return (2 * k) % n;
        else return 2 * k;
    }
    ll temp = josephus(n / 2, k - (n + 1) / 2);
    if (n % 2 == 1) return 2 * temp + 1;
    return 2 * temp - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << josephus(n, k) << endl;
    }

    return 0;
}