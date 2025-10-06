#include <stdio.h>

#define MAX_N 100000

int values[MAX_N];
long long dp[1000];

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void read_values(int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);
}

long long compute_take_value(int i, int k, int dp_size)
{
    long long take = values[i];

    if (i > k)
    {
        int skip_idx = (i - k - 1) % dp_size;
        take += dp[skip_idx];
    }

    return take;
}

long long solve(int n, int k)
{
    if (n == 0)
        return 0;

    if (n == 1) 
        return values[0];
    
    int dp_size = min(n, k + 2);
    
    for (int i = 0; i < dp_size; i++)
        dp[i] = 0;

    dp[0] = values[0];
    
    for (int i = 1; i < n; i++)
    {
        int current_idx = i % dp_size;
        int prev_idx = (i - 1) % dp_size;
        
        long long take = compute_take_value(i, k, dp_size);
        dp[current_idx] = max(dp[prev_idx], take);
    }
    
    return dp[(n - 1) % dp_size];
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    read_values(n);
    
    printf("%lld\n", solve(n, k));
    
    return 0;
}
