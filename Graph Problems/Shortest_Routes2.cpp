#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    for(int i = 0; i < n; i++) d[i][i] = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a; --b;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(d[i][k] == INF) continue;
            for(int j = 0; j < n; j++){
                ll nd = d[i][k] + d[k][j];
                if(nd < d[i][j]) d[i][j] = nd;
            }
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        ll ans = d[a-1][b-1];
        if(ans == INF) cout << -1 << '\n';
        else
        {
        if(q==0) cout<<ans;
        else cout << ans << '\n';
        }
    }
    return 0;
}