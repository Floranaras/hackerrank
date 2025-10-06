#include <stdio.h>

#define MAX_N 100000

int vals[MAX_N][2];

long long min(long long a, long long b)
{
    if(a < b)
        return a;
    return b;
}

void read_values(int n)
{
    int i;
    for(i = 0; i < n; i++)
        scanf("%d %d", &vals[i][0], &vals[i][1]);
}

void update_dp(long long *dp0, long long *dp1, int i, int k)
{
    long long new_dp0;
    long long new_dp1;
    
    new_dp0 = min(*dp0 + vals[i][0], *dp1 + k + vals[i][0]);
    new_dp1 = min(*dp1 + vals[i][1], *dp0 + k + vals[i][1]);
    
    *dp0 = new_dp0;
    *dp1 = new_dp1;
}

int main()
{
    int n;
    int k;
    int i;
    long long dp0;
    long long dp1;
    long long answer;
    
    scanf("%d %d", &n, &k);
    
    read_values(n);
    
    dp0 = vals[0][0];
    dp1 = vals[0][1];
    
    for(i = 1; i < n; i++)
        update_dp(&dp0, &dp1, i, k);
    
    answer = min(dp0, dp1);
    printf("%lld\n", answer);
    
    return 0;
}
