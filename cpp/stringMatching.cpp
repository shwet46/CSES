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
 
    string s, sub_s;
    cin>>s;
    cin>>sub_s;

    int n = s.size(), m = sub_s.size();
    vector<int> lps(m);

    for (int i = 1, j = 0; i < m; ) {
        if (sub_s[i] == sub_s[j]) lps[i++] = ++j;
        else if (j) j = lps[j - 1];
        else lps[i++] = 0;
    }

    int cnt = 0;

    for (int i = 0, j = 0; i < n; ) {
        if (s[i] == sub_s[j]) {
            i++; j++;
        }

        if (j == m) {
            cnt++;
            j = lps[j - 1];
        }
        else if (i < n && s[i] != sub_s[j]) {
            if (j) j = lps[j - 1];
            else i++;
        }
    }

    cout << cnt << "\n";

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/