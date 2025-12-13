#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int x;
	cin >> n >> x;

	map<int, int> m;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(m.count(x-a)){
            cout << i + 1 << " " << m[x - a] + 1 << "\n";
            return 0;
        }
        m[a] = i;
    }

	cout << "IMPOSSIBLE" << endl;
}