#include <stdio.h>
#include <math.h>

const double EPS = 1e-8;

double evap(double x, double d, double k, double a) 
{
    return 1.0 - pow(1.0/(1.0 + exp(-k*(x-0.5))), a) + d;
}

void solve(double s, double d, double k, double a) 
{
    double f0 = evap(0.0, d, k, a) - s;
    double f1 = evap(1.0, d, k, a) - s;
    
    if (fabs(f0) <= EPS) 
	{ 
        printf("%.12f\n", 0.0); 
        return; 
    }

    if (fabs(f1) <= EPS) 
	{ 
        printf("%.12f\n", 1.0); 
        return; 
    }

    if (f0 * f1 > 0) 
	{
        printf("Sweet spot cannot be reached! Those cheeky developers!\n");
        return;
    }
    
    double lo = 0.0, hi = 1.0;
	
    for (int j = 0; j < 200; j++) 
	{       
        double mid = (lo + hi) / 2.0;
        double fm = evap(mid, d, k, a) - s;
        
        if (fm == 0.0) 
		{ 
            lo = hi = mid; 
            break; 
        }

        if (f0 * fm <= 0) 
		{
            hi = mid;
            f1 = fm;
        } 

		else 
		{
            lo = mid;
            f0 = fm;
        }
    }

    printf("%.12f\n", (lo + hi) / 2.0);
}

int main () 
{
    int n;
    if (scanf("%d", &n) != 1) 
		return 0;
    
	for (int j = 0; j < n; j++) 
	{
        double s, d, k, a;
        scanf("%lf %lf %lf %lf", &s, &d, &k, &a);
        solve(s, d, k, a);
    }
    
    return 0;
}
