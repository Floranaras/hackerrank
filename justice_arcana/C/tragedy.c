#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main ()
{
    int n, f, k, j;
    long long total = 0;

    if (scanf("%d %d %d", &n, &f, &k) != 3)
        return 0;

    int vamps[n];
    for (j = 0; j < n; ++j)
        scanf("%d", &vamps[j]);

    qsort(vamps, n, sizeof(int), cmp);
    for (j = 0; j < k; ++j)
        total += vamps[j];

    puts(total <= f ? "YES" : "NO");
    return 0;
}