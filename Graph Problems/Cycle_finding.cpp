#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    vector<ll> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int x = -1;

    for (int i = 1; i <= n; ++i) {
        x = -1;
        for (auto& [a, b, c] : edges) {
            if (dist[b] > dist[a] + c) {
                dist[b] = dist[a] + c;
                parent[b] = a;
                x = b;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        for (int i = 0; i < n; ++i)
            x = parent[x];

        int first = x;
        vector<int> cycle;
        cycle.push_back(first);

        int cur = parent[first];
        while (cur != first) {
            cycle.push_back(cur);
            cur = parent[cur];
        }
        cycle.push_back(first);
        reverse(cycle.begin(), cycle.end());

        for (int node : cycle)
            cout << node << " ";
        cout << "\n";
    }

    return 0;
}
