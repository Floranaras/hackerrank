#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n, f, k;
    cin >> n >> f >> k;
    
    int vamps[n];
    for (int j = 0; j < n; j++)
        cin >> vamps[j];
    
    sort(vamps, vamps + n);
    
    long long total = 0;
    for (int j = 0; j < k; j++)
        total += vamps[j];
    
    cout << (total <= f ? "YES" : "NO");
}