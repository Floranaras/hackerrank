#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right, int pivot_idx) 
{
    int pivot_val = arr[pivot_idx];
    swap(&arr[pivot_idx], &arr[right]);
    
    int store_idx = left;
    for (int j = left; j < right; j++) 
	{
        if (arr[j] <= pivot_val) 
		{  
            swap(&arr[store_idx], &arr[j]);
            store_idx++;
        }
    }
    
    swap(&arr[right], &arr[store_idx]);
    return store_idx;
}

int quickselect(int arr[], int left, int right, int target) 
{
    if (left == right) 
        return arr[left];
    
    int pivot_idx = left + rand() % (right - left + 1);
    pivot_idx = partition(arr, left, right, pivot_idx);
    
    if (target == pivot_idx) 
        return arr[target];
    else if (target < pivot_idx) 
        return quickselect(arr, left, pivot_idx - 1, target);
    else 
        return quickselect(arr, pivot_idx + 1, right, target);
}

int kth_largest(int arr[], int n, int k) 
{
    if (n == 0 || k > n || k <= 0) 
        return -1;
    
    int target = n - k;
    return quickselect(arr, 0, n - 1, target);
}

int main() 
{
    srand(time(NULL));  
    
    int n;
    scanf("%d", &n);
    
    int vals[n];
    for (int i = 0; i < n; i++) 
	{
        int r, c;
        scanf("%d %d", &r, &c);
        vals[i] = r - c;  
    }
    
    int q;
    scanf("%d", &q);
    
    while (q--) 
	{
        int s, e, A, K;
        scanf("%d %d %d %d", &s, &e, &A, &K);
        
        if (s > e) 
		{
            int temp = s;
            s = e;
            e = temp;
        }
        
        int tickets = A / K;
        if (tickets <= 0) 
		{
            printf("-1\n");
            continue;
        }
        
        int range_size = e - s + 1;
        if (tickets > range_size) 
            tickets = range_size;
        
        int subarray[range_size];
        for (int j = 0; j < range_size; j++) 
            subarray[j] = vals[s + j];
        
        int ans = kth_largest(subarray, range_size, tickets);
        printf("%d\n", ans);
    }
    
    return 0;
}
