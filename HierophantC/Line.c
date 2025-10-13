#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

int min(int a, int b) {
    return a < b ? a : b;
}

int solve(int n, int m, int k, int times[][400]) {
    int **dp;
    int level, line;
    int min_time;
    int i;
    
    dp = (int**)malloc(n * sizeof(int*));
    if (!dp) return -1;
    
    for (i = 0; i < n; i++) {
        dp[i] = (int*)malloc(m * sizeof(int));
        if (!dp[i]) {
            for (int j = 0; j < i; j++) free(dp[j]);
            free(dp);
            return -1;
        }
    }
    
    /* Initialize first station: cost is just the time on that line */
    for (line = 0; line < m; line++) {
        dp[0][line] = times[line][0];
    }
    
    /* Process each subsequent station */
    for (level = 1; level < n; level++) {
        for (line = 0; line < m; line++) {
            dp[level][line] = INF;
            
            /* Stay on same line */
            dp[level][line] = min(dp[level][line], 
                                 dp[level - 1][line] + times[line][level]);
            
            /* Switch from adjacent lines */
            if (line > 0) {
                dp[level][line] = min(dp[level][line],
                                     dp[level - 1][line - 1] + k + times[line][level]);
            }
            
            if (line < m - 1) {
                dp[level][line] = min(dp[level][line],
                                     dp[level - 1][line + 1] + k + times[line][level]);
            }
        }
    }
    
    /* Find minimum time at final station */
    min_time = INF;
    for (line = 0; line < m; line++) {
        min_time = min(min_time, dp[n - 1][line]);
    }
    
    for (i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return min_time;
}

int main(void) {
    int n, m, k, i, j;
    int times[400][400];
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &times[j][i]);
        }
    }
    
    printf("%d\n", solve(n, m, k, times));
    
    return 0;
}
