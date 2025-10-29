#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX (100005)

int cmp (const void *a, const void *b)
{
    return *(long long*)a > *(long long*)b ? 1 : 
        *(long long*) a < *(long long*) b ? -1 : 0;
}

int main () 
{
    int N;
    int R;
    long long t;
    long long p;
    long long a[MAX];
    int n = 0;
    int j;
    int req;
    
    scanf("%d %d", &N, &R);

    for(j = 0; j < N; j++)
    {
        scanf("%lld %lld", &t, &p);

        if (p != -1)
            a[n++] = llabs(p-t);
    }

    qsort(a, n, sizeof(long long), cmp);

    req = ceil (N * R / 100.0);

    if (req > n)
        puts("It's impossible!");
    else 
        printf("%lld\n",a[req-1]);
}
