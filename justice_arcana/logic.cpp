#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int K;
    int j;
    int r;
    int b;
    vector<long long> red;
    vector<long long> blue;
    string color;
    long long power;
    long long best_total = 0;
    long long total = 0;
    int best_red_count = 0;
    int max_red;

    cin >> N >> K;

    for (j = 0; j < N; j++)
    {
        cin >> color >> power;
        (color == "red" ? red : blue).push_back(power);
    }

    sort(red.rbegin(), red.rend());
    sort(blue.rbegin(), blue.rend());

    max_red = min(K, (int) red.size());

    for (r = max_red; r >= 0; r--)
    {
        b = K - r;

        if (b > (int)blue.size())
            continue;
        
        for (j = 0; j < r; j++)
            total += red[j];

        for (j = 0; j < b; j++)
            total += blue[j]; 
        
        if (r > best_red_count || (r == best_red_count && total > best_total))
        {
            best_red_count = r;
            best_total = total;
        }
    }

    cout << best_red_count << " " << best_total << "\n";
    return 0;
}