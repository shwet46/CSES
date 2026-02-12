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
 
    int n,x;
    cin>>n>>x;
    vi a(n);
    rep(i,0,n) cin>>a[i];

    int left = 0;
    int right = 0;
    int sum = a[0];
    int count = 0;

    
    while (left < n) {
        while (sum < x && right + 1 < n) {
            right++;
            sum += a[right];
        }
        if (sum == x) {
            count++;
        }
        sum -= a[left];
        left++;
    }

    cout << count << "\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/