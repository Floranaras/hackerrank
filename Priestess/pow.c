#include <stdio.h>

#define MOD 10000000

long long solve (long long e, long long t) 
{
    long long res = 1;
    e %= MOD;
    
    while (t > 0) 
	{
        if (t % 2 == 1) 
            res = (res * e) % MOD;

        e = (e * e) % MOD;
        t /= 2;
    }
    return res;
}

int main () 
{
    long long e, t;
    scanf ("%lld %lld", &e, &t);
    
    printf ("%lld\n", solve(e, t));
    
    return 0;
}
