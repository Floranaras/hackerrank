#include <stdio.h>
#include <stdlib.h>

void read_denoms(int *denoms, int d)
{
    int i;
    for(i = 0; i < d; i++)
        scanf("%d", &denoms[i]);
}

void merge(int *denoms, int *temp, int left, int mid, int right)
{
    int i, j, k;
    
    for(i = left; i <= right; i++)
        temp[i] = denoms[i];
    
    i = left;
    j = mid + 1;
    k = left;
    
    while(i <= mid && j <= right)
    {
        if(temp[i] <= temp[j])
            denoms[k++] = temp[i++];
        else
            denoms[k++] = temp[j++];
    }
    
    while(i <= mid)
        denoms[k++] = temp[i++];
    
    while(j <= right)
        denoms[k++] = temp[j++];
}

void merge_sort(int *denoms, int *temp, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(denoms, temp, left, mid);
        merge_sort(denoms, temp, mid + 1, right);
        merge(denoms, temp, left, mid, right);
    }
}

int read_queries_and_find_max(int *queries, int q)
{
    int i;
    int max_v = 0;
    for(i = 0; i < q; i++)
    {
        scanf("%d", &queries[i]);
        if(queries[i] > max_v)
            max_v = queries[i];
    }
    return max_v;
}

void initialize_dp(long long *dp, int max_v)
{
    int i;
    dp[0] = 1;
    for(i = 1; i <= max_v; i++)
        dp[i] = 0;
}

void fill_dp(long long *dp, int *denoms, int d, int max_v)
{
    int c, i;
    for(c = 0; c < d; c++)
    {
        for(i = denoms[c]; i <= max_v; i++)
            dp[i] += dp[i - denoms[c]];
    }
}

void print_results(long long *dp, int *queries, int q)
{
    int i;
    for(i = 0; i < q; i++)
        printf("%lld\n", dp[queries[i]]);
}

int main()
{
    int d, q, max_v;
    
    scanf("%d %d", &d, &q);
    
    int *denoms = (int *)malloc(d * sizeof(int));
    int *temp = (int *)malloc(d * sizeof(int));
    int *queries = (int *)malloc(q * sizeof(int));
    
    if(denoms == NULL || temp == NULL || queries == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    read_denoms(denoms, d);
    merge_sort(denoms, temp, 0, d - 1);
    
    max_v = read_queries_and_find_max(queries, q);
    
    long long *dp = (long long *)malloc((max_v + 1) * sizeof(long long));
    if(dp == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    initialize_dp(dp, max_v);
    fill_dp(dp, denoms, d, max_v);
    print_results(dp, queries, q);
    
    free(denoms);
    free(temp);
    free(queries);
    free(dp);
    
    return 0;
}
