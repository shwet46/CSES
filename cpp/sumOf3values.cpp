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
    
    int n, x;
    cin >> n >> x;
    
    vector<pii> v;
    
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        v.emplace_back(a, i);
    }
    
    sort(all(v));
    
    for(int i = 0; i < n; i++){
        int j = i+1;
        int k = n-1;
        while(j < k){
            int sum = v[i].first + v[j].first + v[k].first;
            if(sum == x){
                cout << v[i].second <<" " << v[j].second <<" " << v[k].second<<"\n";
                return 0;
            }else if(sum < x){
                j++;
            }else{
                k--;
            }
        }
    }
    
    cout <<"IMPOSSIBLE\n";
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/