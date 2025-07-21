#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long a=0;
    for(int i=1;i<n;i++)
    {
         if(arr[i]<arr[i-1])
         {
             a+=arr[i-1]-arr[i];
             arr[i]=arr[i-1];
         }
    }
    cout<<a;
}