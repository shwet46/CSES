#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi x(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pos[x[i]] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) rounds++;
    }

    auto adjust = [&](int k, int delta) {
        if (k >= 1 && k <= n) {
            if (pos[k - 1] > pos[k]) rounds += delta;
        }
    };

    while (m--) {
        int a, b;
        cin >> a >> b;

        int va = x[a], vb = x[b];


        adjust(va, -1);
        adjust(vb, -1);
        if (va + 1 != vb) adjust(va + 1, -1);
        if (vb + 1 != va) adjust(vb + 1, -1);

        swap(x[a], x[b]);
        pos[va] = b;
        pos[vb] = a;


        adjust(va, +1);
        adjust(vb, +1);
        if (va + 1 != vb) adjust(va + 1, +1);
        if (vb + 1 != va) adjust(vb + 1, +1);

        cout << rounds << "\n";
    }

    return 0;
}

/* 
          /\_/\
         (='.'=)
         (")_(")
*/