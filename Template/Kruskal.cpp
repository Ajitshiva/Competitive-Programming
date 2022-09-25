#include <bits/stdc++.h>
using namespace std;

#define int long long int
vector<array<int, 3>> edges;

class DSU
{
	vector<int> parent;
	vector<int> rank;
	int n;

public:
	
	DSU(int _n):n(_n)
	{
		parent.resize(n+1);
		rank.resize(n+1);
	}

	void build()
	{
		for(int i = 1; i <= n; i++)
		{
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int find(int x)
	{
		if(x == parent[x]) return x;
		return parent[x] = find(parent[x]);
	}

	bool merge(int x, int y)
	{
		x = find(x);
		y = find(y);
		if(x == y) return false;
		if(rank[x] < rank[y]) swap(x, y);
		parent[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
		return true;
	}

	int countComponents()
	{
		return set<int>(parent.begin()+1, parent.end()).size();
	}
};

int32_t main()
{
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	dsu.build();
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	sort(edges.begin(), edges.end(), [](array<int, 3> a, array<int, 3> b){
		return a[2] < b[2];
	});

	for(int i = 0; i < m; i++)
	{
		auto [u, v, w] = edges[i];
		if(dsu.merge(u, v)) ans += w;
	}
	cout << ans << '\n';
	return 0;
}