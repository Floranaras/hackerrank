#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

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
    
    vector<long long> dp(n + 1, 0);
    
    dp[1] = 1;
    
    for (int i = 1; i < n; i++) 
	{
        if (dp[i] > 0) 
		{
            if (i + 1 <= n && !has_spike[i + 1]) 
                dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
            
            if (i + 2 <= n && !has_spike[i + 2]) 
                dp[i + 2] = (dp[i + 2] + dp[i]) % MOD;
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
