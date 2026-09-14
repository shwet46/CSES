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
    vector<vector<int>> event;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        event.pb({a, 1, i});
        event.pb({b, 2, i});
    }

    sort(all(event));

    vi room;
    vi ans(n+1);
    int c = 0;
    
    for(auto e: event){
        if(e[1] == 1){
            if(room.empty()){
                c++;
                room.pb(c);
            }
            ans[e[2]] = room.back();
            room.pop_back();
        }
        if(e[1] == 2){
            room.pb(ans[e[2]]);
        }
    }

    cout << c << "\n";
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/