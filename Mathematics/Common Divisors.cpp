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
//  #include <numeric>
//  #include <utility>

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

//  #include <climits>
//  #include <cstring>
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
const int MAXM = (int)1e5+100;
const int MAXN = (int)(1*1e6)+500;
const int MOD = (int)1e9+7;
vector<int>freq(MAXN);
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    long long n; scanf("%lld",&n);
    long long max_ele=1ll;
    long long max_ans_found=1ll;
    for(long long x{0},i=0ll;i<n;++i){
        scanf("%lld",&x);
        freq[x]++;
        max_ele = max(max_ele , x);
        if(freq[x]>=2ll){
            max_ans_found = max(max_ans_found , x);
        }
    }
    for(long long i=2ll; i<=max_ele/2ll; ++i){
        long long div_counter{};
        for(long long j=i;j<=max_ele; j+=i){
            if(freq[j]){
                div_counter++;
            }
        }
        if(div_counter>=2ll){
            max_ans_found = max(max_ans_found, i);
        }
    }
    printf("%lld\n",max_ans_found);
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
