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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n , x; cin>>n>>x;
    vector<int>v(n); for(auto&itr:v)cin>>itr;
    sort(v.begin() , v.end() );
    int i= 0 ,j = v.size() -1;
    int needed{};
    while(i<=j){
        ++needed ;
        if(v[i]+v[j]<=x){
           ++i , --j;
           continue;
        }
        --j;
    }
    cout << needed << '\n';
    return 0;
}
