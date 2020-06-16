//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

#include <iostream>
#include <algorithm> 
#include <string> 
//  #include <sstream> 
//  #include <fstream>
//  #include <iomanip> 
#include <chrono> 
#include <numeric>
#include <utility>
#include <functional>

#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <array>
//  #include <unordered_map>
//  #include <unordered_set>
#include <set>
#include <map>
//  #include <deque>

#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>
using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//                   TypeInfo ,
//                   null_type ,
//                   less<TypeInfo> ,
//                   rb_tree_tag ,
//                   tree_order_statistics_node_update 
//       > ;

void debug_out() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void debug_out(HEAD H, TAIL... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef HELL_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 

const int MAXM = (int)1e5+100;
const int MAXN = (int)2*1e5+200;
const int MOD = (int)1e9+7;

vector<int>parent(MAXN);

int find_parent(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    iota(parent.begin() , parent.end() , 0);
    int n,m; cin >> n >> m; 
    for(int i=0;i<m;++i){
        int u ,v; cin >> u >> v;
        u = find_parent(u);
        v = find_parent(v);
        parent[u] = v;
    }
    vector<pair<int,int>>roads;
    int a = find_parent(1);
    for(int i=2;i<=n; ++i){
        int u = find_parent(i);
        if(a  != u){
            parent[u] = a;
            roads.push_back(make_pair(1 , i));
        }
    }
    cout << roads.size() << '\n';
    for(auto&itr:roads){
        cout << itr.first <<' ' << itr.second << '\n';
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
