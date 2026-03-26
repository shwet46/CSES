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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<array<int,3>> events;
    rep(i, 1, n + 1) {
        int a, b;
        cin >> a >> b;
        events.pb({a, 1, i});
        events.pb({b, 2, i});
    }

    sort(all(events));

    vi free_rooms;          
    vi assigned(n + 1);    
    int total_rooms = 0;

    for (auto &e : events) {
        int type = e[1];
        int id = e[2];

        if (type == 1) {
            if (free_rooms.empty()) {
                total_rooms++;
                free_rooms.pb(total_rooms);
            }
            assigned[id] = free_rooms.back();
            free_rooms.pop_back();
        }else {
            free_rooms.pb(assigned[id]);
        }
    }

    cout << total_rooms << "\n";
    rep(i, 1, n + 1) {
        cout << assigned[i] << " ";
    }
    cout << "\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/