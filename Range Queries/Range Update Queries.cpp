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
const int MAXN = (int)2 * 1e5+10000;
const int MOD = (int)1e9+7;

long long seg_tree[4 * MAXN];
long long arr[MAXN];
long long lazy_tree[4 * MAXN];

void build(long long current_node , long long start , long long end ){
    if(start > end){
        return ;
    }
    if(start == end ){
        seg_tree[current_node] = arr[start];
        return;
    }
    long long mid = (start + end) / 2ll;
    build(2*current_node , start , mid);
    build(2*current_node +1ll , mid + 1ll, end);
    seg_tree[current_node] = 0ll;
    lazy_tree[current_node] = 0ll;
}
void push_updates(long long current_node , long long start , long long end){
    if(start == end){
        seg_tree[current_node] += lazy_tree[current_node];
    }
    if(start != end){
        lazy_tree[2*current_node] += lazy_tree[current_node];
        lazy_tree[2*current_node + 1] += lazy_tree[current_node];
    }
    lazy_tree[current_node] = 0ll;
}
void update(long long current_node , long long start , long long end , long long q_start , long long q_end , long long value){
    if( start > q_end || end < q_start || start > end ){
        return ;
    }
    if(lazy_tree[current_node] != 0ll){
        push_updates(current_node , start , end);
    }
    if(start >= q_start && end <= q_end){
        if(start == end){
            seg_tree[current_node] += value;
        }else{
            lazy_tree[current_node] += value;
        }
        return;
    }
    long long mid = (start + end)/2;
    update(2*current_node , start , mid , q_start , q_end , value);
    update(2*current_node+1 , mid+1 ,  end , q_start , q_end , value);
}
long long query(long long current_node , long long start , long long end , long long pos){
    if(lazy_tree[current_node]!=0){
        push_updates(current_node , start , end);
    }
    if(start > pos || end < pos){
        return -1;
    }
    if(start == pos && end == pos){
        return seg_tree[current_node];
    }
    long long mid = (start + end) /2;
    if(mid >= pos){
        return query(2*current_node , start , mid , pos);
    }else{
        return query(2*current_node +1 , mid+1 , end , pos);
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

    long long n, q; cin >> n >> q; 
    for(long long i=0;i<n;++i){
        cin >> arr[i];
    }
    build(1 , 0 ,n-1);
    while(q--){
        long long type; cin >> type;
        if(type == 1){
            long long a, b, c; cin >> a >> b >> c;
            --a , --b;
            update(1 , 0 , n-1 , a, b, c);
        }else{
            long long a; cin >> a; 
            --a;
            cout << query(1 , 0 , n-1 , a) << '\n';
        }
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
