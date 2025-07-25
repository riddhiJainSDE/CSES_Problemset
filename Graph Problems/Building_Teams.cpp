#include <iostream>
#include <vector>
using namespace std;
 
vector<vector<int>> g;
vector<bool> v;
vector<int> r;
bool a = true;
 
void dfs(int x) {
    v[x] = true;
    
    for (int y : g[x]) {
        if (!v[y]) {
            r[y] = 3 - r[x]; 
            dfs(y);
        } else if (r[y] == r[x]) {
            a = false; 
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    v.resize(n + 1, false);
    r.resize(n + 1, -1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            r[i] = 1;  
            dfs(i);
        }
    }
 
    if (a) {
        for (int i = 1; i <= n; i++) {
            cout << r[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }
 
    return 0;
}
