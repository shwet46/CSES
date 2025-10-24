#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
const int N = 1000000;

int main() {
    vector<int> count(N + 1);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        count[x]++;
    }

    for (int i = N; i >= 1; i--) {
        int total = 0;
        for (int j = i; j <= N; j += i) {
            total += count[j];
        }
        if (total >= 2) {
            cout << i << "\n";
            break;
        }
    }
}

/* 

          /\_/\          ♡ hi there ♡
         (='.'=)    < meow ~ just coding >
         (")_(")        

*/