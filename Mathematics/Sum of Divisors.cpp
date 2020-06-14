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

//  https://discuss.codechef.com/t/sum-of-divisors-of-all-numbers-less-than-n-in-less-than-o-n-time/65944
// 
//
//
// all values from 1 to sqrt(N) will be distinct, so we can calculate
// their sum by running a loop from 1 to sqrt(N)
//
// Now we are claiming that n/i will have only sqrt(N) distinct values
//
//
// because  there exist only two case :
// 1. I <= sqrt(N) , clearly there exist only sqrt(N) such I
// 2. I > sqrt(N) , in this case floor(n/i) < sqrt(N) so again there
// can be at most sqrt(N) values. 

long long APSUM(long long num){
    num %= MOD;
    long long temp = (num * (num+1))%MOD;
    temp *= (MOD+1)/2; // mod inverse of 2 
    temp %= MOD;
    return temp;
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

    long long n; cin >> n;
    long long sum{};
    for(long long i=1; i*i < n; ++i){
        if(n/i==i)
            continue;
        (sum += (n/i)*i)%=MOD;
    }
    for(long long i = 1; i*i <=n;++i){
        long long temp = (APSUM(n/(i)) - APSUM(n/(i+1)))*i;
        (sum += temp)%=MOD;
    }
    cout << (sum % MOD) << '\n'; 
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
