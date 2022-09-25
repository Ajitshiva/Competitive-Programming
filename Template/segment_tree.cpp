#include <bits/stdc++.h>
using namespace std;
// #include "debug.h"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define int long long int

int mod = 1e9 + 7;


int add(int a, int b)
{
	return (a + b) % mod;
}

int mul(int a, int b)
{
	return a * b % mod;
}

struct node
{
	int val = 0;
	int lazy = 0;
};

int n, q;
class SegmentTree
{
public:	
	vector<int> arr;
	vector<node> seg;
	SegmentTree(int n)
	{
		arr.resize(n);
		seg.resize(4 * n + 1);
	}
	void upd(int id, int val, int l, int r)
	{
		int len = (r - l + 1);
		seg[id].val += len * val;
		seg[id].lazy = val;
	}
	void propagate(int id, int l, int r)
	{
		if(seg[id].lazy == 0) return;
		int left = 2 * id + 1, right = 2 * id + 2;
		int mid = l + (r - l) / 2;
		int val = seg[id].lazy;
		upd(left, val, l, mid);
		upd(right, val, mid + 1, r);
		seg[id].lazy = 0;
	}

	node combine(node x, node y)
	{
		node res;
		res.val = x.val + y.val;
		return res;
	}

	node create(int val)
	{
		node temp;
		temp.val = val;
		return temp;
	}
	void build(int id = 0, int l = 0, int r = n - 1)
	{
		if(l == r)
		{
			seg[id] = create(arr[l]); 
			return;
		}
		int mid = l + (r - l) / 2;
		int left = 2 * id + 1, right = 2 * id + 2;
		build(left, l, mid);
		build(right, mid + 1, r);
		seg[id] = combine(seg[left], seg[right]);
	}

	node query(int x, int y, int id = 0, int l = 0, int r = n - 1)
	{
		if(l > y || r < x)
		{
			return create(0);
		}
		if(l >= x && r <= y)
		{
			return seg[id];
		}
		propagate(id, l, r);

		int mid = l + (r - l) / 2;
		int left = 2 * id + 1, right = 2 * id + 2;
		node ans = combine(query(x, y, left, l, mid), query(x, y, right, mid + 1, r));
		return ans;
	}

	void pointUpdate(int pos, int val, int id = 0, int l = 0, int r = n - 1)
	{
		if(l == r)
		{
			arr[pos] = val;
			seg[id] = create(val);
			return;
		}
		int mid = l + (r - l) / 2;
		int left = 2 * id + 1, right = 2 * id + 2;
		if(pos <= mid)
		{
			pointUpdate(pos, val, left, l, mid);
		}
		else
		{
			pointUpdate(pos, val, right, mid + 1, r);
		}
		seg[id] = combine(seg[left], seg[right]);
	}

	void rangeUpdate(int x, int y, int val, int id = 0, int l = 0, int r = n - 1)
	{
		if(l > y || r < x) return;
		if(l >= x && r <= y)	
		{

			upd(id, val, l, r);
			return;
		}
		int mid = l + (r - l) / 2;
		int left = 2 * id + 1, right = 2 * id + 2;
		propagate(id, l, r);
		rangeUpdate(x, y, val, left, l, mid);
		rangeUpdate(x, y, val, right, mid + 1, r);
		seg[id] = combine(seg[left], seg[right]);
	}
};
signed main()
{
	fastio;
	cin >> n >> q;
	SegmentTree st = SegmentTree(n);
	for(int i = 0; i < n; i++)
	{
		cin >> st.arr[i];
	}
	st.build();
	for(int i = 0; i < q; i++)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int x, y, val;
			cin >> x >> y >> val;
			x--;
			y--;
			st.rangeUpdate(x, y, val);
		}
		else
		{
			int x, y;
			cin >> x >> y;
			y--;
			x--;
			node ans = st.query(x, y);

			cout << ans.val << '\n';
		}
	}
	return 0;
}