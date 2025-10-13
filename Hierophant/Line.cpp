#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int times[400][400];

int solve(int n, int m, int k) 
{
    vector<vector<int>> dp(n, vector<int>(m, INF));
    
    for (int i = 0; i < m; i++) 
        dp[0][i] = times[i][0];
    
    for (int level = 1; level < n; level++) 
	{
        for (int line = 0; line < m; line++) 
		{
            dp[level][line] = dp[level-1][line] + times[line][level];
            
            if (line > 0) 
                dp[level][line] = min(dp[level][line], 
                                    dp[level-1][line-1] + k + times[line][level]);
            
            if (line < m-1) 
                dp[level][line] = min(dp[level][line], 
                                    dp[level-1][line+1] + k + times[line][level]);
        }
    }
    
    int minTime = INF;
    for (int line = 0; line < m; line++) 
        minTime = min(minTime, dp[n-1][line]);
    
    return minTime;
}

int main() 
{
    int n, m, k, i, j;
    cin >> n >> m >> k;
    
    for (i = 0; i < n; i++) 
        for (j = 0; j < m; j++) 
            cin >> times[j][i]; 
    
    cout << solve(n, m, k) << endl;
    return 0;
}
