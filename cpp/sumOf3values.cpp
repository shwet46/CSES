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
    cin >> n >> x;
    vector<pii> v;
    rep(i, 1, n+1){
        int a;
        cin >> a;
        v.emplace_back(a, i);
    }
    
    sort(all(v));
    
    rep(i, 0, n){
        int y = x - v[i].first;
        int a = i+1;
        int b = n-1;
        while(a < b){
            int s = v[a].first + v[b].first;
            if(s == y){
                cout << v[i].second <<" " << v[a].second <<" " << v[b].second <<"\n";
                return 0;
            }else if(s > y){
                b--;
            }else{
                a++;
            }
        }
    }
    
    cout<<"IMPOSSIBLE\n";
 
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/