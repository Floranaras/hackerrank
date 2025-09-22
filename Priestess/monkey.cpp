#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

struct MergeSortTree 
{
	int n;
	vector<vector<int>> tree;
	vector<int> sortedVals;

	MergeSortTree(const vector<int>& vals)
	{
		n = vals.size();
		tree.resize(4 * n);
		sortedVals = vals;
		sort(sortedVals.begin(), sortedVals.end());
		sortedVals.erase(unique(sortedVals.begin(), 
						  sortedVals.end()), sortedVals.end());
		build(1,0,n-1, vals);
	}

	void build(int node, int l, int r, const vector<int>& vals) 
	{
		if (l == r) 
		{
			tree[node] = {vals[l]};
			return;
		}

		int mid = (l + r) >> 1;
		build(node << 1, l, mid + 1, r, vals);
		tree[node].resize(tree[node << 1].size() + tree[(node << 1) + 1].size());
		merge(tree[node << 1].begin(), tree[(node << 1) + 1].end(),
		   tree[(node << 1) + 1].begin(), tree[(node << 1) + 1].end(),
		   tree[node].begin());
	}
	
	int countGE (int node, int l, int r, int ql, int qr, int x) 
	{
		if (qr < l || r < ql)
			return 0;
		if (ql <= l && r <= qr) 
		{
			auto it = lower_bound(tree[node].begin(), tree[node].end(), x);
			return tree[node].end() - it;
		}

		int mid = (l + r) >> 1;
		return countGE(node << 1, l, mid, ql, qr, x) +
			countGE((node << 1) + 1, mid + 1, r, ql, qr, x);
	}

	int kthLargest (int ql, int qr, int k) 
	{
		int lo = 0;
		int hi = sortedVals.size() - 1;
		int ans = -1;

		while (lo <= hi)
		{
			int mid = (lo + hi) >> 1;
			int val = sortedVals[mid];
			int cnt = countGE(1, 0, n - 1, ql, qr, val);

			if (cnt >= k)
			{
				ans = val;
				lo = mid + 1;
			}

			else 
			{
				hi = mid - 1;
			}
		}

		return ans;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	scanf("%d", &n);

	while (q--) 
	{
		int s;
		int e;
		int A;
		int K;

		scanf("%d %d %d %d", &s, &e, &A, &K);
		if (s > e)
			swap(s,e);

		int tickets = A / K;
		if (tickets <= 0)
		{
			printf("-1\n");
			continue;
		}

		int range_size = e - s + 1;
		tickets = min(tickets, range_size);

		int ans = mst.kthLargest(s, e, tickets);
		printf("%d\n", ans);
	}
}
