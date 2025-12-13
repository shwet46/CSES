#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    set<int> st;
    int i = 0, j = 0, ans = 0;
    while(i < n && j < n){
        if(st.find(a[j]) == st.end()){
            st.insert(a[j]);
            ans = max(ans, j - i + 1);
            j++;
        } else {
            st.erase(a[i]);
            i++;
        }
    }

    cout << ans << "\n";
 
    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/