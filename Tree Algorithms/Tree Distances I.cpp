#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>dist ,child , ans;
vector<vector<int>>graph; 
void dfs1(int node = 1 , int par = 0) {
    for (auto&itr:graph[node] ) {
        if (itr != par) {
            dfs1(itr, node);
            if (dist[itr] +1 > dist[node]) {
                child[node] = dist[node]; 
                dist[node] = dist[itr]+1;
            } else {
                child[node] = max(dist[itr]+1, child[node]);
            }
        }
    }
}
void dfs2(int node=1 , int par = 0, int d_par = 0) {
    ans[node] = max(dist[node], d_par); 
    for (auto&itr:graph[node]) {
        if (itr != par) {
            if (dist[itr] +1 == dist[node]) {
                dfs2(itr, node , max(d_par , child[node])+1); 
            } else {
                dfs2(itr , node , ans[node]+1); 
            }
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
    int n; cin >> n; 
    dist.resize(n+10,0);
    child.resize(n+10,0);
    ans.resize(n+10,0);
    graph.resize(n+10);
    for (int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v; 
        graph.at(u).push_back(v); 
        graph.at(v).push_back(u);
    }
    dfs1();
    dfs2();
    for (int i=1; i<=n; ++i){
        cout << ans[i] << ' ';
    }
    cout << '\n'; 
    return 0;
}
