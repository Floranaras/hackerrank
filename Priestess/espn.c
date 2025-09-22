#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) 
{
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;
    
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
	
    return 0;
}

int bisect_right(int* arr, int size, int target) 
{
    int left = 0, right = size;
    
    while (left < right) 
	{
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) 
			left = mid + 1;
		else 
			right = mid;
    }
    
    return left;
}

int main() 
{
    int n, kx, ky;
    scanf("%d %d %d", &n, &kx, &ky);
    
    int* distances = (int*)malloc(n * sizeof(int));
    
    for (int j = 0; j < n; j++) 
	{
        int px, py;
        scanf("%d %d", &px, &py);
        distances[j] = abs(kx - px) + abs(ky - py);
    }
    
    qsort(distances, n, sizeof(int), compare);
    
    int q;
    scanf("%d", &q);
    
    for (int j = 0; j < q; j++) 
	{
        int e;
        scanf("%d", &e);
        int ans = bisect_right(distances, n, e);
        printf("%d\n", ans);
    }
    
    free(distances);
    return 0;
}
