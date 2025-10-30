#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () 
{
    vector<long long> c(10);
    for (auto& x : c) 
        cin >> x;
    
    long long best = 0;
    for (long long k = 1; k <= c[0] + 1; k++) 
    {
        long long t = k - 1;

        for (int j = 1; j < 10; j++) 
            t += min(c[j], k);

        best = max(best, t);
    }
    
    cout << best << '\n';
}