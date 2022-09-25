#include <bits/stdc++.h>

using namespace std;
#define int long long int

struct node
{
	int u;
	int v;
	int dist;
};

vector<node> edges;

int32_t main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	vector<int> dist(n+1, INT_MAX);
	vector<int> parent(n+1);
	dist[1] = 0;
	int relaxedVertex = -1;
	for(int i = 0; i < n; i++)
	{
		relaxedVertex = -1;
		for(auto& edge : edges)
		{
			auto [u, v, w] = edge;
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				parent[v] = u;
				relaxedVertex = v;
			}
		}
	}

	if(relaxedVertex != -1)
	{
		cout << "YES" << '\n';
		for(int i = 0; i < n; i++)
		{
			relaxedVertex = parent[relaxedVertex];
		}
		vector<int> cycle;
		for(int v = relaxedVertex;; v = parent[v])
		{
			cycle.push_back(v);
			if(v == relaxedVertex && cycle.size() > 1)
			{
				break;
			}
		}
		reverse(cycle.begin(), cycle.end());
		for(int i : cycle) cout << i << ' ';
		return 0;
	}
	
	cout << "NO" << "\n";
}