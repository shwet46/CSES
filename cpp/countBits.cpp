#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll sum = 0;
    for (int j = 60; j >= 0; --j) {
        ll bit = 1ll << j;
        sum += n / (bit * 2) * bit;
        sum += max(0ll, n % (bit * 2) - (bit - 1));
    }

    cout << sum << '\n';

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/