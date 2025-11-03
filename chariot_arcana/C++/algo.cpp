#include <bits/stdc++.h>

#define MAX_N 100000
#define MOD 1000000007LL

using namespace std;

typedef long long ll;

struct cut {
    int instability;
    int dimension;
};

bool compare_cuts(struct cut a, struct cut b)
{
    return a.instability > b.instability; // Sort in descending order
}

int l, w, d;
struct cut cuts[MAX_N * 3];
int total_cuts;

ll solve()
{
    ll total = 0;
    ll l_cuts = 0, w_cuts = 0, d_cuts = 0;
    int i;

    sort(cuts, cuts + total_cuts, compare_cuts);

    for (i = 0; i < total_cuts; i++) {
        int inst = cuts[i].instability;
        int dim = cuts[i].dimension;
        
        if (dim == 0) {
            ll sections = (w_cuts + 1) * (d_cuts + 1);
            total = (total + (ll)inst * sections) % MOD;
            l_cuts++;
        } else if (dim == 1) {
            ll sections = (l_cuts + 1) * (d_cuts + 1);
            total = (total + (ll)inst * sections) % MOD;
            w_cuts++;
        } else {
            ll sections = (l_cuts + 1) * (w_cuts + 1);
            total = (total + (ll)inst * sections) % MOD;
            d_cuts++;
        }
    }

    return total;
}

int main()
{
    int i;

    scanf("%d%d%d", &l, &w, &d);

    total_cuts = 0;
    for (i = 0; i < l; i++) {
        scanf("%d", &cuts[total_cuts].instability);
        cuts[total_cuts].dimension = 0;
        total_cuts++;
    }
    for (i = 0; i < w; i++) {
        scanf("%d", &cuts[total_cuts].instability);
        cuts[total_cuts].dimension = 1;
        total_cuts++;
    }
    for (i = 0; i < d; i++) {
        scanf("%d", &cuts[total_cuts].instability);
        cuts[total_cuts].dimension = 2;
        total_cuts++;
    }

    printf("%lld\n", solve());

    return 0;
}