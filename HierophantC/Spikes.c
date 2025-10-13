#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int solve(int n, char *path) {
    bool *spike;
    int *dp;
    int i;
    int result;
    
    /* Allocate arrays - indices 0 to n inclusive */
    spike = calloc(n + 1, sizeof(bool));
    dp = malloc((n + 1) * sizeof(int));
    
    if (!spike || !dp) {
        free(spike);
        free(dp);
        return INT_MAX;
    }
    
    /* Mark spike positions from string */
    for (i = 0; path[i] && i < n; i++) {
        if (path[i] == '1') {
            spike[i + 1] = true;
        }
    }
    
    /* Start and end are always safe */
    spike[1] = false;
    spike[n] = false;
    
    /* Initialize all positions as unreachable */
    for (i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    dp[1] = 0;
    
    /* Compute minimum jumps */
    for (i = 1; i < n; i++) {
        if (dp[i] == INT_MAX) continue;
        
        if (i + 1 <= n && !spike[i + 1]) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }
        
        if (i + 2 <= n && !spike[i + 2]) {
            dp[i + 2] = min(dp[i + 2], dp[i] + 1);
        }
    }
    
    result = dp[n];
    
    free(spike);
    free(dp);
    
    return result;
}

int main(void) {
    int n;
    char *path;
    int result;
    
    scanf("%d", &n);
    
    /* Allocate exactly what we need for the string */
    path = malloc(n + 1);
    if (!path) return 1;
    
    scanf("%s", path);
    
    result = solve(n, path);
    
    free(path);
    
    if (result == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", result);
    }
    
    return 0;
}
