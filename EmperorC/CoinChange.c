#include <stdio.h>

#define MAX_D 100
#define MAX_Q 1000
#define MAX_V 100000

int denoms[MAX_D];
int queries[MAX_Q];
long long dp[MAX_V + 1];
int temp[MAX_D];

void read_denoms(int d)
{
    for (int i = 0; i < d; i++)
        scanf("%d", &denoms[i]);
}

void merge(int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    
    while (i <= mid && j <= right)
    {
        if (denoms[i] <= denoms[j])
            temp[k++] = denoms[i++];
        else
            temp[k++] = denoms[j++];
    }
    
    while (i <= mid)
        temp[k++] = denoms[i++];
    
    while (j <= right)
        temp[k++] = denoms[j++];
    
    for (i = left; i <= right; i++)
        denoms[i] = temp[i];
}

void merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}

int read_queries_and_find_max(int q)
{
    int max_v = 0;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &queries[i]);
        if (queries[i] > max_v)
            max_v = queries[i];
    }
    return max_v;
}

void fill_dp(int d, int max_v)
{
    for (int c = 0; c < d; c++)
    {
        for (int i = denoms[c]; i <= max_v; i++)
            dp[i] = dp[i] + dp[i - denoms[c]];
    }
}

void print_results(int q)
{
    for (int i = 0; i < q; i++)
        printf("%lld\n", dp[queries[i]]);
}

int main()
{
    int d, q;
    scanf("%d %d", &d, &q);
    
    read_denoms(d);
    merge_sort(0, d - 1);
    
    int max_v = read_queries_and_find_max(q);
    
    dp[0] = 1;
    for (int i = 1; i <= max_v; i++)
        dp[i] = 0;
    
    fill_dp(d, max_v);
    print_results(q);
    
    return 0;
}
