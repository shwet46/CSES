#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vi a(n);
    for (int &x : a) cin >> x;

    unordered_map<int, int> freq;

    int l = 0;
    ll ans = 0;

    for (int r = 0; r < n; r++) {
        freq[a[r]]++;

        while ((int)freq.size() > k) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) freq.erase(a[l]);
            l++;
        }

        ans += (r - l + 1);
    }

    cout << ans << "\n";
   
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/