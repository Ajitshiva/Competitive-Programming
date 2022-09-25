#include <bits/stdc++.h>
using namespace std;
#define int long long int


struct node
{
	int val;
	int dist;
};

struct comp
{
	bool operator()(node& a, node b)
	{
		return a.dist > b.dist;
	}
};

vector<vector<node>> adj;
class Dijkstra
{
	vector<int> dist;
	vector<int> parent;
	vector<int> path;
public:
	Dijkstra(int n)
	{
		dist.resize(n+1, LLONG_MAX);
		parent.resize(n+1, -1);
	}

	int findDist(int from, int to)
	{
		dist[from] = 0;
		priority_queue<node, vector<node>, comp> pq;
		pq.push({from, 0});
		dist[from] = 0;
		while(!pq.empty())
		{
			auto from = pq.top();
			int u = from.val;
			pq.pop();
			for(auto to : adj[u])
			{
				int v = to.val;
				int d = to.dist;
				if(dist[u] + d < dist[v])
				{
					dist[v] = dist[u] + d;
					parent[v] = u; 
					pq.push({v, dist[v]});
				}
			}
		} 
		int curr = to;
		while(curr != -1)
		{
			path.push_back(curr);
			curr = parent[curr];
		}
		reverse(path.begin(), path.end());
		return dist[to];
	}

	void printPath()
	{
		for(int i : path) cout << i << ' ';
		cout << '\n';
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	adj.resize(n+1, vector<node>());
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	Dijkstra helper(n);
	int dist = helper.findDist(1, n);
	if(dist == LLONG_MAX)
	{
		cout << -1 << '\n';
		return 0;
	}

	helper.printPath();

}