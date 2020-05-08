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
    string s; cin>>s;
    map<char,int>m;
    for(auto&itr:s){
        m[itr]++;
    }
    int counter{};
    for(auto&itr:m){
        counter+=(itr.second%2);
    }
    if(counter>1){
        cout<<"NO SOLUTION"<<'\n';
    }else{
        if(m.size()==1){
            cout<<string(m.begin()->second , m.begin()->first);
            cout<<'\n';
            return 0;
        }
        string ans{};
        char half_add{};
        bool found = false;
        for(auto&itr:m){

            if(itr.second%2){
                half_add = itr.first;
                found = true;
                itr.second--;
                ans+=string(itr.second/2 , itr.first);
            }else{
                ans+=string(itr.second/2 , itr.first);
            }
        }
        string a = ans;
        if(found){
            a+=half_add;
        }
        reverse(ans.begin() , ans.end());
        a+=ans;
        cout<<a<<'\n';
    }
    return 0;
}
