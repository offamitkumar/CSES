#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>dist;
vector<vector<pair<int,int>>> graph;
void dij(int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push(make_pair(0, n)); 
    while(!pq.empty()){
        auto [d , node] = pq.top(); pq.pop();
        if(dist.at(node) == LONG_MAX){
            dist.at(node) = d;
            for(auto&itr:graph.at(node)){
                pq.push(make_pair(dist.at(node)+itr.second, itr.first));
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
    int n , m; cin >> n >> m; 
    dist.resize(n+1 , LONG_MAX);
    graph.resize(n+1);
    pair<int,int>p;
    for(int i{},u; i < m; ++i){
        cin >>u >> p.first >> p.second;
        graph.at(u).emplace_back(p);
    }
    dij(1);
    for(int i=1; i<=n;++i){
        cout << dist.at(i) << ' ';
    }
    cout << '\n';
    return 0;
}
