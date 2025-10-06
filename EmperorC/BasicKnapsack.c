#include <stdio.h>

#define MOD 1000000007
#define MAX_N 1000
#define MAX_C 10000

int weights[MAX_N];
long long dp[MAX_C + 1];

void read_weights(int n)
{
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &weights[i]);
}

void initialize_dp(int capacity)
{
    int i;
    dp[0] = 1;
    for(i = 1; i <= capacity; i++)
        dp[i] = 0;
}

void update_dp(int capacity, int weight)
{
    int i;
    for(i = capacity; i >= weight; i--)
        dp[i] = (dp[i] + dp[i - weight]) % MOD;
}

long long calculate_sum(int capacity)
{
    int i;
    long long sum;
    sum = 0;
    for(i = 0; i <= capacity; i++)
        sum = (sum + dp[i]) % MOD;

    return sum;
}

int main()
{
    int n;
    int c;
    int item;
    long long answer;
    
    scanf("%d %d", &n, &c);
    
    read_weights(n);
    initialize_dp(c);
    
    for(item = 0; item < n; item++)
        update_dp(c, weights[item]);
    
    answer = calculate_sum(c);
    printf("%lld\n", answer);
    
    return 0;
}
