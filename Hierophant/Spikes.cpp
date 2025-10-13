#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    string s;
    
    cin >> n >> s;
    
    vector<bool> has_spike(n + 1, false);
    
    for (size_t i = 0; i < s.length(); i++) 
        if (s[i] == '1') 
            has_spike[i + 1] = true;
    
    has_spike[1] = has_spike[n] = false;
    
    vector<int> dp(n + 1, INT_MAX);
    
    dp[1] = 0;
    
    for (int i = 1; i < n; i++) 
	{
        if (dp[i] != INT_MAX) 
		{
            if (i + 1 <= n && !has_spike[i + 1]) 
                dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            
            if (i + 2 <= n && !has_spike[i + 2]) 
                dp[i + 2] = min(dp[i + 2], dp[i] + 1);
        }
    }
    
    if (dp[n] == INT_MAX) 
        cout << -1 << endl;
    else 
        cout << dp[n] << endl;
    
    return 0;
}
