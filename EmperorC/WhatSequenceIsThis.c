#include <stdio.h>

#define MOD 1000000007
#define MAX_N 5000

long long catalan[MAX_N + 1];

long long compute_catalan_term(int i)
{
    long long sum;
    long long product;
    int j;
    
    sum = 0;
    for(j = 0; j < i; j++)
    {
        product = (catalan[j] * catalan[i - j - 1]) % MOD;
        sum = (sum + product) % MOD;
    }
    return sum;
}

int main()
{
    int n;
    int i;
    
    scanf("%d", &n);
    
    catalan[0] = 1;
    
    for(i = 1; i <= n; i++)
        catalan[i] = compute_catalan_term(i);
    
    printf("%lld\n", catalan[n]);
    
    return 0;
}
