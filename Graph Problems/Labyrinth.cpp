#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
pair<int, int> start, endPos;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
string dir = "UDLR";

bool isValid(int x, int y, vector<vector<bool>>& vis) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !vis[x][y];
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') endPos = {i, j};
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;

    vis[start.first][start.second] = true;
    q.push(start);

    bool found = false;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == endPos.first && y == endPos.second) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, vis)) {
                vis[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO";
    } else {
        string path;
        pair<int, int> curr = endPos;
        while (curr != start) {
            auto [px, py] = parent[curr.first][curr.second];
            for (int i = 0; i < 4; i++) {
                if (px + dx[i] == curr.first && py + dy[i] == curr.second) {
                    path += dir[i];
                    break;
                }
            }
            curr = {px, py};
        }
        reverse(path.begin(), path.end());
        cout << "YES\n" << path.length() << "\n" << path ;
    }

    return 0;
}
