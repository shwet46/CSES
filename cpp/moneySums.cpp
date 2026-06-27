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
const int X = 100000;
 
bool poss[X+1];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    poss[0] = true;
    rep(i, 0, n){
        int x;
        cin >> x;
        for(int s = X; s >= x; s--){
            poss[s] |= poss[s-x];
        }
    }
    
    int k = 0;
    for(int s = 1; s <= X; s++){
        k += poss[s];
    }
    
    cout << k <<"\n";
    for(int s = 1; s <= X; s++){
        if(poss[s]) cout << s <<" ";
    }
    
    cout<<"\n";
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/