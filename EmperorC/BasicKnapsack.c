#include <stdio.h>
#define MOD 1000000007
#define MAX_C 100000
#define MAX_N 1000

void init_dp(long long dp[], int c)
{
    int i;
    dp[0] = 1;
    for(i = 1; i <= c; i++)
        dp[i] = 0;
}

void lambda_function(long long dp[], int wt, int c)
{
    int i;
    long long temp[MAX_C + 1];
    
    for(i = 0; i <= c; i++)
    {
        temp[i] = dp[i];
        if(i >= wt)
            temp[i] = (temp[i] + dp[i - wt]) % MOD;
    }
    
    for(i = 0; i <= c; i++)
        dp[i] = temp[i];
}

void reduce(long long dp[], int n, int c)
{
    int i, wt;
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &wt);
        lambda_function(dp, wt, c);
    }
}

long long sum_dp(long long dp[], int c)
{
    int i;
    long long sum = 0;
    
    for(i = 0; i <= c; i++)
        sum = (sum + dp[i]) % MOD;
        
    return sum;
}

int main()
{
    int n, c;
    long long dp[MAX_C + 1];
    
    scanf("%d %d", &n, &c);
    
    init_dp(dp, c);
    reduce(dp, n, c);
    
    printf("%lld\n", sum_dp(dp, c));
    
    return 0;
}
