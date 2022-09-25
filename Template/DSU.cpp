#include <bits/stdc++.h>

using namespace std;

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

	void merge(int x, int y)
	{
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(rank[x] < rank[y]) swap(x, y);
		parent[y] = x;
		if(rank[x] == rank[y]) rank[x]++;

	}

	int countComponents()
	{
		return set<int>(parent.begin()+1, parent.end()).size();
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	dsu.build();
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		dsu.merge(u, v);
	}
	cout << dsu.countComponents() << '\n';



}