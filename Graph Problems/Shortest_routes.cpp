#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a1, a2;
        long long w;
        cin >> a1 >> a2 >> w;
        adj[a1 - 1].push_back({a2 - 1, w});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> ans(n, LLONG_MAX);
    ans[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        long long w = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (w > ans[node]) continue;
        for (auto [adjnode, weight] : adj[node]) {
            if (ans[node] + weight < ans[adjnode]) {
                ans[adjnode] = ans[node] + weight;
                pq.push({ans[adjnode], adjnode});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == LLONG_MAX) cout << -1;
        else cout << ans[i];
        cout << (i == n - 1 ? '\n' : ' ');
    }
    return 0;
}