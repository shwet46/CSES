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
const ll INF = 1e9;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a,b;
    cin >> a >> b;
    vector<vector<int>> moves(a+1, vector<int>(b+1));
    
    rep(i, 1, a+1){
        rep(j, 1, b+1){
            if(i == j){
                moves[i][j] == 0;
            }else{
                moves[i][j] = INF;
                rep(x, 1, i){
                    moves[i][j] = min(moves[i][j], moves[x][j] + moves[i-x][j] + 1);
                }
                rep(y, 1, j){
                    moves[i][j] = min(moves[i][j], moves[i][y] + moves[i][j-y] + 1);
                }
            }
        }
    }
    
    cout << moves[a][b] <<"\n";
 
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/