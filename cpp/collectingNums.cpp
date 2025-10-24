#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int ans = 1;

    map<int, int> idx;
    for(int i = 0; i < n; i++) idx[a[i]] = i;

    for (int i = 1; i < n; i++) {
        if (idx[i] > idx[i + 1]) ans++;
    }

    cout << ans << "\n";

    return 0;
}