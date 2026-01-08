#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> tasks;
    for (int i = 1; i <= n; i++) {
        int duration, deadline;
        cin >> duration >> deadline;
        tasks.emplace_back(duration, deadline);
    }
    sort(tasks.begin(), tasks.end());

    ll time = 0;
    ll reward = 0;
    for (auto [duration, deadline] : tasks) {
        time += duration;
        reward += deadline - time;
    }
    cout << reward << "\n";

    return 0;
}

/* 

          /\_/\
         (='.'=)    
         (")_(")        

*/