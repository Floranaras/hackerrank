#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int solve(int n, int times[][21]) {
    int *dp;
    int total_states;
    int mask, next, prev;
    int best_time, new_mask;
    int i;
    
    total_states = 1 << n;
    
    dp = (int*)malloc(total_states * sizeof(int));
    if (!dp) return -1;
    
    for (i = 0; i < total_states; i++) {
        dp[i] = INT_MAX;
    }
    
    dp[0] = 0;
    
    for (mask = 0; mask < total_states; mask++) {
        if (dp[mask] == INT_MAX) continue;
        
        for (next = 0; next < n; next++) {
            if (mask & (1 << next)) continue;
            
            best_time = times[next][0];
            
            for (prev = 0; prev < n; prev++) {
                if (mask & (1 << prev)) {
                    best_time = min(best_time, times[next][prev + 1]);
                }
            }
            
            new_mask = mask | (1 << next);
            dp[new_mask] = min(dp[new_mask], dp[mask] + best_time);
        }
    }
    
    i = dp[total_states - 1];
    free(dp);
    
    return i;
}

int main(void) {
    int n, i, j;
    int times[20][21];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%d", &times[i][j]);
        }
    }
    
    printf("%d\n", solve(n, times));
    
    return 0;
}
