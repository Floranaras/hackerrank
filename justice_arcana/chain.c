#include <stdio.h>
#define MAX (10)

int main () 
{
    int j;
    long long c[MAX];
    long long best = 0;
    long long k;
    long long t;

    for (j = 0; j < MAX; j++) 
        if (scanf("%lld", &c[j]) != 1) 
            return 0;

    for (k = 1; k <= c[0] + 1; ++k) 
    {
        t = k - 1;

        for (j = 1; j < MAX; ++j) 
            t += (c[j] < k ? c[j] : k);
            
        if (t > best) 
            best = t;
    }

    printf("%lld\n", best);
    return 0;
}