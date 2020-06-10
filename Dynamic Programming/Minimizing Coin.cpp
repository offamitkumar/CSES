//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
  #include <algorithm>
//  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
  #include <numeric>
  #include <utility>

//  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
//  #include <map>
//  #include <deque>

  #include <climits>
  #include <cstring>
//  #include <cmath>
//  #include <cassert>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
const int MAXM = (int)111;
const int MAXN = (int)1e6+100;
const int MOD = (int)1e9+7;
int arr[MAXN];
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int n, c; scanf("%d %d",&n,&c);
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    vector<int>dp(c+10,(int)1e8);
    dp[0] = 0;
    for(int i=1;i<=c;++i){
        for(int j=0;j<n;++j){
            if(i >= arr[j])
                dp[i] = min(dp[i] , dp[i-arr[j]]+1);
        }
    }
    printf("%d\n",(dp[c] == (int)1e8) ? -1 : dp[c]);
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
