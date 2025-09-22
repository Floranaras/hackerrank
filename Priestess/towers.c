#include <stdio.h>
#include <stdlib.h>

void solve(int n, int k, int* d_i, int* s_i) 
{
    int* strengths = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
        strengths[i] = s_i[i];
 
    int attack_idx = 0;
    
    while (1) 
	{
        int damage = d_i[attack_idx];
        int standing = 0;
        
        for (int i = 0; i < n; i++) 
		{
            if (strengths[i] > 0) 
			{
                strengths[i] -= damage;
                if (strengths[i] > 0) 
                    standing++;
            }
        }
        
        printf("%d\n", standing);
        
        if (standing == 0) 
            break;
        
        attack_idx = (attack_idx + 1) % k;
    }
    
    free(strengths);
}

int main () 
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int* d_i = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) 
        scanf("%d", &d_i[i]);
    
    int* s_i = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
        scanf("%d", &s_i[i]);
    
    solve(n, k, d_i, s_i);
    
    free(d_i);
    free(s_i);
    
    return 0;
}
