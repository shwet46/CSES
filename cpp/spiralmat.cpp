#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    ll t, x, y;
    cin >> t;
    while (t--) {
        cin >> y >> x;
        ll maxi = max(x, y), square = (maxi - 1) * (maxi - 1);
        cout << (maxi % 2 == 0 ? (x > y ? square + y : maxi * maxi - x + 1)
                               : (x > y ? maxi * maxi - y + 1 : square + x)) << endl;
    }
    return 0;
}