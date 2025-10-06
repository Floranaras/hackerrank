#include <stdio.h>

#define MOD 1000000007
#define MAX_N 1000
#define MAX_C 10000

int w[MAX_N];
long long dp[MAX_C + 1];

void read_weights(int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
}

void update_dp(int capacity, int weight)
{
    for (int i = capacity; i >= weight; i--)
        dp[i] = (dp[i] + dp[i - weight]) % MOD;
}

long long calculate_sum(int capacity)
{
    long long sum = 0;
    for (int i = 0; i <= capacity; i++)
        sum = (sum + dp[i]) % MOD;

    return sum;
}

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    
    read_weights(n);
    
    dp[0] = 1;
    for (int i = 1; i <= c; i++)
        dp[i] = 0;
    
    for (int item = 0; item < n; item++)
        update_dp(c, w[item]);
    
    printf("%lld\n", calculate_sum(c));
    
    return 0;
}
