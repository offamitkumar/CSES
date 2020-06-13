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
const int MAXN = (int)1e5+100;
const int MOD = (int)1e9+7;

array<int,4>X{-1,1,0,0};
array<int,4>Y{0,0,-1,1};

int n, m; 
vector<string>graph(n);
vector<vector<bool>>visited;
bool check(int x, int y){
    if(x >= n || y >=m || x<0 || y<0 || visited[x][y] || graph[x][y]=='#'){
        return false;
    }else{
        return true;
    }
}
void dfs(int x, int y){
    visited[x][y] = true;
    for(int i=0;i<4;++i){
        int tempx = x+X[i];
        int tempy = y+Y[i];
        if(check(tempx,tempy)){
            dfs(tempx,tempy);
        }
    }
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

    scanf("%d %d", &n, &m);
    graph.resize(n);
    visited.assign(n , vector<bool>(m,false));
    for(int i=0;i<n;++i){
        cin >> graph[i];
    }
    int counter{};
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(graph[i][j]=='.' && (!visited[i][j])){
                ++counter;
                dfs(i,j);
            }
        }
    }
    cout << counter << '\n';
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}