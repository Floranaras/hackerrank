#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main ()
{
    int j;
    int N, R;
    cin >> N >> R;
    
    vector<long long> errors;
    
    for (j = 0; j < N; j++)
    {
        long long t, p;
        cin >> t >> p;
        
        if (p != -1)
            errors.push_back(abs(p - t));
    }
    
    sort(errors.begin(), errors.end());
    
    int required = ceil(N * R / 100.0);
    
    if (static_cast<size_t>(required) > errors.size())
        cout << "It's impossible!" << endl;
    else
        cout << errors[required - 1] << endl;
    
    return 0;
}