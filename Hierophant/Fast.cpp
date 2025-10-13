#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<long long> F; 
bool initialized = false; 

int solve(int k, const vector<int>& a) 
{
    if (!initialized) 
	{
        initialized = true;
        int n = a.size();
        F.resize(n);
        
        F[0] = a[0];
        
        long long sum = F[0];
        
        for (int i = 1; i < n; i++) 
		{
            F[i] = (a[i] + sum) % MOD;            
            sum = (sum + F[i]) % MOD;
        }
    }
    
    return (int)F[k];
}

int main() 
{
    int q, n, i, k;
    cin >> q >> n;
    
    vector<int> a(n);
    for (i = 0; i < n; i++) 
        cin >> a[i];
    
    for (i = 0; i < q; i++) 
	{
        scanf("%d", &k);
        printf("%d\n", solve(k, a));
    }
    
    return 0;
}
