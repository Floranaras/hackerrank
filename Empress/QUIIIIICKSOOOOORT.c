#include <stdio.h>
#include <math.h>

unsigned long long compute_ans(unsigned long long t) 
{
    unsigned long long left = 1;
    unsigned long long right = 2000000000000000ULL; 
    unsigned long long result = 1;

    double target = 1e8 * (double)t;

    while (left <= right) 
	{
        unsigned long long mid = left + (right - left) / 2ULL;
        double operations = (double)mid * log2((double)mid);

        if (operations <= target) 
		{
            result = mid;
            left = mid + 1ULL;
        } 
		else 
            right = mid - 1ULL;
    }

    return result;
}

int main(void) 
{
    unsigned long long t;

    if (scanf("%llu", &t) != 1) 
        return 1; 

    printf("%llu\n", compute_ans(t));
    return 0;
}

