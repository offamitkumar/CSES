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


int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    long long n , m; scanf("%lld %lld",&n,&m);
    vector<vector<long long>>dp(n+1 ,vector<long long>(m+1,0));
    for(long long i=0;i<n;++i){
        long long m_val; cin >> m_val; 
        if(i==0){
            if(m_val == 0){
                fill(dp[i].begin() , dp[i].end() , 1);
            }else{
                dp[i][m_val] = 1;
            }
        }else{
            if(m_val == 0){
                for(long long k=1;k<=m;++k){
                    for(auto&itr:{k,k+1,k-1}){
                        if(itr >=1 and itr <=m){
                            (dp[i][k] += dp[i-1][itr])%=MOD;
                        }
                    }
                }
            }else{
                for(auto&itr:{m_val , m_val+1 , m_val-1}){
                    if(itr >=1 and itr<=m){
                        (dp[i][m_val] += dp[i-1][itr])%=MOD;
                    }
                }
            }
        }
    }
    long long total_ways{};
    for(long long i=1;i<=m;++i){
        (total_ways += dp[n-1][i])%=MOD;
    }
    cout << total_ways << '\n'; 
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
