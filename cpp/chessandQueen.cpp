#include <bits/stdc++.h>
using namespace std;

const int n = 8;
string grid[n];
int total;
int col[n], diag1[2 * n], diag2[2 * n];

void search(int r) {
	if (r == n) {
		total++;
		return;
	}
	for (int c = 0; c < n; c++) {
		if (grid[r][c] == '*' || col[c] || diag1[r + c] || diag2[r - c + n]) {
			continue;
		}
		col[c] = diag1[r + c] = diag2[r - c + n] = 1;
		search(r + 1);
		col[c] = diag1[r + c] = diag2[r - c + n] = 0;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	for (auto &row : grid) {
        cin >> row;
    }
    search(0);
    cout << total << "\n";
    
    return 0;
}

/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/