#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
const ll INF = 1e18;


ull power(ull base, ull exp, ull mod) {
    ull res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = ((__int128)res * base) % mod;
        base = ((__int128)base * base) % mod;
        exp /= 2;
    }
    return res;
}

bool isPrime(ull n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    ull d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    static const ull bases[] = {2, 3, 5, 7, 11, 13, 17};

    for (ull a : bases) {
        if (n <= a) break;
        ull x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = ((__int128)x * x) % n;
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

void solve() {
    ll x, c;
    cin >> x >> c;

    if (isPrime(c)) {
        cout << c << "\n";
        return;
    }

    if (__gcd(x, c) > 1) {
        cout << -1 << "\n";
        return;
    }

    ll k = 1;
    while (true) {
        ll ans = k * x + c;

        if (ans > 5 && (ans % 2 == 0 || ans % 3 == 0 || ans % 5 == 0)) {
            k++;
            continue;
        }
        
        if (power(2, ans - 1, ans) != 1) {
            k++;
            continue;
        }
        
   
        if (isPrime(ans)) {
            cout << ans << "\n";
            return;
        }
        k++;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/