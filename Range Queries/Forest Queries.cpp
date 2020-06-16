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
const int MAXN = (int)1100;
const int MOD = (int)1e9+7;
int n,m;
vector<string>grid;
int dummy_tree[4*MAXN][4*MAXN];
int seg_tree[4*MAXN][4*MAXN];

void row_seg(int current_node, int start , int end , int row){
    if(start == end){
        dummy_tree[row][current_node] = (grid[row][start] == '*');
        return ;
    }
    int mid = (start + end)/2;
    row_seg(2*current_node , start , mid , row);
    row_seg(2*current_node+1, mid+1 , end , row);
    dummy_tree[row][current_node]= dummy_tree[row][2*current_node] + dummy_tree[row][2*current_node+1];
    return ;
}

void build(int current_node ,int start , int end){
    if(start == end){
        for(int i=0; i<=4*n; ++i){
            seg_tree[current_node][i] = dummy_tree[start][i];
        }
        return ;
    }
    int mid = (start + end) /2;
    build(current_node * 2, start, mid );
    build(current_node*2+1 , mid+1 , end);
    for(int i=0;i<4*n;++i){
        seg_tree[current_node][i] = seg_tree[2*current_node][i] + seg_tree[2*current_node+1][i];
    }
    return ;
}

int col_query(int current_node , int start , int end , int colOne , int colTwo , int row){
    if(colTwo < start || colOne > end){
        return 0;
    }
    if(colOne <= start && end <= colTwo){
        return seg_tree[row][current_node];
    }
    int mid = (start + end)/2;
    int leftAns = col_query(current_node*2 , start , mid , colOne , colTwo , row);
    int rightAns = col_query(current_node*2+1 , mid+1 , end , colOne, colTwo ,row);
    return leftAns + rightAns;
}

int query(int current_node , int start , int end , int rowOne ,int colOne , int rowTwo , int colTwo){
    if(rowTwo < start || rowOne > end){
        return 0;
    }
    if(rowOne <= start && end <= rowTwo){
        // we want answer from tree which is at level "current_node"
        return col_query(1 , 0 , n-1 , colOne , colTwo , current_node);
    }
    int mid = (start + end) /2 ;
    int leftAns = query(current_node *2 , start , mid , rowOne , colOne , rowTwo , colTwo);
    int rightAns = query(current_node*2+1, mid+1 , end , rowOne , colOne , rowTwo , colTwo);
    return leftAns + rightAns;
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
    cin >> n >> m;
    grid.resize(n);
    for(int i=0;i<n;++i){
        cin >> grid[i];
        row_seg(1 , 0 , n-1 , i);
    }
    build(1 , 0 , n-1);

    while(m--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        --a,--b,--c,--d;
        cout << query(1 , 0 , n-1 , a , b , c , d) << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
