#include <stdio.h>

#define MAX_LEN 1000000000000000000LL
#define MAX_N 100001

long long lengths[MAX_N];

void precompute () 
{
    lengths[0] = 1;
    lengths[1] = 1;
    
    for (int i = 2; i < MAX_N; i++) 
	{
        lengths[i] = lengths[i-2] + lengths[i-1];
        if (lengths[i] > MAX_LEN) 
            lengths[i] = MAX_LEN;
    }
}

char solve (int n, long long k) 
{
    while (n > 1) 
	{
        if (k < lengths[n-2]) 
            n -= 2;
        else 
		{
            k -= lengths[n-2];
            n -= 1;
        }
    }

    return (n == 0) ? 'H' : 'A';
}

int main () 
{
    precompute();
    
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    
    printf("%c\n", solve(n, k));
    
    return 0;
}
