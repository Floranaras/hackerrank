#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll merge_and_count (int arr[], int temp[], int left, int mid, int right) 
{
    int i = left;
    int j = mid;
    int k = left;
    ll inv_count = 0;

    while (i <= mid - 1 && j <= right) 
	{
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++];
        else 
		{
            temp[k++] = arr[j++];
            inv_count += (ll)(mid - i); 
        }
    }

    while (i <= mid - 1) 
        temp[k++] = arr[i++];

    while (j <= right) 
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++) 
        arr[i] = temp[i];

    return inv_count;
}

ll merge_sort_count(int arr[], int temp[], int left, int right) 
{
    ll inv_count = 0;
    if (right > left) 
	{
        int mid = (right + left) / 2;
        inv_count += merge_sort_count(arr, temp, left, mid);
        inv_count += merge_sort_count(arr, temp, mid + 1, right);
        inv_count += merge_and_count(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

ll count_inversions(int arr[], int n) 
{
    int *temp = (int *)malloc(n * sizeof(int));
    ll inv_count = merge_sort_count(arr, temp, 0, n - 1);
    free(temp);

    return inv_count;
}

int main (void) 
{
    int n;
    long long s;

    if (scanf("%d %lld", &n, &s) != 2) 
		return 1;

    int *books = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) 
        scanf("%d", &books[i]);

    int *desc_books = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
        desc_books[i] = -books[i]; 

    ll asc_inv = count_inversions(books, n);
    ll desc_inv = count_inversions(desc_books, n);

    ll swaps_needed = asc_inv < desc_inv ? asc_inv : desc_inv;

    if (swaps_needed == 0) 
        printf("Butz loses!\n");

    else 
	{
        long long k = s / swaps_needed + 1;
        printf("%lld\n", k);
    }

    free(books);
    free(desc_books);
    return 0;
}

