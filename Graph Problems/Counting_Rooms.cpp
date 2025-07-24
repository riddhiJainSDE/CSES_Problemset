#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (grid[x][y] == '#' || vis[x][y]) return;

    vis[x][y] = true;

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    vis.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int rooms = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                ++rooms;
            }
        }
    }

    cout << rooms << endl;
    return 0;
}
