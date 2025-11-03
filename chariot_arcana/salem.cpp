#include <bits/stdc++.h>

using namespace std;

struct interval {
    long long left;
    long long right;
};

int n;
long long L;
struct interval coverage[1000000];

bool compare_intervals(struct interval a, struct interval b)
{
    return a.left < b.left;
}

int main()
{
    int i;
    int needed = 0;
    long long current_end = 0;
    int idx = 0;

    cin >> L >> n;

    for (i = 0; i < n; i++) {
        scanf("%lld%lld", &coverage[i].left, &coverage[i].right);
    }

    sort(coverage, coverage + n, compare_intervals);

    while (current_end < L) {
        long long next_end = current_end;
        
        while (idx < n && coverage[idx].left <= current_end + 1) {
            if (coverage[idx].right > next_end) {
                next_end = coverage[idx].right;
            }
            idx++;
        }

        if (next_end == current_end) {
            printf("'Salem's Lot is doomed.\n");
            return 0;
        }

        current_end = next_end;
        needed++;
    }

    printf("%d\n", n - needed);

    return 0;
}