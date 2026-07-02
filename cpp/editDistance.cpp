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

	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i = 0; i <= n; i++) dp[i][0] = i;
	for(int j = 0; j <= m; j++) dp[0][j] = j;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1] + (a[i-1] != b[j-1])});
		}
	}

	cout << dp[n][m] <<"\n";
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/