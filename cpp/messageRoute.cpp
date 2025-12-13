#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100001;
 
vector<int> graph[N];
bool vis[N];
int par[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,m;
    cin>>n>>m;
    
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    vis[1] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y : graph[x]){
            if(vis[y]) continue;
            vis[y] = true;
            par[y] = x;
            q.push(y);
        }
    }
    
    if(!vis[n]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> ans;
    int x = n;
    while(x != 0){
        ans.push_back(x);
        x = par[x];
    }
    
    reverse(ans.begin(), ans.end());
    
    cout<<ans.size()<<"\n";
    
    for(int nd: ans){
        cout<<nd<<" ";
    }
    
    cout<<"\n";
 
    return 0;
}