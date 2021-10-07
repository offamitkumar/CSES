#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<vector<int>>graph;
bool possible = true;
vector<int>color; 
void dfs(int root) {
    for (auto&node:graph[root]) {
        if (!possible) {
            return; 
        }
        if (color[node] == -1) {
            color[node] = 1^color[root]; 
            dfs (node);
        }
        if (color[node] == color[root]) {
            possible = false; 
            return ;
        }
    }
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n, m; cin >> n >> m; 
    graph.resize(n+1); 
    color.resize(n+1, -1); 
    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v; 
        graph.at(u).push_back(v); 
        graph.at(v).push_back(u);
    }
    for (int i=1; i<=n && possible; ++i) {
        if (color[i] == -1) {
            color[i] = 0; 
            dfs(i);
        }
    }
    if (possible) {
        for (int i=1; i<=n; ++i) {
            cout << color[i]+1 << ' ';
        }
    } else {
        cout << "IMPOSSIBLE"; 
    }
    cout << '\n'; 
    return 0;
}
