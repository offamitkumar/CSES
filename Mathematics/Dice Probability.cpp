#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n, a, b; cin >> n >> a >> b; 
    vector<vector<double>> dp(6*n+10 , vector<double>(6*n+10));
    dp[0][0] = 1; 
    for(int i=1; i<=n; ++i){
        for(int j = 1; j<= 6*n; ++j){
            for(int k=1; k<=6; ++k){
                if(j -k >=0 ){
                    dp[i][j] += dp[i-1][j-k];
                }
            }
            dp[i][j]/=6.0;
        }
    }
    double sum{};
    for(int i=a; i<=b; ++i){
        sum+=dp[n][i];
    }
    cout << fixed << setprecision(6) << sum << '\n'; 
    return 0;
}
