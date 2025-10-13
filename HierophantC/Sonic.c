#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF 1000000000000000LL

long long min_ll(long long a, long long b) {
    return a < b ? a : b;
}

long long solve(int n, int a, int b, int c, int k, int *slippery) {
    long long **dp;
    bool *is_slippery;
    int i, e, j;
    long long ans;
    long long dash_time;
    
    /* Allocate DP table */
    dp = (long long**)malloc((n + 1) * sizeof(long long*));
    if (!dp) return -1;
    
    for (i = 0; i <= n; i++) {
        dp[i] = (long long*)malloc((n + 1) * sizeof(long long));
        if (!dp[i]) {
            for (j = 0; j < i; j++) free(dp[j]);
            free(dp);
            return -1;
        }
        for (j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    
    /* Mark slippery positions */
    is_slippery = (bool*)calloc(n + 1, sizeof(bool));
    if (!is_slippery) {
        for (i = 0; i <= n; i++) free(dp[i]);
        free(dp);
        return -1;
    }
    
    for (i = 0; i < k; i++) {
        is_slippery[slippery[i]] = true;
    }
    
    /* Start at position 1 with 0 energy */
    dp[1][0] = 0;
    
    /* Process each position */
    for (i = 1; i < n; i++) {
        for (e = 0; e <= n; e++) {
            if (dp[i][e] == INF) continue;
            
            /* Walk: move forward, gain energy */
            if (e + 1 <= n) {
                dp[i + 1][e + 1] = min_ll(dp[i + 1][e + 1], dp[i][e] + a);
            }
            
            /* Dash: costs energy */
            if (e >= 1) {
                if (is_slippery[i]) {
                    /* Slippery: dash but stay in place */
                    dash_time = b + c;
                    if (e - 1 >= 0) {
                        dp[i][e - 1] = min_ll(dp[i][e - 1], dp[i][e] + dash_time);
                    }
                } else {
                    /* Normal: dash and move forward */
                    dash_time = b;
                    if (e - 1 >= 0) {
                        dp[i + 1][e - 1] = min_ll(dp[i + 1][e - 1], dp[i][e] + dash_time);
                    }
                }
            }
        }
    }
    
    /* Find minimum time to reach position n with any energy */
    ans = INF;
    for (e = 0; e <= n; e++) {
        ans = min_ll(ans, dp[n][e]);
    }
    
    /* Cleanup */
    for (i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(is_slippery);
    
    return ans;
}

int main(void) {
    int n, a, b, c, k;
    int *slippery;
    int i;
    long long result;

    
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &k);
    
    slippery = (int*)malloc(k * sizeof(int));
    if (!slippery) return 1;
    
    for (i = 0; i < k; i++) {
        scanf("%d", &slippery[i]);
    }
    
    result = solve(n, a, b, c, k, slippery);
    
    printf("%lld\n", result);
    
    free(slippery);
    
    return 0;
}
