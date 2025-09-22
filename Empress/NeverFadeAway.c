#include <stdio.h>

int jobs[30000][2];

long long calculateEarnings (long long skill, int n, long long y) 
{
    long long total = 0;
    long long y2 = (long long)y * y;

    for (int i = 0; i < n; i++) 
	{
        long long diff = jobs[i][0];
        long long pay  = jobs[i][1];

        if (skill > diff) 
			total += pay;
		
        else if (skill == diff) 
		{
            if (pay >= y) 
				total += pay;
        } 
		else 
		{
            if (pay >= y2) 
				total += pay;
        }
    }

    return total;
}

int solve (int x, int n, int g, int y) 
{
    long long lo = 0, hi = 1;

    while (calculateEarnings(x + hi, n, y) < g && hi <= 2000000000LL) 
        hi *= 2;
	
    if (hi > 2000000000LL) 
		return -1; 

	while (lo < hi) 
	{
        long long mid = (lo + hi) / 2;

        if (calculateEarnings(x + mid, n, y) >= g) 
            hi = mid;
        else 
            lo = mid + 1;
    }

    return (int)lo;
}

int main() 
{
    int t;

    scanf("%d", &t);

    while (t--) 
	{
        int x, n, g, y;
        scanf("%d%d%d%d", &x, &n, &g, &y);

        for (int i = 0; i < n; i++) 
            scanf("%d%d", &jobs[i][0], &jobs[i][1]);

        printf("%d\n", solve(x, n, g, y));
    }

    return 0;
}

