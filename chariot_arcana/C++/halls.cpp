#include <bits/stdc++.h>

using namespace std;

int p, n, towns[100000];

bool can_fit(int max_per_place)
{
    int places_needed = 0;
    int i;

    for (i = 0; i < n; i++) {
        places_needed += (towns[i] + max_per_place - 1) / max_per_place;
        
        if (places_needed > p)
            return false;
    }

    return places_needed <= p;
}

int solve()
{
    int left = 1;
    int right = 0;
    int mid, result;
    int i;

    for (i = 0; i < n; i++) {
        if (towns[i] > right)
            right = towns[i];
    }

    result = right;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (can_fit(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main()
{
    int i;

    cin >> p >> n;

    for (i = 0; i < n; i++) {
        cin >> towns[i];
    }

    cout << solve() << endl;

    return 0;
}