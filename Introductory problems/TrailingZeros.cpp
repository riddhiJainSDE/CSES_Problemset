#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int a=0;
    while(n!=0)
    {
       a=a+(n/5);
       n/=5;
    }
   cout<<a;
}
