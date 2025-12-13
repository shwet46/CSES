#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> movies(n);

    for (ll i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](pair<ll, ll>& a, pair<ll, ll>& b) {
        return a.second < b.second;
    });

    ll count = 0, last_end_time = 0;

    for (auto& m : movies) {
        if (m.first >= last_end_time) {
            count++;
            last_end_time = m.second;
        }
    }

    cout << count << "\n";

    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/