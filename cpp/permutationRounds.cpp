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
    cin>>n;
    vi ord(n+1);
    rep(i, 1, n+1) cin>>ord[i];
    vi mc(n+1);

    rep(i, 1, n+1){
        if(ord[i] == 0){
            continue;
        }
        int pos = i;
        int l = 0;
        do{
            l++;
            int newpos = ord[pos];
            ord[pos] = 0;
            pos = newpos;
        }while(pos != i);
        for(int x = 2; x*x <= l; x++){
            int cnt = 0;
            while(l % x == 0){
                l /= x;
                cnt++;
            }
            mc[x] = max(mc[x], cnt);
        }
        if(!mc[l]) mc[l] = 1;
    }

    ll ans = 1;
    rep(x, 2, n+1){
        rep(i, 0, mc[x]){
            ans = ans*x;
            ans %= MOD;
        }
    }

    cout<<ans<<"\n";

 
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/