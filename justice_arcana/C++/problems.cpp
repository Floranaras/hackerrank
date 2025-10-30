#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    
    vector<int> solvable_times;
    
    for (int j = 0; j < N; j++)
    {
        int t, p;
        cin >> t >> p;
        
        if (t != -1 && t <= T)
            solvable_times.push_back(t);
    }
    
    if (solvable_times.empty())
    {
        cout << "This exam is impossible!" << endl;
        return 0;
    }
    
    sort(solvable_times.begin(), solvable_times.end());
    
    int total_time = 0;
    int count = 0;
    
    for (int time : solvable_times)
    {
        if (total_time + time <= T)
        {
            total_time += time;
            count++;
        }
        else
            break;
    }
    
    cout << count << endl;
    
    return 0;
}