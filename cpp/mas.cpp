#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double EPS = 1e-6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, d;
    cin >> n >> d;
    vector<double> a(n + 1);
    for (ll i = 1; i <= n; i++) cin >> a[i];

    double lo = 0, hi = 100, bestMean = 0;
    ll bestL = 1, bestR = d;

    while (hi - lo > EPS) {
        double mid = (lo + hi) / 2;


        vector<double> prefix(n + 1, 0);
        for (ll i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + (a[i] - mid);


        double minPrefix = 0;
        bool ok = false;
        ll minIndex = 0;
        ll curL = 1, curR = d;

        for (ll r = d; r <= n; r++) {
            if (prefix[r] - minPrefix >= 0) {
                ok = true;
                curR = r;
                curL = minIndex + 1;
                break;
            }
            if (prefix[r - d + 1] < minPrefix) {
                minPrefix = prefix[r - d + 1];
                minIndex = r - d + 1;
            }
        }

        if (ok) {
            bestMean = mid;
            bestL = curL;
            bestR = curR;
            lo = mid; 
        } else {
            hi = mid; 
        }
    }

    cout << bestL << " " << bestR << "\n";
    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/