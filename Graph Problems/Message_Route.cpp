#include <iostream>
#include <vector>
using namespace std;
 
vector<vector<int>> g;
vector<bool> v;
 
void dfs(int x) {
    v[x] = true;
    for (int y : g[x]) {
        if (!v[y]) dfs(y);
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    g.resize(n + 1);
    v.resize(n + 1, false);
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    vector<int> r;
 
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            r.push_back(i);
            dfs(i);
        }
    }
 
    int k = r.size() - 1;
    cout << k << endl;
 
    for (int i = 1; i < r.size(); i++) {
        cout << r[i - 1] << " " << r[i] << endl;
    }
 
    return 0;
}
