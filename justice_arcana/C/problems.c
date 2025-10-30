#include <stdio.h>
#include <stdlib.h>

#define MAX (100005)

int cmp (const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int main ()
{
    int N;
    int T;
    int t;
    int p;
    int a[MAX];
    int n = 0;
    int s = 0;
    int c = 0;
    int j; 
    
    scanf ("%d %d", &N, &T);

    for (j = 0; j < N; j++)
    {
        scanf("%d %d", &t, &p);

        if(t != -1 && t <= T)
            a[n++]=t;
    }

    if (!n)
    {
        puts("This exam is impossible!");
        return 0;
    }

    qsort(a,n,sizeof(int),cmp);

    for (j = 0; j < n && s + a[j] <= T; j++)
    {
        s += a[j];
        c++;
    }

    printf("%d\n",c);
}
