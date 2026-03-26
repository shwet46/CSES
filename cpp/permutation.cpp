#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = n / 2; i >= 1; i--) {
        cout << i << " " << i + n / 2 << " ";
    }
    if (n % 2 == 1) cout << n << " ";
    cout << "\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/