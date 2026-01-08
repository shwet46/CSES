#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll t;
    cin >> n >> t;
    vector<ll> k(n);
    for (int i = 0; i < n; i++) cin >> k[i];

    // Binary search boundaries
    ll low = 0;
    ll high = *min_element(k.begin(), k.end()) * t; // worst case: fastest machine makes all products
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        // Calculate total products in 'mid' seconds
        __int128 total = 0; // prevent overflow
        for (ll time : k) {
            total += mid / time;
            if (total >= t) break; // optimization
        }

        if (total >= t) {
            ans = mid;
            high = mid - 1; // try smaller time
        } else {
            low = mid + 1; // need more time
        }
    }

    cout << ans << "\n";
    return 0;
}

/*  
          /\_/\        
         (='.'=)     
         (")_(")        
*/