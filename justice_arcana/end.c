#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main () 
{
    int n;
    int c = 0;
    int j;
    long long x;
    long long t  = 0;
    long m = LLONG_MIN;

    scanf("%d", &n);

    for (j = 0; j < n; ++j)
    {
        scanf("%lld", &x);
        
        if (x > 0)
        {
            t += x;
            ++c;
        }

        m = fmaxl(m, x);
    }

    printf("%d %lld", c ? c : 1, c ? t : m); 
}