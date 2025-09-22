#include <stdio.h>
#include <stdlib.h>

#define MAX_N 300000

int fs[MAX_N], ms[MAX_N], answers[MAX_N];

int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

int countFrequencies(int arr[], int size, int target) 
{
    int left = 0, right = size - 1, result = 0;
    
    while (left <= right) 
	{
        int mid = left + (right - left) / 2;
        
        if (arr[mid] <= target) 
		{
            result = mid + 1;  
			left = mid + 1;
        } 

		else 
		{
            right = mid - 1;
        }
    }
    
    return result;
}

void solve(int k, int n) 
{
    qsort(fs, k, sizeof(int), compare);
    
    for (int i = 0; i < n; i++) 
        answers[i] = countFrequencies(fs, k, ms[i]);
}

int main () 
{
    int k, n, i;
    
    scanf("%d %d", &k, &n);
    
    for (i = 0; i < k; i++) 
        scanf("%d", &fs[i]);
    
    for (i = 0; i < n; i++) 
        scanf("%d", &ms[i]);
    
    solve(k, n);
    
    for (i = 0; i < n; i++) 
        printf("%d\n", answers[i]);
    
    return 0;
}
