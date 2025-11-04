#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    int k;
    cin >> n >> k;

    vector<ll> primes(k);
    for (int i = 0; i < k; i++) {
        cin >> primes[i];
    }

    ll answer = 0;
    for (int b = 1; b < (1 << k); b++) {
        ll prod = 1;
        bool fail = false;

        for (int i = 0; i < k; i++) {
            if (b & (1 << i)) {
                if (primes[i] > n / prod) fail = true;
                prod *= primes[i];
            }
        }

        if (fail) continue;

        ll add = n / prod;
        if (__builtin_parity(b) == 0) add = -add;
        answer += add;
    }

    cout << answer << "\n";

 
    return 0;
}

/* 

          /\_/\     
         (='.'=)    
         (")_(")        

*/