#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <math.h>
 
using namespace std;
 
int gcd(int n1, int n2)
{
	int div;
	if (n1 == n2)
		return n1;
	int d = n1 - n2;
	if (d < 0)
	{
		d = -d;
		div = gcd(n1, d);
	}
	else
	{
		div = gcd(n2, d);
	}
	return div;
}
int main() {
	int p = 1;
	// cin >> p;
	for (int t = 0; t < p; t++) {
		int n;
		cin >> n;
		vector<int> a;
		set <pair<int, int>> s;
		int ind1, ind2;
		int r = 0;
		for (int j = 0; j < n; j++) {
			int b;
			cin >> b;
			a.push_back(b);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (gcd(a[i], 2 * a[j]) > 1 && i != j) {
					s.insert({ min(a[i], 2 * a[j]), max(a[i], 2 * a[j]) });
					r++;
				}
				else if (gcd(a[j], 2 * a[i]) > 1 && i != j) {
					s.insert({ min(a[i], 2 * a[j]), max(a[i], 2 * a[j]) });
					r++;
				}
			}
		}
 
		cout << r / 2<< '\n';
	}
}