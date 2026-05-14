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
#define rep(i, a, b) for (int i = a; i < b; i++)
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
 
bool is_possible(const vll& a, int k, ll max_sum) {
    int segments = 1;
    ll current_sum = 0;
 
    for (ll x : a) {
        if (x > max_sum) return false;
        if (current_sum + x > max_sum) {
            segments++;
            current_sum = x;
        } else {
            current_sum += x;
        }
    }
    return segments <= k;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, k;
    cin>>n>>k;
 
    vll a(n);
    ll low = 0, high = 0;
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        low = max(low, a[i]); 
        high += a[i];        
    }
 
    ll ans = high;
 
    while (low <= high) {
        ll mid = low + (high - low) / 2;
 
        if (is_possible(a, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1; 
        }
    }

    cout<<ans<<"\n";

    return 0;
}
 
/* 
 
          /\_/\        
         (='.'=)    
         (")_(")        
 
*/
