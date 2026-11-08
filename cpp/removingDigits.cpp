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
    int steps = 0;

    while(n){
        int mx = 0;
        int t = n;
        while(t){
            int d = t % 10;
            mx = max(mx, d);
            t /= 10;
        }
        n -= mx;
        steps++;
    }

    cout << steps <<"\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/