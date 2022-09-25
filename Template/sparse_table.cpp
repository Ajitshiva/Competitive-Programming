#include<bits/stdc++.h>
using namespace std;
#define int long long int


class SparseTable
{
public:
	vector<int> arr;
	vector<vector<int>> st;
	vector<int> LOG;
	int m = 20;
	int n;
	SparseTable(int n)
	{
		arr.resize(n);
		this->n = n;
		st.resize(n, vector<int>(m+1, LLONG_MAX));
		LOG.resize(n+1);
	}
	void build()
	{
		for(int i = 0; i < n; i++)
		{
			st[i][0] = arr[i];
		}
		for(int j = 1; j <= m; j++)
		{
			for(int i = 0; i < n; i++)
			{
				int l = i;
				int r = i + (1 << j);
				if(r > n) break;
				st[l][j] = min(st[l][j-1] , st[l + (1 << (j - 1))][j-1]);
			}
		}
		LOG[1] = 0;
		for(int i = 2; i <= n; i++)
		{
			LOG[i] = LOG[i/2] + 1;
		}
	}

	int rmq(int l, int r)
	{
		int j = LOG[r - l + 1];
		return min(st[l][j], st[r - (1 << j) + 1][j]);
	}

	int rsq(int l, int r)
	{
		int sum = 0;
		for(int j = m; j >= 0; j--)
		{
			if((1 << j) <= r - l + 1)
			{
				sum += st[l][j];
				l += (1 << j);
			}
		}
		return sum;
	}
};

int32_t main()
{
	int n;
	cin >> n;
	int q;
	cin >> q;
	SparseTable st = SparseTable(n);
	for(int i = 0; i < n; i++)
	{
		cin >> st.arr[i];
	}
	st.build();
	for(int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << st.rmq(l, r) << '\n';
	}

}