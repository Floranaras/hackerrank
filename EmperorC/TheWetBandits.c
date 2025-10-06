#include <stdio.h>

#define MAX_N 100000

int values[MAX_N];
long long dp[1000];

long long max(long long a, long long b)
{
    if(a > b)
        return a;
    return b;
}

int min(int a, int b)
{
    if(a < b)
        return a;
    return b;
}

void read_values(int n)
{
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &values[i]);
}

void initialize_dp(int dp_size)
{
    int i;
    for(i = 0; i < dp_size; i++)
        dp[i] = 0;
}

long long compute_take_value(int i, int k, int dp_size)
{
    long long take;
    int skip_idx;
    
    take = values[i];
    if(i > k)
    {
        skip_idx = (i - k - 1) % dp_size;
        take = take + dp[skip_idx];
    }
    return take;
}

long long solve(int n, int k)
{
    int dp_size;
    int i;
    int current_idx;
    int prev_idx;
    long long take;
    long long result;
    
    if(n == 0)
        return 0;
    if(n == 1)
        return values[0];
    
    dp_size = min(n, k + 2);
    initialize_dp(dp_size);
    dp[0] = values[0];
    
    for(i = 1; i < n; i++)
    {
        current_idx = i % dp_size;
        prev_idx = (i - 1) % dp_size;
        take = compute_take_value(i, k, dp_size);
        dp[current_idx] = max(dp[prev_idx], take);
    }
    
    result = dp[(n - 1) % dp_size];
    return result;
}

int main()
{
    int n;
    int k;
    long long answer;
    
    scanf("%d %d", &n, &k);
    
    read_values(n);
    answer = solve(n, k);
    printf("%lld\n", answer);
    
    return 0;
}
