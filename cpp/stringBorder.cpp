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

    string s;
    cin>>s;
    int n = s.size();
    vi lps(n);

    rep(i, 1, n) {
        int j = lps[i-1];
        while(j > 0 && s[i] != s[j]) j = lps[j-1];
        if(s[i] == s[j]) j++;
        lps[i] = j;
    }

   vi borders;
   int k = lps[n-1];
   while(k > 0) {
       borders.pb(k);
       k = lps[k-1];
    }

    reverse(all(borders));
 
    for(int x : borders) cout << x << " ";
    cout<<endl;
 
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/