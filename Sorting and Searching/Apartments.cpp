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
    int n, m, k;
    cin >> n >> m >>k;
    vector<int>apartment_desired(n);for(auto&itr:apartment_desired)cin>>itr;
    vector<int>apartment(m);for(auto&itr:apartment)cin>>itr;
    sort(apartment_desired.begin() , apartment_desired.end());
    sort(apartment.begin() , apartment.end());
    int room_allocated{};
    int i = 0 , j = 0;
    while(i<n and j < m){
        if(apartment_desired[i]+k >= apartment[j] and apartment_desired[i]-k <= apartment[j]  ) {
//            cout<<apartment_desired[i] <<" bought "<<apartment[j] << '\n';
            ++i , ++j , ++room_allocated;
        } else if( apartment_desired[i] + k < apartment[j] ) { // if after incrementing by k , current user can't purchase it
            // none of the other house can be purchased by current user , so just change the user
            ++i;
        } else if( apartment_desired[i] - k > apartment[j] ) {
            ++j;
        }
    }
    cout << room_allocated << '\n'; 
    return 0;
}
