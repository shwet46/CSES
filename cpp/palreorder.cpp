#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve() {
    string s;
    cin >> s;
    map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    int oddCount = 0;
    char oddChar;
    for (auto &[c, cnt] : freq) {
        if (cnt % 2 != 0) {
            oddCount++;
            oddChar = c;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION\n";
        return;
    }

    string half = "";
    for (auto &[c, cnt] : freq) {
        half += string(cnt / 2, c);
    }

    string res = half;
    if (oddCount == 1) {
        res += string(freq[oddChar], oddChar).substr(0, freq[oddChar] % 2);
    }
    reverse(half.begin(), half.end());
    res += half;

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}