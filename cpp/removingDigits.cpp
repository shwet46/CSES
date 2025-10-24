#include<bits/stdc++.h>
using namespace std;    
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int steps = 0;
    while (n) {
        int number = n;
        int max_digit = 0;
        while (number) {
            int digit = number % 10;
            max_digit = max(max_digit, digit);
            number /= 10;
        }
        n -= max_digit;
        steps++;
    }

    cout << steps << "\n";
  
    return 0;
}