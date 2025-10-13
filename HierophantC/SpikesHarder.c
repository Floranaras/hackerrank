#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MOD 1000000007

typedef struct {
    int min_jumps;
    long long num_ways;
} Result;

void bfs_shortest_path(int *dist, bool *safe, int *jumps, int k, int n) {
    int *queue;
    int front, back;
    int curr, i, next;
    
    queue = malloc(n * sizeof(int));
    if (!queue) return;
    
    front = 0;
    back = 0;
    
    for (i = 1; i <= n; i++) {
        dist[i] = -1;
    }
    
    dist[1] = 0;
    queue[back++] = 1;
    
    while (front < back) {
        curr = queue[front++];
        
        for (i = 0; i < k; i++) {
            next = curr + jumps[i];
            
            if (next >= 1 && next <= n && safe[next] && dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                queue[back++] = next;
            }
        }
    }
    
    free(queue);
}

void count_paths(long long *ways, bool *safe, int *jumps, int k, int n) {
    int i, j, next;
    
    for (i = 1; i <= n; i++) {
        ways[i] = 0;
    }
    
    ways[1] = 1;
    
    for (i = 1; i <= n; i++) {
        if (!safe[i]) continue;
        
        for (j = 0; j < k; j++) {
            next = i + jumps[j];
            
            if (next <= n && safe[next]) {
                ways[next] = (ways[next] + ways[i]) % MOD;
            }
        }
    }
}

Result solve(int n, int k, char *path, int *jumps) {
    bool *safe;
    int *dist;
    long long *ways;
    Result result;
    int i;
    
    safe = malloc((n + 1) * sizeof(bool));
    dist = malloc((n + 1) * sizeof(int));
    ways = malloc((n + 1) * sizeof(long long));
    
    if (!safe || !dist || !ways) {
        result.min_jumps = -1;
        result.num_ways = 0;
        free(safe);
        free(dist);
        free(ways);
        return result;
    }
    
    /* Mark safe positions */
    for (i = 1; i <= n; i++) {
        safe[i] = true;
    }
    
    for (i = 0; path[i] && i < n; i++) {
        if (path[i] == '1') {
            safe[i + 1] = false;
        }
    }
    
    safe[1] = true;
    safe[n] = true;
    
    /* Find shortest path using BFS */
    bfs_shortest_path(dist, safe, jumps, k, n);
    
    /* Count number of paths */
    count_paths(ways, safe, jumps, k, n);
    
    result.min_jumps = dist[n];
    result.num_ways = ways[n];
    
    free(safe);
    free(dist);
    free(ways);
    
    return result;
}

int main(void) {
    int n, k, i;
    char *path;
    int *jumps;
    Result result;
    
    scanf("%d %d", &n, &k);
    
    path = malloc(n + 1);
    jumps = malloc(k * sizeof(int));
    
    if (!path || !jumps) {
        free(path);
        free(jumps);
        return 1;
    }
    
    scanf("%s", path);
    
    for (i = 0; i < k; i++) {
        scanf("%d", &jumps[i]);
    }
    
    result = solve(n, k, path, jumps);
    
    free(path);
    free(jumps);
    
    if (result.min_jumps == -1) {
        printf("-1 0\n");
    } else {
        printf("%d %lld\n", result.min_jumps, result.num_ways);
    }
    
    return 0;
}
