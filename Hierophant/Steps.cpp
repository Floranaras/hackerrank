#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int solve(int n) 
{
    if (n % 2 == 1) 
		return 0;
    
    n = n / 2;
    
    vector<long long> catalan(n + 1, 0);
    catalan[0] = 1;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < i; j++) 
            catalan[i] = (catalan[i] + (catalan[j] * catalan[i - j - 1]) % MOD) % MOD;
    
    return catalan[n];
}

int main() 
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
