#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        ll n = max(y, x);
        ll val;
        if (n % 2 == 0) {
            if (y == n) val = n * n - x + 1;
            else val = (n - 1) * (n - 1) + y;
        } else {
            if (x == n) val = n * n - y + 1;
            else val = (n - 1) * (n - 1) + x;
        }
        cout << val << '\n';
    }
    return 0;
}
