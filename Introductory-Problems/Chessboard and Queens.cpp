#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
vector<string>grid(8);
bitset<30>d1 , d2 , col;
bool issafe(int row , int Col){
    if(col[Col]==true){
        return false;
    }
    if(d1[row+Col]){
        return false;
    }
    if(d2[row-Col+7]){
        return false;
    }
    if(grid[row][Col]=='*'){
        return false;
    }
    return true;
}
int get(int n = 0 , int row = 0){
    if(n==8){
        return 1;
    }
    int total_ways{};
    for(int i=0;i<8;++i){
        if(issafe(row , i)){
            col.set(i);
            d1.set(row+i);
            d2.set(row -i + 7);
            total_ways+=get(n+1 , row+1);
            col.reset(i);
            d1.reset(row+i);
            d2.reset(row -i + 7);
        }
    }
    return total_ways;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    d1.reset();
    d2.reset();
    col.reset();
    for(auto&itr:grid){
        cin>>itr;
    }
    cout<<get()<<'\n';
    return 0;
}
