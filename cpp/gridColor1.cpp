#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    
     vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = 'A'; c <= 'D'; c++) {
                bool fail = false;
                if (grid[i][j] == c) fail = true;
                if (i > 0 && grid[i - 1][j] == c) fail = true;
                if (j > 0 && grid[i][j - 1] == c) fail = true;
                if (!fail) {
                    grid[i][j] = c;
                    break;
                }
            }
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/