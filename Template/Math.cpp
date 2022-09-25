#include <bits/stdc++.h>

using namespace std;


const int N = 1e3 + 5;
vector<int> spf;

void sieve()
{
    spf.resize(N, 0);
    for(int i = 1; i < N; i++) spf[i] = i;

    for(int i = 2; i * i < N; i++)
    {
        if(spf[i] != i) continue;
        for(int j = i * i; j < N; j += i)
        {
            spf[j] = i;
        }
    }
}


int mul(int a, int b)
{
    return a * b % mod;
}
int power(int base, int exponent, int mod)
{
	int ans = 1;
	while(exponent > 0)
	{
		if(exponent & 1)
		{
			ans = ans * base % mod;
		}
		base = base * base % mod;
		exponent /= 2;
	}
	return ans;
}

int ncr(int n, int r)
{
	int 
} 
int main()
{
	cout << power(5, 4, 1000007);
}
typedef array<int, 3> Node; // node, time, cost
auto cmp = [](auto &a, auto &b) { return a[1] > b[1]; }; // min-heap: Heap top is the node with the smallest time to reach
priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);