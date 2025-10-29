#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (3000005)
#define COLORN (8)

int cmp_desc (const void *a,const void *b)
{
    long long x=*(long long*)a;
    long long y=*(long long*)b;

    return (x < y)-(x > y);
}

int main ()
{
    int N,K;
    long long *red;
    long long *blue;
    int rcount = 0;
    int bcount = 0;
    int j = 0;
    int b;
    char color[COLORN];
    long long power,total = 0;
    long long best_total = 0;
    int r;
    int best_red=0;

    scanf ("%d %d", &N, &K);

    red = (long long*)malloc(N*sizeof(long long));
    blue = (long long*)malloc(N*sizeof(long long));
    
    if(!red || !blue) 
        return 1;

    for(j = 0; j < N; j++)
    {
        scanf("%s%lld",color,&power);

        if(!strcmp(color,"red")) 
            red[rcount++]=power;
        else 
            blue[bcount++]=power;
    }

    qsort(red,rcount,sizeof(long long),cmp_desc);
    qsort(blue,bcount,sizeof(long long),cmp_desc);

    for(r = (K < rcount ? K:rcount); r >=0 ;r--)
    {
        b = K - r;

        if(b>bcount) 
            continue;

        total=0;

        for(j=0;j<r;j++) 
            total+=red[j];

        for(j=0;j<b;j++) 
            total+=blue[j];

        if(r>best_red||(r==best_red&&total>best_total))
            best_red=r,best_total=total;
    }

    printf("%d %lld\n",best_red,best_total);

    free(red);
    free(blue);
    return 0;
}