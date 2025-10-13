#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long solve(int n) {
    long long *catalan;
    int i, j;
    long long result;
    
    if (n % 2 == 1) {
        return 0;
    }
    
    n = n / 2;
    
    catalan = calloc(n + 1, sizeof(long long));
    if (!catalan) return 0;
    
    catalan[0] = 1;
    
    /* Compute Catalan numbers using recurrence relation */
    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) {
            catalan[i] = (catalan[i] + (catalan[j] * catalan[i - j - 1]) % MOD) % MOD;
        }
    }
    
    result = catalan[n];
    
    free(catalan);
    
    return result;
}

int main(void) {
    int n;
    long long result;
    
    scanf("%d", &n);
    
    result = solve(n);
    
    printf("%lld\n", result);
    
    return 0;
}
