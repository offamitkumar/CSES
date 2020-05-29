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
#include <unordered_map>
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
#define MOD (int64_t)1000000007
#define MAXN (int)1e6+10
int64_t total_ways_to_reach[MAXN];
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; scanf("%d", &n);
    total_ways_to_reach[0] = 1;
    for (int j=1; j<=n; ++j) {
        total_ways_to_reach[j] = (int64_t)0;
        for (int i = 1; i <= 6 && j - i >= 0 ; ++i ){
            (total_ways_to_reach[j] += total_ways_to_reach[j-i])%=MOD;
        }
    }
    cout << (total_ways_to_reach[n])%MOD << '\n'; 
    return 0;
}
