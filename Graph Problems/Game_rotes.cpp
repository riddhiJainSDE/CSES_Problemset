#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    vector<int> in(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        in[v]++;
    }

    vector<int> count(n, 0);
    const int mod = 1e9 + 7;
    count[0] = 1; 

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int v : adj[node]) {
            count[v] = (count[v] + count[node]) % mod;
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << count[n - 1] << endl;
    return 0;
}
