#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POINTS 101
#define MAX_ACTIONS 101

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(int e, int s, int y, int k, int d, int *quality, int *cost) {
    int dp[MAX_ACTIONS][MAX_POINTS];
    int min_weaves;
    int remaining_actions;
    int actions, points, i;
    int max_quality;
    
    min_weaves = (e + s - 1) / s;
    
    if (min_weaves > d) {
        return -1;
    }
    
    remaining_actions = d - min_weaves;
    
    /* Initialize: -1 means unreachable state */
    for (actions = 0; actions <= remaining_actions; actions++) {
        for (points = 0; points <= y; points++) {
            dp[actions][points] = -1;
        }
    }
    
    dp[remaining_actions][y] = 0;
    
    /* Work backwards from initial state */
    for (actions = remaining_actions; actions >= 0; actions--) {
        for (points = 0; points <= y; points++) {
            if (dp[actions][points] == -1) continue;
            
            /* Try crafting each item */
            for (i = 0; i < k; i++) {
                if (actions > 0 && points >= cost[i]) {
                    int new_quality = dp[actions][points] + quality[i];
                    if (dp[actions - 1][points - cost[i]] < new_quality) {
                        dp[actions - 1][points - cost[i]] = new_quality;
                    }
                }
            }
        }
    }
    
    max_quality = 0;
    for (actions = 0; actions <= remaining_actions; actions++) {
        for (points = 0; points <= y; points++) {
            if (dp[actions][points] > max_quality) {
                max_quality = dp[actions][points];
            }
        }
    }
    
    return max_quality;
}

int main(void) {
    int e, s, y, k, d;
    int quality[100];
    int cost[100];
    int i;
    int result;
    
    scanf("%d %d %d %d %d", &e, &s, &y, &k, &d);
    
    for (i = 0; i < k; i++) {
        scanf("%d %d", &quality[i], &cost[i]);
    }
    
    result = solve(e, s, y, k, d, quality, cost);

    
    if (result < 0) {
        printf("Impossible\n");
    } else {
        printf("%d\n", result);
    }
    
    return 0;
}
