#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    vector<vector<int>> times(n, vector<int>(n + 1));
    
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j <= n; j++) 
		{
            cin >> times[i][j];
        }
    }
    
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0; 
    
    for (int mask = 0; mask < (1 << n); mask++) 
	{
        if (dp[mask] == INT_MAX) continue;
        
        for (int next = 0; next < n; next++) 
		{
            if (mask & (1 << next)) continue;
            
            int best_time = times[next][0];
            
            for (int prev = 0; prev < n; prev++) 
			{
                if (mask & (1 << prev)) 
				{
                    best_time = min(best_time, times[next][prev + 1]);
                }
            }
            
            int new_mask = mask | (1 << next);
            dp[new_mask] = min(dp[new_mask], dp[mask] + best_time);
        }
    }
    
    cout << dp[(1 << n) - 1] << endl;
    
    return 0;
}
