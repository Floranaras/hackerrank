#include <stdio.h>

long long min(long long a, long long b)
{
    if (a < b)
        return a;

    return b;
}

void update_dp_state(long long *dp0, long long *dp1, int a, int b, int k)
{
    long long new_dp0 = min(*dp0 + a, *dp1 + k + a);
    long long new_dp1 = min(*dp1 + b, *dp0 + k + b);
    
    *dp0 = new_dp0;
    *dp1 = new_dp1;
}

long long solve_assembly_lines(int n, int k)
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    long long dp0 = a;
    long long dp1 = b;
    
    int i;
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        update_dp_state(&dp0, &dp1, a, b, k);
    }
    
    return min(dp0, dp1);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    printf("%lld\n", solve_assembly_lines(n, k));
    
    return 0;
}
