#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'A']++;

    int maxFreq = *max_element(freq.begin(), freq.end());
    if (maxFreq > (n + 1) / 2) {
        cout << "-1\n";
        return 0;
    }

    string result;
    result.reserve(n);
    char prev = 0;

    for (int pos = 0; pos < n; pos++) {
        for (int c = 0; c < 26; c++) {
            if (freq[c] == 0) continue;
            char cur = char('A' + c);
            if (cur == prev) continue;

            freq[c]--;
            int remaining = n - pos - 1;
            int curMax = *max_element(freq.begin(), freq.end());

            if (curMax <= (remaining + 1) / 2) {
                result.push_back(cur);
                prev = cur;
                break;
            }

            freq[c]++;
        }
    }

    cout << result << "\n";
    return 0;
}


/* 

          /\_/\        
         (='.'=)    
         (")_(")        

*/