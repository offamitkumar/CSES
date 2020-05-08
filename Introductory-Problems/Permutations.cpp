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
    int n;cin>>n;
    if(n==1){
        cout<<1<<'\n';
    }else if(n<4){
        cout<<"NO SOLUTION"<<'\n';
    }else if(n==4){
        cout<<"2 4 1 3"<<'\n';
    }else{
        for(auto i=1;i<=n;i+=2){
            cout<<i<<' ';
        }
        for(auto i=2;i<=n;i+=2){
            cout<<i<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
