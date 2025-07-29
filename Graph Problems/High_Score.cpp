#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = LLONG_MIN/4;
struct Edge { int u, v; ll w; };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<vector<int>> rev(n+1);
    for(int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        rev[edges[i].v].push_back(edges[i].u);
    }
    vector<bool> canReach(n+1,false);
    queue<int> q;
    canReach[n] = true;
    q.push(n);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int p: rev[u]){
            if(!canReach[p]){
                canReach[p] = true;
                q.push(p);
            }
        }
    }
    vector<ll> dist(n+1, NEG_INF);
    dist[1] = 0;
    for(int i = 0; i < n-1; i++){
        for(auto &e: edges){
            if(dist[e.u] > NEG_INF){
                dist[e.v] = max(dist[e.v], dist[e.u] + e.w);
            }
        }
    }
    for(auto &e: edges){
        if(dist[e.u] > NEG_INF && dist[e.u] + e.w > dist[e.v] && canReach[e.v]){
            cout << -1;
            return 0;
        }
    }
    cout << dist[n];
    return 0;
}
