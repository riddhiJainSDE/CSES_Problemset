#include <bits/stdc++.h>
using namespace std;

int cycle_start = -1, cycle_end = -1;

bool dfs(int node, int par, vector<int>& par_arr, vector<bool>& vis, vector<vector<int>>& adj) {
    vis[node] = true;
    for (int eigh : adj[node]) {
        if (!vis[eigh]) {
            par_arr[eigh] = node;
            if (dfs(eigh, node, par_arr, vis, adj))
                return true;
        }
        else if (eigh != par) {
            cycle_end = node;
            cycle_start = eigh;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> vis(n + 1, false);
    vector<int> par(n + 1, -1);
    bool flag = false;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, par, vis, adj)) {
                flag = true;
                break;
            }
        }
    }

    if (!flag) {
        cout << "IMPOSSIBLE";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = par[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (int x : cycle) cout << x << " ";
    }

    return 0;
}
