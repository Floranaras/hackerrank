#include <iostream>
#include <climits>
using namespace std;

int main() 
{
    int n, c = 0;
    long long x, t = 0, m = LLONG_MIN;
    
    for (cin >> n; n--; ) 
    {
        cin >> x;
        
        if (x > 0) 
            t += x, c++;
        if (x > m) 
            m = x;
    }
    
    cout << (c ? c : 1) << " " << (c ? t : m);
}