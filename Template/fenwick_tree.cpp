#include<bits/stdc++.h>
using namespace std;
// #include "debug.h"
#define int long long int


class FenwickTree
{
	vector<int> bit;
	int n;
public:
	FenwickTree(int n)
	{
		bit.assign(n + 5, 0);
		this->n = n + 5;
	}

	int query(int idx)
	{
		int sum = 0;
		while(idx > 0)
		{
			sum += bit[idx];
			idx -= idx & (-idx);
		}
		return sum;
	}

	void add(int idx, int val)
	{
		while(idx < n)
		{
			bit[idx] += val;
			idx += idx & (-idx);
		}
	}

	int find(int val) // find kth element in the multiset
	{
		int sum = 0;
		int pos = 0;

		for(int i = 20; i >= 0; i--)
		{
			int idx = (1 << i);
			if(pos + idx < n && sum + bit[pos + idx] < val)
			{
				sum += bit[pos + idx];
				pos += idx;
			}
		}

		return pos + 1;
	}
};

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	int arr[n];
	FenwickTree ft(n);
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		ft.add(arr[i], 1);
	}
	for(int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		if(x >= 1 && x <= n)
		{
			ft.add(x, 1);
		}
		else if(x < 0)
		{
			x = abs(x);
			int idx = ft.find(x);
			ft.add(idx, -1);
		}
	}
	int idx = ft.find(1);
	if(idx > n) cout << 0 << '\n';
	else cout << idx << '\n';

}