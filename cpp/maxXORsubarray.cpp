#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    Node* child[2];
    Node() {
        child[0] = child[1] = NULL;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(ll num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new Node();
            node = node->child[bit];
        }
    }

    ll query(ll num) {
        Node* node = root;
        ll maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->child[1 - bit]) {
                maxXor |= (1LL << i);
                node = node->child[1 - bit];
            } else {
                node = node->child[bit];
            }
        }
        return maxXor;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    Trie trie;
    trie.insert(0); 

    ll prefix = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        prefix ^= a[i];

        ans = max(ans, trie.query(prefix));

        trie.insert(prefix);
    }

    cout << ans << '\n';
}