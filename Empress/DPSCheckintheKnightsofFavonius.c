#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KNIGHTS 100000
#define MAX_HILLICHURLS 100000
#define MAX_NAME_LEN 100

typedef struct 
{
	char name[MAX_NAME_LEN];
	int defeated;
} KnightResult;

int compare_knights(const void *a, const void *b) 
{
	KnightResult *knightA = (KnightResult *)a;
	KnightResult *knightB = (KnightResult *)b;

	if (knightA->defeated != knightB->defeated) 
		return knightB->defeated - knightA->defeated;

	return strcmp(knightA->name, knightB->name);
}

int compare_ints(const void *a, const void *b) 
{
	return (*(int*)a - *(int*)b);
}

int max(int a, int b) 
{
	return a > b ? a : b;
}

int count_defeated(int hillichurls[], int h, int damage) 
{
	int left = 0, right = h - 1, result = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (hillichurls[mid] <= damage) 
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

void solve(int k, int h, char names[][MAX_NAME_LEN], int atks[], int scalings[][4], int hillichurls[]) 
{
	KnightResult results[MAX_KNIGHTS];

	qsort(hillichurls, h, sizeof(int), compare_ints);

	for (int i = 0; i < k; i++) 
	{
		int maxDamage = 0;

		for (int j = 0; j < 4; j++) 
		{
			int damage = (atks[i] * scalings[i][j]) / 100;
			maxDamage = max(maxDamage, damage);
		}

		int defeated = count_defeated(hillichurls, h, maxDamage);

		strcpy(results[i].name, names[i]);

		results[i].defeated = defeated;
	}

	qsort(results, k, sizeof(KnightResult), compare_knights);

	for (int i = 0; i < k; i++) 
	{
		printf("%s %d\n", results[i].name, results[i].defeated);
	}
}

int main() 
{
	int k, h;
	scanf("%d %d", &k, &h);

	char names[MAX_KNIGHTS][MAX_NAME_LEN];
	int atks[MAX_KNIGHTS];
	int scalings[MAX_KNIGHTS][4];

	for (int i = 0; i < k; i++) 
	{
		scanf("%s %d %d %d %d %d", names[i], &atks[i], &scalings[i][0], 
		&scalings[i][1], &scalings[i][2], &scalings[i][3]);
	}

	int hillichurls[MAX_HILLICHURLS];
	for (int i = 0; i < h; i++) 
	{
		scanf("%d", &hillichurls[i]);
	}

	solve(k, h, names, atks, scalings, hillichurls);

	return 0;
}
