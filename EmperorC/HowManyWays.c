#include <stdio.h>

#define MOD 1000000007

long long power(long long base, long long exp, long long mod)
{
    long long result;
    result = 1;
    base = base % mod;
    while(exp > 0)
    {
        if(exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp >> 1;
    }
    return result;
}

long long compute_numerator(int n, int r)
{
    long long num;
    int i;
    num = 1;
    for(i = 0; i < r; i++)
        num = (num * (n - i)) % MOD;
    return num;
}

long long compute_denominator(int r)
{
    long long den;
    int i;
    den = 1;
    for(i = 0; i < r; i++)
        den = (den * (i + 1)) % MOD;
    return den;
}

long long solve(int n, int r)
{
    long long num;
    long long den;
    
    if(r > n || r < 0)
        return 0;
    if(r == 0 || r == n)
        return 1;    
    if(r > n - r)
        r = n - r;
    
    num = compute_numerator(n, r);
    den = compute_denominator(r);
    
    return (num * power(den, MOD - 2, MOD)) % MOD;
}

int main()
{
    int q;
    int i;
    int n;
    int r;
    
    scanf("%d", &q);
    
    for(i = 0; i < q; i++)
    {
        scanf("%d %d", &n, &r);
        printf("%lld\n", solve(n, r));
    }
    
    return 0;
}
