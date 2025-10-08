#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int j = 0; j < n; ++j) {
        cin >> c[j];
    }

    vector<int> amount(x + 1);
    amount[0] = 0;
    for (int i = 1; i <= x; ++i) {
        amount[i] = INF;
        for (int j = 0; j < n; ++j) {
            if (i - c[j] >= 0) {
                amount[i] = min(amount[i], amount[i - c[j]] + 1);
            }
        }
    }

    int answer = amount[x];
    if (answer == INF) answer = -1;
    cout << answer << "\n";
 
    return 0;
}