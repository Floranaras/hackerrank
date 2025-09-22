#include <stdio.h>
#include <math.h>
typedef long long ll;

int main () 
{
    ll a, q;
    scanf ("%lld%lld", &a, &q);
    
    for (int j = 0; j < q; j++) 
	{
        ll T;  
        scanf("%lld", &T);
        
        if (a == 0) 
		{
            printf("Pat is the Best Tunnel Master!\n");
            continue;
        }
        
        if (T < 0) 
		{
            printf("0\n");
            continue;
        }
        
        double threshold = (double)T / a;
        
        ll left = 0;
        ll right = (ll)(threshold + 1);
        
        if (right > 1000000) 
			right = 1000000;
        
        while (left < right) 
		{
            ll mid = left + (right - left + 1) / 2;
            
            if (sin(mid) + mid <= threshold) 
                left = mid;
            else 
                right = mid - 1;
        }
        
        printf("%lld\n", left);
    }
    
    return 0;
}
