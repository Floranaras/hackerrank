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
    int i;
    for(i = 0; i < d; i++)
        scanf("%d", &denoms[i]);
}

void merge(int left, int mid, int right)
{
    int i;
    int j;
    int k;
    
    i = left;
    j = mid + 1;
    k = left;
    
    while(i <= mid && j <= right)
    {
        if(denoms[i] <= denoms[j])
        {
            temp[k] = denoms[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = denoms[j];
            k++;
            j++;
        }
    }
    
    while(i <= mid)
    {
        temp[k] = denoms[i];
        k++;
        i++;
    }
    
    while(j <= right)
    {
        temp[k] = denoms[j];
        k++;
        j++;
    }
    
    for(i = left; i <= right; i++)
        denoms[i] = temp[i];
}

void merge_sort(int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = left + (right - left) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}

int read_queries_and_find_max(int q)
{
    int i;
    int max_v;
    max_v = 0;
    for(i = 0; i < q; i++)
    {
        scanf("%d", &queries[i]);
        if(queries[i] > max_v)
            max_v = queries[i];
    }
    return max_v;
}

void initialize_dp(int max_v)
{
    int i;
    dp[0] = 1;
    for(i = 1; i <= max_v; i++)
        dp[i] = 0;
}

void fill_dp(int d, int max_v)
{
    int c;
    int i;
    for(c = 0; c < d; c++)
    {
        for(i = denoms[c]; i <= max_v; i++)
            dp[i] = dp[i] + dp[i - denoms[c]];
    }
}

void print_results(int q)
{
    int i;
    for(i = 0; i < q; i++)
        printf("%lld\n", dp[queries[i]]);
}

int main()
{
    int d;
    int q;
    int max_v;
    
    scanf("%d %d", &d, &q);
    
    read_denoms(d);
    merge_sort(0, d - 1);
    
    max_v = read_queries_and_find_max(q);
    initialize_dp(max_v);
    fill_dp(d, max_v);
    print_results(q);
    
    return 0;
}
