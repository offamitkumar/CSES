//  Author : Amit Kumar 

#include <iostream>
#include <algorithm> 
#include <string> 
#include <sstream>
#include <fstream>
#include <iomanip> 
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
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <deque>
#include <list>


#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
using namespace __gnu_pbds;
template<typename TypeInfo>
using new_set = tree< 
/* ob.order_of_key(element) -> number of element strictly less than element
 * *ob.find_by_order(n) ->  nth element in increasing order
 */
         TypeInfo ,
         null_type ,
         less<TypeInfo> ,
         rb_tree_tag ,
         tree_order_statistics_node_update 
 > ;

void debug_out() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void debug_out(HEAD H, TAIL... T) {
  cerr << " " << (H);
  debug_out(T...);
}
 
#ifdef HELL_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 


const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int MOD  = (int)1e9+7;

vector<bool>visited;
vector<int>parent;
vector<vector<int>>graph;

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            //
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int n , m; cin >> n >> m;
    parent.assign(n+1,-1);
    visited.assign(n+1,false);
    graph.resize(n+1);
    for(int i=0;i<m;++i){
        int u , v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int>q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == n){
            break;
        }
        for(auto&itr:graph[node]){
            if(!visited[itr]){
                q.push(itr);
                visited[itr] = true;
                parent[itr] = node;
            }
        }
    }
    if(visited[n]==false){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    int x = n;
    stack<int>s;
    while(x != -1){
        s.push(x);
        x = parent[x];
    }
    cout << s.size() << '\n';
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
