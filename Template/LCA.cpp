#include <bits/stdc++.h>
using namespace std;

class LCAHelper
{
public:
    vector<vector<int>> adj;
    vector<vector<int>> parent;
    vector<int> level;
    vector<int> dist;
    int m = 20;
    LCAHelper(int n)
    {
        adj.resize(n + 1, vector<int>());
        parent.resize(n + 1, vector<int>(m+1, -1));
        level.resize(n + 1);
        dist.resize(n + 1);
    }

    void build(int node, int par)
    {
        parent[node][0] = par;
        for(int i = 1; i < m; i++)
        {
            int middle = parent[node][i-1];
            if(middle != -1)
            parent[node][i] = parent[middle][i-1];
        }

        for(int child : adj[node])
        {
            if(child != par)
            {
            	level[child] = level[node] + 1;
                build(child, node);
            }
        }
    }


    int findLCA(int u, int v)
    {
        if(level[u] < level[v]) swap(u, v); // level[u] >= level[v]

        int diff = level[u] - level[v];

        for(int i = m; i >= 0; i--)
        {
            int lift = (1 << i);
            if(lift <= diff)
            {
                diff -= lift;
                u = parent[u][i];
            }
        }

        if(u == v) return u;

        for(int i = m; i >= 0; i--)
        {
            if(parent[u][i] != parent[v][i])
            {
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        return parent[u][0];
    }

    int findDist(int u, int v)
    {
        return level[u] + level[v] - 2 * level[findLCA(u, v)];
    }

    int findKthNode(int u, int v, int k)
    {
        int LCA = findLCA(u, v);
        int left = findDist(u, LCA);
        int right =  findDist(v, LCA);
        if(k <= left + 1)
        {
            int diff = k - 1;
            for(int i = m; i >= 0; i--)
            {
                int val = (1 << i);
                if(val <= diff)
                {
                    u = parent[u][i];
                    diff -= val;
                }
            }
            return u;
        }
        else
        {
            int total = left + right + 1;
            int diff = total - k;
            for(int i = m; i >= 0; i--)
            {
                int val = (1 << i);
                if(val <= diff)
                {
                    v = parent[v][i];
                    diff -= val;
                }
            }
            return v;

        }
    }
    
};
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int q;
	cin >> q;
	LCAHelper lcaUtil = LCAHelper(n); 
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		lcaUtil.adj[u].push_back(v);
		lcaUtil.adj[v].push_back(u);
	}
	lcaUtil.build(1, -1);
	for(int i = 0; i < q; i++)
	{
		int u, v;
		cin >> u >> v;
		cout << lcaUtil.findDist(u, v) << '\n';
	}
	
}