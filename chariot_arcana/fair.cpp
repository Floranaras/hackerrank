#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, c, ans, cur_ind, left_bound;
vii vals;

long long solve(int n, int c, vii vals)
{
    int count = 0;
    int last_end = -1;
    int i;

    sort(vals.begin(), vals.end());

    for (i = 0; i < n; i++) {
        int end_time = vals[i].first;
        int start_time = vals[i].second;

        if (start_time >= last_end) {
            count++;
            last_end = end_time;
        }
    }

    return (long long)count * c;
}

int main()
{
    int i;
    int start, end;

    cin >> n >> c;
    vals.assign(n, ii());

    for (i = 0; i < n; i++) {
        cin >> start >> end;
        vals[i] = ii(end, start);
    }

    cout << solve(n, c, vals) << endl;

    return 0;
}