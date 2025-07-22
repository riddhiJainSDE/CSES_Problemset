#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int mod = 1e9 + 7;
    ll a = 1, b = 2;
    while (n) {
        if (n & 1) a = (a * b) % mod;
        b = (b * b) % mod;
        n >>= 1;
    }
    cout << a;
}
