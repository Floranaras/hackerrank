#include <bits/stdc++.h>

using namespace std;

long long solve(int n, int a, int b, int c, int k, int slippery[]){
    const long long INF = 1e18;
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
    
    dp[1][0] = 0;
    
    set<int> slippery_set;
    for(int i = 0; i < k; i++){
        slippery_set.insert(slippery[i]);
    }
    
    for(int i = 1; i < n; i++){
        bool is_slippery = slippery_set.count(i) > 0;
        
        for(int e = 0; e <= n; e++){
            if(dp[i][e] == INF) continue;
            
            if(e + 1 <= n){
                dp[i + 1][e + 1] = min(dp[i + 1][e + 1], dp[i][e] + a);
            }
            
            if(e >= 1){
                long long dash_time;
                if(is_slippery){
                    dash_time = b + c;
                    if(e - 1 >= 0){
                        dp[i][e - 1] = min(dp[i][e - 1], dp[i][e] + dash_time);
                    }
                } else {
                    dash_time = b;
                    if(e - 1 >= 0){
                        dp[i + 1][e - 1] = min(dp[i + 1][e - 1], dp[i][e] + dash_time);
                    }
                }
            }
        }
    }
    
    long long ans = INF;
    for(int e = 0; e <= n; e++)
	{
        ans = min(ans, dp[n][e]);
    }
    
    return ans;
}

int main() 
{
    int n, a, b, c, k;
    cin >> n >> a >> b >> c >> k;
    
    int slippery[2000];
    for(int i = 0; i < k; i++)
	{
        cin >> slippery[i];
    }
    
    cout << solve(n, a, b, c, k, slippery) << endl;
    
    return 0;
}
