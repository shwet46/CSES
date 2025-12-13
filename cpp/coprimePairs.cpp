#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int maxA = 0;
    for (int &x : a) {
        cin >> x;
        maxA = max(maxA, x);
    }

    vector<int> freq(maxA + 1, 0);
    for (int x : a) freq[x]++;

    vector<ll> cnt(maxA + 1, 0);
    for (int d = 1; d <= maxA; d++) {
        for (int j = d; j <= maxA; j += d) cnt[d] += freq[j];
    }

    vector<ll> gcdPairs(maxA + 1, 0);
    for (int d = maxA; d >= 1; d--) {
        ll total = cnt[d] * (cnt[d] - 1) / 2; 
        for (int j = 2 * d; j <= maxA; j += d)
            total -= gcdPairs[j]; 
        gcdPairs[d] = total;
    }

    cout << gcdPairs[1] << "\n";

    return 0;
}

    /* 

          /\_/\     
         (='.'=)    
         (")_(")        

    */