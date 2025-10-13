#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MOD 1000000007

long long solve(int n, char *path) {
    bool *spike;
    long long *ways;
    int i;
    long long result;
    
    spike = calloc(n + 1, sizeof(bool));
    ways = calloc(n + 1, sizeof(long long));
    
    if (!spike || !ways) {
        free(spike);
        free(ways);
        return 0;
    }
    
    /* Mark spike positions */
    for (i = 0; path[i] && i < n; i++) {
        if (path[i] == '1') {
            spike[i + 1] = true;
        }
    }
    
    spike[1] = false;
    spike[n] = false;
    
    /* One way to be at position 1: start there */
    ways[1] = 1;
    
    /* Count ways to reach each position */
    for (i = 1; i < n; i++) {
        if (ways[i] == 0) continue;
        
        if (i + 1 <= n && !spike[i + 1]) {
            ways[i + 1] = (ways[i + 1] + ways[i]) % MOD;
        }
        
        if (i + 2 <= n && !spike[i + 2]) {
            ways[i + 2] = (ways[i + 2] + ways[i]) % MOD;
        }
    }
    
    result = ways[n];
    
    free(spike);
    free(ways);
    
    return result;
}

int main(void) {
    int n;
    char *path;
    long long result;
    
    scanf("%d", &n);
    
    path = malloc(n + 1);
    if (!path) return 1;
    
    scanf("%s", path);
    
    result = solve(n, path);
    
    free(path);
    
    printf("%lld\n", result);
    
    return 0;
}
