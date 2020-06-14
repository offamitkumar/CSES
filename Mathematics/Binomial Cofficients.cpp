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
const int MOD = (int)1e9+7;


const int MAXN = (int)1e6+100;
long long factorial[MAXN];
void mod_factorial(int uMOD = (int)1e9+7){
    factorial[0] =1;
    for(int i=1;i <= MAXN; ++i){
        (factorial[i] = factorial[i-1] * i) %= uMOD;
    }
}


long long modInverse(long long a, long long m) { 
    long long m0 = m; 
    long long y = 0ll, x = 1ll; 
    if (m == 1ll) return 0ll; 
    while (a > 1ll) { 
        long long q = a / m; 
        long long t = m; 
        m = a % m, a = t; t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0ll) x += m0; 
    return x; 
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

    mod_factorial(); 
    int n; cin >> n; 
    while(n--){
        int a, b; cin >> a >> b; 
        long long down = modInverse((factorial[b] * factorial[abs(a-b)])%MOD , MOD);
        cout << (factorial[a] * down) %MOD << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
