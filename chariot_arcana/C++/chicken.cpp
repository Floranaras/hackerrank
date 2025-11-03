#include <bits/stdc++.h>
using namespace std;

int n, k;
int nums[100000];

long long solve()
{
    if (k == 1) {
        vector<int> freqs(nums, nums + n);
        sort(freqs.begin(), freqs.end(), greater<int>());
        
        long long total = 0;
        for (int i = 0; i < n; i++)
            total += (long long)freqs[i] * (i + 1);
        
        return total;
    }

    multiset<long long> nodes;
    for (int i = 0; i < n; i++)
        nodes.insert(nums[i]);

    long long ans = 0;

    while (nodes.size() > 1) {
        long long sum = 0;
        int merge_count = min(k, (int)nodes.size());
        
        for (int i = 0; i < merge_count; i++) {
            sum += *nodes.begin();
            nodes.erase(nodes.begin());
        }
        
        ans += sum;
        nodes.insert(sum);
    }

    return ans;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    printf("%lld\n", solve());
    return 0;
}