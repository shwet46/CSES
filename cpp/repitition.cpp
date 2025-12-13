#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    
    int curr = 1;
    int maxl = 1;
    
    for(int i = 1; i < s.length(); i++){
        if(s[i] == s[i-1]){
            curr++;
        }else{
            maxl = max(curr, maxl);
            curr = 1;
        }
    
    }
    
    maxl = max(maxl, curr);
    cout<<maxl<<endl;


    return 0;
}