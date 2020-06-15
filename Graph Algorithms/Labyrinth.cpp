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
const int MAXN = (int)1e3+100;
const int MOD = (int)1e9+7;
int n , m; 
vector<string>graph;
int visited[MAXN][MAXN];
char path[MAXN][MAXN];

bool check(int x , int y){
    if( x<0 || y <0 || x>=n || y >= m || visited[x][y]==true || graph[x][y]=='#' ) {
        return false;
    }
    return true;
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

    scanf("%d %d",&n,&m);
    graph.resize(n);
    pair<int,int> start , dest;
    for(int i=0;i<n;++i){
        cin >> graph[i];
        for(int j=0;j<m;++j){
            path[i][j] = ' ';
            if(graph[i][j]=='A'){
                start = make_pair(i,j);
            }else if(graph[i][j]=='B'){
                dest = make_pair(i,j);
            }
        }
    }
    queue<int>q;
    q.push(start.first);
    q.push(start.second);
    visited[start.first][start.second]=true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        // left 
        if(check(x+1 ,y)){
            path[x+1][y]='U';
            visited[x+1][y] = true;
            q.push(x+1);
            q.push(y);
        }
        if(check(x-1 ,y)){
            path[x-1][y]='D';
            visited[x-1][y] = true;
            q.push(x-1);
            q.push(y);
        }
        if(check(x ,y-1)){
            path[x][y-1] = 'R';
            visited[x][y-1] = true;
            q.push(x);
            q.push(y-1);
        }
        if(check(x ,y+1)){
            path[x][y+1] = 'L';
            visited[x][y+1] = true;
            q.push(x);
            q.push(y+1);
        }
    }
//     for(int i=0;i<n; ++i){
//         for(int j=0;j<m;++j){
//             if(graph[i][j]=='A'){
//                 cout <<'A'<<' ';
//             }else{
//                 cout << path[i][j]<<' ';
//             }
//         }
//         puts("");
//     }
    if(!visited[dest.first][dest.second]){
        cout <<"NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n'; 
    int cx=dest.first , cy=dest.second;
    string p="";
    while(graph[cx][cy]!='A'){
        if(path[cx][cy]=='L'){
            p+='R';
            cy-=1;
        }else if(path[cx][cy]=='R'){
            p+='L';
            cy+=1;
        }else if(path[cx][cy]=='U'){
            p+='D';
            cx-=1;
        }else if(path[cx][cy]=='D'){
            p+='U';
            cx+=1;
        }

    }
    cout << p.size() << '\n';
    reverse(p.begin() , p.end());
    cout << p << '\n'; 
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
