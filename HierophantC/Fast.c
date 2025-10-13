#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long *F = NULL;
int initialized = 0;

void precompute(int *a, int n) {
    int i;
    long long sum;
    
    if (initialized) return;
    
    F = (long long*)malloc(n * sizeof(long long));
    if (!F) return;
    
    F[0] = a[0];
    sum = F[0];
    
    for (i = 1; i < n; i++) {
        F[i] = (a[i] + sum) % MOD;
        sum = (sum + F[i]) % MOD;
    }
    
    initialized = 1;
}

int solve(int k, int *a, int n) {
    if (!initialized) {
        precompute(a, n);
    }
    
    return (int)F[k];
}

int main(void) {
    int q, n, i, k;
    int *a;
    
    scanf("%d %d", &q, &n);
    
    a = (int*)malloc(n * sizeof(int));
    if (!a) return 1;
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (i = 0; i < q; i++) {
        scanf("%d", &k);
        printf("%d\n", solve(k, a, n));
    }
    
    free(a);
    free(F);
    
    return 0;
}
