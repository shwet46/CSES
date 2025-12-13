#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    vector<int> lens(n);
    for(int i=0;i<n;i++) cin>>lens[i];

    sort(lens.begin(), lens.end());
    int mid = lens[n/2];

    ll cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(mid - lens[i]);
    }

    cout << cost << "\n";
 
    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/