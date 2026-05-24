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
 
const int N = 5000;
int x[N];
ll score[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    ll sum = 0;
    rep(i, 0, n){
        cin >> x[i];
        score[i] = x[i];
        sum += x[i];
    }
    
    rep(len, 2, n+1){
        for(int l = 0; l+1 <= n; l++){
            int r = l+len-1;
            score[l] = max(x[l]-score[l+1], x[r]-score[l]);
        }
    }
    
    cout << (sum+score[0]) / 2 <<"\n";
 
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/