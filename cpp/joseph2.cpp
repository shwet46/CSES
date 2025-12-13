#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n+1,0) {}
    void add(int i,int v){ for(;i<=n;i+=i&-i) bit[i]+=v; }
    int sum(int i){ int s=0; for(;i>0;i-=i&-i) s+=bit[i]; return s; }
    int findKth(int k){ 
        int idx=0;
        int mask=1<<20;
        while(mask){
            int next=idx+mask;
            if(next<=n && bit[next]<k){
                k-=bit[next];
                idx=next;
            }
            mask>>=1;
        }
        return idx+1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    Fenwick fw(n);
    for(int i=1;i<=n;i++) fw.add(i,1);

    vector<int> order;
    int alive=n;
    int pos=0; 

    while(alive){
        pos=(pos+k)%alive; 
        int child=fw.findKth(pos+1); 
        order.push_back(child);
        fw.add(child,-1);
        alive--;
    }

    for(int x:order) cout<<x<<" ";
    cout<<"\n";
}