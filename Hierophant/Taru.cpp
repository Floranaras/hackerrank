#include <bits/stdc++.h>
#define MAX_N 100

using namespace std;

int e, s, y, k, d;
int quality[MAX_N], cost[MAX_N];
int dp[101][101]; 

int solve(int e, int s, int y, int k, int d) 
{
    int min_weaves = (e + s - 1) / s;
    
    if (min_weaves > d) 
        return -1; 

	memset(dp, -1, sizeof(dp));
    
    int remaining_actions = d - min_weaves;
    dp[remaining_actions][y] = 0;
    
    for (int actions = remaining_actions; actions >= 0; actions--) 
	{
        for (int points = 0; points <= y; points++) 
		{
            if (dp[actions][points] == -1) 
				continue;
            
            for (int i = 0; i < k; i++) 
			{
                if (actions > 0 && points >= cost[i]) 
                    dp[actions-1][points-cost[i]] = max(
                        dp[actions-1][points-cost[i]],
                        dp[actions][points] + quality[i]);
            }
        }
    }
    
    int max_quality = 0;
    for (int actions = 0; actions <= remaining_actions; actions++) 
        for (int points = 0; points <= y; points++) 
            max_quality = max(max_quality, dp[actions][points]);
    
    return max_quality;
}

int main() 
{
    cin >> e >> s >> y >> k >> d;
    
    for (int i = 0; i < k; i++) 
        cin >> quality[i] >> cost[i];
    
    int ans = solve(e, s, y, k, d);
    
    if (ans < 0) 
        cout << "Impossible" << endl;
    else 
        cout << ans << endl;
    
    return 0;
}
