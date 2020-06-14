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
const int MAXN = (int)2e5+100;
const int MOD = (int)1e9+7;


// default size is considered MAXN
long long arr[MAXN];
long long seg_tree[4*MAXN];

// FILL THIS FUNCTION 
inline long long funct(const long long &value_one , const long long &value_two){
    return value_one ^ value_two; // ERROR POINT 1
}


// BUILD THE SEGMENT TREE 
void build(int current_node , int left_, int right_){
    if(left_ == right_) {
        seg_tree[current_node] = arr[left_];
        return ;
    }
    int mid_point = left_ + (right_ - left_) / 2;
    build(2*current_node, left_ , mid_point);
    build(2*current_node+1, mid_point+1 , right_);
    seg_tree[current_node] = funct(seg_tree[2*current_node], seg_tree[2*current_node+1]);
    return ;
}

// RANGE QUERIES 
long long query(int current_node , int start_, int end_, int q_start, int q_end){
    if(q_start > end_ || q_end < start_ || start_ > end_){
        return 0; // ERROR POINT 2 , CHANGE WITH MIN OR MAX QUERY 
    }
    if(start_ == end_){
        return seg_tree[current_node];
    }
    if(q_start <= start_ && end_ <=q_end){
        return seg_tree[current_node];
    }
    int mid_point = start_ + (end_ - start_) / 2;
    long long left_ans = query(current_node*2,start_,mid_point,q_start, q_end);
    long long right_ans= query(current_node*2+1,mid_point+1,end_,q_start, q_end);
    return funct(left_ans, right_ans);
}

// FOR POINT UPDATE  
void update(int current_node , int start , int end , int pos , int value){
    if(start > end || pos > end || pos < start ){
        return ;
    }
    if(start == pos && end == pos){
        seg_tree[current_node] = value;
        return ;
    }
    int mid = (start + end) /2;
    update(current_node*2 , start , mid , pos , value);
    update(current_node*2+1, mid+1 , end , pos , value);
    seg_tree[current_node] = funct(seg_tree[2*current_node] , seg_tree[2*current_node+1]);
}

// 0 BASED INDEXING , BE CAREFUL WITH QUESTION QUERY TYPE
// BUILD (CURRENT_NODE, ARRAY_START_POINT , ARRAY_END_POINT);
// QUERY(CURRENT_NODE, ARRAY_START_POINT , ARRAY_END_POINT, Q_START, Q_END);
// UPDATE(CURRENT_NODE, ARRAY_START_POINT, ARRAY_END_POINT, POSITION, VALUE);


int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int n, q; scanf("%d %d",&n,&q);
    for(int i=0;i<n;++i){ scanf("%lld ",&arr[i]); }
    build(1 , 0 , n-1 );
    while(q--){
        int a, b; scanf("%d %d",&a , &b);
        --a,--b;
        printf("%lld\n",query(1,0,n-1,a,b));
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
