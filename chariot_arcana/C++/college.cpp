#include <bits/stdc++.h>

#define MAX_N 200000

using namespace std;

int diffs[MAX_N]; // stores the difficulty values of each of the courses

/*
Solve a single test case.

Parameters:
n : int - number of courses to consider
k : int - maximum number of courses that can be taken in one term

Returns:
An integer indicating the smallest total difficulty rating across all terms.
*/
long long solve(int n, int k) {
    long long total = 0;
    int i;

    sort(diffs, diffs + n, greater<int>());

    for (i = 0; i < n; i += k) {
        total += diffs[i];
    }

    return total;
}

int main() {
    int n, k;
    scanf("%d%d",&n,&k);

    for(int i = 0; i < n; i++) {
        scanf("%d",&diffs[i]);
    }

    printf("%lld\n",solve(n,k));
}